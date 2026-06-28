# ccwc - A High-Performance Clone of the Unix 'wc' Tool

A custom implementation of the classic Unix command-line utility `wc` (word, line, character, and byte count) built in C++ built as a series of project inspired by [coding challenges.fyi](https://codingchallenges.fyi/challenges/challenge-wc/).

## Project Scope & Objectives

The goal of this project is to learn and get better at CPP by recreating the complete functional requirements of the standard `man wc` specification. The tool handles input both from physical files on disk and from piped standard inputs (`stdin`), executing processing routines at production-grade speeds.

### Feature Roadmap

- [x] **Step 1:** Byte Counting (`-c`) — Count raw physical bytes of a file. (completed)
- [ ] **Step 2:** Line Counting (`-l`) — Count newline characters.
- [ ] **Step 3:** Word Counting (`-w`) — Detect word boundaries using whitespace states.
- [ ] **Step 4:** Character Counting (`-m`) — Support multi-byte UTF-8 character structures.
- [ ] **Step 5:** Standard Pipeline Integration — Accept data seamlessly via standard streams (`std::cin`).

---

## Technical Architecture & Implementation Details

Rather than taking naive shortcuts (like loading entire files into memory or utilizing OS-specific file size metadata), this tool uses an **Optimized Unified Stream Consumer** architecture.

### Core Components & Functions

#### 1. `size_t countBytes(std::istream& input)`

This is the core engine of Step 1.

* **Memory-Efficient Buffering:** Instead of pulling a file into memory line-by-line or byte-by-byte, this function reads data in fixed-size blocks (`char buffer[8192]`). This 8KB window matches typical operating system page sizes, minimizing expensive I/O system calls.
* **Stream Abstraction:** By accepting a generic reference to `std::istream`, the exact same counting logic processes a physical disk file (`std::ifstream`) or a terminal pipeline interface (`std::cin`).
* **Accurate Tracking via `.gcount()`:** Uses `input.gcount()` to track the exact number of bytes pulled into the buffer during the final, partial chunk sequence, ensuring accurate tracking down to the final byte.

---

## Key Learning Outcomes & Concepts Mastered

Through Step 1 of this challenge, I have learned and applied:

* **Binary vs. Text I/O (`std::ios::binary`):** Understood how operating systems implicitly alter newline characters (`\r\n` to `\n`) in text mode, and how forcing binary streaming ensures raw, uncorrupted byte extraction.
* **Polymorphism via `std::istream`:** Leveraged C++ stream class hierarchies to write extensible code that handles multiple input sources through a single, shared interface function.
* **Buffer Management:** Explored block-based stream reading algorithms to maintain a flat, minimal memory footprint regardless of whether the target file size is 3KB or 3GB.
