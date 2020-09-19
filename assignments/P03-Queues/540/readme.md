## 540 - Team Queue
### Paige Champagne
### Description:

The input file will contain one or more test cases. Each test case begins with the number of teams
t (1 ≤ t ≤ 1000). Then t team descriptions follow, each one consisting of the number of elements
belonging to the team and the elements themselves. Elements are integers in the range 0..999999. A
team may consist of up to 1000 elements.
Finally, a list of commands follows. There are three different kinds of commands:
• ENQUEUE x — enter element x into the team queue
• DEQUEUE — process the first element and remove it from the queue
• STOP — end of test case
The input will be terminated by a value of 0 for t.
Warning: A test case may contain up to 200000 (two hundred thousand) commands, so the implementation of the team queue should be efficient: both enqueing and dequeuing of an element should
only take constant time.

### Files:
| Number | Folder                              | Description                            |
| :----: | ----------------------------------- | -------------------------------------- |
| 1 | [540.cpp](./540.cpp)   | Solution file |
| 2 | [input](./input)   | Input file |

### Sources:
https://www.geeksforgeeks.org/deque-cpp-stl/
