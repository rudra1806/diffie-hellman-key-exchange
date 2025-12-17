#ifndef DIFFIE_HELLMAN_H
#define DIFFIE_HELLMAN_H

class DiffieHellman {
private:
    long long P; // Prime number
    long long G; // Primitive Root (Generator)
    long long privateKey;
    
    // Helper for Modular Exponentiation: (base^exp) % mod
    long long power(long long base, long long exp, long long mod);

public:
    long long publicKey;

    // Constructor initiates P and G
    DiffieHellman(long long p, long long g);
    
    // Generates Private and Public keys
    void generateKeys();
    
    // Calculates the Shared Secret using the other person's Public Key
    long long computeSecret(long long otherPublicKey);
};

#endif