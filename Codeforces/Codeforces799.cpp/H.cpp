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
Creep
Radiohead
*/

void solve(){
    int n; cin>>n;
    map<int, vector<int>>freq;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux].push_back(i);
    }
    int ans=0, ansl=0, ansr=0, auxl=0, num=0;
    for(auto it:freq){
        vector<int>v=it.second;
        //kadane's algorithm
        int sum=0;
        auxl=v[0];
        for(int i=0 ; i<(int)v.size() ; i++){
            sum++;
            if(i>0) sum-=v[i]-v[i-1]-1;
            if(sum<=0){
                sum=1;
                auxl=v[i];
            }else{
                if(sum>ans){
                    num=it.first;
                    ans=sum;
                    ansr=v[i];
                    ansl=auxl;
                }
            }
        }
    }
    cout<<num<<" "<<ansl+1<<" "<<ansr+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}