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
Don
Miranda!
*/

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    vector<set<int>>num(3);
    vector<vector<int>>move(3);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        v[i]=aux;
    }
    for(int i=n-1 ; i>=0 ; i--){
        int aux=v[i];
        move[0].push_back(aux);
        num[0].insert(aux);
    }
    //first move
    using T=pair<int, int>;
    queue<T>ans;
    while(!move[0].empty()){
        int auxi=move[0].back();
        move[0].pop_back();
        num[0].erase(auxi);
        if(num[1].count(n)){
            ans.push({1, 3});
            move[2].push_back(auxi);
            num[2].insert(auxi);
        }else{
            ans.push({1, 2});
            move[1].push_back(auxi);
            num[1].insert(auxi);
        }
    }
    int now=n;
    while((int)move[0].size()<n){
        if(num[1].count(now)){
            while(1){
                int curr=move[1].back();
                move[1].pop_back();
                num[1].erase(curr);
                if(curr==now){
                    ans.push({2, 1});
                    move[0].push_back(curr);
                    num[0].insert(curr);
                    break;
                }else{
                    ans.push({2, 3});
                    move[2].push_back(curr);
                    num[2].insert(curr);
                }
            }
        }else{
            while(1){
                int curr=move[2].back();
                move[2].pop_back();
                num[2].erase(curr);
                if(curr==now){
                    ans.push({3, 1});
                    move[0].push_back(curr);
                    num[0].insert(curr);
                    break;
                }else{
                    ans.push({3, 2});
                    move[1].push_back(curr);
                    num[1].insert(curr);
                }
            }
        }
        now--;
    }
    cout<<(int)ans.size()<<"\n";
    while(!ans.empty()){
        auto [x, y]=ans.front();
        cout<<x<<" "<<y<<"\n";
        ans.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}