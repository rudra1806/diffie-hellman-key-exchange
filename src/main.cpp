#include <iostream>
#include "../include/diffie_hellman.h"

int main() {
    long long P, G;

    std::cout << "=== Diffie-Hellman Key Exchange Simulation ===\n\n";
    
    // Step 1: Agree on Public Parameters
    std::cout << "Enter a Prime Number (P): ";
    std::cin >> P;
    std::cout << "Enter a Primitive Root (G): ";
    std::cin >> G;

    // Step 2: Create Alice and Bob
    DiffieHellman alice(P, G);
    DiffieHellman bob(P, G);

    // Step 3: Generate Keys
    alice.generateKeys();
    bob.generateKeys();

    std::cout << "\n[Public Data]\n";
    std::cout << "Alice's Public Key: " << alice.publicKey << "\n";
    std::cout << "Bob's Public Key:   " << bob.publicKey << "\n";

    // Step 4: Exchange Keys and Compute Secret
    // Alice takes Bob's public key, Bob takes Alice's public key
    long long aliceSecret = alice.computeSecret(bob.publicKey);
    long long bobSecret = bob.computeSecret(alice.publicKey);

    std::cout << "\n[Private Secrets]\n";
    std::cout << "Alice's Calculated Secret: " << aliceSecret << "\n";
    std::cout << "Bob's Calculated Secret:   " << bobSecret << "\n";

    // Validation
    if (aliceSecret == bobSecret) {
        std::cout << "\n[SUCCESS] Secure connection established! Shared secret is " << aliceSecret << "\n";
    } else {
        std::cout << "\n[ERROR] Secrets do not match.\n";
    }

    return 0;
}