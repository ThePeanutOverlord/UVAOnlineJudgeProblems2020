#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct point{
  double x, y;

  point(){
    x = 0;
    y = 0;
  }
  point(int a, int b){
    x = a;
    y = b;
  }
  point(double a, double b){
    x = a;
    y = b;
  }
};

void swap(point *xp, point *yp)  
{  
    point temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(point arr[], int size)  
{  
    int i, j;  
    for (i = 0; i < size-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < size-i-1; j++)  
        if (arr[j].x > arr[j+1].x)  
            swap(&arr[j], &arr[j+1]);  
}  
  
float distance(point a, point b){ //a is top point, b is bottom. might need abs value
  float d;
  d = sqrt(pow(b.x-a.x, 2)+ pow(b.y-a.y, 2));
  return d;
}

int main() {
  point * arr; //oops i want this to be points
  int mountcount, peakcount;

  cin >> mountcount;

  for(int i = 0; i < mountcount; i++){
    cin >> peakcount;
    float sum = 0;
    double maxY=0;
    arr = new point[peakcount]; //again change from ints to points
    for(int j = 0; j < peakcount; j++){
      double a, b;
      cin >> a;//read in each point into the array
      cin >> b;
      point n(a, b);
      arr[j] = n;

      
    }
    bubbleSort(arr, peakcount);//sort the array by x val

    for(int j = peakcount-1; j >= 0; j--){

       
    if(arr[j].y > maxY && sum == 0){
      sum += distance(arr[j], arr[j+1]);

       maxY = arr[j].y;
    } 
    else if(arr[j].y > maxY && sum != 0){
      double m = ((arr[j+1].y - arr[j].y)/(arr[j+1].x - arr[j].x));
      //cout << m << " ";
      double tempe = (maxY - (arr[j].y - (m * arr[j].x)))/m;
     // cout << tempe;
      point temp(tempe, maxY);
      //cout << "distance: " << distance(arr[j], temp) << endl;
      sum += distance(arr[j], temp);
       maxY = arr[j].y;
    }
      
    
    }
      cout << fixed << setprecision(2)<< sum << endl;


  } //outer loop end



}