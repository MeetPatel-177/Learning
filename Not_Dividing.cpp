#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //here as we know that if we have 1 in our array
        //then it may create a problem for us because every number is divisible by 1
        //so we will modify 1 to 2 wherever we have 1 on our array
        //so this will make maximum n operation if all elements are 1
        for(int i=0; i<n; i++) {
            if(arr[i] == 1) arr[i] = 2;
        }
        //now since we don't have any 1 in our array so we just check for divsibility
        //if arr[i+1] is divisible by arr[i] then we will modify only arr[i+1]
        //so that after modification only second number modifies and previous number 
        //remains same and that will help us
        //so this will also take maximum n operations if all have 1 then all will be 2
        //and so that we have to modify all elements
        for(int i=0; i<n-1; i++) {
            if(arr[i+1] % arr[i] == 0) {
                arr[i+1] += 1;
            }
        }
        //so the total maximum operations will be n+n = 2n and that is given in question 
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}