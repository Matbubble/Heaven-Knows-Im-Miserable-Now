#include "naketami.h"
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

const int maxN=1e6;
int freq[maxN+1], dp[maxN+1], pref[maxN+1];
bool vis[maxN+1];

int gcd (int a, int b) {
  return b?gcd(b, a%b):a;
}

vector<int> portales_accesibles(int N, int K, vector<int> H) {
  vector<int> result(N);
  for(int i=0 ; i<N ; i++) freq[H[i]]++;
  for(int i=1 ; i<=maxN ; i++) pref[i]=pref[i-1]+freq[i];
  vis[1]=1;
  for(int i=0 ; i<N ; i++){
    if(K>=H[i]) continue;
    if(!vis[H[i]]){
      vis[H[i]]=1;
      int extra=1;
      while(1){
        int l=H[i]*extra+K;
        if(l>maxN) break;
        dp[l]+=freq[H[i]];
        extra++;
      }
    }
  }
  for(int i=0 ; i<N ; i++){
    result[i]=dp[H[i]];
    if(K>H[i]) result[i]=0;
    if(K==H[i]) result[i]=pref[maxN]-pref[H[i]];
  }
  return result;
}
