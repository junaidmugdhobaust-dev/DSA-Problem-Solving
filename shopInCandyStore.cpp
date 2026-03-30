// problem source: https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1 

#include <bits/stdc++.h>
using namespace std;
vector<int> result(vector<int> candies, int n, int k){
    sort(candies.begin(), candies.end());
    int minimum = 0;
    int buy = 0;
    int free = n-1;
    while(buy <= free){
        minimum = minimum + candies[buy];
        buy++;
        free = free-k;
    }

    int maximum = 0;
    buy = n-1;
    free = 0;
    while(free<=buy){
        maximum = maximum + candies[buy];
        buy--;
        free = free + k;
    }

    vector<int> v;
    v.push_back(minimum);
    v.push_back(maximum);
    return v;
}
int main() {
    int n, k;
    cin>>n>>k;
    vector<int> candies;
    candies.resize(n);
    for(int i=0; i<n; i++) cin>>candies[i];
    vector<int> pair_min_max = result(candies, n, k);
    for(int i:pair_min_max) cout<<i<<" ";
    
    return 0;
}