#include "../include/diffie_hellman.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

DiffieHellman::DiffieHellman(long long p, long long g) : P(p), G(g) {
    // Seed the random number generator
    std::srand(std::time(0));
}

long long DiffieHellman::power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

void DiffieHellman::generateKeys() {
    // Generate a private key (random number)
    // In real world, this would be much larger
    privateKey = std::rand() % 100 + 1; 
    
    // Calculate Public Key: G^privateKey mod P
    publicKey = power(G, privateKey, P);
}

long long DiffieHellman::computeSecret(long long otherPublicKey) {
    // Calculate Secret: otherPublicKey^OurPrivateKey mod P
    return power(otherPublicKey, privateKey, P);
}