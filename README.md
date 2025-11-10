<!-- README.md -->
<div align="center">
  
<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,18,30&height=180&section=header&text=Secure%20Coding%20Labs&fontSize=42&fontAlignY=38&animation=fadeIn&fontColor=ffffff" alt="Header Wave"/>

<br/>


<br/>

<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
<img src="https://img.shields.io/badge/Security-CERT%20Rules-critical?style=for-the-badge&logo=shield&color=red" alt="CERT Secure Coding"/>
<img src="https://img.shields.io/badge/Tools-Valgrind%20%7C%20Frama--C%20%7C%20GCC%20Sanitizers-success?style=for-the-badge&logo=linux" alt="Tools"/>
<img src="https://img.shields.io/badge/Course-M.Tech%20Cybersecurity-orange?style=for-the-badge&logo=graduation-cap" alt="M.Tech"/>
<img src="https://img.shields.io/badge/Instructor-Dr.%20Praveen%20K-brightgreen?style=for-the-badge&logo=chalkboard-teacher" alt="Instructor"/>

<br/><br/>

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,18,30&height=180&section=header&text=Secure%20Coding%20Labs&fontSize=42&fontAlignY=38&animation=fadeIn&fontColor=ffffff" alt="Header Wave"/>

<br/>



---

## 📖 Overview

**Secure Coding Labs** is a comprehensive, hands-on collection of **C programs** that demonstrate **real-world vulnerabilities** and their **secure counterparts**, aligned with **CERT Secure Coding Standards**.

Designed for **M.Tech Cybersecurity** coursework under **Dr. Praveen K**, this repo goes beyond theory — every lab lets you **exploit**, **crash**, and **fix** classic bugs using industry-standard tools.

> **Goal**: Turn fragile C code into **bulletproof**, audit-ready software.

---

## 🗂 Lab Directory

| Lab Folder | CERT Rule | Key Vulnerabilities & Fixes |
|------------|---------|-------------------------------|
| `Buffer_Overflows_Code/` | MEM35-C, STR31-C | Stack smashing, `gets()`, safe `fgets`, `memcpy_s` |
| `CERT-FIO_Input_Output_Code/` | FIO00-C | Path traversal, insecure `fopen`, safe temporary files |
| `CERT-INT_Integer_Security_Code/` | INT30-C | Signed overflow, wraparound, safe integer libraries |
| `CERT-MEM_Memory_Management_Code/` | MEM35-C | Double-free, use-after-free, secure allocators |
| `CERT-STR_String_Handling_Code/` | STR31-C | `strcpy`, truncation, `strlcpy`/`strlcat` |
| `Frama-C_Static_Analysis_for_Integers_Code/` | INT32-C | **Static proof** of no overflow using Frama-C + WP |
| `Helgrind_Thread_Race_Conditions_Code/` | CON33-C | Data races, improper locking, Helgrind reports |
| `Valgrind_Memcheck_Memory_Debugging_Code/` | MEM35-C | Leaks, invalid reads/writes, full Memcheck workflow |
| `C_Memory_Layout_Code/` | - | Visualize stack, heap, BSS, data, text segments |
| `Set-UID_and_Privilege_Escalation_Code/` | POS36-C | SetUID exploits, privilege dropping patterns |
| `Set-UID_and_Environment_Variables_Code/` | ENV33-C | `LD_PRELOAD`, insecure `getenv`, environment sanitization |

Each folder includes:
- `vulnerable.c` – Broken on purpose
- `secure.c` – Fixed with best practices
- `Makefile` – Build both + run analysis
- `README.md` – Step-by-step exploit + fix guide

---

## 🧠 Core Concepts Covered

```text
✔ Stack & Heap Management
✔ Integer Overflow / Underflow Prevention
✔ String Handling Without Truncation
✔ Secure File I/O & Path Validation
✔ Memory Leak & Use-After-Free Detection
✔ Thread Race Conditions & Synchronization
✔ SetUID Safety & Privilege Separation
✔ Environment Variable Hardening
