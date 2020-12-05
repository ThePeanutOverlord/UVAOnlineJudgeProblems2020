///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Chamagpne
// Email:            paigechamp@gmail.com
// Label:            11172 - Relational Operator
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 11172 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           11172.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {
int count;
int a, b;

cin >> count;

for(int i = 0; i < count; i++){
  cin >> a;
  cin >> b;

  if(a == b){
    cout << "=\n";
  }else if(a > b){
    cout << ">\n";
  }else{
    cout << "<\n";
  }

}


}