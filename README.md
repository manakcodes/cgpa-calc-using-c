# CGPA Calculator using C

A simple terminal-based CGPA calculator written in C.

---

## ⚠️ This CGPA Calculator uses the following grade-to-grade-point conversion system:

![CGPA Calculator Demo](grade_system.png)

---

## 🧠 How It Works

- Enter the number of subjects.
- Enter the marks of each subject, credits of each subject.
- Validates inputs for marks and credits.
- Automatically calculates :

  - Final CGPA
  - Final Percentage

- Displays the calculated data in a tabular form.

---

## 🛠️ Tools & Languages Used

<p align="left">
  
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" alt="C language logo" width=60/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/gcc/gcc-original.svg" alt="gcc logo" width=60/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cmake/cmake-original.svg" alt="Cmake logo" width=60/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/vscode/vscode-original.svg" alt="VS-Code logo" width="60"/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg" alt="bash-terminal logo" width="60"/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" alt="git logo" width=60/>

  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original-wordmark.svg" alt="github logo" width=60/>
          
</p>

---

## 🖥️ Project Requirements

Before you run the program, make sure you have the following:

Before you run the program, make sure you have the following :

- A **C compiler** (e.g., `gcc`)
- The **Make** utility (to build the project using a Makefile)
- A **terminal or shell environment** (macOS, Linux, or Windows using WSL/MinGW)

## 🤖 How to Run This On Your Device

### 🛸 First-Time Setup Instructions

> (Follow these steps when setting up the project for the first time.)

#### ⒈ Navigate to Desktop (you can clone in any directory)

`cd Desktop`

#### ⒉ Clone the Repository

`git clone https://github.com/manakcodes/cgpa-calc-using-c.git`

---

### 📊 How to Use the Calculator

> (Follow these steps to use the cgpa calculator every time.)

#### ⒈Enter the project directory

`cd ~/Desktop/cgpa-calculator-in-c`

#### ⒉ Compile the Source Code Using Makefile

`make`

#### ⒊ Run the Program

`./Main`

#### ⒋ Clean Build Artifacts (To remove compiled files and reset the project state)

`make clean`

---

## 🪪 [LICENSE](https://github.com/manakcodes/cgpa-calc-using-c/blob/82ddf3f5669b9a5e2e3a5e4a131ae997368e6a7b/LICENSE)

## 🌲 Project Tree

<pre>
<code>
.
├── grade_system.png
├── include
│   ├── cgpa_calculator.h
│   ├── get_result.h
│   ├── input_user.h
│   ├── print_resultset.h
│   └── utility_methods.h
├── LICENSE
├── Makefile
├── README.md
└── src
    └── Main.c

3 directories, 10 files
</code>
</pre>

---
