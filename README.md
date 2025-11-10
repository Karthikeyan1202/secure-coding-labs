<div align="center">
<br/>
<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,18,30&height=180&section=header&text=Secure%20Coding%20Labs&fontSize=42&fontAlignY=38&animation=fadeIn&fontColor=ffffff" alt="Header Wave"/>
<br/>
<br/>
<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
<img src="https://img.shields.io/badge/Security-CERT%20Rules-critical?style=for-the-badge&logo=shield&color=red" alt="CERT Secure Coding"/>
<img src="https://img.shields.io/badge/Tools-Valgrind%20%7C%20Frama--C%20%7C%20GCC%20Sanitizers-success?style=for-the-badge&logo=linux" alt="Tools"/>
<img src="https://img.shields.io/badge/Course-M.Tech%20Cybersecurity-orange?style=for-the-badge&logo=graduation-cap" alt="M.Tech"/>
<br/>
</div>

---

# Secure Coding Labs

**Secure Coding Labs** is a hands-on repository of concise C programs that demonstrate common software vulnerabilities and their secure fixes.  
This collection is intended for M.Tech Cybersecurity coursework under **Dr. Praveen K** and focuses on practical, reproducible lab exercises: exploit, observe, and fix.

---

## What you get
- Minimal, focused examples: `vulnerable.c` vs `secure.c` for each lab.  
- Makefiles to build, run, and analyze each lab.  
- Guided README for each lab: step-by-step exploit + fix notes.  
- Tool-friendly: Valgrind, Helgrind, GCC sanitizers, Frama-C workflows included.

---

## Lab index

| Folder | CERT Rule | Key vulnerabilities & fixes |
|---|---:|---|
| `Buffer_Overflows_Code/` | `MEM35-C`, `STR31-C` | Stack smashing via `gets()` → use `fgets()`, bounds-safe copies (`memcpy_s` / `strlcpy`) |
| `CERT-FIO_Input_Output_Code/` | `FIO00-C` | Path traversal & insecure `fopen` → use safe temp files, validate/sanitize paths |
| `CERT-INT_Integer_Security_Code/` | `INT30-C` | Signed/unsigned wraparound and overflows → use safe integer libraries / checks |
| `CERT-MEM_Memory_Management_Code/` | `MEM35-C` | Double-free, use-after-free → initialize pointers, use RAII-style patterns, safe allocators |
| `CERT-STR_String_Handling_Code/` | `STR31-C` | `strcpy` truncation → `strlcpy`/`strlcat`, explicit length checks |
| `Frama-C_Static_Analysis_for_Integers_Code/` | `INT32-C` | Formal verification of no-overflow paths using Frama-C + WP |
| `Helgrind_Thread_Race_Conditions_Code/` | `CON33-C` | Data races and improper locking → proper mutex discipline; Helgrind examples |
| `Valgrind_Memcheck_Memory_Debugging_Code/` | `MEM35-C` | Memory leaks, invalid reads/writes → full Memcheck walkthrough |
| `C_Memory_Layout_Code/` | — | Visualize stack, heap, BSS, data, text segments (learning aid) |
| `Set-UID_and_Privilege_Escalation_Code/` | `POS36-C` | Set-UID exploits, secure privilege dropping patterns |
| `Set-UID_and_Environment_Variables_Code/` | `ENV33-C` | `LD_PRELOAD` pitfalls, insecure `getenv`, env sanitization |

Each lab folder contains:
- `vulnerable.c` — intentionally insecure code
- `secure.c` — fixed version with explanations
- `Makefile` — quick build & analysis targets
- `README.md` — step-by-step exploit, analysis, and remediation guide

---
