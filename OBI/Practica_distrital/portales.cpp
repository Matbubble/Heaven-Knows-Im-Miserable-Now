#include "portales.h"
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

vector<int> portales_magicos(int N, vector<int> P) {
  vector<int> result(N);
  set<int>s;
  for(int i=0 ; i<N ; i++){
    if(s.empty()) result[i]=-1;
    else{
      auto it=s.lower_bound(P[i]);
      if(it==s.begin()) result[i]=-1;
      else{
        it--;
        result[i]=(*it);
      }
    }
    s.insert(P[i]);
  }
  return result;
}
