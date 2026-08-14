# 42 C++ Modules (CPP 00 - CPP 09) ⚡

[![42 School](https://img.shields.io/badge/42-Project-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr/)
[![Language: C++](https://img.shields.io/badge/Language-C++11--C++98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Standard: C++98](https://img.shields.io/badge/Standard-C++98-blue?style=for-the-badge)](https://en.wikipedia.org/wiki/C%2B%2B98)
[![Norminette](https://img.shields.io/badge/Style-42_Compliant-brightgreen?style=for-the-badge)]()

---

## 📌 Overview

The **C++ Modules** series at 42 School introduces Object-Oriented Programming (OOP) and modern C++ paradigms. Moving away from procedural C, this series covers key C++ concepts step-by-step: data abstraction, encapsulation, inheritance, subtype polymorphism, resource management (RAII), exception handling, templates, and the Standard Template Library (STL).

All modules strictly adhere to the **C++98 standard** (compiled with `-std=c++98`), encouraging a deep understanding of memory layout, standard containers, and fundamental algorithms without modern language syntactic shortcuts.

---

## 🧠 Key Programming Concepts

* **Object-Oriented Programming (OOP):** Encapsulation, abstraction, inheritance, and polymorphism.
* **Orthodox Canonical Class Form (OCF):** Writing safe, reusable classes with default constructors, copy constructors, copy assignment operators, and destructors.
* **Resource Acquisition Is Initialization (RAII):** Automatic resource management and memory cleanup tied to object lifecycles.
* **Subtype & Ad-hoc Polymorphism:** Virtual functions, abstract base classes, pure virtual interfaces, and function/operator overloading.
* **Exception Handling:** Robust error management using `try`, `catch`, and custom `std::exception` classes.
* **Generic Programming:** Function templates, class templates, and template specialization.
* **Standard Template Library (STL):** Containers (`vector`, `deque`, `list`, `map`, `stack`), iterators, and algorithms.

---

## 🛠️ Tech Stack & Constraints

* **Language:** C++ (C++98 standard)
* **Compiler Flags:** `c++ -Wall -Wextra -Werror -std=c++98`
* **Build System:** Makefile per module (`all`, `clean`, `fclean`, `re`)
* **Forbidden Features:** C++11/14/17/20 features, external libraries (Boost, C-style memory allocations like `malloc`/`free` are strictly avoided in favor of `new`/`delete`).

---

## 🗺️ Modules Breakdown

| Module | Core Topic | Key Concepts Learned |
| :--- | :--- | :--- |
| **[module 00](#-cpp-00--namespaces-classes-member-functions-stdio)** | Basics & Syntax | Namespaces, classes, member functions, `std::cin`/`std::cout`, `const` specifiers, static members. |
| **[module 01](#-cpp-01--memory-allocation-pointers-to-members-references-switch)** | Memory & References | Dynamic allocation (`new`/`delete`), references vs pointers, pointers to members, file streams (`fstream`). |
| **[module 02](#-cpp-02--ad-hoc-polymorphism-operator-overloading-fixed-point)** | Operator Overloading | Fixed-point numbers, operator overloading (`+`, `-`, `=`, `<<`, etc.), Orthodox Canonical Form. |
| **[module 03](#-cpp-03--inheritance)** | Inheritance | Class inheritance (`public`/`protected`/`private`), virtual inheritance, base/derived constructor order. |
| **[module 04](#-cpp-04--subtype-polymorphism-abstract-classes-interfaces)** | Subtype Polymorphism | Virtual destructors, pure virtual functions, Abstract Base Classes (ABCs), Interfaces, deep copying. |
| **[module 05](#-cpp-05--repetition-and-exceptions)** | Exceptions | Custom exceptions (`std::exception`), nested classes, `try`/`catch` blocks, strict class invariants. |
| **[module 06](#-cpp-06--c-casts)** | Type Casting | C++ explicit casts: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`, serialization. |
| **[module 07](#-cpp-07--templates)** | Templates | Function templates, class templates, generic data structures, iterative template functions. |
| **[module 08](#-cpp-08--templated-containers-iterators-algorithms)** | STL Containers & Algorithms | Standard containers (`vector`, `list`, `deque`), iterators, sequence analysis algorithms (`std::find`, `std::sort`). |
| **[module 09](#-cpp-09--stl-real-world-applications)** | Advanced STL Applications | Complex container selection, expression evaluation (RPN), Bitcoin exchange parsing, PmergeMe algorithm. |

---

### 🔹 CPP 00 | Namespaces, Classes, Member Functions, Stdio
* **Focus:** Transition from C to C++, basic OOP concepts.
* **Exercises:**
  * `Megaphone`: Basic I/O streams and string manipulations (`std::cout`, `std::string`).
  * `Pony` / `PhoneBook`: Static array of object instances, dynamic member searches, `const` correctness.
  * `Account`: Static class attributes, log generation, static member functions.

### 🔹 CPP 01 | Memory Allocation, Pointers to Members, References
* **Focus:** Memory layout, stack vs heap allocation, dynamic lifetime management.
* **Exercises:**
  * `Zombie`: Heap (`new`) vs Stack allocation and lifetime scope.
  * `Moar Zombies!`: Arrays of objects dynamically allocated with `new[]` and freed with `delete[]`.
  * `HI THIS IS BRI`: References (`type&`) vs Pointers (`type*`).
  * `Sed is for losers`: File stream manipulation using `std::ifstream` and `std::ofstream`.

### 🔹 CPP 02 | Ad-hoc Polymorphism, Operator Overloading, Fixed-Point
* **Focus:** Canonical class structure and custom type representations.
* **Exercises:**
  * `Fixed`: Implementing a fixed-point number class using bitwise operations (`Orthodox Canonical Form`).
  * Operator Overloading: Overloading arithmetic (`+`, `-`, `*`, `/`), comparison (`>`, `<`, `==`), and increment/decrement (`++`, `--`) operators.

### 🔹 CPP 03 | Inheritance
* **Focus:** Object inheritance hierarchies and initialization order.
* **Exercises:**
  * `ClapTrap`: Base class setup with attributes, access specifiers (`protected` vs `private`).
  * `ScavTrap` / `FragTrap`: Derived classes overriding parent methods and using parent constructors.
  * `DiamondTrap`: Solving the "Diamond Problem" using `virtual` inheritance.

### 🔹 CPP 04 | Subtype Polymorphism, Abstract Classes, Interfaces
* **Focus:** Dynamic dispatch via virtual tables (vtable) and pure interfaces.
* **Exercises:**
  * `Animal` / `Dog` / `Cat`: Virtual functions and virtual destructors to avoid memory leaks during polymorphic deletion.
  * `Brain`: Deep copying vs shallow copying in classes containing dynamic pointer members.
  * `Character` / `AMateria`: Implementing pure abstract base classes (interfaces) in C++98.

### 🔹 CPP 05 | Repetition and Exceptions
* **Focus:** Graceful error handling using exceptions.
* **Exercises:**
  * `Bureaucrat`: Custom exception classes inheriting from `std::exception`.
  * `Form` / `AForm`: Exception throwing when invariants fail (e.g., grade too low/high).
  * `Intern`: Factory pattern using function pointers to construct objects dynamically.

### 🔹 CPP 06 | C++ Casts
* **Focus:** Type conversion mechanics in C++.
* **Exercises:**
  * `ScalarConverter`: String parsing and explicit casting across scalar types using `static_cast`.
  * `Serializer`: Pointer address reinterpretation using `reinterpret_cast` (`uintptr_t`).
  * `Identify`: Runtime type identification (RTTI) without `typeid` using `dynamic_cast`.

### 🔹 CPP 07 | Templates
* **Focus:** Generic programming in C++.
* **Exercises:**
  * `swap`, `min`, `max`: Generic function templates.
  * `iter`: Template function executing arbitrary functions across generic array types.
  * `Array`: Generic class template managing dynamically allocated arrays with bounds checking.

### 🔹 CPP 08 | Templated Containers, Iterators, Algorithms
* **Focus:** Using standard algorithms with STL containers.
* **Exercises:**
  * `easyfind`: Template search function working across any STL integer container.
  * `Span`: Store numbers and calculate shortest/longest spans using range-based iterator insertion.
  * `MutantStack`: Making `std::stack` iterable by exposing underlying container iterators.

### 🔹 CPP 09 | Advanced STL Applications
* **Focus:** Designing solutions using optimal STL containers based on algorithmic complexity.
* **Exercises:**
  * `Bitcoin Exchange`: Parsing CSV historical price data using `std::map` for efficient lookup and upper/lower bound search.
  * `Reverse Polish Notation (RPN)`: Mathematical expression evaluator built using `std::stack`.
  * `PmergeMe`: High-performance Ford-Johnson merge-insert sort algorithm implemented using two distinct containers (`std::vector` and `std::deque`) to benchmark performance differences.

---

## 🎯 Hard Skills

* **Deep Memory Management:** Zero-leak memory management validated with Valgrind under continuous allocation and dynamic dispatch.
* **Canonical Code Design:** Writing bulletproof classes according to the Orthodox Canonical Class Form.
* **Algorithmic Selection:** Selecting appropriate STL containers (`map`, `vector`, `deque`, `stack`) based on $O(1)$, $O(\log n)$, or $O(n)$ access/insertion needs.
* **Explicit Casting Mastery:** Eliminating dangerous C-style implicit casts in favor of controlled C++ casts.

---

## 🤝 Soft Skills

* **Language Precision:** Adapting to legacy/strict standards (C++98) without relying on modern syntax conveniences (`auto`, lambda functions, smart pointers).
* **Rigor & Invariant Design:** Enforcing class contracts and invariants using strong typing, `const` qualifiers, and custom exceptions.
* **Code Modularization:** Organising header/source file layouts clean of namespace pollution (`using namespace std` is strictly avoided in header files).

---

## 📁 Repository Structure

```text
.
├── module00/  # Basics, Namespaces, Classes, Stdio
├── module01/  # Memory allocation, References, Pointers to members
├── module02/  # Fixed-point, Operator overloading, Canonical form
├── module03/  # Inheritance & Diamond Problem
├── module04/  # Subtype polymorphism, Interfaces, Abstract classes
├── module05/  # Exceptions & Factory pattern
├── module06/  # C++ Type Casting (static, dynamic, reinterpret)
├── module07/  # Function & Class Templates
├── module08/  # STL Containers, Iterators, Algorithms
└── module09/  # Real-world STL (Map, Stack, Vector/Deque sorting)
