#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector<vector<int>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int r;
int n,q;

int nulo[4];
int v[200200][4];
int seg[800800][4];

void mult (int* a,int* b, int* ans){
	ans[0] = a[0]*b[0] + a[1]*b[2];
	ans[1] = a[0]*b[1] + a[1]*b[3];
	ans[2] = a[2]*b[0] + a[3]*b[2];
	ans[3] = a[2]*b[1] + a[3]*b[3];

	fr(i,4) ans[i]%= r;

}

void build (int node,int l,int r){
	//printf("node = %d\n", node);
	if(l == r){
		fr(k,4)
			seg[node][k] = v[l][k];
		return;
	}

	int m = (l + r)/2;

	build(2*node,l,m);
	build(2*node + 1,m+1,r);

	mult(seg[2*node],seg[2*node + 1],seg[node]); 

}

void query(int node,int l,int r,int a,int b,int* res){
	if(a <= l && r <= b){
		fr(k,4) res[k] = seg[node][k];
		return;
	}
	if(b < l || r < a){
		fr(k,4) res[k] = nulo[k];
		return;
	}

	int m =  (l + r)/2;


	int res1[4],res2[4];
	query(2*node,l,m,a,b,res1);
	query(2*node + 1,m+1,r,a,b,res2);

	mult(res1,res2,res);
}


int main(){

	scanf("%d %d %d", &r, &n, &q);
	nulo[0] = nulo[3] = 1;


	frr(i,n){
		scanf("%d %d %d %d", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
		
	}

	build(1,1,n);

	fr(i,q){
		int a,b;
		scanf("%d %d", &a, &b);
		int x[4];
		query(1,1,n,a,b,x);

		printf("%d %d\n",x[0],x[1]);
		printf("%d %d\n\n",x[2],x[3]);
	}



}
