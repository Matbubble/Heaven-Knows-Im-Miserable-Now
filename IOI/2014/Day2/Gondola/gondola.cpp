#include "gondola.h"
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
#include <cassert>
#define dbg(x) cerr<<#x<<": "<<x<<"\n";
using namespace std;

int valid(int n, int inputSeq[])
{
  vector<int>extra;
  set<int>freq;
  for(int i=0 ; i<n ; i++){
    int curr=inputSeq[i], next=inputSeq[(i+1)%n];
    if(freq.count(curr)) return 0;
    freq.insert(curr);
    if(curr>n) extra.push_back(curr);
    if(next>n || curr>n) continue;
    if((next-curr+n)%n>1) return 0;
  }
  sort(extra.begin(), extra.end());
  for(int i=0 ; i<(int)extra.size()-1 ; i++){
    if(extra[i+1]-extra[i]>1) return 0;
  }
  return 1;
}

//----------------------

int replacement(int n, int gondolaSeq[], int replacementSeq[])
{
  using T=pair<int, int>;
  vector<T>extra;
  int posi=-1;
  for(int i=0 ; i<n ; i++){
    if(gondolaSeq[i]<=n){
      posi=i;
      break;
    }
  }
  if(posi>=0){
    vector<int>nuevo(n+1);
    nuevo[posi]=gondolaSeq[posi];
    int curr=(posi+1)%n;
    while(curr!=posi){
      int last=(curr-1+n)%n;
      nuevo[curr]=(nuevo[last]+1)%n;
      if(nuevo[curr]==0) nuevo[curr]=n;
      // dbg(nuevo[curr])
      curr=(curr+1)%n;
    }
    for(int i=0 ; i<n ; i++){
      if(gondolaSeq[i]>n) extra.push_back({nuevo[i], gondolaSeq[i]});
    }
  }else{
    for(int i=0 ; i<n ; i++){
      extra.push_back({i+1, gondolaSeq[i]});
    }
  }
  sort(extra.begin(), extra.end(), [](T a, T b){
    return a.second<b.second;
  });
  int actual=n+1; posi=0;
  for(int i=0 ; i<(int)extra.size() ; i++){
    while(extra[i].first!=extra[i].second){
      // dbg(123)
      replacementSeq[posi]=extra[i].first;
      // dbg(extra[i].first)
      posi++;
      extra[i].first=actual;
      actual++;
    }
  }
  return posi;
}

//----------------------


const long long MOD=1e9+9, maxN=1e5;
int countReplacement(int n, int inputSeq[])
{
  if(!valid(n, inputSeq)) return 0;
  long long ans=1;
  vector<long long>extra;
  vector<long long>diff(maxN);
  for(int i=0 ; i<n ; i++){
    if(inputSeq[i]>n){
      extra.push_back(inputSeq[i]);
      diff[inputSeq[i]]--;
    }
  }
  int aux=(int)extra.size();
  if(aux==n){
    // assert(0);
    for(int i=n+1 ; i<maxN ; i++){
      ans*=aux;
      ans%=MOD;
      aux+=diff[i];
      if(aux==0) break;
    }
    return ans%MOD;
  }
  for(int i=n+1 ; i<maxN ; i++){
    if(diff[i]<0) aux+=diff[i];
    else{
      if(aux<=0) break;
      ans*=aux;
      ans%=MOD;
    }
  }
  return ans%MOD;
}
