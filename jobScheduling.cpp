#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id;
    int deadline;
    int profit;
};

// custom comparator function to sort the vector of struct

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &arr){
    sort(arr.begin(), arr.end(), cmp);
    //finding maximum deadline
    int maxDeadline = 0;
    for(auto i:arr){
        maxDeadline = max(maxDeadline, i.deadline);
    }
    // create a slot array
    vector<int> slotArr(maxDeadline+1, -1);
    // Finding Total profit
    int totalProfit = 0;

    for(auto i: arr){
        for(int j=i.deadline; j>0; j--){
            if(slotArr[j] == -1){
                slotArr[j] = i.id; // i ---> job
                totalProfit += i.profit;
                break;
            }
        }
    }
    for(int i=1; i<=maxDeadline; i++){
        if(slotArr[i] != -1){
            cout<<slotArr[i]<< " "; 
        }
    }
    cout<< endl <<"Total Profit: "<< totalProfit << endl;
}
int main(){

    // vector<Job> jobs = {
    //     {1,2,100},
    //     {2,1,19},
    //     {3,2,27},
    //     {4,1,25},
    //     {5,3,15}
    // };
     
    int n;
    int id;
    int deadline;
    int profit;
    cin>>n;
    vector<Job> jobs(n);
    for(int i=0; i<n; i++){
        cin>>id>>deadline>>profit;
        jobs[i].id = id;
        jobs[i].deadline = deadline;
        jobs[i].profit = profit;        
    }
    jobScheduling(jobs);
}