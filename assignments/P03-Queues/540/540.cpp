///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            540 - Team Queue
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 540 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           540.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <deque>
using namespace std;

int main() {
  int teamcount, members;

  cin >> teamcount;
  int trycounter = 1;  

  while(teamcount != 0){
    cout << "in main loop\n";
    string cmnd;
    deque <deque<string>> line;
    deque <string> team;
    for(int i = 0; i < teamcount; i++){

      team.clear();
      cin >> members;
        for(int i = 0; i < members; i++){
            string a;
            cin >> a;
            team.push_back(a);
        }
       line.push_back(team); 
    }
    
    cin >> cmnd;
    while(cmnd != "STOP"){
      cout <<"in cmnd loop\n";
     
      if(cmnd == "ENQUEUE"){
        string a;
        cin >> a;
        for(int i = 0; i < line.size(); i++){
          
            if ((line[i][1][1] == a[1]) && (line[i][1][2] == a[2])){
              line[i].push_back(a);
            }
          
       }
      }

      if(cmnd == "deque")
        line[1].pop_front();
      cin >> cmnd; 
    }

  cout << "Scenario #" << trycounter << "\n";
    for(int i = 0; i < line.size(); i++){
      for(int j = 0; j < team.size(); j++){
          cout << line[i][j] << "\n";
      }
      cout << "\n";
    }
    
  trycounter ++;

  cin >> teamcount;
  }


}