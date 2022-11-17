// async example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <Windows.h>

// a non-optimized way of checking for prime numbers:
bool is_prime(long int x) {
	std::cout << "Calculating. Please, wait...\n";
	Sleep(3000);
	for (long int i = 2; i < x; ++i) if (x % i == 0) return false;
	return true;
	
}

int main()
{
	// call is_prime(313222313) asynchronously:
	std::future<bool> fut = std::async(is_prime, 3132223131232132313);

	std::cout << "Checking whether 313222313 is prime.\n";
	// ...
	int i = 1;

	while (!(fut.wait_for(std::chrono::seconds(1))== std::future_status::ready)) {
		std::cout<< "Cekam: " << i++ << " sekund"<< std::endl;
	}

	bool ret = fut.get();      // waits for is_prime to return

	bool stopped = false;

	

	if (ret) std::cout << "It is prime!\n";
	else std::cout << "It is not prime.\n";

	return 0;
}