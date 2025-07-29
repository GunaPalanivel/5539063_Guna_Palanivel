# 🔧 Git Workflow Demo – Patch, Rebase, Branch, Tag Practice

This repo demonstrates a complete Git lifecycle with realistic version control tasks, including rebase, patch generation, tagging, and cleanup.

---

## 📁 Repository Structure

```

5539063\_Guna\_Palanivel/
│
├── assets/
│   └── Agile\_for\_Beginners.png
├── notepad.txt
├── notes.txt
├── .gitignore
└── 0001-Hotfix-fixed-typo-in-notes.txt.patch

````

---

## ✅ What This Demo Covers

### 🔹 1. Local Commits & Branching
- Initialized repo and added `.gitignore`, `notepad.txt`
- Created feature branch `gp5901`
- Committed tracked files

```bash
git checkout -b gp5901
git add .
git commit -m "added .txt file & .gitignore file"
````

---

### 🔹 2. Hotfix with Rebase

* Created `notes.txt` on new `hotfix-linefix` branch
* Rebased it onto `main` to preserve clean history

```bash
git checkout -b hotfix-linefix
git commit -m "Hotfix: fixed typo in notes.txt"
git switch main
git rebase hotfix-linefix
```

---

### 🔹 3. Tagging and Patch Flow

* Tagged the rebase commit as `v1.0`
* Generated patch file and applied it on `patch-test`

```bash
git tag v1.0
git format-patch -1 HEAD
git checkout -b patch-test
git apply 0001-Hotfix-fixed-typo-in-notes.txt.patch
git commit -am "Applied patch manually"
```

---

### 🔹 4. Remote Sync & Pull Requests

* Pushed all working branches to GitHub:

  * `gp5901`
  * `hotfix-linefix`
  * `patch-test`

```bash
git push --set-upstream origin <branch>
git push origin --tags
```

Then opened PRs via:

* [gp5901 → main](https://github.com/GunaPalanivel/5539063_Guna_Palanivel/pull/new/gp5901)
* [patch-test → main](https://github.com/GunaPalanivel/5539063_Guna_Palanivel/pull/new/patch-test)

---

### 🔹 5. Cleanup (Branches & Tags)

```bash
git branch -d hotfix-linefix
git push origin --delete hotfix-linefix

git tag -d v1.0
git push origin --delete tag v1.0
```

---

## 🔍 Git Commit Graph

```
* 3cd90ae (HEAD -> patch-test, origin/patch-test, main) Hotfix: fixed typo in notes.txt
| *   47cc9da (origin/main, origin/HEAD) Merge pull request #1 from GunaPalanivel/gp5901
| |\
| |/
|/|
* | cdfa391 (origin/gp5901, gp5901) added .txt file & .gitignore file
|/
* 03b7e98 Add Agile for Beginners image to README and update description
* 1e156cc Initial commit
```

---

## 🧠 Learnings

This repo helps reinforce:

* Clean history via `rebase`
* Generating and applying patch files
* Tagging specific points in history
* Proper Git cleanup and remote tracking



---

✅ This is clean, audit-worthy, and GitHub/GitLab-friendly. Commit and push it:

```bash
notepad README.md
git add README.md
git commit -m "Added Git lifecycle README documentation"
git push origin patch-test
````


