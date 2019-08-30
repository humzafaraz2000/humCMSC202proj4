//Title: War.cpp
//Author: Humza Faraz
//Date: 4/13/18
//Section: 32
//E-mail: hfaraz1@umbc.edu

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Untrained.h"
#include "Horse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

using namespace std;


// Default Constructor
// Preconditions: None
// Postconditions: None
Untrained::Untrained(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Untrained::Untrained(string name, Size size, int health, int speed)
  :Horse(name, size, health, speed){

}

// specialize() - if an horse successfully produces specializes it is replaced
//           by a corresponding warhorse
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new warhorse or NULL
Horse* Untrained::specialize(){
  string name = getName();
  Size size = getSize();
  int health = getHealth();
  int speed = getSpeed();
  if (size == SMALL){
    Horse* newLight = new Light(name, size, health, speed);
    cout << "You have created a new Light warhorse" << endl;
    return newLight;
  }
  else if (size == MEDIUM){
    Horse* newMedium = new Medium(name, size, health, speed);
    cout << "You have created a new Medium warhorse" << endl;
    return newMedium;
  }
  else{
    Horse* newHeavy = new Heavy(name, size, health, speed);
    cout << "You have created a new Heavy warhorse" << endl;
    return newHeavy;
  }
  
}

// train() : attempts to train an untrained horse
// Preconditions: all variables are set valid
// Postconditions: says that horses cannot be trained
bool Untrained::train(){
  cout << "Horses cannot be trainded." << endl;
  return false;
}

// toString() - a string representation of the untrained horse
// Preconditions: all variables are set valid
// Postconditions: returns an string describing the horse
string Untrained::toString(){
  return "Unknown";
}

// attack(string, int) - only light, medium, and heavy can attack
// Preconditions: target passed and health of attacker
// Postconditions: displays that untrained horses can't attack
int Untrained::attack(string name, int health){
  cout << "Untrained horses can't attack." << endl;
  return health;
}