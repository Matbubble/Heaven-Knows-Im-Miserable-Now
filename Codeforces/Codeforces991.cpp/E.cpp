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
Grupo bryndis
*/

const int maxN=1e3;
int dp[maxN+5][maxN+5];
string a, b,c;

int recursive(int x, int y, int z){
    if(z==(int)c.size()){
        return dp[x][y]=0;
    }
    if(dp[x][y]!=1e9) return dp[x][y];
    int curr1=1e9, curr2=1e9;
    if(x<(int)a.size()){
        if(a[x]==c[z]) curr1=recursive(x+1, y, z+1);
        else curr1=1+recursive(x+1, y, z+1);
    }
    if(y<(int)b.size()){
        if(b[y]==c[z]) curr2=recursive(x, y+1, z+1);
        else curr2=1+recursive(x, y+1, z+1);
    }
    return dp[x][y]=min(curr1, curr2);
}

void solve(){
    cin>>a>>b>>c;
    for(int i=0 ; i<=(int)a.size() ; i++){
        for(int j=0 ; j<=(int)b.size() ; j++) dp[i][j]=1e9;
    }
    cout<<recursive(0, 0, 0)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}