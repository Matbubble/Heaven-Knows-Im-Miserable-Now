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

void solve(){
    string a, b; cin>>a>>b;
    int tam=1e9, l=-1, r=-1;
    map<char, int>posi;
    for(int i=0 ; i<(int)b.size()-1 ; i++) posi[b[i]]=i+1;
    for(int i=1 ; i<(int)a.size() ; i++){
        int curr=posi[a[i]];
        if(curr==0 || curr==(int)b.size()) continue;
        if(i+1+(int)b.size()-curr+1<tam){
            tam=i+1+(int)b.size()-curr+1;
            l=i; r=curr-1;
        }
    }
    if(tam==1e9) cout<<-1<<"\n";
    else{
        if(a[l]==b[r]) r++;
        for(int i=0 ; i<=l ; i++) cout<<a[i];
        for(int i=r ; i<(int)b.size() ; i++) cout<<b[i];
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}