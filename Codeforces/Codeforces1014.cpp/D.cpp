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

int maxi=0;
int freq[3];
vector<int>ans;
bool ok=0;
int n;
map<string, bool>mp;

void backtrack(string s, vector<int>paso){
    if(ok || mp[s]) return;
    mp[s]=1;
    freq[0]=freq[1]=freq[2]=0;
    for(char ch:s){
        if(ch=='L') freq[0]++;
        if(ch=='I') freq[1]++;
        if(ch=='T') freq[2]++;
    }
    if(freq[0]==freq[1] && freq[1]==freq[2]){
        ok=1;
        swap(paso, ans);
        return;
    }
    if(freq[1]>n || freq[2]>n || freq[0]>n) return;
    vector<int>aux=paso;
    string nuevo;
    for(int i=0 ; i<(int)s.size()-1 ; i++){
        nuevo+=s[i];
        if(s[i]!=s[i+1]){
            string curr=nuevo;
            char one=min(s[i], s[i+1]), two=max(s[i], s[i+1]);
            aux.push_back(i+1);
            if(one=='I' && two=='L'){
                nuevo+='T';
                for(int j=i+1 ; j<(int)s.size() ; j++){
                    nuevo+=s[j];
                }
            }
            if(one=='I' && two=='T'){
                nuevo+='L';
                for(int j=i+1 ; j<(int)s.size() ; j++){
                    nuevo+=s[j];
                }
            }
            if(one=='L' && two=='T'){
                nuevo+='I';
                for(int j=i+1; j<(int)s.size() ; j++){
                    nuevo+=s[j];
                }
            }
            backtrack(nuevo, aux);
            aux.pop_back();
            swap(curr, nuevo);
        }
    }
}

void solve(){
    ans.clear();
    freq[0]=freq[1]=freq[2]=0;
    maxi=0;
    ok=0;
    mp.clear();
    cin>>n;
    string s; cin>>s;
    for(char ch:s){
        if(ch=='L') freq[0]++;
        if(ch=='I') freq[1]++;
        if(ch=='T') freq[2]++;
    }
    if(freq[0]==freq[1] && freq[1]==freq[2]){
        cout<<0<<"\n";
        return;
    }
    maxi=max({freq[0], freq[1], freq[2]});
    vector<int>xd;
    backtrack(s, xd);
    if(ans.empty()) cout<<-1<<"\n";
    else{
        cout<<(int)ans.size()<<"\n";
        for(int x:ans) cout<<x<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}