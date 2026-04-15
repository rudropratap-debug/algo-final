#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int num;
    cout<<"Enter num: ";
    cin>>num;

    vector<int>profit(num);
    vector<int>weight(num);

    for(int i = 0; i < num; i++){
        cin>>profit[i];
        cin>>weight[i];
    }

    int capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;

    vector<vector<int>>ks(num+1,vector<int>(capacity+1,0));

    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= capacity; j++){
            if(j >= weight[i]){
                ks[i][j] = max(ks[i-1][j-1],profit[i]+ks[i-1][j + weight[i]]);
            }

            else 
                ks[i][j] = ks[i-1][j];
        }
    }

    cout<<"Max profit: "<<ks[num][capacity];
    return 0;
}