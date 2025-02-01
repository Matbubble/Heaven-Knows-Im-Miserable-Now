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

struct persona{
    int edad, altura, peso;
    persona(int x, int y, int z):edad(x), altura(y), peso(z){}

    bool operator<(const persona&p)const{
        return edad+altura+peso<p.edad+p.altura+p.peso;
    }

    bool operator==(const persona& p)const{
        return p.altura==altura && p.edad==edad && p.peso==peso;
    }

};  

class hashing{
    public:
        size_t operator()(const persona& p)const {
            return p.edad+p.altura+p.peso;
        }
};

void solve(){
    map<persona, string, hashing>mp;
    persona lin(101, 1, 98), agus(100, 50, 50);
    mp[lin]=1;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}