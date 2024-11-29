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
Matilin de Kate
*/

void solve(long long c, long long n){
    vector<long long>v(n), dp;
    vector<vector<long long> >freq(n);
    long long sum=0;
    for(long long &x:v){
        cin>>x;
        sum+=x;
        dp.push_back(sum%c);
        freq[sum%c].push_back((long long)dp.size()-1);
    }
    if(!freq[0].empty()){
        for(int i=0 ; i<=freq[0][0] ; i++) cout<<i+1<<" \n"[i==freq[0][0]];
        return;
    }else{
        // dbg(123)
        for(int i=1 ; i<n ; i++){
            if(freq[i].size()>=2){
                for(int j=freq[i][0]+1 ; j<=freq[i][1] ; j++){
                    cout<<j+1<<" \n"[j==freq[i][1]];
                }
                return;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c, n;
    while(cin>>c>>n){
        if(c==0) break;
        solve(c, n);
    }
    return 0;
}