#include "comandos.h"
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

int longitud_maxima(int N, int K, vector<int> A) {
  set<int>cast;
  map<int, int>mp, freq;
  for(int i=0 ; i<N ; i++) cast.insert(A[i]);
  int posi=1;
  for(int x:cast) mp[x]=posi++;
  segtree st(posi+1);
  int ans=0;
  int l=0, r=0;
  freq[A[0]]++;
  st.update(mp[A[0]], freq[A[0]]);
  while(1){
    int now=st.querie(1, posi);
    if(now<=K){
      ans=max(ans, r-l+1);
      r++;
      if(r>=N) break;
      freq[A[r]]++;
      st.update(mp[A[r]], freq[A[r]]);
    }else{
      freq[A[l]]--;
      st.update(mp[A[l]], freq[A[l]]);
      l++;
    }
  }
  return ans;
}
