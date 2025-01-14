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
Desenlace
Enjambre
*/

void solve(){
    int n; cin>>n;
    char lab[2][n];
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<n ; j++) cin>>lab[i][j];
    }
    bool unique=1;
    for(int i=0 ; i<n ; i++){
        if(lab[0][i]=='#' && lab[1][i]=='#') continue;
        if(lab[0][i]=='.' && lab[1][i]=='.'){
            if(i<n-1){
                if(lab[0][i+1]=='.' && lab[1][i+1]=='.'){
                    unique=0;
                    i++;
                }
            }
            continue;
        }
        if(lab[0][i]=='.'){
            if(i==n-1 || lab[0][i+1]=='#'){
                cout<<"None\n";
                return;
            }
            lab[0][i+1]='#';
        }
        if(lab[1][i]=='.'){
            if(i==n-1 || lab[1][i+1]=='#'){
                cout<<"None\n";
                return;
            }
            lab[1][i+1]='#';
        }
    }
    cout<<(unique?"Unique\n":"Multiple\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}