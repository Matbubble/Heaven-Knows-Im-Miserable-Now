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
Ingrataaaaa
*/

const long long maxN=6e5 + 10;
long long tree[maxN+1];
void add(long long posi, long long size){
    while(posi<=size){
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
    long long n, m; cin>>n>>m;
    for(long long i=0 ; i<=n+m ; i++) tree[i]=0;
    vector<long long>a(n), b(m);
    set<long long>cast;
    for(long long &x:a){
        cin>>x;
        cast.insert(x);
    }
    for(long long &x:b){
        cin>>x;
        cast.insert(x);
    }
    map<long long, long long>freq;
    long long actual=1;
    for(long long x:cast){
        freq[x]=actual;
        ++actual;
    }
    for(long long x:a) add(freq[x], n+m+5);
    // sort(b.begin(), b.end());
    long long useNow=0;
    vector<long long>ans;
    for(long long x:b){
        if(x>a[0]){
            // dbg(querie(freq[x]))
            // dbg(x)
            useNow=querie(freq[x]-1);
            ans.push_back(n-useNow+1);
        }else ans.push_back(1);
    }
    sort(ans.begin(), ans.end());
    // for(long long i=0 ; i<m ; i++) cout<<ans[i]<<" ";
    for(long long i=1 ; i<=m ; i++){
        long long mod=m%i;
        long long curr=0;
        for(long long j=m-1-mod ; j>=0 ; j-=i) curr+=ans[j];
        cout<<curr<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}