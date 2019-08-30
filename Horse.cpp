//Title: Horse.h
//Author: Humza Faraz
//Date: 3/21/2019
//Description: This is the header file for the parent class Horse

#include "Horse.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: A horse is created
Horse::Horse(){
  m_training = (Training) 0;
}


// Overloaded Constructor
// Preconditions: Valid inputs (name, align, size, health, speed)
//                Training always 0
// Postconditions: None
Horse::Horse(string name, Size size, int health, int speed){
  m_name = name;
  m_size = size;
  m_health = health;
  m_speed = speed;
}

// Destructor - virtual (implement in child classes)
// Preconditions: Horse object in memory
// Postconditions: Deallocates horse object in memory
//Horse::~Horse(){};

// getName() - returns the name of horse
// Preconditions: m_name is set
// Postconditions: returns a string name of the horse
string Horse::getName(){
  return m_name;
}

// getSize() - returns the size of horse
// Preconditions: m_size is set
// Postconditions: returns an enum Size referring to the size of the horse
Size Horse::getSize(){
  return m_size;
}

// getHealth() - returns the health of horse
// Preconditions: m_health is set
// Postconditions: returns an int referring to health from (1 - MAX_HEALTH)
int Horse::getHealth(){
  return m_health;
}

// getSpeed() - returns the speed of the horse
// Preconditions: m_speed is set
// Postconditions: returns an int referring to speed from (1 - MAX_SPEED)
int Horse::getSpeed(){
  return m_speed;
}

// getTraining() - returns the training level of horse
// Preconditions: m_training is set
// Postconditions: returns an enum Training referring to training level of the horse
Training Horse::getTraining(){
  return m_training;
}

// setHealth() - updates the health of the horse
// Preconditions: m_health is set
// Postconditions: updates m_health
void Horse::setHealth(int change){
  m_health = change;
}

// increaseTraining() - increase training by one, up to max
// Preconditions: all variables are set valid
// Postconditions: returns an bool (true if increased, false if at max)
bool Horse::increaseTraining(){
  for (int i = UNTRAINED; i < MASTER ; i++){
    if (m_training == i){
      m_training = (Training)(i + 1);
      return true;
    }
    cout << "Already at max training." << endl;
    return false;
  }
  return false;
}

// specialize() - Attempts to converts an Untrained horse to
//                a war horse (light, medium, or heavy)
//                Only Untrained type of horses can be specialized
// Preconditions: all variables are set valid
// Postconditions: returns a pointer to a new warhorse or NULL
Horse* Horse::specialize(){
  return nullptr;
}

// attack(string, int) - Virtual function for light/medium/heavy to attack
// Preconditions: all variables are set valid
// Postconditions: Child class will return the number of points of damage
//int Horse::attack(string, int)=0;

// train() - Tests if horse was successfully trained
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether horse trained or not
//does train go here? its pure vitrual
//virtual bool train() = 0;

// battle() - Sends a horse to battle another horse
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether horse won the battle or not
bool Horse::battle(Horse* enemy){
  if (enemy->getHealth() <= 0){
    return true;
  }
  else if (getHealth() <= 0){
    return false;
  }
}
  
// Overloaded << - Prints the details of a horse
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of horse
std::ostream& operator<<(ostream& output, Horse& horse){
  output << horse.getName() << "\t" << 
    horse.getSize() << "\t" <<
    horse.getHealth() << "\t" <<
    horse.getSpeed() << "\t" << 
    horse.toString() << endl;
  
  return output;
}


// randomPercentBased (Helper function)
// Precondition: Given int to "pass"
// Description: This function is used to see if a certain random event occurs
//              A random number 1-100 is compared to the int passed
//              If the random number is less than the passed value, return true
//              Else return false (30 = 30%, 70 = 70%)
// Postcondition: Returns boolean
//do we say it's static?
bool Horse::randomPercentBased(int pass){
  int chance = rand() % 100 + 1;
  if (chance <= pass){
    return true;
  }
  return false;
} 

// toString() - a string representation of the horse
// Preconditions: all variables are set valid
// Postconditions: returns an string describing the horse
//uncomment?
//string Horse::toString() = 0;

// trainingString() - a string representation of a training level enum
// UNTRAINED = 0, SADDLE = 1, GREEN = 2, INTERMEDIATE = 3, EXPERT = 4, MASTER = 5
// Preconditions: Pass a training level to the function
// Postconditions: Returns the string of the enum
string Horse::trainingString(Training level){
  if (level == UNTRAINED)
    return "UNTRAINED";
  else if (level == SADDLE)
    return "SADDLE";
  else if (level == GREEN)
    return "GREEN";
  else if (level == INTERMEDIATE)
    return "INTERMEDIATE";
  else if (level == EXPERT)
    return "EXPERT";
  else if (level == MASTER)
    return "MASTER";
  else
    return "Training cannot be found.";
}



