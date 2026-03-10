# Q-Script

## Overview
This project is a C++ implementation of a custom scripting language designed to simulate a **Deterministic Finite Automaton (DFA)**. It reads a structured configuration file containing the DFA's formal definition (alphabet, states, start state, final states, and transitions) and evaluates a set of input strings to determine if they are accepted or rejected by the automaton.

## Features
* **Custom File Parser**: Reads and extracts DFA components dynamically from a text file.
* **State Management**: Accurately maps states and transitions using C++ standard containers (`std::set`, `std::map`).
* **Simulation Engine**: Processes input strings character by character (or string by string) and traverses the defined states.
* **Error Handling**: Detects missing transitions and halts execution for invalid paths ("Compilation error").

## Scripting Language Syntax
The automaton is defined in a text file (default: `Text.txt`) using specific section tags. Every section must be closed with the `[end]` tag. 

### Syntax Breakdown:
* `[sigma]`: The alphabet of the automaton.
* `[nodes]`: All the available states in the DFA.
* `[start]`: The initial/starting state (must be a single state).
* `[final]`: The accepting/final states of the DFA.
* `[relations]`: The transition functions. The syntax strictly follows the format: `CurrentState + InputSymbol = NextState`. Spaces are ignored.
* `[input]`: The sequence of inputs to be parsed and evaluated by the automaton.

## Prerequisites
* A C++ compiler that supports C++11 or later (e.g., MSVC, GCC, Clang).

## Project Structure
* `main.cpp`: Contains the main simulation loop and logic for traversing the DFA.
* `parser.h` / `parser.cpp`: Contains the `parser` class responsible for reading `Text.txt` and extracting the DFA components.
* `Text.txt`: The script/configuration file where the DFA is written.
