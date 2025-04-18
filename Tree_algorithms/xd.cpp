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

long long pot[61];

void init(){
    pot[0]=1;
    for(long long i=1 ; i<=60 ; i++) pot[i]=pot[i-1]*2;
}

long long cuadrante(long long n, long long x, long long y, long long&a, long long&b){
    a=x;
    b=y;
    long long one, two;
    long long mitad=pot[n-1];
    if(x<=mitad) one=0;
    else one=1;
    if(y<=mitad) two=0;
    else two=1;
    if(one==1){
        a-=mitad;
    }
    if(two==1){
        b-=mitad;
    }
    if(one==0 && two==0) return 0;
    if(one==1 && two==1) return 1;
    if(one==1 && two==0) return 2;
    return 3;
}

long long q1(long long n, long long x, long long y){
    long long a, b;
    long long val=cuadrante(n, x, y, a, b);
    if(n==1){
        return val+1;
    }
    return val*pot[2*n-2]+q1(n-1, a, b);
}

pair<long long, long long>ans;
void q2(long long n, long long val){
    for(long long i=1 ; i<=4 ; i++){
        if(val<=pot[2*n-2]*i){
            if(i==2){
                ans.first+=pot[n-1];
                ans.second+=pot[n-1];
            }
            if(i==3){
                ans.first+=pot[n-1];
            }
            if(i==4){
                ans.second+=pot[n-1];
            }
            q2(n-1, val-(i-1)*pot[2*n-2]);
            break;  
        }
    }
}



void solve(){
    long long n, q; cin>>n>>q;
    while(q--){
        string aux; cin>>aux;
        if(aux=="->"){
            long long x, y; cin>>x>>y;
            cout<<q1(n, x, y)<<"\n";
        }else{
            long long val; cin>>val;
            ans={0, 0};
            q2(n, val);
            cout<<ans.first+1<<" "<<ans.second+1<<"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}