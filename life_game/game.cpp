#include "game.h"

Game::Game(UniverseParams params) : universe(params) {}

void Game::dump(std::string name) {
	std::ofstream out(name);
	if (!out.is_open())
		throw std::runtime_error("File could not be opened");

	out << "#Life 1.06\n";
	out << "#N " << universe.get_name() << "\n";
	out << "#R B";
	for (const auto& i : universe.get_rb())
		out << (char)(i + '0');
	out << "/S";

	for (const auto& i : universe.get_rs())
		out << (char)(i + '0');
	out << "\n#S " << universe.get_size() << "\n";

	std::vector<std::vector<bool>> field = universe.get_field();
	for (int i = 0; i < field.size(); ++i)
		for (int j = 0; j < field.size(); ++j)
			if (field[i][j])
				out << i << " " << j << "\n";

	out.close();
}

void Game::cnt_tick() {
	std::vector<std::vector<bool>> nfield;
	int size = universe.get_size();
	for (int i = 0; i < size; ++i) {
		std::vector<bool> row(size, false);
		nfield.push_back(row);
	}
	
	std::vector<char> rb = universe.get_rb();
	std::vector<char> rs = universe.get_rs();
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			int neigh = universe.cnt_neigh(i, j);
			if (!universe.get_field()[i][j] && (find(rb.begin(), rb.end(), neigh) != rb.end()))
				nfield[i][j] = true;
			else if (universe.get_field()[i][j] && (find(rs.begin(), rs.end(), neigh) != rs.end()))
				nfield[i][j] = true;
		}

	universe.update_field(nfield);
}

void Game::tick(int n) {
	for (int i = 0; i < n; ++i)
		cnt_tick();

	std::cout << "Iteration: " << n << "\n";
	universe.show_universe();
}

void Game::get_help() {
	std::cout << "In process you can use next commands:\n"
		"dump <file> - game will be saved in output file\n"
		"tick <n=1> (t <n=1>) - count <n> iterarions (default 1)\n"
		"exit - end game\n";
}

void Game::show_status() {
	universe.show_info();
	universe.show_universe();
}