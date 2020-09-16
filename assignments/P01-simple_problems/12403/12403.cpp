///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            12403 - Save Setu
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 12403 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           12403.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

int main() {
  int T, a = 0;
  cin >> T;

  for(int i = 0; i < T; i++){
    string op = "";
    cin >> op;
    if(op == "donate"){
      int j = 0;
      cin >> j;
      a += j;
    } else if(op == "report"){
      cout << a << "\n";
    }
  }
}