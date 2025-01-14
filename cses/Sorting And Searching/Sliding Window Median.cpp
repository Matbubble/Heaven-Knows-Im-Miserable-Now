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

priority_queue<long long>ll;
priority_queue<long long, vector<long long>, greater<long long>>rr;
long long  l, r;

void add(long long x){
    long long median=(ll.empty()?1e18:ll.top());
    if(x<=median){
        ll.push(x); l+=x;
    }else{
        rr.push(x); r+=x;
    }
    if((long long)rr.size()+1<(long long)ll.size()){
        long long next=ll.top();
        ll.pop();
        rr.push(next);
        l-=next;
        r+=next;
    }else if((long long)rr.size()>(long long)ll.size()){
        long long next=rr.top();
        rr.pop();
        ll.push(next);
        r-=next;
        l+=next;
    }
}
const long long maxN=1e5;
long long pref[maxN+1];

void solve(){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}