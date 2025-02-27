# CSC-145 - Text-Based Role-Playing Game (RPG)

## Project Description
We have no idea what we're doing.

## Setting Up Git and Syncing with Visual Studio
### Download Git for Windows

Git is our version control system and can be downloaded for Windows, Mac, and Linux systems.
The guide here is specifically meant for Windows hosts; however, the website and guides online can show how to download for other hosts.

Once you've downloaded the latest version of Git, run the application, and the default prompts are acceptable for our purposes.
Feel free to customize it to your personal preference (Hint: Vim sucks as a text editor). Many of these settings can be changed later.

[Download Here](https://git-scm.com/downloads)

### Configure Author Details

Once Git is installed, you'll want to access the Git Bash terminal. The terminal uses typical bash commands and text editors.
Git identifies the author of commits using a username and email, so at the prompt, use the commands:
```bash
git config user.name "{username}"
git config user.email "{email_address}"
```
where \{username} is your username and \{email_address} is your email.

Verify the status of these using:
```bash
git config --list
```
or
```bash
git config user.name
git config user.email
```

### Create a Local Repository
To create a local repository you'll need to have a project with Visual Studio.
1. Either create a new C++ empty project or use an existing one and navigate to where your code files are located.
```bash
cd C:/Users/.../Project/ProjectName/SolutionName/
```
2. Run the git init to initialize a new repository in the current directory.
```bash
git init
```
Note a new .git (hidden folder) will be placed in that directory and can be used as the source to pull and push changes.

3a. Set up the remote connection to GitHub.
```bash
git remote add origin https://{username}@github.com/{username}/CSC145-TextBasedRPG.git
git remote -v # Verify changes.
```
Adding the remote connection may open a browser tab and ask you to authenticate.

3b. Don't forget the .git portion. If you do run:
```bash
git remote remove origin
# We use set-url to replace a URL.
git remote set-url origin https://{username}@github.com/{username}/CSC145-TextBasedRPG.git
```

4. Fetch the current branches and/or pull changes.
```bash
git fetch # Downloads changes without merging them with your local files.
git pull origin main # Downloads changes from main and merges them with your local files.
```
NOTE: Pull changes before uploading new files to main.

### Changing Branches

Identifying branches:
```bash
git branch # Shows local repositories.
git branch -r # Shows remote repositories.
git branch -a # Shows local and remote repositories.
```

Switch branches:
```bash
git switch {branch-name}
# Or
git checkout {branch-name} # Older method
```

Creating branches:
```bash
git switch -c {new-branch-name}
git push --set-upstream origin {new-branch-name}
```

Deleting branches:
```bash
git pull origin main # Always remember this.
git branch -d {feature-branch-name} # For local repositories.
git branch -D {feature-branch-name} # Force deletes even if the branch is not merged.
git push origin --delete {feature-branch-name}
```

### Pulling, Pushing, and Merging
BEFORE YOU PUSH ANY CHANGES YOU NEED TO PULL THE CURRENT FILES DOWN.

Pulling files:
```bash
git pull origin main
```

First-time pushing files to a specific branch, change the last command to:
```bash
git push origin --set-upstream {feature-branch-name}
```

Pushing files:
```bash
git pull origin main # Always remember this.
# Either
git add . # Adds all files in the current directory.
# Or
git add {filename.extension}
git commit -m "Commit message" # Adds a commit with a message.
git status # Verify that the adding and committing were successful.
git push origin {feature-branch-name}
```

Merging files:
```bash
git pull origin main # Always remember this.
git switch main
git merge {feature-branch-name}
git branch -d {feature-branch-name} # For local repositories.
git push origin --delete {feature-branch-name}
```

## Syncing Git Files with Visual Studio
Go to your Visual Project with the newly added files from Git.

Step 1 - Open Solution Explorer --> Show All Files

This lets you see all the files not included in the project

![Step 1](./Images/Step-1.png)

Step 2 - Open Up the Folders Needed

All files not in the project have the red minus symbol.

![Step 2](./Images/Step-2.png)

Step 3 - Right-click and click "Include in Project."

![Step 3](./Images/Step-3.png)

Unhighlight the "Show All Files" (See Step 1) to view your newly added files.

## Contributors
*Ian McCurdy* - Project Mismanager, Watch Out For This One (Has a Tendency to Delete Main)

*Philomène Sturgeon* - Software De-engineer, Has an Accented è (Some French Thing)

*Noah Parkhurst* - Software Architect and Owner of a Monopoly of Food Establishments on FUS Grounds.

*Christian Wolk* - Professional Band Kid, Also Codes (We Think)
