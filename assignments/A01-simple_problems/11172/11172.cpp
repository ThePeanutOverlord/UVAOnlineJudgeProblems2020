/*
*
*/

#include <iostream>

using namespace std;

int main() {
  int t,l,r=0;
  cin >> t;
  for(int i=0;i<t;i++){
      cin>>l>>r;
      if(l<r){
          cout<<"<\n";
      }else if(l>r){
          cout<<">\n";
      }else{
          cout<<"=\n";
      }
  }
}