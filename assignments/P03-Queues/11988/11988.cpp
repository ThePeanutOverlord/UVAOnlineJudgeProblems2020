///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            11988 - broken keyboard
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 11988 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           127.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <deque>
using namespace std;

int main() {
  
  char a;
  string s;
  char holder;
 while(getline(cin, s)){
  deque <char> list;
  deque <char> parenthesis;
   string hold;
   for(int i = 0; i < s.length(); i++){
     if(s[i] =='['){
       parenthesis.push_back('[');

     }
      if(s[i] == ']'){
        parenthesis.pop_front();
      }

    if(!parenthesis.empty() && s[i] != '[' && s[i] != ']'){
      hold += s[i];
    }

    if(parenthesis.empty() && s[i] != ']' && s[i] != '[')
      list.push_back(s[i]);

   }
   if(hold.size() > 0){
      for(int i = hold.size(); i >= 0; i--){
     list.push_front(hold[i]);
      }
   }
    for(int i = 0; i < list.size(); i++){
        cout << list[i];
      }
      cout << "\n";
 }


}