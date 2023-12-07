// 6_6_ThreadsAOC202215.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <regex>
#include <unordered_set>


//template<typename T>
//void print_2d(std::list<T> l) {
//	for (auto line : l) {
//		std::cout << line;
//	}
//}

class Beacon {
public:
	int x;
	int y;
	Beacon() {}

	Beacon(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend std::ostream& operator<<(std::ostream& out, Beacon& obj)
	{
		out << "x: " << obj.x << ",y: " << obj.y;
		return out;
	}
};

class Sensor {
public:
	int x;
	int y;
	Beacon nearest_beacon;
	int manhattan_range;
	Sensor(std::vector<int> data) {
		this->x = data[0];
		this->y = data[1];
		this->nearest_beacon = Beacon(data[2], data[3]);
		this->manhattan_range = std::abs(this->x - this->nearest_beacon.x) + std::abs(this->y - this->nearest_beacon.y);
	}
	friend std::ostream& operator<<(std::ostream& out, Sensor& obj)
	{
		out << "x: " << obj.x << ",y: " << obj.y << ", range: " << obj.manhattan_range << ", beacon: " << obj.nearest_beacon;
		return out;
	}
};
struct Range {
	int min;
	int max;
	Range(int min, int max) {
		this->min = min;
		this->max = max;
	}
	bool operator<(const Range& obj)
	{
		if (this->min < obj.min) {
			return true;
		}
		else if(this->min==obj.min and this->max<obj.max)
		{
			return true;
		}
		return false;
	}
};

int find_not_possible(std::list<Sensor> sensors, int y, int limit = 0) {
	std::unordered_set<int> not_possible;
	for (auto sensor : sensors) {
		int temp = sensor.manhattan_range - std::abs(sensor.y - y);
		if (temp >= 0) {
			int max = (limit != 0 && sensor.x + temp>limit) ? limit : sensor.x + temp;
			for (int min = sensor.x - temp; min < max; min++)
			{
				not_possible.insert(min);
			}
		}
	}
	return not_possible.size();

	/*std::vector<Range> ranges;
	for (auto sensor : sensors) {
		int temp = sensor.manhattan_range - std::abs(sensor.y - y);
		if (temp >= 0) {
			int max = (limit != 0 && sensor.x + temp > limit) ? limit : sensor.x + temp;
			int min = sensor.x - temp;
			ranges.push_back(Range(min, max));
		}
	}
	std::sort(ranges.begin(), ranges.end());
	int min_val = ranges[0].min;
	int max_val = ranges[0].max;
	for (auto range : ranges) {
		if (range.min < min_val && range.max >= min_val) min_val = range.min;
		if (range.max > max_val and range.min < max_val) max_val = range.max;
	}
	if (max_val <= limit or min_val >= 0) std::cout << y <<", " << min_val << ", " << max_val << std::endl;
	return 0;*/
}


int main()
{
	std::ifstream file("input.txt"); // Replace "example.txt" with your file name
	std::list<Sensor> sensorList;

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::regex numberPattern(R"(-?\d+)");
			std::sregex_iterator it(line.begin(), line.end(), numberPattern);
			std::sregex_iterator end;
			std::vector<int> numbers;

			while (it != end) {
				numbers.push_back(std::stoi(it->str()));
				++it;
			}
			sensorList.push_back(Sensor(numbers));
		}
		file.close(); // Close the file after reading

		/*for (auto s : sensorList) {
			std::cout << s << std::endl;
		}*/

		//std::cout << find_not_possible(sensorList, 10) << std::endl;
		std::cout << find_not_possible(sensorList, 2000000) << std::endl;

		/*for (int radek = 0; radek < 4000000; radek++)
		{
			if (find_not_possible(sensorList, radek, 4000000) == 1) {
				std::cout << radek << std::endl;
			}
		}*/

		//solve concurently
		/*std::vector<std::thread> threads;
		std::vector<int> primes;
		std::mutex mtx;

		int step = numThreads;
		for (int i = 0; i < numThreads; ++i) {
			int start = i;
			threads.emplace_back(findPrimesThreaded, start, maxNum, step, &primes, &mtx);
		}

		for (auto& thread : threads) {
			thread.join();
		}*/


	}
	else {
		std::cout << "Unable to open the file." << std::endl;
	}

}