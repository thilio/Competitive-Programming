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

vi nodes[1003];
int hgt[1002];
int vis[1002];
int memo[1002][12];
int freq[1002];

void dfs(int v){
	vis[v] = 1;
	for(auto x: nodes[v]){
		if (vis[x]) continue;
		hgt[x] = 1 + hgt[v];
		memo[x][0] = v;
		frr(i,11){
			memo[x][i] = memo[memo[x][i-1]][i-1];
		}
		dfs(x);
	}
}

int lca(int a,int b){
	if(hgt[a]<hgt[b])
		swap(a,b);

	for(int i =11;i>= 0;i--){
		if(hgt[memo[a][i]]>= hgt[b])
			a = memo[a][i];
	}

	if(a==b) return a;

	for(int i = 11; i>= 0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}
	//dbg(a);

	return (memo[a][0]);
}

int main(){

	fastio;
	int T;
	int g = 1;
	cin >> T;
	while(T--){

		int n;
		cin >> n;

		ms(hgt,0);
		ms(vis,0);
		ms(freq,0);
		fr(i,1002){
			ms(memo[i],0);
		}
		fr(i,1003) nodes[i].clear();



		int a,b;
		

		frr(i,n){

			cin >> a;
			fr(j,a){
				cin >> b;
				freq[b]++;
				nodes[b].pb(i);
				nodes[i].pb(b);
			}
		}

		int raiz = 0;

		frr(i,n){
			if(freq[i] == 0) raiz = i;
		}

		fr(i,12) memo[raiz][i] = raiz;

		dfs(raiz);

		

		int q;
		cin >> q;
		cout << "Case "<<g++<<":"<< endl;

		fr(i,q){
			cin >> a >> b;
			cout << lca(a,b)<< endl;
		}

	}

}
