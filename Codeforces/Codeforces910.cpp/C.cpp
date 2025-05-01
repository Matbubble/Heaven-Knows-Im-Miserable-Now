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
    int n, m, k; cin>>n>>m>>k;
    {
        int dis=n+m-2;
        if(k-dis>0){
            if((k-dis)%4==0){
                cout<<"YES\n";
                for(int i=0 ; i<n ; i++){
                    for(int j=0 ; j<m-1 ; j++){
                        if(j&1) cout<<"R ";
                        else cout<<"B ";
                    }
                    cout<<"\n";
                }
                for(int i=0 ; i<n-1 ; i++){
                    for(int j=0 ; j<m ; j++){
                        if(m&1){
                            if(i&1) cout<<"R ";
                            else cout<<"B ";
                        }else{
                            if(!(i&1)) cout<<"R ";
                            else cout<<"B ";
                        }
                    }
                    cout<<"\n";
                }
                return;
            }
        }
    }
    {
        int dis=n+m-3;
        if(k-dis>0){
            if((k-dis)%4==3){
                cout<<"YES\n";
                for(int i=0 ; i<n ; i++){
                    for(int j=0 ; j<m-1 ; j++){
                        if(i==0 && j==0){
                            cout<<"R ";
                        }else if(i==1 && j==0){
                            cout<<"R ";
                        }else if(j&1) cout<<"R ";
                        else cout<<"B ";
                    }
                    cout<<"\n";
                }
                for(int i=0 ; i<n-1 ; i++){
                    for(int j=0 ; j<m ; j++){
                        if(i==0 && j<=1) cout<<"B ";
                        else if(m&1){
                            if(i&1) cout<<"R ";
                            else cout<<"B ";
                        }else{
                            if(!(i&1)) cout<<"R ";
                            else cout<<"B ";
                        }
                    }
                    cout<<"\n";
                }
                return;
            }
        }
    }
    {
        int dis=n+m-4;
        if(k-dis>0){
            if((k-dis)%4==2){
                cout<<"YES\n";
                for(int i=0 ; i<n ; i++){
                    for(int j=0 ; j<m-1 ; j++){
                        if(i==0 && j==0){
                            cout<<"R ";
                        }else if(i==1 && j==0){
                            cout<<"R ";
                        }else if(j&1) cout<<"R ";
                        else cout<<"B ";
                    }
                    cout<<"\n";
                }
                for(int i=0 ; i<n-1 ; i++){
                    for(int j=0 ; j<m ; j++){
                        if(i==0 && j<=1) cout<<"B ";
                        else if(m&1){
                            if(i&1) cout<<"B ";
                            else cout<<"R ";
                        }else{
                            if(!(i&1)) cout<<"B ";
                            else cout<<"R ";
                        }
                    }
                    cout<<"\n";
                }
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