///////////////////////////////////////////////////////////////////////////////
//
// stack1uthor:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            514 - Relational Operator
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 514 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           514.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
// void printVector(vector<int> v){
//     for (int i = 0; i < v.size(); i++){
//         cout << v[i] << " ";
//     }
//     cout<<endl;
// }
/**
 * 514 Rails
 */
int main(int argc, char** argv){
    int numCars;
    int carNum;
    int carCount=0;
    int a;
    bool keepChecking = true;
    int sum;
    vector<int> outTrain;
    vector<int> inTrain;
    vector<int> station;
    cin>>numCars;
    inTrain.clear();
    outTrain.clear();
    station.clear();
    a=1;
    while(numCars){
        cin>>carNum;
        if(carNum == 0){
            cout<<endl;
            outTrain.clear();
            carCount = 0;
            cin>>numCars;
            if(numCars == 0){
                exit(0);
            }
        } else {
            inTrain.push_back(a);
            outTrain.push_back(carNum);
            carCount++;
            a++;
        }
        if(carCount % numCars == 0){
            station.clear();
            if(inTrain.size()){
                if(inTrain == outTrain){
                    cout<<"Yes";
                }else if(inTrain.size() != outTrain.size()){
                    cout<<"No";
                }else{
                    
                    int i = 0;
                    int j = 0;
                    keepChecking = true;
                    while(keepChecking){
                        if(i < numCars){
                            if(inTrain[i] == outTrain[j]){
                                i++;
                                j++;
                            }else if(station.size() > 0 && station.back() == outTrain[j]){
                                station.pop_back();
                                j++;
                            }else{
                                station.push_back(inTrain[i]);
                                i++;
                            }
                        }else{
                            if(j>=numCars){
                                keepChecking = false;
                                cout<<"Yes";
                                i=0;
                                j=0;
                                break;
                            }else if(station.size() > 0 && station.back() == outTrain[j]){
                                station.pop_back();
                                j++;
                            }else{
                                keepChecking = false;
                                cout<<"No";
                                break;
                            }
                        }
                    }
                    /*cout<<"\t : ";
                    sum = 0;
                    for(int i=0;i<inTrain.size();i++){
                        cout<<inTrain[i]-outTrain[i]<<"\t";
                    }
                    for(int i=0;i<inTrain.size()/2+1;i++){
                        sum += (inTrain[i]-outTrain[i]);
                    }               
                    cout<<sum;*/
                }
                cout<<endl;
            }
            inTrain.clear();
            outTrain.clear();
            a = 1;
        }
    }
    return 0;
}