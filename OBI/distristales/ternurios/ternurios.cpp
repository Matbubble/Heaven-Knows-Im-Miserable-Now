#include "ternurios.h"
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

struct segtree{
  int n; 
  vector<int>st;
  segtree(int n):n(n), st(2*n){}
  void update(int posi, int val){
    for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=max(st[posi], st[posi^1]);
  }
  int querie(int l, int r){
    int res=0;
    for(l+=n, r+=n ; l<r ; l/=2, r/=2){
      if(l&1) res=max(res, st[l++]);
      if(r&1) res=max(res, st[--r]);
    }
    return res;
  }
};

int max_ternurios(int N, vector<int> T) {
  vector<int>v(N+1);
  segtree st(N+1);
  for(int i=1 ; i<=N ; i++){
    int now=T[i-1]+st.querie(1, i-1);
    st.update(i, now);
    // cout<<now<<"\n";
  }
  
  return st.querie(1, N+1);
}
