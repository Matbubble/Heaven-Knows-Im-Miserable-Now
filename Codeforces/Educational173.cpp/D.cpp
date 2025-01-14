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
Vuela muy alto
Jerry Rivera
*/

long long gcd(long long a, long long b){
    return(b==0?a:gcd(b, a%b));
}
long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}

void solve(){
    long long l, r, g; cin>>l>>r>>g;
    long long right=(r/g)*g;
    long long left=((l+g-1)/g)*g;
    if(right<l || left>r){
        cout<<-1<<" "<<-1<<"\n";
        dbg(g)
    }else{
        long long diff=right-left;
        if(diff==0){
            if(right==g) cout<<right<<" "<<left<<"\n";
            else cout<<-1<<" "<<-1<<"\n";
        }else{
            if(diff==left && left!=g) right-=g;
            long long uwu=gcd(right, left);
            if(uwu!=g) right-=g;
            cout<<left<<" "<<right<<"\n";
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