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
One more hour
Tame Impala
*/



void solve(){
    int n; cin>>n;
    string s; cin>>s;
    string vowel="aeiou";
    map<char, set<int>>c;
    for(int i=0 ; i<n ; i++) c[s[i]].insert(i);
    vector<int>last(n), mat(n), real(n);
    vector<vector<int>>posi;
    vector<bool>vis(n);
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            last[i]=-1;
            int auxi=i;
            real;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}