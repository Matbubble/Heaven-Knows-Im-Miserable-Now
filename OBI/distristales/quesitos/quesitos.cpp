#include "quesitos.h"
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

int max_quesitos(int N, int M, vector<vector<int>> C) {
  vector<vector<int>>dp(N, vector<int>(M));
  dp[0][0]=C[0][0];
  for(int i=0 ; i<N ; i++){
    for(int j=0 ; j<M ; j++){
      if(i==0 && j==0) continue;
      if(i==0) dp[i][j]=C[i][j]+dp[i][j-1];
      else if(j==0) dp[i][j]=C[i][j]+dp[i-1][j];
      else dp[i][j]=C[i][j]+max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[N-1][M-1];
}
