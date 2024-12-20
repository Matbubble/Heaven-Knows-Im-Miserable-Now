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
Shhhhh!
*/


const int maxN=2e5;
int hashi(string s){
    return s[0]*128 + s[1];
}
stack<int>g[maxN+1];
int in[maxN+1], out[maxN+1];

void solve(){
    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        string s; cin>>s;
        int a=hashi(s.substr(0, 2));
        int b=hashi(s.substr(1, 2));
        g[a].push(b);
        out[a]++;
        in[b]++;
    }
    int start=-1, end=-1;
    for(int i=0 ; i<=maxN ; i++){
        if(in[i]==out[i]) continue;
        if(abs(in[i]-out[i])>1){
            cout<<"NO\n";
            return;
        }
        if(in[i]-1==out[i]){
            if(end==-1) end=i;
            else{
                cout<<"NO\n";
                return;
            }
        }
        if(in[i]+1==out[i]){
            if(start==-1) start=i;
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    if(start==-1){
        for(int i=0 ; i<maxN ; i++){
            if(!g[i].empty()){
                start=i;
                break;
            }
        }
    }
    stack<int>st;
    vector<int>path;
    int at=start;
    st.push(at);
    // dbg(at)
    // dbg(hashi("bc"))
    while(1){
        if(g[at].empty()){
            path.push_back(st.top());
            // dbg(at)
            st.pop();
            if(!st.empty()) at=st.top();
            else break;
        }else{
            int to=g[at].top();
            g[at].pop();
            st.push(to);
            at=to;
        }
    }
    if((int)path.size()<n){
        cout<<"NO\n";
        return;
    }
    reverse(path.begin(), path.end());
    cout<<"YES\n";
    string ans="";
    for(int x:path){
        char a=x/128;
        char b=x%128;
        if(ans==""){
            ans+=a;
            ans+=b;
        }else ans+=b;
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