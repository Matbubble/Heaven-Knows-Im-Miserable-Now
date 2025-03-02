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

struct fentree{
    long long n;
    vector<long long>ft;
    fentree(long long n):n(n), ft(n+1){}
    void add(long long posi, long long val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }
    long long querie(long long posi){
        long long res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
};

void solve(){
    long long n; cin>>n;
    vector<long long>v(n);
    set<long long>cast;
    map<long long, long long>mp;
    for(long long &x:v){
        cin>>x;
        cast.insert(x);
    }
    long long posi=1;
    for(long long x:cast) mp[x]=posi++;
    vector<long long>aux;
    fentree one((long long)cast.size()), two((long long)cast.size());
    for(long long i=n-1 ; i>=0 ; i--){
        one.add(mp[v[i]], 1);
        aux.push_back(one.querie(mp[v[i]]-1));
    }
    reverse(aux.begin(), aux.end());
    long long ans=0;
    for(long long i=n-1 ; i>=0 ; i--){
        two.add(mp[v[i]], aux[i]);
        ans+=two.querie(mp[v[i]]-1);
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