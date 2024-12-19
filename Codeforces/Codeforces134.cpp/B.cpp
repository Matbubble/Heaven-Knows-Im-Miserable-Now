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
Yo tomo
Bersuit Vergarabat
*/

void solve(){
    int n, r; cin>>n>>r;
    int sum=0, maxi=0;
    vector<int>f;
    for(int i=1 ; ; i++){
        if(i==1) f.push_back(1);
        else if(i==2) f.push_back(2);
        else f.push_back(f[i-2]+f[i-3]);
        sum+=((i+1)/2)-1;
        if(f.back()>=r){
            maxi=(int)f.size();
            break;
        }
    }
    if(n!=maxi || r<f.back()-sum){
        cout<<-1<<"\n";
        return;
    }
    vector<bool>use(maxi+1);
    int need=f.back()-r;
    int now=0;
    for(int i=3 ; i<=maxi ; i++){
        now=(i==3?1:f[i-4]);
        if(need>=now){
            need-=now;
            use[i]=1;
            if(need==0) break;
        }
    }
    int cur=0;
    string ans;
    ans+='T';
    for(int i=2 ; i<=maxi ; i++){
        // dbg(use[i])
        // dbg(i)
        if(!use[i]) ans+=(ans.back()=='T'?'B':'T');
        else{
            ans+=ans.back();
            cur++;
        }
    }
    cout<<cur<<"\n";
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}