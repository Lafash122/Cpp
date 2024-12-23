#ifndef UNIVERSE
#define UNIVERSE

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>

struct UniverseParams {
	int size;
	std::string name;
	std::vector<char> rule_birth;
	std::vector<char> rule_surve;
	std::vector<std::vector<bool>> field;
};

class Universe {
private:
	UniverseParams params;

public:
	Universe(UniverseParams prms);
	char cnt_neigh(int x, int y);
	void update_field(std::vector<std::vector<bool>> f);
	void show_info();
	void show_universe();

	int get_size();
	const std::string& get_name() const;
	const std::vector<char>& get_rb() const;
	const std::vector<char>& get_rs() const;
	const std::vector<std::vector<bool>>& get_field() const;
};

class UniverseHandler {
private:
	std::string filename;
	std::ifstream in;
	bool check_label();
	std::vector<std::vector<bool>> read_cells(int size);

public:
	UniverseHandler(std::string fname);
	UniverseParams handle();
};


#endif //UNIVERSE