// Problem source: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n){
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        pair<int, int> t = make_pair(start[i], end[i]);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    int count = 1;
    int endTime = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].first>endTime){
            count++;
            endTime = v[i].second;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int start[n], end[n];
    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n; i++) cin>>end[i];
    cout<<maxMeetings(start, end, n);
}