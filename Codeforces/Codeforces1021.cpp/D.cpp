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


const long long MOD=1e9+7;
long long dirX[]={1, 0, -1, 0};
long long dirY[]={0, -1, 0, 1};
long long n, m;

bool in(long long x, long long y){
    return x>0 && y>0 && x<=n && y<=m;
}

void solve(){
    long long k; cin>>n>>m>>k;
    vector<vector<long long>>dp(n+1, vector<long long>(m+1));
    vector<vector<long long>>xd(n+1, vector<long long>(m+1, 1));
    vector<vector<long long>>pene(n+1, vector<long long>(m+1, 0));
    using T=pair<long long, long long>;
    vector<T>move(k+1);
    for(T &x:move){
        cin>>x.first>>x.second;
    }
    map<T, vector<T>>webos;
    for(long long i=0 ; i<k ; i++){
        long long dis=abs(move[i].first-move[i+1].first)+abs(move[i].second-move[i+1].second);
        if(dis==2){
            if(move[i].first==move[i+1].first){
                xd[move[i].first][(move[i].second+move[i+1].second)/2]=0;
                webos[{move[i].first, (move[i].second+move[i+1].second)/2}]={{move[i].first, move[i].second}, {move[i+1].first, move[i+1].second}};
            }
            if(move[i].second==move[i+1].second){
                xd[(move[i].first+move[i+1].first)/2][move[i].second]=0;
                webos[{(move[i].first+move[i+1].first)/2, move[i].second}]={{move[i].first, move[i].second}, {move[i+1].first, move[i+1].second}};
            }
            
        }
    }
    map<T, bool>xdd;
    dp[move[0].first][move[0].second]=1;
    vector<vector<long long>>nose(n+1, vector<long long>(m+1, 0));
    for(long long i=0 ; i<=k ; i++){
        long long a=move[i].first;
        long long b=move[i].second;
        for(long long j=0 ; j<4 ; j++){
            long long aa=a+dirX[j], bb=b+dirY[j];
            if(!in(aa, bb)) continue;
            if(dp[aa][bb]==0) continue;
            if(xdd[{aa, bb}]==0){
                continue;
            }
            nose[aa][bb]=1;
            if(xd[aa][bb]==0){
                if(webos[{aa, bb}][1]==make_pair(a, b)) dp[a][b]+=dp[aa][bb];
            }else dp[a][b]+=dp[aa][bb];
            dp[a][b]%=MOD;
            
            dp[aa][bb]=1;
        }
        xdd.clear();
        // dbg("---")
        // dbg(dp[a][b])
        // dbg(a)
        // dbg(b)
        // dbg(dp[a][b])
        if(i==k) break;
        long long dis=abs(move[i].first-move[i+1].first)+abs(move[i].second-move[i+1].second);
        if(dis<=1 || dis>=3){
            cout<<0<<"\n";
            return;
        }
        for(long long j=0 ; j<4 ; j++){
            long long aa=a+dirX[j], bb=b+dirY[j];
            if(!in(aa, bb)) continue;
            xdd[{aa, bb}]=1;
            if(nose[aa][bb]==0){
                dp[aa][bb]=dp[a][b];
                dp[aa][bb]%=MOD;
                // dbg(aa)
                // dbg(bb)
            }
        }
        // dbg("----")
    }
    // dbg(move[k].first)
    // dbg(move[k].second)
    cout<<(dp[move[k].first][move[k].second]%MOD)<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}