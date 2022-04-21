#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <array>
#include <cstdlib>
#include <ctime>
#include "tortoise_hare.h"

int RollDice() {
  return (rand() % 10) + 1;
}

void PrintRaceMap(Contestant cont_1, Contestant cont_2) {
  array<string, 70> race_map = {};

  // Get updated race map
  for (int i = 0; i < race_map.size(); i++) {
    if (i == cont_1.GetPosition() - 1  && i == cont_2.GetPosition() - 1) {
      race_map[i] = "BUMP!";
    }
    else if (i == cont_1.GetPosition() - 1) {
      race_map[i] = cont_1.GetSymbol();
    } 
    else if (i == cont_2.GetPosition() - 1) {
      race_map[i] = cont_2.GetSymbol();
    }
    else {
      race_map[i] = "-";
    }
  }

  // Print the race map
  for (string s : race_map) cout << s;
  cout << endl;
}

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

  InitMode(mode);

  cout << "Bang! Off they go!" << endl; // start race message

  while (tortoise.GetPosition() < finish && hare.GetPosition() < finish) {
    this_thread::sleep_for(chrono::seconds(1));
    int roll = RollDice();
    tortoise.Move(roll);
    hare.Move(roll);
    PrintRaceMap(tortoise, hare);
    if (mode == '2') system("pause");
  }
  return 0;
}