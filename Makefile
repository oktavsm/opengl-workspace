.PHONY: help new-task new-exp update-template format

help:
	@echo "=========================================================="
	@echo "🎮 OpenGL Workspace Template Helper"
	@echo "=========================================================="
	@echo "Available commands:"
	@echo "  make new-task NAME=<task_name>  - Create a new branch for a coursework task"
	@echo "  make new-exp NAME=<exp_name>    - Create a new branch for an experiment"
	@echo "  make update-template            - Pull the latest changes from the main template"
	@echo "  make format                     - Auto-format C++ code using clang-format"
	@echo "=========================================================="

format:
	@find src include -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i
	@echo "✅ Code formatted successfully!"

new-task:
	@if [ -z "$(NAME)" ]; then echo "❌ Error: NAME is not set. Use 'make new-task NAME=my-task'"; exit 1; fi
	git checkout main
	git pull origin main
	git checkout -b task/$(NAME)
	@echo "✅ Created and switched to new branch: task/$(NAME)"

new-exp:
	@if [ -z "$(NAME)" ]; then echo "❌ Error: NAME is not set. Use 'make new-exp NAME=my-exp'"; exit 1; fi
	git checkout main
	git pull origin main
	git checkout -b experiment/$(NAME)
	@echo "✅ Created and switched to new branch: experiment/$(NAME)"

update-template:
	git fetch origin main
	git merge origin/main
	@echo "✅ Merged latest template changes into current branch"
