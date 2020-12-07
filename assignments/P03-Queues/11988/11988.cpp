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
#include <list>
#include <iterator>
using namespace std;

int main() {
  
  char a;
  string s;
 while(getline(cin, s)){
  list <char> list, parenthesis;
  string hold;
  int j = 0;
   for(int i = 0; i < s.length(); i++){
              //if regular letters
     if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '_')){
       if(parenthesis.empty()){ //if there is no beiju
         list.push_back(s[i]);
       }else{// if there's [] on the list and s[i] isn't a [], put beiju in holder
         hold += s[i];
       }
     }else if(s[i] =='['){
       parenthesis.push_back('[');
     }else if(s[i] == ']'){
        parenthesis.pop_front();
     }  

   }
  //cout << hold[0] <<endl;
   if(hold.size() > 0){
      for(int i = hold.size(); i >= 0; i--){
        list.push_front(hold[i]);
      }
    }
    int k = list.size();
    for(int i = 0; i < k; i++){
        cout << list.front();
        list.pop_front();
      }
      cout << "\n";
 }


}

