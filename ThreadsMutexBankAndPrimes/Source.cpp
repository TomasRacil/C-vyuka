#pragma warning(disable : 4996)

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

int GetRandom(int max) {
    srand(time(NULL));
    return rand() % max;
}

std::string GetTime() {
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime =
        std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}

double acctBalance = 100;

// Protects shared data from being accessed at the
// same time
std::mutex acctLock;

void GetMoney(int id,
    double withdrawal) {

    // The exception safe way to protect access
    // to code within its scope. The lock is released 
    // after execution leaves this scope
    std::lock_guard<std::mutex> lock(acctLock);

    // Blocks access between lock and unlock
    // until execution completes
    // This isn't good to use however if an error 
    // occurs between lock and unlock
    // acctLock.lock();

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << id <<
        " tries to withdrawal $" <<
        withdrawal << " on " <<
        GetTime() << "\n";

    if ((acctBalance - withdrawal) >= 0) {
        acctBalance -= withdrawal;
        std::cout << "New Account Balance is $" <<
            acctBalance << "\n";
    }
    else {
        std::cout << "Not Enough Money in Account\n";
        std::cout << "Current Balance is $" <<
            acctBalance << "\n";
    }
    // acctLock.unlock();
}

int main1()
{
    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(GetMoney, i, 15);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }



    return 0;
}


void FindPrimes(unsigned int start,
    unsigned int end,
    std::vector<unsigned int>& vect) {

    // Cycle through numbers while ignoring evens
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            }
            else if ((y + 1) == x) {
                vect.push_back(x);
            }
        }
    }
}

int main2()
{
    std::vector<unsigned int> primeVect;

    // Get time before code starts executing
    int startTime = clock();

    FindPrimes(1, 100000, primeVect);
    for (auto i : primeVect)
        std::cout << i << "\n";

    // Get time after execution
    int endTime = clock();

    // Print out the number of seconds by taking the difference
    // and dividing by the clock ticks per second
    std::cout << "Execution Time : " <<
        (endTime - startTime) / double(CLOCKS_PER_SEC)
        << std::endl;

    return 0;
}


// Used to protect writing to the vector
std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes2(unsigned int start,
    unsigned int end) {

    // Cycle through numbers while ignoring evens
    for (unsigned int x = start; x <= end; x += 2) {

        // If a modulus is 0 we know it isn't prime
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            }
            else if ((y + 1) == x) {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start,
    unsigned int end,
    unsigned int numThreads) {

    std::vector<std::thread> threadVect;

    // Divide up the calculation so each thread
    // operates on different primes
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    // Create prime list for each thread
    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes2,start, newEnd);

        start += threadSpread;
        newEnd += threadSpread;
    }

    for (auto& t : threadVect) {
        t.join();
    }

}

int main()
{
    // Get time before code starts executing
    int startTime = clock();

    FindPrimesWithThreads(1, 100000, 3);

    // Get time after execution
    int endTime = clock();

    for (auto i : primeVect)
        std::cout << i << "\n";

    // Print out the number of seconds
    std::cout << "Execution Time : " <<
        (endTime - startTime) / double(CLOCKS_PER_SEC)
        << std::endl;

    return 0;
}
