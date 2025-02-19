#include "friend.h"
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

const int maxN=1001;
int dp[maxN+1];
vector<int>g[maxN+1];
vector<int>confi;

void dfs(int root, int v){
	bool leave=1;
	for(int u:g[v]){
		dfs(v, u);
		leave=0;
	}
	dp[v]=confi[v];
	int a=0, b=0;
	for(int u:g[v]){
		a+=dp[u];
		for(int vv:g[u]) b+=dp[vv];
	}
	// dp[v]+=max(dp[u], dp[v]);
}

int findSample(int n,int confidence[],int host[],int protocol[]){
	int ans=0;
	for(int i=0 ; i<n ; i++) confi.push_back(confidence[i]);
	for(int i=1 ; i<n ; i++){
		g[host[i]].push_back(i);
		g[i].push_back(host[i]);
	}
	dfs(-1, 0);
	return ans;
}
