//Title: War.cpp
//Author: Humza Faraz
//Date: 4/13/18
//Section: 32
//E-mail: hfaraz1@umbc.edu

#include "Warhorse.h"
#include "Heavy.h"
#include <ctime>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Heavy::Heavy(){

}

// Overloaded Constructor
// Preconditions: Valid inputs (name, align, size, health, speed)
// Postconditions: None
Heavy::Heavy(string name, Size size, int health, int speed)
  :Warhorse(name, size, health, speed){

}

// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + training level (0-5)
// Also, displays actual attack
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Heavy::attack(string name, int health){
  Training train = getTraining();
  int damage = health/ATTACK_DIVISOR + (int)train + kick();
  cout << "The " << toString() << " Warhorse " << getName() << " hits " << name << endl;
  cout << "The heavy horse spins and kicks the enemy." << endl;
  
  return damage;
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Light")
string Heavy::toString(){
  return HEAVY_WEIGHT;
}

// kick() - a special attack by heavy warhorses
// Preconditions: all variables are set valid
// Postconditions: returns an int between 1 and 3 of additional damage
int Heavy::kick(){
  int additional = rand() % 3 + 1;
  return additional;
}