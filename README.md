# CPP Modules

<div align="center">

![42 Lyon](https://img.shields.io/badge/42-Lyon-000000?style=for-the-badge&logo=42&logoColor=white)
![Score](https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge)
![C++](https://img.shields.io/badge/C++-98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

**Object-Oriented Programming with C++**

</div>

---

## Description

This repository contains my solutions to the **CPP Modules** (00-09) from the 42 School curriculum. These modules introduce Object-Oriented Programming concepts in C++98, covering topics from basic syntax to advanced template programming and STL containers.

---

## Modules Overview

| Module | Topics | Exercises |
|:------:|--------|:---------:|
| **CPP01** | Memory allocation, References, Pointers to members, Switch | 7 |
| **CPP02** | Ad-hoc polymorphism, Operator overloading, Orthodox Canonical Form | 4 |
| **CPP03** | Inheritance | 3 |
| **CPP04** | Subtype polymorphism, Abstract classes, Interfaces | 3 |
| **CPP05** | Exceptions | 4 |
| **CPP06** | C++ Casts | 3 |
| **CPP07** | C++ Templates | 3 |
| **CPP08** | Templated containers, Iterators, Algorithms | 3 |
| **CPP09** | STL Containers | 3 |

---

## Module Details

<details>
<summary><b>CPP01 - Memory & References</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | BraiiiiiiinnnzzzZ | Stack vs Heap allocation |
| ex01 | Moar brainz! | Pointer arrays, Memory management |
| ex02 | HI THIS IS BRAIN | References vs Pointers |
| ex03 | Unnecessary violence | References, Pointers to members |
| ex04 | Sed is for losers | File streams, String manipulation |
| ex05 | Harl 2.0 | Pointers to member functions |
| ex06 | Harl filter | Switch statements |

</details>

<details>
<summary><b>CPP02 - Operator Overloading</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | My First Class in Orthodox Canonical Form | Orthodox Canonical Form |
| ex01 | Towards a more useful fixed-point number class | Fixed-point numbers, Constructors |
| ex02 | Now we're talking | Operator overloading |
| ex03 | BSP | Binary Space Partitioning |

</details>

<details>
<summary><b>CPP03 - Inheritance</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Aaaaand... OPEN! | ClapTrap class |
| ex01 | Serena, my love! | ScavTrap inheritance |
| ex02 | Repetitive work | FragTrap inheritance |

</details>

<details>
<summary><b>CPP04 - Polymorphism</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Polymorphism | Virtual functions |
| ex01 | I don't want to set the world on fire | Deep copy, Brain class |
| ex02 | Abstract class | Pure virtual functions |

</details>

<details>
<summary><b>CPP05 - Exceptions</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Mommy, when I grow up, I want to be a bureaucrat! | Exception handling |
| ex01 | Form up, maggots! | Form class, try/catch |
| ex02 | No, you need form 28B, not 28C... | Abstract forms |
| ex03 | At least this beats coffee-making | Intern class, Form creation |

</details>

<details>
<summary><b>CPP06 - C++ Casts</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Conversion of scalar types | static_cast |
| ex01 | Serialization | reinterpret_cast |
| ex02 | Identify real type | dynamic_cast |

</details>

<details>
<summary><b>CPP07 - Templates</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Start with a few functions | Function templates |
| ex01 | Iter | Template with function pointer |
| ex02 | Array | Class templates |

</details>

<details>
<summary><b>CPP08 - Templated Containers</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Easy find | STL algorithms, Iterators |
| ex01 | Span | Container manipulation |
| ex02 | Mutated abomination | Stack inheritance |

</details>

<details>
<summary><b>CPP09 - STL</b></summary>

| Exercise | Description | Key Concepts |
|:--------:|-------------|--------------|
| ex00 | Bitcoin Exchange | std::map |
| ex01 | Reverse Polish Notation | std::stack |
| ex02 | PmergeMe | std::vector, std::deque, Ford-Johnson algorithm |

</details>

---

## Compilation

Each exercise contains its own `Makefile` with the following rules:

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Requirements

- C++98 compliant compiler (clang++ or g++)
- Make

---

## Usage

```bash
# Navigate to the desired exercise
cd cpp01/ex00

# Compile
make

# Run (executable name varies by exercise)
./zombie
```

---

## Project Structure

```
.
├── cpp01/          # Memory, References, Switch
├── cpp02/          # Operator Overloading
├── cpp03/          # Inheritance
├── cpp04/          # Polymorphism
├── cpp05/          # Exceptions
├── cpp06/          # C++ Casts
├── cpp07/          # Templates
├── cpp08/          # Templated Containers
├── cpp09/          # STL
└── README.md
```

---

## Author

| | |
|---|---|
| **vzuccare** | 42 Lyon |

[![GitHub](https://img.shields.io/badge/GitHub-FumiVZ-181717?style=flat-square&logo=github)](https://github.com/FumiVZ)
