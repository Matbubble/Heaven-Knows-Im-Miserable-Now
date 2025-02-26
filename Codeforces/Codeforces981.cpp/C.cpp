#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    vector<vector<int>>num(n, vector<int>(2));
    vector<vector<int>>dp(n, vector<int>(2));
    for(int i=0 ; i<n/2 ; i++){
        num[i][0]=v[i];
        num[i][1]=v[n-i-1];
        num[n-i-1][0]=v[n-i-1];
        num[n-i-1][1]=v[i];
    }
    for(int i=1 ; i<n/2 ; i++){
        //case 1
        int a=dp[i-1][0]+(num[i][0]==num[i-1][0]?1:0)+dp[n-i][0]+(num[n-i-1][0]==num[n-i][0]?1:0);
        int b=dp[i-1][1]+(num[i][0]==num[i-1][1]?1:0)+dp[n-i][1]+(num[n-i-1][0]==num[n-i][1]?1:0);
        dp[i][0]=min(a, b);
        //case 2
        a=dp[i-1][0]+(num[i][1]==num[i-1][0]?1:0)+dp[n-i][0]+(num[n-i-1][1]==num[n-i][0]?1:0);
        b=dp[i-1][1]+(num[i][1]==num[i-1][1]?1:0)+dp[n-i][1]+(num[n-i-1][1]==num[n-i][1]?1:0);
        dp[i][1]=min(a, b);
    }
    int aux=0;
    if(n%2==1){
        if(v[n/2]==v[n/2+1]) aux++;
        if(v[n/2]==v[n/2-1]) aux++;
    }else{
        if(v[n/2]==v[n/2-1]) aux++;
    }
    cout<<min(dp[n/2-1][0], dp[n/2-1][1])+aux<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}