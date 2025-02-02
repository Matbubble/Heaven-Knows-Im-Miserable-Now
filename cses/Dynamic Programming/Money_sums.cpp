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

const int maxN=1e5;
bool dp[maxN+1];

void solve(){
    int n, sum=0; cin>>n;
    vector<int>coins(n);
    for(int &x:coins){
        cin>>x;
        sum+=x;
    }
    dp[0]=1;
    for(int x:coins){
        for(int j=sum ; j>=0 ; j--){
            if(j-x<0) continue;
            dp[j]|=dp[j-x];
        }
    }
    vector<int>ans;
    for(int j=1 ; j<=sum ; j++){
        if(dp[j]==1) ans.push_back(j);
    }
    cout<<(int)ans.size()<<"\n";
    for(int x:ans) cout<<x<<" "; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}