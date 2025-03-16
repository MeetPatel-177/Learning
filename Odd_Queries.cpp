#include <bits/stdc++.h>
using namespace std;

//prefix sum
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,q;
        cin >> n >> q;
        vector<long long>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //we will first find prefix sum for every element of arr
        for(int i=1; i<n; i++) {
            arr[i] += arr[i-1];
        }
        //for every query
        while(q--) {
            long long l,r,k;
            cin >> l >> r >> k;
            long long deleting_sum,adding_sum,final_sum;
            //we have to delete the sum from l to r so below two lines are for that
            if(l != 1) deleting_sum = arr[r-1] - arr[l-2];
            else deleting_sum = arr[r-1];
            //then we have to make all the elements from l to r equal to k
            adding_sum = (r-l+1)*k;
            //arr[n-1] will be the total sum of all elements of arr 
            //final sum will be like below
            final_sum = arr[n-1] - deleting_sum + adding_sum;
            if(final_sum % 2 != 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}