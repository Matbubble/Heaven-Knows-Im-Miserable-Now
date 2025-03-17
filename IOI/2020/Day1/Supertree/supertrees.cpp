#include "supertrees.h"
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> answer;
set<int>ilegal;
vector<bool>vis;
int n;
vector<vector<int>>xd;
bool dfs(int u){
	vis[u]=1;
	for(int j=0 ; j<n ; j++){
		if(xd[u][j]==0) ilegal.insert(j);
		else if(ilegal.count(j)) return false;
	}
	int cont=0;
	for(int j=0 ; j<n ; j++){
		cont+=xd[u][j]==2;
	}
	if(cont==1) return false;
	for(int j=0 ; j<n ; j++){
		if(xd[u][j]==0 || xd[u][j]==1 || vis[j]) continue;
		answer[u][j]=1;
		answer[j][u]=1;
	}
	return true;
}

int construct(vector<vector<int>>p) {
	n = p.size();
	vis.resize(n);
	answer.resize(n, vector<int>(n));
	xd.resize(n, vector<int>(n));
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++) xd[i][j]=p[i][j];
	}
	for(int i=0 ; i<n ; i++){
		ilegal.clear();
		bool ok=1;
		if(!vis[i]){
			ok&=dfs(i);
		}
		if(!ok) return 0;
	}
	build(answer);
	return 1;
}
