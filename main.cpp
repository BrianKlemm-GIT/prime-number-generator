#include <iostream>
#include <vector>
#include <fstream>

bool isPrime(int n) {
    if (n <= 1)
        return false; // 0 and 1 are not prime numbers
    if (n == 2)
        return true; // 2 is the only even prime number
    if (n % 2 == 0)
        return false; // all other even numbers are not prime

    // Check odd numbers up to the square root of n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {

    std::cout << "Enter how many primes you would like me to list." << std::endl;
    int primes_requested;
    std::cin >> primes_requested;

    std::vector<int> primesFound;
    std::ifstream file_in("primes.dat", std::ios::in);
    int prime;

    // Read primes from file
    while (file_in >> prime) {
        primesFound.push_back(prime);
    }

    file_in.close();

    int i = primesFound.empty() ? 2 : primesFound.back() + 1;
    while (primesFound.size() < primes_requested) {
        if(isPrime(i)) {
            primesFound.push_back(i);
        }
        i++;
    }

    // Save primes to file
    std::ofstream file_out("primes.dat", std::ios::out | std::ios::trunc);
    for(int prime : primesFound) {
        file_out << prime << std::endl;
    }

    file_out.close();

    for(int i = 0; i < primes_requested; i++){
        std::cout << primesFound[i] << ", ";
    }

    return 0;
}
