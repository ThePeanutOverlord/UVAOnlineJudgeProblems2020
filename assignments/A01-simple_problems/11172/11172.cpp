///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
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
// Files:           main.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
  int t,l,r=0;
  cin >> t;
  for(int i=0;i<t;i++){
      cin>>l>>r;
      if(l<r){
          cout<<"<\n";
      }else if(l>r){
          cout<<">\n";
      }else{
          cout<<"=\n";
      }
  }
}