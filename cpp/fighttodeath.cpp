#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <math.h>

class Warrior{
private:
	int attack;
	int block;

public:
	std::string name;
	int health;

	// Methods
	int Attack(){
		return std::rand() % this -> attack;
	}

	int Block(){
		return std::rand() % this -> block;
	}

	// Constructor
	Warrior(std::string name, int health, int attack, int block){
		this->name = name; 
		this->health = health;
		this->attack = attack;
		this->block = block;
	}

	// Default Constructor
	Warrior(){
		this->name = "None"; 
		this->health = 0;
		this->attack = 0;
		this->block = 0;
	}

	// Deconstructor
	~Warrior(){};

};

class Battle{
public:
	// Methods
	static void StartFight(Warrior &player1, Warrior &player2){
		while(true){
			if(Battle::GetAttackResult(player1, player2).compare("Game Over") == 0){
				std::cout << "Game Over\n";
				break;
			}
			if(Battle::GetAttackResult(player2, player1).compare("Game Over") == 0){
				std::cout << "Game Over\n";
				break;
			}
		}
	}

	static std::string GetAttackResult(Warrior &player1, Warrior &player2){
		int warriorAattack = player1.Attack();
		int warriorBblock = player2.Block();

		int damagetoWarriorB = ceil(warriorAattack - warriorBblock);
		damagetoWarriorB = (damagetoWarriorB <= 0) ? 0 : damagetoWarriorB;

		player2.health = player2.health - damagetoWarriorB;

		printf("%s attacks %s and deals %d damage\n", player1.name.c_str(), player2.name.c_str(), damagetoWarriorB);
		printf("%s is down to %d health\n", player2.name.c_str(), player2.health);

		if(player2.health <= 0){
			printf("%s has died %s is the winner\n", player2.name.c_str(), player1.name.c_str());
			return "Game Over";
		} else {
			return "Fight Again";
		}
	}
};

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Warrior thor("Thor", 100, 30, 15);
	Warrior hulk("Hulk", 135, 25, 10);

	Battle::StartFight(thor,hulk);


	return 0;
}
