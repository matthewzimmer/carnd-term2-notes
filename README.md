# CarND Term 2 Notes

---

##### Syncing Upstream Changes
 
https://help.github.com/articles/syncing-a-fork/

Specify a new remote upstream repository that will be synced with the fork.

```bash
$ git remote add upstream https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git
```

1. Fetch the branches and their respective commits from the upstream repository. Commits to master will be stored in a local branch, upstream/master.
```bash
$ git fetch upstream
  remote: Counting objects: 75, done.
  remote: Compressing objects: 100% (53/53), done.
  remote: Total 62 (delta 27), reused 44 (delta 9)
  Unpacking objects: 100% (62/62), done.
  From https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY
  * [new branch]      master     -> upstream/master
```

2. Check out your fork's local master branch.
```bash
$ git checkout master
```

3. Merge the changes from upstream/master into your local master branch. This brings your fork's master branch into sync with the upstream repository, without losing your local changes.
```bash
$ git merge upstream/master
  Updating a422352..5fdff0f
  Fast-forward
   README                    |    9 -------
   README.md                 |    7 ++++++
   2 files changed, 7 insertions(+), 9 deletions(-)
   delete mode 100644 README
   create mode 100644 README.md
```

  If your local branch didn't have any unique commits, Git will instead perform a "fast-forward":
  
```bash
$ git merge upstream/master
  Updating 34e91da..16c56ad
  Fast-forward
   README.md                 |    5 +++--
   1 file changed, 3 insertions(+), 2 deletions(-)
```
