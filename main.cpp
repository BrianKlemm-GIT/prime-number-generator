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

    std::vector<int> primesFound;
    std::ifstream file_in("primes.dat", std::ios::in);
    if (!file_in) {
        std::cerr << "Error opening file for reading\n";
        return 1;
    }

    int prime;
    while (file_in >> prime) {
        primesFound.push_back(prime);
    }
    file_in.close();

    // Tell user how many primes are already saved
    std::cout << "There are " << primesFound.size() << " primes already saved." << std::endl;

    std::cout << "Enter how many primes you would like me to list." << std::endl;
    int primes_requested;
    std::cin >> primes_requested;

    int i = primesFound.empty() ? 2 : primesFound.back() + 1;
    while (primesFound.size() < primes_requested) {
        if(isPrime(i)) {
            primesFound.push_back(i);
        }
        i++;
    }

    // Save primes to file
    std::ofstream file_out("primes.dat", std::ios::out | std::ios::trunc);
    if (!file_out) {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }
    for(int prime : primesFound) {
        file_out << prime << std::endl;
    }
    file_out.flush(); // flush the buffer to make sure all data is written to the file
    if (!file_out) {
        std::cerr << "Error writing to file\n";
        return 1;
    }
    file_out.close();

    for(int i = 0; i < primes_requested; i++){
        std::cout << primesFound[i] << ", ";
    }

    return 0;
}
