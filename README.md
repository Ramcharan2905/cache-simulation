# Set-Associative Cache Simulator in C++

This repository contains a **C++ implementation of a Set-Associative Cache Simulator**. The program models the behavior of a cache memory system, handling memory access requests (reads and writes) and simulating cache hits and misses.

It demonstrates core computer architecture concepts, including cache organization, address translation (tag, index, offset), and various cache write policies.

---

## 📘 Overview

This project provides a low-level simulation of how a modern CPU cache operates. It is designed to be a command-line application that takes configurable cache parameters (size, block size, associativity) and simulates a series of random memory accesses.

The simulator implements specific cache policies, such as **Write-Through** with **No-Write-Allocate** for write operations and a **Random Replacement** policy for evicting blocks on a cache miss.

---

## 🧠 Problem Statement

The goal is to simulate the interaction between a CPU and a set-associative cache. For a given memory address and operation type (read/write), the program must:

1.  Decompose the address into its **Tag**, **Index**, and **Offset** bits.
2.  Check the corresponding cache set for a **hit** or a **miss**.
3.  Simulate the appropriate action based on the cache policy (e.g., fetch from memory, write-through).
4.  Track cache statistics and calculate the final **hit rate**.

---

## ⚙️ Tech Stack

-   **C++**: The core language for the simulation.
-   **Standard Template Library (STL)**: For data structures like `vector` and `pair`.
-   **Compiler**: A standard C++ compiler like **g++** or **Clang**.
-   **Operating System**: Linux, macOS, or Windows.

---

## 🚀 Features

-   **Configurable Cache Geometry**: Easily change cache size, block size, and associativity in the `main` function.
-   **Set-Associative Mapping**: Implements a generic N-way set-associative cache structure.
-   **Address Decomposition**: Correctly calculates tag, index, and offset from a physical address.
-   **Cache Policies Implemented**:
    -   **Write Policy**: Write-Through (data is written to both cache and main memory on a write hit).
    -   **Replacement Policy**: Random Replacement (a random block in a set is chosen for eviction).
-   **Performance Metrics**: Calculates and displays the final cache hit rate after the simulation.

---

## ▶️ How to Run

1.  **Clone the repository**
    ```bash
    git clone https://github.com/Ramcharan2905/cache-simulation/
    cd cache-simulator-cpp
    ```

2.  **Compile the code**
    You will need a C++ compiler. Use the following command with g++:
    ```bash
    g++ -o cache_simulator cache_simulator.cpp -std=c++11
    ```

3.  **Run the executable**
    ```bash
    ./cache_simulator
    ```
    The program will simulate 100 memory accesses with the defined cache parameters and print the results to the console.

---

## 📊 Results

-   **Model**: Set-Associative Cache
-   **Language**: C++
-   **Task**: Simulation of memory access patterns.

The output will show a step-by-step log of each memory access, indicating whether it was a "Cache hit" or "Cache miss," and detailing the action taken. The simulation concludes by printing the final **Cache Hit Rate**.

---

## 📈 Learning Purpose

This project is designed to help students and developers understand:
-   The internal workings of cache memory.
-   The logic behind address mapping in set-associative caches.
-   The impact of different cache policies on performance.
-   Low-level system simulation using C++.

  ---

## 🤝 Contribution

Contributions are welcome and appreciated.

If you would like to contribute:

1. Fork the repository  
2. Create a new branch (`feature/your-feature-name`)  
3. Make your changes  
4. Commit your changes with clear messages  
5. Push to your fork  
6. Open a Pull Request  

For major changes, please open an issue first to discuss what you would like to improve or add.

---

## 📝 Code Guidelines

- Follow clean and readable code practices  
- Use meaningful variable and function names  
- Keep functions modular and concise  
- Add comments where necessary  
- Ensure your code does not break existing functionality  

---

## 🐛 Reporting Issues

If you find a bug or have a feature request:
- Open an issue  
- Clearly describe the problem  
- Provide steps to reproduce (if applicable)  
- Attach screenshots/logs if helpful  

---

## 📜 License

This project is open source.

---

## ⭐ Support

If you find this project helpful:
- Star the repository  
- Share it with others  
- Contribute to improve it  

---

## 🙌 Acknowledgements

Thanks to all contributors and the open-source community for their support and inspiration.
