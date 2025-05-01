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

void solve(){
    string s; cin>>s;
    map<char, int>freq;
    for(int i=0 ; i<(int)s.size() ; i++) freq[s[i]]++;
    for(int i=0 ; i<(int)s.size() ; i++){
        for(int j=(int)s.size()-i-1 ; j<=9 ; j++){
            char xd=j+'0';
            if(freq[xd]>=1){
                cout<<xd;
                freq[xd]--;
                break;
            }
        }
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}