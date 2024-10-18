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
typedef long long ll;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";
 
/*
Who will dry your eyes?
*/
 
void solve(){
    long long n, cc=0; cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        long long aux; cin>>aux;
        cc+=aux;
    }
    cout<<(n*(n+1)/2)-cc<<"\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //test cases
    solve();
    return 0;
}