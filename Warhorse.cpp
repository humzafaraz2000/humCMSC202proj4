//Title: War.cpp
//Author: Humza Faraz
//Date: 4/13/18
//Section: 32
//E-mail: hfaraz1@umbc.edu

#include "Warhorse.h"
#include "Horse.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: None
Warhorse::Warhorse(){
  
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
//added name, size, health, and speed
Warhorse::Warhorse(string name, Size size, int health, int speed)
  :Horse(name, size, health, speed){
  
}

// train() - Gives a 50% of increasing training up to maximum.
// Preconditions: all variables are set valid
// Postconditions: returns true if successfully trained
bool Warhorse::train(){
  int pass = 50;
  Training train = getTraining();
  bool chance = randomPercentBased(pass);
  if (chance == true){
    for (int i = 0; i < MAX_TRAINING; i++){
      if (train == Training(i)){
        train = Training(i+1);
        return true;
      }
    }
    
    return false;
  }
  else{
    
    return false;
  }
}

// toString() - purely virtual
// Preconditions: all variables are set valid
// Postconditions: used for subclasses to return string of their type
//string Warhorse::toString() = 0;

// battle(Horse*) - passed enemy horse
// turns are based on speed - counter starts at 0 and if counter % speed == 0 then
// that horse attacks counter%getSpeed()==0, attacks. If attack leaves at or below 0
// then that horse loses battle.
// Preconditions: enemy horse has been defined
// Postconditions: returns a bool of who won battle between two horses
bool Warhorse::battle(Horse* enemy){
  int counter = 0;
  int damage = attack(enemy->getName(), getHealth());
  enemy->setHealth(enemy->getHealth() - damage);
  counter ++;
  while (getHealth() > 0 and enemy->getHealth() > 0){
    if (counter % getSpeed() == 0){
      damage = attack(enemy->getName(), getHealth());
      enemy->setHealth(enemy->getHealth() - damage);
      counter ++;
    }
    else{
      damage = attack(getName(), enemy->getHealth());
      setHealth(getHealth() - damage);
      counter ++;
    }
  }
  if (getHealth() > 0){
    return true;
  }
  else{
    return false;
  }
}

// attack(string, int) - purely virtual (implemented in all child classes)
// Preconditions: passed string name of target and health of attacker
// Postconditions: returns damage as an integer
//int Warhorse::attack(string, int) = 0;
