///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            12372 - Packing for Holiday
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 12372 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           12372.cpp
//                  input
//                  input2
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main() {
  int T = 0;
  cin >> T;

  for(int i = 1; i <= T; i++){
    int a, b, c = 0;
    cin >> a >> b >> c;

    if( a > 20 || b > 20 || c > 20){
      cout << "Case " << i << ": bad\n";
    }else{
      cout << "Case " << i << ": good\n";
    }
  }
}