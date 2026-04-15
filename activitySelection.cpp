#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int num;
    cout<<"Enter number of activities: ";
    cin>>num;

    int st[num],et[num];

    for(int i = 0; i < num; i++){
        cout<<"Enter start time for activity: "<<i+1<<": ";
        cin>>st[i];

        cout<<"Enter finish time for activity: "<<i+1<<": ";
        cin>>et[i];
    }

    for(int i = 0; i < num-1; i++){
        for(int j = 0; j < num-i-1; j++){
            if(et[j]>et[j+1]) {
                swap(st[j],st[j+1]);
                swap(et[j],et[j+1]);
            }
        }
    }


    int counter = 1; 
    int lastEnd = et[0];

    for(int i = 1; i < num; i++){
        if(st[i]>= lastEnd){
            counter++;
            lastEnd = et[i];
        }
    }

    cout<<"Max num of activities: "<<counter<<": "<<endl;
    return 0;
}