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
    int n, m; cin>>n>>m;
    vector<vector<int>>mat(n, vector<int>(m+1));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>mat[i][j];
    }
    vector<int>steps((n*m)*2);
    auto vecinos = [&](pair<int, int>a, pair<int, int>b){
        return (abs(a.first-b.first)+abs(a.second-b.second))==1;
    };
    for(int num=1 ; num<=n*m ; num++){
        vector<pair<int, int>>vp;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==num) vp.push_back({i, j});
            }
        }
        vector<vector<pair<int, int>>>xd;
        for(auto it:vp){
            if(xd.empty()){
                vector<pair<int, int>>aux;
                aux.push_back(it);
                xd.push_back(aux);
            }else{
                bool encontre=0;
                for(auto &v:xd){
                    bool ok=1;
                    for(pair<int, int>a:v){
                        if(vecinos(a, it)){
                            ok=0;
                            break;
                        }
                    }
                    if(ok){
                        encontre=1;
                        v.push_back(it);
                    }
                    if(encontre) break;
                }
                if(!encontre) {
                    vector<pair<int, int>>aux;
                    aux.push_back(it);
                    xd.push_back(aux);
                }
            }
        }
        steps[num]=xd.size();
    }
    int ans=0;
    int maxi=0;
    for(int i=1 ; i<=n*m ; i++){
        ans+=steps[i];
        maxi=max(maxi, steps[i]);
    }
    cout<<ans-maxi<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}