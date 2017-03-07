//
// Created by Matthew Zimmer on 3/6/17.
//

#include "main.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
int main() {

  /*******************************************************************************
   *  Set Measurements															 *
   *******************************************************************************/
  vector<MeasurementPackage> measurement_pack_list;
  vector<GroundTruthPackage> gt_pack_list;

  // hardcoded input file with laser and radar measurements
  string in_file_name_ = "obj_pose-laser-radar-synthetic-input.txt";
  ifstream in_file(in_file_name_.c_str(),std::ifstream::in);

  // hardcoded output file with the estimation (px, py, vx, vy), measurements (px and py meas) and ground truths (px, py, vx, vy)
  string out_file_name_ = "obj_pose-laser-radar-output.txt";
  std::ofstream out_file_(out_file_name_.c_str(),std::ofstream::out);

  if (!in_file.is_open()) {
    cout << "Cannot open input file: " << in_file_name_ << endl;
  }

  if (!out_file_.is_open()) {
    cout << "Cannot Open output file: " << out_file_name_ << endl;
  }

  string line;
  while(getline(in_file, line)){

    MeasurementPackage meas_package;
    GroundTruthPackage gt_package;

    istringstream iss(line);
    string sensor_type;
    iss >> sensor_type;	//reads first element from the current line
    long timestamp;
    if(sensor_type.compare("L") == 0){	//laser measurement
      //read measurements
      meas_package.sensor_type_ = MeasurementPackage::LASER;
      meas_package.raw_measurements_ = VectorXd(2);
      float x;
      float y;
      iss >> x;
      iss >> y;
      meas_package.raw_measurements_ << x,y;
      iss >> timestamp;
      meas_package.timestamp_ = timestamp;
      measurement_pack_list.push_back(meas_package);

    }else if(sensor_type.compare("R") == 0){
      //Skip Radar measurements
      continue;
    }
    //read gt
    float x_gt;
    float y_gt;
    float vx_gt;
    float vy_gt;
    iss >> x_gt;
    iss >> y_gt;
    iss >> vx_gt;
    iss >> vy_gt;
    gt_package.gt_values_ = VectorXd(4);
    gt_package.gt_values_ << x_gt,y_gt,vx_gt,vy_gt;
    gt_pack_list.push_back(gt_package);

  }

  //Create a Tracking instance
  Tracking tracking;

  //call the ProcessingMeasurement() function for each measurement
  size_t N = measurement_pack_list.size();
  for (size_t k = 0; k < N; ++k) {	//start filtering from the second frame (the speed is unknown in the first frame)
    tracking.ProcessMeasurement(measurement_pack_list[k]);
    //output the estimation
    out_file_ << tracking.kf_.x_(0) << "\t";
    out_file_ << tracking.kf_.x_(1) << "\t";
    out_file_ << tracking.kf_.x_(2) << "\t";
    out_file_ << tracking.kf_.x_(3) << "\t";

    //output the measurements
    if (measurement_pack_list[k].sensor_type_
        == MeasurementPackage::LASER) {
      //output the estimation
      out_file_ << measurement_pack_list[k].raw_measurements_(0) << "\t";
      out_file_ << measurement_pack_list[k].raw_measurements_(1) << "\t";
    } else if (measurement_pack_list[k].sensor_type_
               == MeasurementPackage::RADAR) {
      continue;
    }

    //output the gt packages
    out_file_ << gt_pack_list[k].gt_values_(0) << "\t";
    out_file_ << gt_pack_list[k].gt_values_(1) << "\t";
    out_file_ << gt_pack_list[k].gt_values_(2) << "\t";
    out_file_ << gt_pack_list[k].gt_values_(3) << "\n";
  }


  //close files
  if(out_file_.is_open()){
    out_file_.close();
  }

  if(in_file.is_open()){
    in_file.close();
  }
  return 0;
}


#pragma clang diagnostic pop