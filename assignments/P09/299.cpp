///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Chamagpne
// Email:            paigechamp@gmail.com
// Label:            299 - Train Swapping
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 299 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           299.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;


void swap(int *xp, int *yp)  
{  

    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  

}  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

int main() {
int casecount;
cin >> casecount;
for(int i = 0; i < casecount; i++){
  int carcount;
  int swapcount = 0;
  cin >> carcount;
  int *traincars = new int[carcount];
  int k, j;  
    for(int p = 0; p < carcount; p++){
      int temp;
      cin >> temp;
      traincars[p] = temp;
    }
    for (k = 0; k < carcount-1; k++){     
      
    // Last i elements are already in place  
     for (j = 0; j < carcount-k-1; j++){  
        if (traincars[j] > traincars[j+1]){  
            swap(&traincars[j], &traincars[j+1]);  
            swapcount++;
        }

      }
    }

  cout << "Optimal train swapping takes " << swapcount << " swaps.\n";
}


}