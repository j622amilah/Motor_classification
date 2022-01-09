# Motor_classification

---------------------------------
Git : push files in a folder from the PC to my GitHub account
---------------------------------
git config --list --show-origin


1) Go to folder of the files that you want to upload
cd C:\Users\jamilah\Documents\Github_analysis_PROJECTS\Motor_classification


Set the remote repository (github repository) that you want to push and pull to/from
git config --global remote.origin.url https://github.com/j622amilah/Motor_classification.git

OR

git remote add origin https://github.com/j622amilah/Motor_classification.git
git remote add origin git://github.com/j622amilah/Motor_classification.git


2) Initialize the local directory as a Git repository
git init -b main


3) Add Local repository : called 'Stage and commit all the files in your project'
git add .     (if you want to add everything in the local repository)

OR

git add foldername       (if you want to add a folder from the local repository)


4) Commit repository
git commit -m "empty message"


5) git merge

If merge or pull fails, you need to fix document conflicts ON github by either add or rm each file manually.  Then you can commit and try again
git add filename
OR
git rm filename    (This actually deletes the file on GitHUB)


6) Pull Repository from github first, while synchronizing the branches
git pull origin main --allow-unrelated-histories


7) Push the changes in your local repository to the remote repositor (NOTE: you can not push if you have not successfully pulled first)
git push origin main

If you use -u in the command, it will remember your preferences for remote and branch and you can simply use the command git push next time.  git push -u origin master
---------------------------------
