#include <bits/stdc++.h>
using namespace std;
//when dealing with bigger values and specifically decimal values try to avoid using float
//and doubles the first thought should come to your mind is that just store it in float or 
//double type of variable but as values get bigger these both datatypes give precision errors
//so according to conditions try to always use integer or long long
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        //first possibility is : we multiply m with a so the sequence will be [am,b,c]
        //now to be an AP we have 2b = am+c so m = (2b-c)/a
        //second possibility is : we multiply m with b so the sequence will be [a,bm,c]
        //now to be an AP we have 2bm = a+c so m = (a+c)/2b
        //third possibility is : we multiply m with c so the sequence will be [a,b,cm]
        //now to be an AP we have 2b = a+cm so m = (2b-a)/c
        
        //first i thought to store all three possible values of m in float type variables
        //but it gets rejected due to precision errors as we have already seen that
        //as values get bigger double and float values generally give precision errors
        //so we will just check necessary conditions in int only and avoid using float
        //here first condition is for checking if m is positive or not
        //and second condition is for checking if m is perfect integer or not
        if((2*b - c) > 0 && (2*b - c)%a == 0) cout << "YES" << endl;
        else if((a + c) > 0 && (a + c)%(2*b) == 0) cout << "YES" << endl;
        else if((2*b - a) > 0 && (2*b - a)%c == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}