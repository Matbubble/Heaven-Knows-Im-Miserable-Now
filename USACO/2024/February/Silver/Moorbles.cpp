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

void solve(){
    long long n, m, k; cin>>n>>m>>k;
    using T=pair<long long, long long>;
    vector<T>v(m);
    for(long long i=0 ; i<m ; i++){
        for(long long j=0 ; j<k ; j++){
            long long aux; cin>>aux;
            if(aux&1ll) v[i].second=max(v[i].second, aux);
            else v[i].first=max(v[i].first, aux);
        }
    }
    long long now=n;
    string ans;
    vector<long long>dp(m+1);
    for(long long i=0 ; i<m ; i++){
        if(v[i].second==0) now+=v[i].first;
        else now-=v[i].second;
        dp[i+1]=now;
        ans+='0';
    }
    if(now<=0){
        for(long long i=m-1 ; i>=0 ; i--){
            long long aux=now;
            if(v[i].second==0) aux-=v[i].first;
            else aux+=v[i].second;
            if(v[i].first==0) aux+=v[i].second;
            aux-=v[i].first;
            if(aux>now){
                swap(now, aux);
                ans[i]='1';
            }
            if(now>0) break;
        }
    }
    if(now<=0) cout<<-1<<"\n";
    else{
        for(char ch:ans) cout<<(ch=='0'?"Even":"Odd")<<" ";
        cout<<"\n";
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