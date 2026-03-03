#include <bits/stdc++.h>
using namespace std;
int findDistinctElements(vector<int> arr){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        bool isDistinct = false;
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                isDistinct = true;
                break;
            }
        }
        if(isDistinct == false) count++;
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findDistinctElements(arr);
    

    return 0;
}