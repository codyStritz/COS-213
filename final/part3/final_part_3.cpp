// Cody Stritz
// Final - Part 3
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include<fstream>
using namespace std;

int main() {
  // initialize input and output fstreams
  ifstream infile;
  infile.open("input.txt");
  ofstream outfile;
  outfile.open("output.txt",ios::out);

  char c;           // current char
  int count = 0;    // current count

  while (infile.get(c)) {   // get next char
    if (isspace(c)) {       // check if c is any form of whitespace
      cout << count << " ";       // print to screen
      outfile << count << " ";    // copy to outfile
      count = 0;                  // reset count
    }
    else
      count++;  // if not whitespace, increment count
  }

  cout << count << " " << endl;       // print to screen
  outfile << count << " ";    // copy to outfile
  count = 0;                  // reset count

  // close the fstreams
  infile.close(); 
  outfile.close();
  system("pause");
  return 0;
}