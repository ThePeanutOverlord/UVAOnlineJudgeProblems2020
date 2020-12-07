## 10194 -Football Problem
### Paige Champagne
### Description:
A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it
scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3
points for each win, 1 point for each tie and 0 point for each loss.
Teams are ranked according to these rules (in this order):

1. Most points earned.
2. Most wins.
3. Most goal difference (i.e. goals scored - goals against)
4. Most goals scored.
5. Less games played.
6. Lexicographic order.


The first line of input will be an integer N in a line alone (0 < N < 1000). Then, will follow N
tournament descriptions. Each one begins with the tournament name, on a single line. Tournament
names can have any letter, digits, spaces etc. Tournament names will have length of at most 100.
Then, in the next line, there will be a number T (1 < T ≤ 30), which stands for the number of teams
participating on this tournament. Then will follow T lines, each one containing one team name. Team
names may have any character that have ASCII code greater than or equal to 32 (space), except for
‘#’ and ‘@’ characters, which will never appear in team names. No team name will have more than 30
characters.
Following to team names, there will be a non-negative integer G on a single line which stands for
the number of games already played on this tournament. G will be no greater than 1000. Then, G
lines will follow with the results of games played. They will follow this format:
team name 1#goals1@goals2#team name 2
For instance, the following line:
Team A#3@1#Team B
Means that in a game between T eam A and T eam B, T eam A scored 3 goals and T eam B scored
1.
All goals will be non-negative integers less than 20. You may assume that there will not be inexistent
team names (i.e. all team names that appear on game results will have apperead on the team names
section) and that no team will play against itself.

For each tournament, you must output the tournament name in a single line. In the next T lines you
must output the standings, according to the rules above. Notice that should the tie-breaker be the
lexographic order, it must be done case insenstive. The output format for each line is shown bellow:
[a]) T eam name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
Where:

• [a] = team rank
• [b] = total points earned
• [c] = games played
• [d] = wins
• [e] = ties
• [f] = losses
• [g] = goal difference
• [h] = goals scored
• [i] = goals against

There must be a single blank space between fields and a single blank line between output sets. See
the sample output for examples.

### Files:
| Number | Folder                              | Description                            |
| :----: | ----------------------------------- | -------------------------------------- |
| 1 | [10194.cpp](./10194.cpp)   | Solution file |
| 2 | [input](./input)   | Input file |

### Sources:
http://www.cplusplus.com/reference/algorithm/swap/