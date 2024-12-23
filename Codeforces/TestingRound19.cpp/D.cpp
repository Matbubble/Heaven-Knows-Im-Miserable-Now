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
A crying Diamond
Mon Laferte
*/

void solve(){
    string s; cin>>s;
    map<deque<char>, bool>freq;
    deque<char>a, b;
    int l=0, r=(int)s.size()-1;
    while(1){
        a.push_back(s[l]);
        b.push_front(s[r]);
        if(r<=l) break;
        l++;
        r--;
    }
    if(l==(int)s.size()-1){
        cout<<"NO\n";
        return;
    }
    freq[a]=1;
    if(freq[b]==1){
        cout<<"YES\n";
        for(char ch:b) cout<<ch;
        cout<<"\n";
        return;
    }
    freq.erase(a);
    for(int i=l+1 ; i<(int)s.size()-1 ; i++){
        freq.erase(a);
        a.push_back(s[i]);
        b.push_front(s[r-i+(l)]);
        freq[a]=1;
        if(freq[b]==1){
            cout<<"YES\n";
            for(char ch:b) cout<<ch;
            cout<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}