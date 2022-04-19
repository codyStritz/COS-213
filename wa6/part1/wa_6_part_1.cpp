// Cody Stritz
// Written Assignment 6 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

// If char c is lowercase -> make it uppercase
// If char c is alphabetic -> return true; else -> return false
bool EnsureUppercase(char& c) {
  if (c >= 97 && c <= 122) {   // lowercase
    c -= 32;
    return true;
  }
  else return (c >= 65 && c <= 90); // uppercase
}

int main() {
  // Variable declarations
  ifstream infile;  // input fstream
  ofstream outfile; // output fstream
  string input_filename; 
  string output_filename;
  int line_count = 0;
  char curr = 0;
  string line;
  // map for counting alphabetic characters
  map<char, int> count_map;
  
  // Get input and output filenames from user
  cout << "Enter input file name: ";
  cin >> input_filename;
  cin.ignore();
  cout << "Enter output file name: ";
  cin >> output_filename;
  cin.ignore();

  // Count alphabetic characters
  infile.open(input_filename);
  if (infile.is_open()) {
    while(infile.good()) {
      infile.get(curr);
      if (!infile) break;
      if (EnsureUppercase(curr)) {
        count_map[curr]++;
      }
    }
  }
  // Handle errors while reading from input file
  if(!infile.eof() && infile.fail()) {
    cout << "error reading " << input_filename << endl;
  }
  infile.close(); // Close input file

  // Copy input file contents to output file line-by-line
  infile.open(input_filename);    
  outfile.open(output_filename);  
  if(infile.is_open() && outfile.is_open()) {
    while(getline(infile, line)) {
      outfile << line << endl;
      line_count++;   // Count lines
    }
  }
  // Handle errors while reading from input file
  if(!infile.eof() && infile.fail()) {
    cout << "error reading " << input_filename << endl;
  }
  infile.close(); // Close input file

  // Add line count to output file
  outfile << "The number of lines in the input file is " << line_count << endl;

  // Add count of alphabetic characters to output file
  for (auto i : count_map) {
    outfile << i.first << " appears " << i.second << " times." << endl;
  }
  outfile.close();  // Close output file
  system("pause");
  return 0;
}