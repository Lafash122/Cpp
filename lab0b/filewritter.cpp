#include "filewritter.h"

FileWritter::FileWritter(std::string name) {
	out.open(name);
}

void FileWritter::write(const std::map<std::string, int>& frequency, int wrds_num) {
	if (!out.is_open())
		std::cerr << "The file could not be opened" << std::endl;

	std::list<std::pair<std::string, int>> sorted_frequency(frequency.begin(), frequency.end());

	sorted_frequency.sort([](const auto& prev, const auto& next) {
		if (prev.second != next.second)
			return prev.second > next.second;
		return prev.first < next.first;
		});

	for (auto& i : sorted_frequency) {
		double statistic = double (i.second) / wrds_num;
		out << i.first << ";" << i.second << ";" << statistic << std::endl;
	}

	out.close();
}