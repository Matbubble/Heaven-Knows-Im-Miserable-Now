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

//Calcula la respuesta MODULO 1e9+7

const long long MOD=1e9+7;
vector<vector<int>>padres;
vector<vector<int>>graph;
int timer=0;
vector<int>Tin, Tout;
int n;

void dfs(int v, int root){
    Tin[v]=++timer;
    padres[v][0]=root;
    for(int i=1 ; i<=log(n) ; i++){
        padres[v][i]=padres[padres[v][i-1]][i-1];
    }
    for(int u:graph[v]){
        if(u==root) continue;
        dfs(u, v); 
    }

    Tout[v]=++timer;
}

bool is_ancestor(int a, int b){
    return Tin[a]<=Tin[b] && Tout[a]>=Tout[b];
}


void solve(){
    cin>>n;
    for(int i=1 ; i<=n-1 ; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}