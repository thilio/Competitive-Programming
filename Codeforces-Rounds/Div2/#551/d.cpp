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
int n;
int k;
int mm[300300];
vector<int> adj[300300];

int dfs(int v){
	if(adj[v].size() == 0){
		k++;
		return 1;
	}

	int sum,mn;
	sum = 0;
	mn = 300300;

	fr(i,adj[v].size()){
		int f = dfs(adj[v][i]);
		if(f < mn) mn = f;
		sum += f;
	}

	if(mm[v] == 0) return sum;
	else return mn;
}

int main(){

	fastio;
	cin >> n;

	frr(i,n) cin >> mm[i];

	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		adj[x].pb(i);
	}

	int p = dfs(1);

	cout << k + 1 - p << endl;

}
