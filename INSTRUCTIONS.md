# Repository Usage Instructions

This repository is designed as a **Template Repository** for OpenGL/C++ projects. 

## Branching Strategy

To keep the template clean and reusable, the `main` branch is strictly reserved for the core template files. All your work (experiments, coursework, assignments) should be done on separate branches.

- `main`: The base template. Do not commit assignment or experiment code here.
- `experiment/<name>`: For random tests or practicing OpenGL concepts.
- `task/<name>`: For actual coursework assignments or specific projects.

## How to Work on This Repository

Whenever you want to start a new assignment or experiment, you should create a new branch from `main`. We have provided a `Makefile` to make this extremely easy.

```bash
# To start a new coursework task
make new-task NAME=tugas1

# To start a new experiment
make new-exp NAME=test-triangle
```

These commands will automatically switch to `main`, pull the latest template updates, and create your new branch so you always start with a clean slate.

## Running Code in This Workspace

| Shortcut | Target | When to Use |
| :--- | :--- | :--- |
| **`F5`** | `src/main.cpp` (NVIDIA) | Running your primary coursework/task code structured with CMake. |
| **`Ctrl + Shift + F5`** | Current Active File (AMD) | Running quick standalone `.cpp` files or textbook resources (`docs/ExperimenterSource`) without black screen issues. |

### Important Rule When Switching Branches
Always commit your changes before switching or creating new branches:
```bash
git add .
git commit -m "feat: complete experiment X"
```
If you switch branches with uncommitted edits, Git will carry those edits over to the new branch.

## How to Pull Template Updates into an Existing Branch

If the `main` branch template receives updates (configurations, utilities, or docs), you can pull them into your current branch:
```bash
make update-template
```

## How to Use This Template for a Completely New Repository

If you want to use this template for a completely different GitHub repository, follow these steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/oktavsm/opengl-workspace.git my-new-project
   cd my-new-project
   ```
2. Remove the existing Git history:
   ```bash
   rm -rf .git
   ```
3. Initialize a new Git repository:
   ```bash
   git init
   git add .
   git commit -m "chore: initialize project from opengl template"
   ```
4. Connect and push to your new remote repository:
   ```bash
   git remote add origin <YOUR_NEW_REPO_URL>
   git branch -M main
   git push -u origin main
   ```
