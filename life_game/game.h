#ifndef GAME
#define GAME

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "universe.h"

class Game {
private:
	Universe universe;

public:
	Game(UniverseParams params);
	void dump(std::string name);
	void cnt_tick();
	void tick(int n);
	void get_help();
	void show_status();
};


#endif //GAME
