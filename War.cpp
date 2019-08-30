//Title: War.cpp
//Author: Humza Faraz
//Date: 4/13/18
//Section: 32
//E-mail: hfaraz1@umbc.edu


#include "Horse.h"
#include "Untrained.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"
#include "War.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Default Constructor
// Preconditions: None
// Postconditions: Seeds srand only
War::War(){
  srand(time(NULL));
}

// Destructor
// Preconditions: m_myStable and/or m_enemyStable is populated
// Postconditions: Deallocates horse objects in all vectors
War::~War(){
  for (int i = 0; i < (int)sizeof(m_enemyStable); i++){
    delete m_enemyStable.at(i);
  }
  for (int i = 0; i < (int)sizeof(m_myStable); i++){
    delete m_myStable.at(i);
  }
}

// Name: loadHorses
// Desc - Loads each horse into m_enemyStable from file
// Preconditions - Requires file with valid horse data
// Postconditions - m_enemyStable is populated with enemy horse pointers
void War::loadHorses(char* filename){
  ifstream myfile;
  string name;
  int size;
  int health;
  int speed;
  myfile.open(filename);
  if (myfile.is_open()){
    while (myfile >> name){
      myfile >> size;
      //size = (Size)size;
      myfile >> health;
      myfile >> speed;
      if (myfile.peek() == '\n'){
        myfile.ignore();
      }
      if (size == 0){
        Horse* newLight = new Light(name, SMALL, health, speed);
        m_enemyStable.push_back(newLight);
      }
      else if (size == 1){
        Horse* newMedium = new Medium(name, MEDIUM, health, speed);
        m_enemyStable.push_back(newMedium);
      }
      else if (size == 2){
        Horse* newHeavy = new Heavy(name, LARGE, health, speed);
        m_enemyStable.push_back(newHeavy);
      }
    }
  }
  else{
    cout << "File could not open." << endl;
  }
  myfile.close();
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - m_enemyStable has been populated from file
// Postconditions - exits if user entered 6
void War::mainMenu(){
  cout << "Welcome to UMBC  War!" << endl << endl;
  int choice = 0;
  cout << "What would you like to do?" << endl;
  cout << "1. Display Friendly Stable" << endl
    << "2. Display Enemy Stable" << endl
    << "3. Acquire Horse" << endl
    << "4. Train Horse" << endl
    << "5. Battle" << endl
    << "6. Quit" << endl;
  cin >> choice;
  while (choice != 6){
    if (choice == 1){
      displayMyHorses();
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl
        << "2. Display Enemy Stable" << endl
        << "3. Acquire Horse" << endl
        << "4. Train Horse" << endl
        << "5. Battle" << endl
        << "6. Quit" << endl;
      cin >> choice;
    }
    else if (choice == 2){
      displayEnemyHorses();
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl
        << "2. Display Enemy Stable" << endl
        << "3. Acquire Horse" << endl
        << "4. Train Horse" << endl
        << "5. Battle" << endl
        << "6. Quit" << endl;
      cin >> choice;
    }
    else if (choice == 3){
      acquireHorse();
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl
        << "2. Display Enemy Stable" << endl
        << "3. Acquire Horse" << endl
        << "4. Train Horse" << endl
        << "5. Battle" << endl
        << "6. Quit" << endl;
      cin >> choice;
    }
    else if (choice == 4){
      trainHorse();
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl
        << "2. Display Enemy Stable" << endl
        << "3. Acquire Horse" << endl
        << "4. Train Horse" << endl
        << "5. Battle" << endl
        << "6. Quit" << endl;
      cin >> choice;
    }
    else if (choice == 5){
      startBattle();
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl
        << "2. Display Enemy Stable" << endl
        << "3. Acquire Horse" << endl
        << "4. Train Horse" << endl
        << "5. Battle" << endl
        << "6. Quit" << endl;
      cin >> choice;
    }
    else{
      cout << "Invalid. Please enter only 1-6." << endl;
      cin >> choice;
    }
  }
  cout << "Thank you for using UMBC War simulator!" << endl;
}

// Name: acquireHorse()
// Desc - user randomly acquires a new untrained horse (random size)
// Preconditions - none
// Postconditions - new horse is added to m_myStable
void War::acquireHorse(){
  int newHealth = 0;
  int newSpeed = 0;
  int newSize = rand() % 2 + 0;
  string newName = "";
  cout << "What would you like to name your new horse?" << endl;
  cin >> newName;
  if (newSize == 0){
    newHealth = rand() % (LT_MAX_HEALTH - LT_MIN_HEALTH + 1) + LT_MIN_HEALTH;
    newSpeed = rand() % (LT_MAX_SPEED - LT_MIN_SPEED + 1) + LT_MIN_HEALTH;
    Horse* newUntrained = new Untrained(newName, SMALL, newHealth, newSpeed);
    m_myStable.push_back(newUntrained);
    cout << "You have acquired a new horse." << endl;
  }
  else if (newSize == 1){
    newHealth = rand() % (MD_MAX_HEALTH - MD_MIN_HEALTH + 1) + MD_MIN_HEALTH;
    newSpeed = rand() % (MD_MAX_SPEED - MD_MIN_SPEED + 1) + MD_MIN_HEALTH;
    Horse* newUntrained = new Untrained(newName, MEDIUM, newHealth, newSpeed);
    m_myStable.push_back(newUntrained);
    cout << "You have acquired a new horse." << endl;
  }
  else if (newSize == 2){
    newHealth = rand() % (HV_MAX_HEALTH - HV_MIN_HEALTH + 1) + HV_MIN_HEALTH;
    newSpeed = rand() % (HV_MAX_SPEED - HV_MIN_SPEED + 1) + HV_MIN_HEALTH;
    Horse* newUntrained = new Untrained(newName, LARGE, newHealth, newSpeed);
    m_myStable.push_back(newUntrained);
    cout << "You have acquired a new horse." << endl;
  }
}

// Name: trainHorse()
// Desc - user randomly acquires a horse
// Preconditions - none
// Postconditions - new horse is added to m_stable
void War::trainHorse(){
  int choice = chooseHorse();
  Horse* chosen = m_myStable.at(choice-1);
  if(chosen->toString() == "Unknown"){
    m_myStable.at(choice-1) = chosen->specialize();
  }
  else{
    bool doesTrain = false;
    doesTrain = chosen->train();
    if (doesTrain == true){
      cout << "Training increased" << endl;
    }
    else{
      cout << "Training didn't increase." << endl;
    }
  }
}

// Name: startBattle()
// Desc - user selects a horse to battle with and fights first horse in enemy
// m_enemyStable. Horse that loses is removed from their respective stable forever
// User must have at least ONE specialized horse at least training level 2 or higher
// Preconditions - Use has at least one horse and horse is specialized trained
// Postconditions - m_myStable or m_enemyStable has loser removed
void War::startBattle(){
  bool hasSpecial = false;
  for (int i = 0; i < (int)m_myStable.size(); i++){
    if (m_myStable[i]->toString() != "Unknown"){
      hasSpecial = true;
    }
  }
  if (hasSpecial == true){
    int choice = chooseHorse();
    while (m_myStable.at(choice-1)->getTraining()  != 0){
      cout << "Training level must be greater than 2!" << endl;
      choice = chooseHorse();
    }
    Horse* enemy = m_enemyStable.at(0);
    Horse* chosen = m_myStable.at(choice-1);
    bool isWinner = false;
    isWinner = chosen->battle(enemy);
    if (isWinner == true){
      cout << "You win!" << endl;
      m_enemyStable.pop_back();
    }
    else{
      cout << "Horse died" << endl;
      m_myStable.erase (m_myStable.begin() + (choice-1));
    }
  }
  else{
    cout << "You don't have a specialized horse!" << endl;
  }
}

// Name: displayMyHorses()
// Desc - Displays all horses in m_myStable or empty message if no horses
// Preconditions - m_myStable is populated
// Postconditions - None
void War::displayMyHorses(){
  cout << "My horses" << endl;
  if ((int)m_myStable.size() == 0){
    cout << "Your stable is currenlty empty." << endl;
  }
  else{
    cout << "Num \t Horse \t Size \t Health \t Speed \t Training" << endl;
    for (int i = 0; i < (int)m_myStable.size(); i++){
      cout << i+1 << "\t" << *m_myStable[i] << endl; 
    }
  }
}

// Name: displayEnemyHorses()
// Desc - Displays all horses in m_enemyStable or win message if empty
// Preconditions - m_enemyStable is populated
// Postconditions - None
void War::displayEnemyHorses(){
  cout << "Num \t Horse \t Size \t Health \t Speed \t Training" << endl;
  for (int i = 0; i < (int)m_enemyStable.size(); i++){  
    cout << i+1 << "\t" << *m_enemyStable[i] << endl; 
  } 
}

// Name: chooseHorse
// Desc - Helper that either displays that m_myStable is empty or allows user to
//        choose a horse to use for training or battle. Returns index + 1
// Preconditions - None
// Postconditions - None
int War::chooseHorse(){
  int choice = 0;
  cout << "What horse would you like to choose?" << endl;
  cin >> choice;
  return choice;
}