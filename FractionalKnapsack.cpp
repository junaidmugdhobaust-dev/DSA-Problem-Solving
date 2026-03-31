#include<bits/stdc++.h>
using namespace std;
struct Item{
    int id;
    double weight;
    double profit;
    double ratio;
};
bool cmp(Item a, Item b){
    return a.ratio>b.ratio;
}
void fractionalKnapsack(vector<Item> &items, double capacity){
    for(auto &item : items){
        item.ratio = item.profit/item.weight;
    }
    sort(items.begin(), items.end(), cmp);
    double totalProfit = 0.0;

    for(auto item : items){
        if(capacity>=item.weight){
            capacity -= item.weight;
            totalProfit += item.profit;

            cout<<"Item "<<item.id<< "(FULL)"<<endl;
        }
        else{
            totalProfit += capacity*item.ratio;
            cout<<"Item "<<item.id<< " (Fractional, weight taken = "<<capacity<<")"<<endl;
        }
        capacity = 0;
    }

    cout<<"Total Profit: "<<totalProfit<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<Item> items(n);
    
    for(int i=0; i<n; i++){
        int id,profit,weight;
        cin>>id>>profit>>weight;
        items[i].id = id;
        items[i].profit = profit;
        items[i].weight = weight;
        items[i].ratio = 0;
    }
    double capacity = 50.0;
    fractionalKnapsack(items, capacity);
}