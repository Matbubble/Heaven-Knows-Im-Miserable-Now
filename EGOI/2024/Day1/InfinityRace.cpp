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
Seventh Heaven
INOHA
*/

void solve(){
    long long n, q; cin>>n>>q;
    set<long long>aux;
    long long ans=0;
    for(long long i=0 ; i<q ; i++){
        long long curr; cin>>curr;
        if(curr<0){
            curr=-curr;
            aux.erase(curr);
        }else{
            if(aux.count(curr)){
                ans++;
                aux.clear();
                aux.insert(curr);
            }else aux.insert(curr);
        }
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