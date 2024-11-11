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
Aun es legal bro uuuu
*/

void solve(){
    int n, m, ans=0; cin>>n>>m;
    char lab[n][m];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    pair<int, int>a, b, c, d;
    a=make_pair(0, 0);
    b=make_pair(0, m-1);
    c=make_pair(n-1, m-1);
    d=make_pair(n-1, 0);
    int move=0, l=0, r=-1;
    deque<char>dq, aux;
    while(1){
        if(move==1){
            r++;
            dq.push_back(lab[l][r]);
            if(r==b.second) move++;
        }else if(move==2){
            l++;
            if(l>c.first) l--;
            else dq.push_back(lab[l][r]);
            if(l==c.first) move++;
        }else if(move==3){
            r--;
            if(r<d.second) r++;
            else dq.push_back(lab[l][r]);
            if(r==d.second) move++;
        }else if(move==4){
            l--;
            if(l==a.first) move++;
        }else if(move==5){
            r++;
            dq.push_back(lab[l][r]);
            if(r==b.second) move++;
        }else if(move==6){
            {
                a.first=a.first+1;
                a.second=a.second+1;
            }
            {
                b.first=b.first+1;
                b.second=b.second-1;
            }
            {
                c.first=c.first-1;
                c.second=c.second-1;
            }
            {
                d.first=d.first-1;
                d.second=d.second+1;
            }
            if(a.second>b.second || a.first>d.first || c.second<d.second || c.first<b.first){
                cout<<ans<<"\n";
                return;
            }
            l=a.first;
            r=a.second-1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}