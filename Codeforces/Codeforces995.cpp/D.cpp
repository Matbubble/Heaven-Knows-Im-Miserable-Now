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
Shut up and drive
Rihanna
*/
const int maxN=1e6;
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
    long long n, x, y, sum=0; cin>>n>>x>>y;
    vector<long long>v(n);
    set<long long>cast;
    map<long long, long long>posi;
    for(long long &x:v){
        cin>>x;
        cast.insert(x);
        sum+=x;
    }
    for(long long i=0 ; i<n ; i++){
        cast.insert(sum-v[i]);
        cast.insert(sum-v[i]-y);
        cast.insert(sum-v[i]-x);
    }
    long long now=1;
    for(long long x:cast){
        posi[x]=now++;
    }
    for(int i=0 ; i<=now ; i++) tree[i]=0;
    long long ans=0;
    for(long long i=n-1 ; i>=0 ; i--){
        sum-=v[i];
        if(sum>=x){
            long long low=sum-y, up=sum-x;
            ans+=querie(posi[max(up, low)])-querie(posi[min(up, low)]-1);
        }
        add(posi[v[i]], now);
        sum+=v[i];
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}