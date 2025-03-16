#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        //intuition :
        //let's take an example (n=990990 and [l,...,r] = [9,10,11])
        //so if we take [1,2,3] then 9%1 == 0 && 10%2 == 0 && 9%3 == 0
        //so if we have anywhere a length of (r-l+1) interval [l,l+1,l+2,...,r] then
        //we can replace it with [1,2,3,...,(r-l+1)] and we can calculate for this
        int i = 1;
        //this will keep track of max length of interval
        int max_len = 0;
        while(1) {
            //if anywhere the curr_num is not divisor of n that means our streak breaks
            //so we will just cout maxlen and break out from the loop
            if(n % i != 0) {
                cout << max_len << endl;
                break;
            }
            //this means it is a divisor of n so we will increment maxlen and i also
            else {
                max_len++;
                i++;
            }
        }
    }
    return 0;
}