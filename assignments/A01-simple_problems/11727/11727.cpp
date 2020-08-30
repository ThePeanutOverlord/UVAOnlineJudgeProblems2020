///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            11727 - Cost Cutting
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 11727 (see attached files for more info)
//
// Usage:
//       run with an input file
//
// Files:           11727.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main() {
  int T, a, b, c = 0;
  cin >> T;

  for(int i = 1; i <= T; i++){
    int it = 0;
    cin >> a >> b >> c;

    if((a < b && a > c) || (a > b && a < c)){
      it = a;
    }if((b > a && b < c) || (b < a && b > c)){
      it = b;
    }if((c > a && c < b) || (c < a && c > b)){
      it = c;
    }
    cout << "Case " << i << ": " << it <<"\n";
  }
}