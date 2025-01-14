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
Tu misterioso alguien
Miranda!
*/

const int maxN=3e5;
using T=pair<long long, long long>;
T dp[maxN+1][41];
bool take[maxN+1][41];
long long last1[maxN+1], last0[maxN+1];


void solve(){
    int n; cin>>n;
    vector<long long>v(n);
    for(long long i=0 ; i<=n ; i++) last0[i]=last1[i]=-1;
    for(long long &x:v) cin>>x;

    sort(v.begin(), v.end());
    long long ansxor=0, ansor=0;
    for(long long i=0 ; i<41 ; i++){
        long long zero=0, one=0;
        long long tot0=0, tot1=0;
        vector<T>mp(45), np(45);
        for(int j=0 ; j<n ; j++){
            long long x=v[j];
            long long bit=((x>>i)&(1ll));
            if(bit==0){
                zero++;
            }
            else one++;
            dbg(i)
            dbg(last0[j])
            
            if(bit==1){
                mp[last0[j]+1].second++;
                if(last1[j]>=0) np[last1[j]].second++;
            }
            else{
                mp[last0[j]+1].first++;
                if(last1[j]>=0) np[last1[j]].first++;
            }
            dbg(bit)
            long long no0=0, no1=0;
            long long aux0=zero, aux1=one;
            long long k;
            for(k=i-1 ; k>=0 ; k--){
                long long last=((x>>k)&1ll);
                if(last==1){
                    no0+=np[k].first;
                    no1+=np[k].second;
                }else break;
            }
            for(k=k ; k>=0 ; k--){
                long long last=((x>>k)&1ll);
                if(last==1){
                    no0+=mp[k].first;
                    no1+=mp[k].second;
                }
            }
            aux0-=no0; aux1+=no0;
            aux1-=no1; aux0+=no1;
            if(bit==1){
                swap(aux0, aux1);
                last1[j]=i;
            }else last0[j]=i;
            dbg(no1)
            dbg(no0)
            dbg(aux0)
            dbg(aux1)
            dbg("----")
            tot0+=aux0; tot1+=aux1;
        }
        dbg(tot1)
        if((tot1&1)) ansxor+=(1ll<<i);
        if(tot1>0) ansor+=(1ll<<i);
    }
    cout<<ansxor<<" "<<ansor<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}