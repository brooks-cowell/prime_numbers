/*
Brooks D Cowell
Computer Scienec Fall 2024
Due: November 20 2024
Coding Challenge Prime Number Finder
*/

#include <chrono>
#include <iostream>
#include <cmath> // For sqrt

bool isPrime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime
    }
    if (num == 2) {
        return true; // 2 is prime
    }
    if (num % 2 == 0) {
        return false; // Exclude all even numbers
    }
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false; // Divisible by another number, not prime
        }
    }
    return true;
}

int main() {
    auto start = std::chrono::system_clock::now();

    // Check all numbers from 0 to 1,000,000 for primality
    int primeCount = 0;
    for (int i = 0; i <= 1000000; i++) {
        if (isPrime(i)) {
            primeCount++;
            // Uncomment the next line if you want to print prime numbers
            //std::cout << i; //<< " is a prime number.\n";
        }
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsed = end - start;

    std::cout << "Found " << primeCount << " prime numbers." << std::endl;
    std::cout << "Time to complete task: " << elapsed.count() << " seconds." << std::endl;

    
}


