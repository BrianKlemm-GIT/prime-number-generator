# Prime Number Generator
This is a C++ prime number generator. It generates prime numbers by user specified count. It then saves the found 
prime numbers to a .dat file. If a user later request a lesser number of prime numbers the program will provide them 
from the file instead of calculating them again. The program never calculates a prime twice.


isPrime(int n) determines if a number is prime. 

## Progam Starts:
- Current number of saved primes are announced in the console
- The user is prompted for how many primes they want listed
- If no primes.dat exists in the program directory a primes.dat file is created
- Requested number of primes is compared to the saved number of primes in primes.dat

## User request less than the number of stored primes
- If the requested is less than or equal to the number of primes saved in primes.dat the primes requested are read from
primes.dat and no new calculations are preformed.
- Program then closes

## User request more than the number of stored primes
- Only the additional requested primes are calculated
- The obvious cases of negative numbers, 0, 1, and all even numbers greater than 2 are eliminated.
- Modulo the test case with all odd numbers upto the square root of the test case until a 0
remainder is found or the square root of the test case is exceeded. 
- true is returned if the number is prime and false is returned if the number is not prime
- If true is returned the test case is added to the vector primesFound 
- In both cases of a true or false return, the function continues to the next test case until the primesFound vector
contains the requested number of primes.
- Once the primesFound contains the number of user requested primes the vector primesFound is saved to the primes.dat 
file.