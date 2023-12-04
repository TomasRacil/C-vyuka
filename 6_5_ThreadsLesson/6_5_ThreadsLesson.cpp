// 6_5_ThreadsLesson.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

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

std::vector<int> findPrimesNonThreaded(int start, int end) {
    std::vector<int> primes;
    for (int num = start; num < end; ++num) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

void findPrimesThreaded(int start, int end, std::vector<int>* primes, std::mutex* mtx) {
    for (int num = start; num < end; ++num) {
        if (isPrime(num)) {
            mtx->lock();
            primes->push_back(num);
            mtx->unlock();
        }
    }
}

std::vector<int> generatePrimesConcurrently(int numThreads, int maxNum) {
    std::vector<std::thread> threads;
    std::vector<int> primes;
    std::mutex mtx;

    int step = maxNum / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = i * step;
        int end = (i < numThreads - 1) ? start + step : maxNum;
        threads.emplace_back(findPrimesThreaded, start, end, &primes, &mtx);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return primes;
}

int main()
{
    int maxNumberToCheck = 1000000;
    int repetitions = 100;
    int threads = 4;
    std::vector<int> resultNonThreaded;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < repetitions; i++)
    {
        resultNonThreaded  = findPrimesNonThreaded(0, maxNumberToCheck);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedNonThreaded = (end - start)/repetitions;

    std::cout << "Time taken without threading: " << elapsedNonThreaded.count() << " seconds" << std::endl;
    std::cout << "Number of primes: " << resultNonThreaded.size() << std::endl;

    std::vector<int> resultThreaded;
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < repetitions; i++)
    {
        resultThreaded = generatePrimesConcurrently(threads, maxNumberToCheck);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedThreaded = (end - start) / repetitions;

    std::cout << "Time taken with threading: " << elapsedThreaded.count() << " seconds" << std::endl;
    std::cout << "Number of primes: " << resultThreaded.size() << std::endl;
}