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
    int n=0, s=0, e=0, w=0;
    int N; cin>>N;
    string S; cin>>S;
    for(char ch:S){
        if(ch=='N') n++;
        if(ch=='S') s++;
        if(ch=='W') w++;
        if(ch=='E') e++;
    }
    if((max(n, s)-min(n, s))%2==0 && (max(w, e)-min(w, e))%2==0){
        map<char, int>freq;
        if(s>=n){
            int need=(s-n)/2;
            freq['N']=n;
            freq['S']=n+need;
        }else{
            int need=(n-s)/2;
            freq['S']=s;
            freq['N']=s+need;
        }
        if(w>=e){
            int need=(w-e)/2;
            freq['E']=e;
            freq['W']=e+need;
        }else{
            int need=(e-w)/2;
            freq['W']=w;
            freq['E']=w+need;
        }
        string ans="";
        for(char ch:S){
            if(freq[ch]>=1){
                ans+='R';
                freq[ch]--;
            }else ans+='H';
        }
        bool ok=0;
        for(int i=1 ; i<N ; i++){
            if(ans[i]!=ans[0]) ok=1;
        }
        if(ok) cout<<ans<<"\n";
        else{
            int one=-1, two=-1;
            for(int i=0 ; i<N ; i++){
                if(S[i]=='W') one=i;
                if(S[i]=='E') two=i;
            }
            if(one>=0 && two>=0){
                ans[one]='H'; ans[two]='H';
                bool use=0;
                for(int i=1 ; i<N ; i++){
                    if(ans[i]!=ans[0]) use=1;
                }
                if(use){
                    cout<<ans<<"\n";
                    return;
                }
                
            }
            one=two=-1;
            for(int i=0 ; i<N ; i++){
                if(S[i]=='S') one=i;
                if(S[i]=='N') two=i;
            }
            if(one>=0 && two>=0){
                ans[one]='H'; ans[two]='H';
                bool use=0;
                for(int i=1 ; i<N ; i++){
                    if(ans[i]!=ans[0]) use=1;
                }
                if(use){
                    cout<<ans<<"\n";
                    return;
                }
            }
            cout<<"NO\n";
        }
    }else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}