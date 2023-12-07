#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find prime numbers within a range (non-threaded)
std::vector<int> findPrimesNonThreaded(int start, int end) {
    std::vector<int> primes;
    for (int num = start; num < end; ++num) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

// Function to find prime numbers within a range (threaded)
void findPrimes(int start, int end, std::vector<int>* primes, std::mutex* mtx) {
    for (int num = start; num < end; ++num) {
        if (isPrime(num)) {
            std::lock_guard<std::mutex> lock(*mtx);
            primes->push_back(num);
        }
    }
}

// Function to generate prime numbers using multithreading
std::vector<int> generatePrimesConcurrently(int numThreads, int maxNum) {
    std::vector<std::thread> threads;
    std::vector<int> primes;
    std::mutex mtx;

    int step = maxNum / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = i * step;
        int end = (i < numThreads - 1) ? start + step : maxNum;
        threads.emplace_back(findPrimes, start, end, &primes, &mtx);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return primes;
}

int main() {
    int numThreads = 4;
    int maxNumberToCheck = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> resultThreaded = generatePrimesConcurrently(numThreads, maxNumberToCheck);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedThreaded = end - start;

    std::cout << "Time taken with threading: " << elapsedThreaded.count() << " seconds" << std::endl;
    std::cout << "Number of primes: " << resultThreaded.size() << std::endl;


    start = std::chrono::high_resolution_clock::now();
    std::vector<int> resultNonThreaded = findPrimesNonThreaded(0, maxNumberToCheck);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedNonThreaded = end - start;
    
    std::cout << "Time taken without threading: " << elapsedNonThreaded.count() << " seconds" << std::endl;
    std::cout << "Number of primes: " << resultNonThreaded.size() << std::endl;

    return 0;
}