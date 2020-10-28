#include <iostream>
using namespace std;


int main() {
  int * arr; //oops i want this to be points
  int mountcount, peakcount;

  cin >> mountcount;

  for(int i = 0; i < mountcount; i++){
    cin >> peakcount;
    double sum;
    int maxY;
    arr = new int[peakcount]; //again change from ints to points
    for(int j = 0; j < peakcount; j++){
      //read in each point into the array
    }
      //sort the array by x val (might have to write that myself)

      //create a for loop here and traverse from the back (biggest x val, y val should be 0)
      //if the y val > maxY, calculate the
      //distance between those first two consecutive points and add to sum.
      //save that y val as maxY
  
      
    //print sum with 2 decimal places

    //in hindsight this might be expensive but it's what we talked about in class

  }



}