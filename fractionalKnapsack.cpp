#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int num;
    cout<<"Enter num: ";
    cin>>num;
    
    double weight[num], profit[num],ratio[num];

    for(int i = 0;  i < num; i++){
        cout<<"Enter profit for item : "<<i+1<<": ";
        cin>>profit[i];

        cout<<"Enter weight for item : "<<i+1<<": ";
        cin>>weight[i];

        ratio[i] = profit[i]/weight[i];
    }


    int capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(profit[j],profit[j+1]);
                swap(weight[j],weight[j+1]);
            }
        }
    }

    double maxProfit = 0;

    for(int i = 0; i < num; i++){
        
        if(capacity == 0)break;

        else if(weight[i] <= capacity){
            maxProfit += profit[i];
            capacity -= weight[i];
        }

        else {
            maxProfit += ratio[i] * capacity;
        }
    }

    cout<<"Max profit: "<<maxProfit<<endl;

    return 0;
}