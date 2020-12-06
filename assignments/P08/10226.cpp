///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Chamagpne
// Email:            paigechamp@gmail.com
// Label:            10226 - Hardwood Species
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 10226 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           10226.cpp
//                  input
//                  input2
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct tree{
  int count;
  string name;

  tree(){
    name = "";
    count = 0;
  }
  tree(string n){
    name = n;
    count = 1;
  }
};
void swap(tree *xp, tree *yp)  
{  
    tree temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  /*
// A function to implement bubble sort  
void Sort(tree v[], int size)  
{  
    int i, j;  
    for (i = 0; i < size-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < size-i-1; j++)  
        if (v[j].name > v[j+1].name)  
            swap(&v[j], &v[j+1]);  

}  */

int partition (tree arr[], int low, int high) 
{ 
    string pivot = arr[high].name;    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j].name <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(tree arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int main() {
int testcount;
string blank;
cin >> testcount;
getline(cin, blank);
cin.ignore(); 


for(int i = 0; i < testcount; i++){

  int totaltree = 0;
  string tname;
  getline(cin, tname);
  double treepercent;
 // cout << tname;
  tree treelist[10000];  
  int tlistsize = 0;    
  while(tname != ""){
    bool newtree = true;



    for(int j = 0; j < tlistsize; j++){ //check if in vector
     //cout << treelist[j].name << " " << tname <<endl;
      if(treelist[j].name == tname){
        treelist[j].count++;
        newtree = false;
      }

    }
   // cout << treelist.size() <<endl;
    if(newtree == true){  //if not already in vector, add
      tree t = tree(tname);
      treelist[tlistsize] = t;
      tlistsize++;
    }

    totaltree++;

    getline(cin, tname);

  }
   //Sort(treelist, tlistsize);
   quickSort(treelist, 0, tlistsize-1);
      for(int j = 0; j< tlistsize; j++){ //check if in vector
        cout << treelist[j].name << " ";
        treepercent = (double)treelist[j].count/totaltree * 100; //uhh fix this
        cout << fixed << setprecision(4) << treepercent <<endl;
    }
  cout <<endl;
  //also need to sort vector by tree name
}

}