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
const long long maxN=2e5;
long long tree[maxN+1];

void add(long long posi, long long tam){
    while(posi<=tam){
        tree[posi]++;
        posi+=posi&-posi;
    }
}

long long querie(long long posi){
    long long res=0;
    while(posi>0){
        res+=tree[posi];
        posi-=posi&-posi;
    }
    return res;
}

void solve(){
    long long n; cin>>n;
    vector<long long>a(n), b(n);
    set<long long>cast;
    map<long long, long long>mp;
    for(long long &x:a){
        cin>>x;
        cast.insert(x);
    }
    for(long long &x:b){
        cin>>x;
        cast.insert(x);
    }
    long long posi=1;
    for(long long x:cast) mp[x]=posi++;
    for(long long &x:a) x=mp[x];
    for(long long &x:b) x=mp[x];
    vector<long long>auxa=a, auxb=b;
    sort(auxa.begin(), auxa.end());
    sort(auxb.begin(), auxb.end());
    bool ok=1;
    for(long long i=0 ; i<n ; i++) ok&=(auxa[i]==auxb[i]);
    n=max(auxa.back(), auxb.back());
    if(ok){
        for(long long i=0 ; i<=n ; i++) tree[i]=0;
        long long one=0;
        for(long long x:a){
            one+=querie(x);
            add(x, n);
        }
        for(long long i=0 ; i<=n ; i++) tree[i]=0;
        long long two=0;
        for(long long x:b){
            two+=querie(x);
            add(x, n);
        }
        if(one%2==two%2) cout<<"YES\n";
        else cout<<"NO\n";
    }else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}