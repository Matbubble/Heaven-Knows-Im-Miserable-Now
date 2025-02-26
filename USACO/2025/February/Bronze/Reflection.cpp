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

struct friends{
    pair<int, int>a, b, c, d;
};

void solve(){
    int n, q; cin>>n>>q;
    char lab[n+1][n+1];
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++) cin>>lab[i][j];
    }
    friends labamigos[n+1][n+1];
    for(int i=1 ; i<=n/2 ; i++){
        for(int j=1 ; j<=n/2 ; j++){
            //one
            labamigos[i][j].a={i, j};
            labamigos[i][j].b={i, n+1-j};
            labamigos[i][j].c={n+1-i, j};
            labamigos[i][j].d={n+1-i, n+1-j};

            //two
            labamigos[i][n+1-j].a={i, j};
            labamigos[i][n+1-j].b={i, n+1-j};
            labamigos[i][n+1-j].c={n+1-i, j};
            labamigos[i][n+1-j].d={n+1-i, n+1-j};

            //three
            labamigos[n+1-i][n+1-j].a={i, j};
            labamigos[n+1-i][n+1-j].b={i, n+1-j};
            labamigos[n+1-i][n+1-j].c={n+1-i, j};
            labamigos[n+1-i][n+1-j].d={n+1-i, n+1-j};

            //four
            labamigos[n+1-i][j].a={i, j};
            labamigos[n+1-i][j].b={i, n+1-j};
            labamigos[n+1-i][j].c={n+1-i, j};
            labamigos[n+1-i][j].d={n+1-i, n+1-j};
        }
    }
    int start=0;
    for(int i=1 ; i<=n/2 ; i++){
        for(int j=1 ; j<=n/2 ; j++){
            int dot=0, hashi=0;
            if(lab[labamigos[i][j].a.first][labamigos[i][j].a.second]=='.') dot++;
            else hashi++;
            if(lab[labamigos[i][j].b.first][labamigos[i][j].b.second]=='.') dot++;
            else hashi++;
            if(lab[labamigos[i][j].c.first][labamigos[i][j].c.second]=='.') dot++;
            else hashi++;
            if(lab[labamigos[i][j].d.first][labamigos[i][j].d.second]=='.') dot++;
            else hashi++;
            start+=min(dot, hashi);
        }
    }
    cout<<start<<"\n";
    while(q--){
        int i, j; cin>>i>>j;
        //one
        int dot=0, hashi=0;
        if(lab[labamigos[i][j].a.first][labamigos[i][j].a.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].b.first][labamigos[i][j].b.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].c.first][labamigos[i][j].c.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].d.first][labamigos[i][j].d.second]=='.') dot++;
        else hashi++;
        start-=min(dot, hashi);
        if(lab[i][j]=='.') lab[i][j]='#';
        else lab[i][j]='.';

        //two
        dot=0; hashi=0;
        if(lab[labamigos[i][j].a.first][labamigos[i][j].a.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].b.first][labamigos[i][j].b.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].c.first][labamigos[i][j].c.second]=='.') dot++;
        else hashi++;
        if(lab[labamigos[i][j].d.first][labamigos[i][j].d.second]=='.') dot++;
        else hashi++;
        start+=min(dot, hashi);
        cout<<start<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}