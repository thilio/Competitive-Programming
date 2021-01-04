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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int id[200200];
int sz[200200];
int mx[200200];

int find(int v){
	if(id[v] == v) return v;
	return(id[v] = find(id[v]));
}

int merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return 0;

	if(sz[a] > sz[b]) swap(a,b);
	sz[b] += sz[a];
	id[a] = b;
	mx[b] = max(mx[a],mx[b]);

	return 1;
}

int main(){


	int n,m;

	scanf("%d %d", &n ,&m);

	frr(i,n){
		id[i] = i;
		sz[i] = 1;
		mx[i] = i;
	}

	fr(i,m){
		int u,v;
		scanf("%d %d", &u ,&v);
		int x = merge(u,v);
	}



	int ans = 0;
	int k = 1;
	while(k <= n){
		int p = mx[find(k)];
		
		for(int i = k + 1; i<= p; i++){
			ans += merge(k,i);
			p = mx[find(k)];
		}

		k = p + 1;
	}

	printf("%d\n",ans);


}
