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
  char Value; //card Value
  char suit;  //card color
};

bool compare(Card a, Card b)
{
  if (a.Value == b.Value || a.suit == b.suit)
    return 1;

  return 0;
}

int main()
{
  string str;
  int i;
  Card Deck[52];                   //main holder of the deck
  vector<stack<Card>> DecksHolder; //Vector of stacks of cards

  while (cin >> str && str != "#") //while getting input
  {
    i = 0;
    Deck[i].Value = str[0];
    Deck[i].suit = str[1];
    for (i = 1; i < 52; i++)
    {
      cin >> str;
      Deck[i].Value = str[0];
      Deck[i].suit = str[1];
    }
    DecksHolder.clear();
    for (int i = 0; i < 52; i++)
    {
      stack<Card> s;
      s.push(Deck[i]);
      DecksHolder.push_back(s);
      Card temp;
      for (int j = DecksHolder.size() - 1; j < DecksHolder.size(); j++)
      {
        temp = DecksHolder[j].top();
        if (j >= 3)
        {
          if (compare(temp, DecksHolder[j - 3].top()))
          {
            DecksHolder[j - 3].push(temp);
            DecksHolder[j].pop();
            if (DecksHolder[j].empty())
              DecksHolder.erase(DecksHolder.begin() + j);
            j -= 4;
          }
          else
          {
            if (compare(temp, DecksHolder[j - 1].top()))
            {
              DecksHolder[j - 1].push(temp);
              DecksHolder[j].pop();
              if (DecksHolder[j].empty())
                DecksHolder.erase(DecksHolder.begin() + j);
              j -= 2;
            }
          }
        }
        else if (j > 0 && j < 3)
        {
          if (compare(temp, DecksHolder[j - 1].top()))
          {
            DecksHolder[j - 1].push(temp);
            DecksHolder[j].pop();
            if (DecksHolder[j].empty())
              DecksHolder.erase(DecksHolder.begin() + j);
            j -= 2;
          }
        }
      }
    }

    int answer = DecksHolder.size(); //There are a few piles at the end
    if (answer == 1)
      cout << "1 pile remaining: ";
    else
      cout << answer << " piles remaining: ";
    for (int i = 0; i < answer; i++)
    {
      cout << DecksHolder[i].size();
      if (i + 1 != answer)
        cout << " ";
    }
    cout << "\n";
  }
}
