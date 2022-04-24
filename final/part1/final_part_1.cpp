// Cody Stritz
// Final - Part 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <array>
#include <cstdlib>
#include <ctime>
#include "tortoise_hare.h"

// Returns random number between 1 and 10
int RollDice() {
  return (rand() % 10) + 1;
}

// Prints the current race map based on the 
// positions of the given Contestants
void PrintRaceMap(Contestant cont_1, Contestant cont_2) {
  array<string, 70> race_map = {};  // string Array of size 70

  // Populate race map
  for (int i = 0; i < race_map.size(); i++) {
    // If both are in same position
    if (i == cont_1.GetPosition() - 1  && i == cont_2.GetPosition() - 1) {
      race_map[i] = "BUMP!";
    }
    // cont_1 is there
    else if (i == cont_1.GetPosition() - 1) {
      race_map[i] = cont_1.GetSymbol();
    } 
    // cont_2 is there
    else if (i == cont_2.GetPosition() - 1) {
      race_map[i] = cont_2.GetSymbol();
    }
    // neither are there
    else {
      race_map[i] = "-";
    }
  }

  // Print the race map
  for (string s : race_map) cout << s;
  cout << endl;
}

// Get preferred mode from user
void InitMode(char& mode) {
  char input = 0;
  while (input != '1' && input != '2') {
    cout << "Select a Mode:\n1 = Auto\n2 = Interactive" << endl;
    cin.get(input);
  }
  mode = input;
}

int main() {
  srand((unsigned) time(0));  // set seed
  Tortoise tortoise;
  Hare hare;
  const int finish = 70;
  char mode;

  InitMode(mode); // Get mode from user

  cout << "Bang! Off they go!" << endl; // start race message

  // While neither Contestant has reached the finish
  while (tortoise.GetPosition() < finish && hare.GetPosition() < finish) {
    this_thread::sleep_for(chrono::seconds(1)); // sleep for 1 second
    int roll = RollDice();  // roll dice
    tortoise.Move(roll);  // move tortoise
    hare.Move(roll);      // move hare
    PrintRaceMap(tortoise, hare);   // print updated race map
    // If "interactive" mode, wait for user to press to continue
    if (mode == '2') system("pause");
  }
  system("pause");
  return 0;
}