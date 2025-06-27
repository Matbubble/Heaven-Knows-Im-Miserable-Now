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
    int n, q; cin>>n>>q;
    string s; cin>>s;
    map<pair<char, char>, set<int>>mp;
    for(int i=0 ; i<q ; i++){
        char x, y; cin>>x>>y;
        mp[{x, y}].insert(i);
    }
    for(int i=0 ; i<n ; i++){
        if(s[i]=='a') continue;
        else if(s[i]=='c'){
            if(!mp[{'c', 'a'}].empty()){
                s[i]='a';
                mp[{'c', 'a'}].erase(mp[{'c', 'a'}].begin());
            }else{
                //caso 1
                if(!mp[{'c', 'b'}].empty()){
                    int posiInit=(*mp[{'c', 'b'}].begin());
                    s[i]='b';
                    mp[{'c', 'b'}].erase(posiInit);
                    // dbg(posiInit)
                    if(!mp[{'b', 'a'}].empty()){
                        auto it=mp[{'b', 'a'}].lower_bound(posiInit);
                        // dbg(i)
                        // if(it==mp[{'b', 'a'}].end()) dbg(int(*mp[{'b', 'a'}].begin()))
                        if(it!=mp[{'b', 'a'}].end()){
                            // dbg("123123123123")
                            s[i]='a';
                            mp[{'b', 'a'}].erase(it);
                        }
                        // dbg(s)
                    }
                }
            }
        }else if(s[i]=='b'){
            if(!mp[{'b', 'a'}].empty()){
                s[i]='a';
                mp[{'b', 'a'}].erase(mp[{'b', 'a'}].begin());
            }else{
                //caso 1
                if(!mp[{'b', 'c'}].empty()){
                    int posiInit=(*mp[{'b', 'c'}].begin());
                    if(!mp[{'c', 'a'}].empty()){
                        auto it=mp[{'c', 'a'}].lower_bound(posiInit);
                        if(it!=mp[{'c', 'a'}].end()){
                            s[i]='a';
                            mp[{'c', 'a'}].erase(it);
                            mp[{'b', 'c'}].erase(posiInit);
                        }
                    }
                }
                
            }
        }
        // dbg(s)
    }
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