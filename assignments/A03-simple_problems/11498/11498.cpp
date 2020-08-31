///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            11498 - division of Nlogonia
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 11498 (see attached files for more info)
//
// Usage:
//       run with an input file
//
// Files:           11498.cpp
//                  input
//                  input2
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main() {
  int t, n, m, x, y = 0;
  

  do{
  cin >> t;  
  cin >> n >> m;

  for(int i = 0; i <t; i++){
    cin >> x >> y;
    if(x > n && y > m){
      cout << "NE\n";
    }else if(x > n && y < m){
      cout << "SE\n";
    }else if(x < n && y > m){
      cout << "NO\n";
    }else if(x < n && y < m){
      cout << "SO\n";
    }else if(x == n || y == m){
      cout << "divisa\n";
    }
  }
  }while(t != 0);
}