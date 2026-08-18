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
