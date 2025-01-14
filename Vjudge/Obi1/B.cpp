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

void solve(long long n){
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    for(long long one=0 ; one<n-5 ; one++){
        for(long long two=one+1 ; two<n-4 ; two++){
            for(long long three=two+1 ; three<n-3 ; three++){
                for(long long four=three+1 ; four<n-2 ; four++){
                    for(long long five=four+1 ; five<n-1 ; five++){
                        for(long long six=five+1 ; six<n ; six++){
                            cout<<v[one]<<" "<<v[two]<<" "<<v[three]<<" "<<v[four]<<" "<<v[five]<<" "<<v[six]<<"\n";
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n; 
    bool f=0;
    while(cin>>n){
        if(n==0) break;
        if(f) cout<<"\n";
        if(!f) f=1;
        solve(n);
    }
    return 0;
}