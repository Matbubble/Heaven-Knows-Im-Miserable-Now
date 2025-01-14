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
Como tu
Leon Larregui
*/

void solve(){
    int n, m, k; cin>>n>>m>>k;
    char lab[n][m];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    int ans=0;
    for(int i=0 ; i<n ; i++){
        int aux=0;
        for(int j=0 ; j<m ; j++){
            if(lab[i][j]=='.') aux++;
            else{
                ans+=max(aux-k+1, 0);
                aux=0;
            }
        }
            ans+=max(aux-k+1, 0);
    }
    // dbg(ans)
    if(k>1){
        for(int i=0 ; i<m ; i++){
            int aux=0;
            for(int j=0 ; j<n ; j++){
                if(lab[j][i]=='.') aux++;
                else{
                    ans+=max(aux-k+1, 0);
                    aux=0;
                }
            }
                ans+=max(aux-k+1, 0);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}