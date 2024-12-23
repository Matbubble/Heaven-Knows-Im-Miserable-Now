#include "dna.h"
#include <iostream>
#define dbg(x) cerr<<#x<<": "<<x<<"\n";
using namespace std;
const int maxN=1e5+10;
int tree[4*maxN][10];
int curr[10];
int prefA[maxN+10][3], prefB[maxN+10][3];
string A, B;
int hashi(char a, char b){
	int num=3*(a-'A')+(b-'A');
	return num;
}

void build(int root, int l, int r){
	if(l==r){
		tree[root][hashi(A[l], B[r])]++;
		return;
	}
	int mid=((l+r)>>1);
	build(2*root, l, mid);
	build(2*root+1, mid+1, r);
	for(int i=0 ; i<9 ; i++) tree[root][i]=tree[2*root][i]+tree[2*root+1][i];
}

void querie(int root, int l, int r, int ql, int qr){
	if(r<ql || l>qr) return;
	if(l>=ql && r<=qr){
		// dbg(l)
		// dbg(r)
		for(int i=0 ; i<9 ; i++) curr[i]+=tree[root][i];
		return;
	}
	int mid=((l+r)>>1);
	querie(2*root, l, mid, ql, qr);
	querie(2*root+1, mid+1, r, ql, qr);
}

void init(std::string a, std::string b) {
	for(char &ch:a){
		if(ch=='T') ch='B';
	}
	for(char &ch:b){
		if(ch=='T') ch='B';
	}
	// return;
	A=a;
	B=b;
	build(1, 0, (int)a.size()-1);
	for(int i=1 ; i<=(int)a.size() ; i++){
		if(i>1){
			for(int j=0 ; j<3 ; j++){
				prefA[i][j]=prefA[i-1][j];
				prefB[i][j]=prefB[i-1][j];
			}
		}
		int sumA=a[i-1]-'A', sumB=b[i-1]-'A';
		prefA[i][sumA]++;
		prefB[i][sumB]++;
	}
}

int get_distance(int x, int y) {
	// return 0;
	for(int i=0 ; i<3 ; i++){
		if(prefA[y+1][i]-prefA[x][i]!=prefB[y+1][i]-prefB[x][i]) return -1;
	}
	for(int i=0 ; i<9 ; i++) curr[i]=0;
	// dbg(x)
	// dbg(y)
	querie(1, 0, (int)A.size()-1, x, y);
	int ans=0, need=0;
	// for(int i=0 ; i<9 ; i++) dbg(curr[i])
	for(int i=0 ; i<9 ; i++){
		int izq=i/3, der=i%3;
		if(izq==der) continue;
		int aux=min(curr[i], curr[3*der+izq]);
		ans+=aux;
		curr[i]-=aux;
		curr[3*der+izq]-=aux;
		need+=curr[i];
	}
	return ans+(2*(need/3));
}
