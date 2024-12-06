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
I love DP
*/

void solve(){
    string s; cin>>s;
    long long sum=0;
    long long a=0, b=0;
    for(char ch:s){
        sum+=(ch-'0');
        if(ch=='2') a++;
        else if(ch=='3') b++;
    }
    sum%=9;
    long long aux=a;
    sum=9-sum;
    if(sum==0 || sum==9){
        cout<<"YES\n";
        return;
    }
    // dbg(sum)
    //caso 1
    long long need=-2;
    for(int i=0 ; i<=5 ; i++){
        if(aux>=0){
            need+=2;
            need%=9;
            aux--;
        }
        if(sum==need){
            cout<<"YES\n";
            return;
        }
    }
    //caso 2
    aux=a;
    if(b>=1){
        long long need=6-2;
        for(int i=0 ; i<=5 ; i++){
            if(aux>=0){
                need+=2;
                need%=9;
                aux--;
            }
            if(sum==need){
                cout<<"YES\n";
                return;
            }
        }
    }
    aux=a;
    //caso 3
    if(b>=2){
        long long need=3-2;
        for(int i=0 ; i<=5 ; i++){
            if(aux>=0){
                need+=2;
                need%=9;
                aux--;
            }
            
            if(sum==need){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}