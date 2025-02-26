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

vector<int>v;
const int maxN=101;
int dp[maxN+1][maxN+1];

int dq(int l, int r){
    int auxi=1e9;
    bool ok=1;
    for(int i=l ; i<=r ; i++) ok&=(v[i]==v[l]);
    if(ok){
        dp[l][r]=1;
        return 1;
    }
    //case 1
    for(int i=l ; i<r ; i++){
        int a=(dp[l][i]==-1?dq(l, i):dp[l][i]);
        int b=(dp[i+1][r]==-1?dq(i+1, r):dp[i+1][r]);
        auxi=min(auxi, a+b);
    }
    //case 2
    for(int i=l ; i<r-1 ; i++){
        for(int j=i+1 ; j<r ; j++){
            int a=(dp[l][i]==-1?dq(l, i):dp[l][i]);
            int b=(dp[i+1][j]==-1?dq(i+1, j):dp[i+1][j]);
            int c=(dp[j+1][r]==-1?dq(j+1, r):dp[j+1][r]);
            auxi=min(auxi, a+b+c);
        }
    }
    int n=r-l+1;
    for(int div=1 ; div<n ; div++){
        if(n%div==0){
            ok=1;
            vector<int>temp;
            for(int i=l ; i<l+div ; i++){
                temp.push_back(v[i]);
            }
            for(int i=0 ; i<n ; i++){
                if(temp[i%div]==v[l+i]) ok=1;
                else{
                    ok=0;
                    break;
                }
            }
            if(ok){
                int a=(dp[l][l+div-1]==-1?dq(l, l+div-1):dp[l][l+div-1]);
                auxi=min(auxi, a);
            }
        }
    }
    return dp[l][r]=auxi;
}

void solve(){
    v.clear();
    for(int i=0 ; i<=maxN ; i++){
        for(int j=0 ; j<=maxN ; j++) dp[i][j]=-1;
    }
    int n, k; cin>>n>>k;
    v.push_back(0);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        v.push_back(aux);
    }
    int ans=dq(1, n);
    if(ans<=k) cout<<"YES\n";
    else cout<<"NO\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}