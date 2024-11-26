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
Chiquitita tell me the truth
*/

void solve(){
    long long n, ans=0; cin>>n;
    for(int i=1 ; i<n ; i++){
        long long aux; cin>>aux;
        ans+=aux;
    }
    cout<<(n*(n+1)/2)-ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     solve();
    return 0;
}