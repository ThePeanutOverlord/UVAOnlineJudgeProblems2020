///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            10194 - Football Problem
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 10194 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           10194.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Team{
  string name;
  int rank;
  int totalpts;
  int gamesplayed;
  int wins;
  int ties;
  int losses;
  int goaldiff;
  int goalscored;
  int goalagainst;

  Team(){
    name = "";
    rank = 0;
    totalpts = 0;
    gamesplayed = 0;
    wins = 0;
    ties = 0;
    losses = 0;
    goaldiff = 0;
    goalscored = 0;
    goalagainst = 0;
  }
  Team(string n){
    name = n;
    rank = 0;
    totalpts = 0;
    gamesplayed = 0;
    wins = 0;
    ties = 0;
    losses = 0;
    goaldiff = 0;
    goalscored = 0;
    goalagainst = 0;
  }


};
  void print(vector<Team> T, int size){
    for(int i = 0; i < size; i++){
      cout << i+1 << ") " << T[i].name << " " << T[i].totalpts << "p, " << T[i].gamesplayed << "g (" << T[i].wins << "-" << T[i].ties << "-" << T[i].losses << "), " << T[i].goaldiff << "gd (" << T[i].goalscored << "-" << T[i].goalagainst << ")" <<endl;
    }
  }

struct colon_is_space : std::ctype<char> {
  colon_is_space() : std::ctype<char>(get_table()) {}
  static mask const* get_table()
  {
    static mask rc[table_size];
    rc['#'] = std::ctype_base::space;
    rc['@'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    return &rc[0];
  }
};
/*
void swap(Team *xp, Team *yp)  
{  
    Team temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
void bubbleSort(Team *arr[], int n)  
{  //cout << "in bubblesort\n";
    int i, j;  
    for (i = 0; i < n-1; i++){      
      //cout << "in first loop\n";
      cout << n-i-1 <<endl;
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++){ 
      //cout << "in second loop\n";
      cout << arr[j]->name << arr[j]->rank << " " << arr[j+1]->name << arr[j+1]->rank <<endl;
        if (arr[j]->rank > arr[j+1]->rank){  
          cout << "in if\n";
            cout << arr[j]->name << arr[j]->rank << " " << arr[j+1]->name << arr[j+1]->rank <<endl;
            swap(arr[j], arr[j+1]);  
        }
        //else if(arr[j].rank = arr[j+1].rank)
    }
    }
} */

bool Compare(const Team &a, const Team &b) {
  if (a.totalpts != b.totalpts)
    return a.totalpts > b.totalpts;

  if (a.wins != b.wins)
    return a.wins > b.wins;

  if (a.goalscored - a.goalagainst != b.goalscored - b.goalagainst)
    return a.goalscored - a.goalagainst > b.goalscored - b.goalagainst;

  if (a.goalscored != b.goalscored)
    return a.goalscored > b.goalscored;

  if (a.gamesplayed != b.gamesplayed)
    return a.gamesplayed < b.gamesplayed;

  string s1 = a.name, s2 = b.name;
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  return s1 < s2;
}
int main() {
cin.imbue(locale(cin.getloc(), new colon_is_space));
int cases;
cin >> cases;
//cout << cases <<endl;
for(int i = 0; i < cases; i++){
  string tournyname;
  //cout << "owo\n";
  int teamnum, gamenum;
  cin.ignore();  
  getline(cin, tournyname); 
  //cout << tournyname<<endl;
  cin >> teamnum;
  //cout << teamnum <<endl;
  //cout << "dfsz" <<endl;
  vector<Team> list;
  for(int i = 0; i < teamnum; i++){
    //cout <<"in here\n";
    string temp;
    cin >> temp;
    Team k(temp);
    list.push_back(k);
   // cout << list[i].name <<endl;
  }
  
  cin >> gamenum;

  for(int i = 0; i < gamenum; i++){
    string team1, team2;
    int goals1, goals2;

    cin >> team1 >> goals1 >> goals2 >> team2;
  // cout << team1 << " " << goals1 << " " << goals2 << " " << team2 <<endl;
   for(int i = 0; i < teamnum; i++){
     if(team1 == list[i].name){
       list[i].gamesplayed++;
       
       list[i].goalscored += goals1;
       list[i].goalagainst += goals2;
       list[i].goaldiff = list[i].goalscored - list[i].goalagainst;
       if(goals1 > goals2){
         list[i].wins++;
         list[i].totalpts += 3;
       }else if(goals1 < goals2){
         list[i].losses++;
       }else{
         list[i].ties++;
         list[i].totalpts++;
       }
      //cout <<list[i].name << list[i].totalpts << endl;
     }
     if(team2 == list[i].name){
       list[i].gamesplayed++;

       list[i].goalscored += goals2;
       list[i].goalagainst += goals1;
       list[i].goaldiff = list[i].goalscored - list[i].goalagainst;
       if(goals1 < goals2){
         list[i].wins++;
         list[i].totalpts += 3;
       }else if(goals1 > goals2){
         list[i].losses++;
       }else{
         list[i].ties++;
         list[i].totalpts++;
       }
       //cout <<list[i].name << list[i].totalpts << endl;
     }

   }


  }
  //cout << teamnum <<endl;
  //bubbleSort(list, teamnum);
  cout << tournyname <<endl;
  sort(list.begin(), list.end(), Compare);
  print(list, teamnum);
  if(i != cases-1){
    cout << endl;
  }
}


}