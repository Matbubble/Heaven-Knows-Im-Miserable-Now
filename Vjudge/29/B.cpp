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
uwuwu
*/

void solve(){
    long long n, ans=999; cin>>n;
    vector<long long>mult, aux;
    for(long long i=1 ; i<=9 ; i++){
        aux.push_back(n*i);
        mult.push_back(n*i);
    }
    for(long long x:aux){
        long long curr=0;
        while(1){
            long long unit=x%10; x/=10;
            long long mini=unit, extra=0;
            bool ok=0;
            for(long long y:mult){
                long long nuum=(x*10)+unit;
                if(nuum+y==nuum*10) continue;
                long long one=y%10;
                if(x<=0){
                    long long temp=y+unit;
                    long long res=0;
                    while(temp>0){
                        res+=temp%10; temp/=10;
                    }
                    if(res<mini){
                        ok=1;
                        mini=(one+unit)%10;
                        extra=(one+unit)/10;
                    }
                }else if((y+unit)%10<mini){
                    dbg(123)
                    ok=1;
                    mini=(y+unit)%10;
                    extra=(y+unit)/10;
                }
            }
            curr+=mini;
            if(!ok && x<=0) break;
            x+=extra;
            dbg(x)
            dbg(curr)
        }
        dbg(curr)
        ans=min(ans, curr);
        break;
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