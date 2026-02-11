#!/bin/bash

project_dir="E:/projects/c++ course/13 - Algorithms  Problem Solving Level 5"
cd "$project_dir" || exit

echo ".vs/" >> .gitignore 2>/dev/null

if [ ! -d ".git" ]; then
    git init
    git branch -M main
fi

git remote remove origin 2>/dev/null
git remote add origin "https://github.com/osama-mohamoud2006/13---Algorithms-Problem-Solving-Level-5.git"

git add .
git commit -m "Auto commit: $(date)" || echo "Nothing to commit"
git push -u origin main
