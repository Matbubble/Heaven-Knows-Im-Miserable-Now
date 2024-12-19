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
Give me give me
*/

void solve(){
    string s; cin>>s;
    int last=0;
    for(int i=0 ; i<(int)s.size() ; i++){
        if(s[i]=='0'){
            last=i;
            break;
        }
    }
    int size=(int)s.size()-last;
    string ans;
    for(int i=0 ; i<(int)s.size() ; i++) ans+='0';
    pair<int, int>bound;
    bound.first=bound.second=1;
    for(int i=0 ; i<=(int)s.size()-size ; i++){
        string aux="";
        if(s[i]=='1'){
            for(int j=i ; j<i+size ; j++){
                aux+=s[j];
            }
            string curr="";
            for(int j=0 ; j<(int)s.size() ; j++){
                if(j>=(int)s.size()-size){
                    int actual=j+size-(int)s.size();
                    if(s[j]=='0') curr+=(aux[actual]=='1'?'1':'0');
                    else curr+=(aux[actual]=='1'?'0':'1');
                }else curr+=s[j];
            }
            for(int j=0 ; j<(int)s.size() ; j++){
                if(ans[j]>curr[j]) break;
                if(ans[j]<curr[j]){
                    bound.first=i+1;
                    bound.second=i+size;
                    swap(ans, curr);
                    break;
                }
            }
        }
    }
    cout<<1<<" "<<(int)s.size()<<" "<<bound.first<<" "<<bound.second<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}