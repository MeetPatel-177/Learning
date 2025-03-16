#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        //allowed moves of knight in any one direction
        int a,b;
        cin >> a >> b;
        //coordinates of king
        int xk,yk;
        cin >> xk >> yk;
        //coordinates of queen
        int xq,yq;
        cin >> xq >> yq;
        //always initialise direction like this remember it
        vector<int>dx = {-1,1,-1,1};
        vector<int>dy = {-1,-1,1,1};
        //this will store at which which position knight can hit king and queen
        //we know that there will be exxactly 8 positions for both king and queen
        //why we store it in set data structure
        //we will have only 4 different positions if we have (a==b) 
        //so set will make sure that no one element is duplicate
        set<pair<int,int>>king_hits, queen_hits;
        //we will iterate 4 times so that every direction we can consider
        for(int i=0; i<4; i++) {
            //8 positions will be inserted into set for king
            king_hits.insert({xk+dx[i]*a, yk+dy[i]*b});
            king_hits.insert({xk+dx[i]*b, yk+dy[i]*a});
            //8 positions will be inserted into set for queen
            queen_hits.insert({xq+dx[i]*a, yq+dy[i]*b});
            queen_hits.insert({xq+dx[i]*b, yq+dy[i]*a});
        }
        int ans = 0;
        //this will check if both has any common position
        for(auto position : king_hits) {
            if(queen_hits.find(position) != queen_hits.end()) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}