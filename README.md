# 🔐 Diffie-Hellman Key Exchange (C++)

### A simple simulation of secure key sharing

This project is a modular implementation of the **Diffie-Hellman Key Exchange protocol** written in C++.  
It simulates how two parties ("Alice" and "Bob") can establish a shared secret over an insecure public channel **without ever revealing their private keys**.

I built this project to move beyond cryptography theory and gain hands-on understanding of the low-level mathematics that secure modern internet communications.

---

## 🚀 What this project includes

This is not just a single file program — it is structured like a real C++ project.

- **Clean code structure**  
  Header files (`.h`) and source files (`.cpp`) are separated, similar to how C++ projects are written in practice.

- **Manual math implementation**  
  Modular exponentiation (`(base^power) % mod`) is implemented from scratch to handle large values efficiently.

- **Cross-platform build support**  
  A `CMakeLists.txt` file is included so the project can be built on Windows, Linux, or macOS.

---

## 📂 Project Structure

```text
Diffie-Hellman-Cpp/
├── include/
│   └── diffie_hellman.h      // Class definition
├── src/
│   ├── diffie_hellman.cpp    // Core logic
│   └── main.cpp              // Program entry point
└── CMakeLists.txt            // Build configuration

```

## 💻 How to Run

You can compile and run this project using either **G++** or **CMake**.

### Option 1: Quick Run (G++)

```bash
cd src
g++ main.cpp diffie_hellman.cpp -o app
./app
```

### Option 2: Professional Build (CMake)

```bash
mkdir build
cd build
cmake ..
cmake --build .
./Debug/DiffieKeyExchange.exe
```

## 🧪 Sample Output

Below is an example output showing a successful Diffie-Hellman key exchange between two users:

> **Note:** The exact values shown below may be different every time you run the program.  
> This is expected behavior and part of how the Diffie-Hellman algorithm works.


```text
=== Diffie-Hellman Key Exchange Simulation ===

Enter a Prime Number (P): 1153
Enter a Primitive Root (G): 18

[Public Data]
Alice's Public Key: 956
Bob's Public Key:   170

[Private Secrets]
Alice's Calculated Secret: 1086
Bob's Calculated Secret:   1086

[SUCCESS] Secure connection established! Shared secret is 1086
```
## 🧠 The Math Behind the Code

The security of this implementation relies on the **Discrete Logarithm Problem**. In simple terms: it is very easy to mix paint (calculate the public key), but computationally impossible to un-mix it to find the original colors (reverse-engineer the private key).



#### 1. The Setup (Public Parameters)
Alice and Bob agree on two numbers that anyone can see:
* **`P` (Modulus):** A very large prime number.
* **`G` (Base):** A primitive root modulo `P` (a number that generates all possible values when powered).

#### 2. The Private Secrets
* **Alice** generates a random private integer: `a`
* **Bob** generates a random private integer: `b`

#### 3. The Exchange (One-Way Function)
They calculate their Public Keys using the formula: `Public = G^Private mod P`.
* **Alice sends `A`:** `A = G^a mod P`
* **Bob sends `B`:** `B = G^b mod P`

> **Note:** Even if an attacker knows `G`, `P`, and the intercepted value `A`, they cannot easily calculate `a` because of the difficulty of reversing the modulo operation.

#### 4. The Final Secret (The Magic)
Now, they combine their private key with the *other person's* public key.
* **Alice computes:** `S = B^a mod P`
* **Bob computes:** `S = A^b mod P`

#### Why they match:
Mathematically, both users are calculating the exact same number, even though they used different inputs:

`S = (G^b)^a mod P` is equal to `(G^a)^b mod P`

Therefore: **`S = G^ab mod P`**

---

## 👤 Author

**Rudra Sanandiya**