///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            127 - Accordian Patience
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 127 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           127.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Card
{
  char Val;  //card Value
  char suit; //card color
};

bool compare(Card a, Card b)
{
  if (a.Val == b.Val || a.suit == b.suit)
    return 1;

  return 0;
}

int main()
{
  Card c[52];            //main holder of the deck
  vector<stack<Card>> V; //Vector of stacks of cards
  string str;

  int i;
  while (cin >> str && str != "#")
  {
    i = 0;
    c[i].Val = str[0];
    c[i].suit = str[1];
    for (i = 1; i < 52; i++)
    {
      cin >> str;
      c[i].Val = str[0];
      c[i].suit = str[1];
    }
    V.clear();
    for (int i = 0; i < 52; i++)
    {
      stack<Card> s;
      s.push(c[i]);
      V.push_back(s);
      Card temp;
      for (int j = V.size() - 1; j < V.size(); j++)
      {
        temp = V[j].top();
        if (j >= 3)
        {
          if (compare(temp, V[j - 3].top()))
          {
            V[j - 3].push(temp);
            V[j].pop();
            if (V[j].empty())
              V.erase(V.begin() + j);
            j -= 4;
          }
          else
          {
            if (compare(temp, V[j - 1].top()))
            {
              V[j - 1].push(temp);
              V[j].pop();
              if (V[j].empty())
                V.erase(V.begin() + j);
              j -= 2;
            }
          }
        }
        else if (j > 0 && j < 3)
        {
          if (compare(temp, V[j - 1].top()))
          {
            V[j - 1].push(temp);
            V[j].pop();
            if (V[j].empty())
              V.erase(V.begin() + j);
            j -= 2;
          }
        }
      }
    }

    int ans = V.size(); //There are a few piles at the end
    if (ans == 1)
      cout << "1 pile remaining: ";
    else
      cout << ans << " piles remaining: ";
    for (int i = 0; i < ans; i++){
      cout << V[i].size(); 
      if(i+1 != ans)
        cout << " ";
    }
    cout << "\n";
  }
}
