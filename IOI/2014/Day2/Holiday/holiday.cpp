#include"holiday.h"
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

struct fentree{
    vector<long long>ft;
    int n;
    fentree (int n):n(n), ft(n+1){}
    long long querie(int posi){
        long long res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }

    void add(int posi, long long val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }

    int bs(int k){
        int aux=querie(n);
        if(aux<=k) return 1;
        int res=0;
        int l=1, r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(aux-querie(mid-1)>=k){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};

long long int findMaxAttraction(int n, int start, int d, int attraction[]) {
    long long ans=0;
    vector<long long> v(n);
    set<long long>cast;
    map<long long, int>val;
    map<int, long long>rev;
    for(int i=0 ; i<n ; i++){
        v[i]=attraction[i];
        cast.insert(v[i]);
    }
    int posi=1;
    for(long long x:cast){
        val[x]=posi;
        rev[posi]=x;
        posi++;
    }
    //left
    {
        fentree freq(n), pref(n);
        for(int i=start ; i<n ; i++){
            int left=d-(i-start);
            if(left<=0) break;
            pref.add(val[v[i]], v[i]);
            freq.add(val[v[i]], 1);
            int posi=freq.bs(left);
            int now=freq.querie(n)-freq.querie(posi-1);
            long long curr=pref.querie(n)-pref.querie(posi-1);
            if(now>left){
                now-=left;
                curr-=now*rev[posi];
            }
            // cout<<left<<" "<<curr<<"\n";
            ans=max(ans, curr);
        }
    }
    //right
    {
        fentree freq(n), pref(n);
        for(int i=start ; i>=0 ; i--){
            int left=d-(start-i);
            if(left<=0) break;
            pref.add(val[v[i]], v[i]);
            freq.add(val[v[i]], 1);
            int posi=freq.bs(left);
            int now=freq.querie(n)-freq.querie(posi-1);
            long long curr=pref.querie(n)-pref.querie(posi-1);
            if(now>left){
                now-=left;
                curr-=now*rev[posi];
            }
            // cout<<left<<" "<<curr<<"\n";
            ans=max(ans, curr);
        }
    }
    if(start==0 || start==n-1) return ans;
    //both
    {
        //start right
        {
            for(int i=start ; i>=0 ; i--){
                fentree freq(n), pref(n);
                for(int j=i ; j<n ; j++){
                    pref.add(val[v[j]], v[j]);
                    freq.add(val[v[j]], 1);
                    if(j<=start) continue;
                    int left=d-(((2*(start-i))+(j-start)));
                    if(left<=0) break;
                    int posi=freq.bs(left);
                    int now=freq.querie(n)-freq.querie(posi-1);
                    long long curr=pref.querie(n)-pref.querie(posi-1);
                    if(now>left){
                        now-=left;
                        curr-=now*rev[posi];
                    }
                    // cout<<left<<" "<<curr<<"\n";
                    ans=max(ans, curr);
                }
            }
        }
        //start left
        {
            for(int i=start ; i<n ; i++){
                fentree freq(n), pref(n);
                for(int j=i ; j>=0 ; j--){
                    pref.add(val[v[j]], v[j]);
                    freq.add(val[v[j]], 1);
                    if(j>=start) continue;
                    int left=d-(((2*(i-start))+(start-j)));
                    if(left<=0) break;
                    int posi=freq.bs(left);
                    int now=freq.querie(n)-freq.querie(posi-1);
                    long long curr=pref.querie(n)-pref.querie(posi-1);
                    if(now>left){
                        now-=left;
                        curr-=now*rev[posi];
                    }
                    // cout<<left<<" "<<curr<<"\n";
                    ans=max(ans, curr);
                }
            }
        }
    }
    return ans;
}
