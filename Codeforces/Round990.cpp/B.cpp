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
Lagrimas tres
*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int>freq(27);
    int change=0;
    for(char ch:s) freq[ch-'a']++;
    int maxi=0, temp=0;
    int mini=1000, temp1=0;
    for(int i=0 ; i<27 ; i++){
        if(freq[i]>maxi){
            maxi=freq[i];
            temp=i;
        }
        // if(freq)
        if(freq[i]<=mini){
            dbg(i+'a')
            mini=freq[i];
            temp1=i;
        }
    }
    dbg(temp1)
    s[temp1]=(char)(temp+'a');
    cout<<s<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}