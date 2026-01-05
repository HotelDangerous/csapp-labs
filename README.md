# CSAPP Labs

This repository contains small, focused learning artifacts created while working through  
**Computer Systems: A Programmer’s Perspective (CSAPP)**.

The goal of this project is to build a deep, practical understanding of how C programs map to
machine-level behavior, with an emphasis on correctness, representation, and systems thinking.

---

## Project Structure

Each artifact in this repository follows a simple rule:

> **One concept, one file.**

Examples include:
- Bit-level integer operations
- Two’s complement edge cases
- Shift behavior and sign extension
- Overflow detection
- Small, isolated C functions with explicit assumptions

Where useful, selected functions are compiled to assembly and inspected to understand how the
compiler translates high-level code into machine instructions.

---

## Project Philosophy

- Focus on **depth over breadth**
- Prefer **small, correct artifacts** over large projects
- Make assumptions explicit (e.g., word size, two’s complement, arithmetic shifts)
- Treat exercises as opportunities to reason about edge cases and invariants

This repository is not intended to be a reusable library or production codebase.  
It is a collection of deliberate learning exercises designed to strengthen low-level intuition.

---

## Notes

- Code is written in C unless otherwise stated
- Assembly output is examined for learning purposes; instruction sequences may vary by
  compiler and optimization level
- Tests are lightweight and local, typically using `assert`

---

## Status

This repository evolves incrementally alongside CSAPP chapters and exercises.
