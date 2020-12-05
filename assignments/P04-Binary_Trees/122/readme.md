## 122 - Trees on the Level
### Paige Champagne
### Description:
In this problem a binary tree is specified by a sequence
of pairs ‘(n,s)’ where n is the value at the node whose path
from the root is given by the string s. A path is given be
a sequence of ‘L’s and ‘R’s where ‘L’ indicates a left branch and ‘R’ indicates a right branch. In the
tree diagrammed above, the node containing 13 is specified by (13,RL), and the node containing 2 is
specified by (2,LLR). The root node is specified by (5,) where the empty string indicates the path from
the root to itself. A binary tree is considered to be completely specified if every node on all root-to-node
paths in the tree is given a value exactly once.
The input is a sequence of binary trees specified as described above. Each tree in a sequence consists
of several pairs ‘(n,s)’ as described above separated by whitespace. The last entry in each tree is ‘()’.
No whitespace appears between left and right parentheses.
All nodes contain a positive integer. Every tree in the input will consist of at least one node and
no more than 256 nodes. Input is terminated by end-of-file.


### Files:
| Number | Folder                              | Description                            |
| :----: | ----------------------------------- | -------------------------------------- |
| 1 | [122.cpp](./122.cpp)   | Solution file |
| 2 | [input](./input)   | Input file |
| 3 | [input 2](./input2)   | Input file |

### Sources:
http://www.cplusplus.com/reference/cstdio/scanf/
https://www.geeksforgeeks.org/strcmp-in-c-cpp/
