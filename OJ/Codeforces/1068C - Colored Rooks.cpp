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

int esta[10010];
int fim[10010];

vi adj[10010];


int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,m){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i,100) if(adj[i].size() == 0) adj[i].pb(1000);

	frr(i,100) sort(all(adj[i]));

	int sum = 0;
	frr(i,n){
		cout << adj[i].size() << endl;
		sum += adj[i].size();
		int k = 0;
		fr(j,adj[i].size()){
			if(adj[i][j] > i) break;
			int x = esta[adj[i][j]];
			cout << x << ' ' << i << endl;
			esta[adj[i][j]]++;
			k++;
		}

		int com = fim[i-1];
		com++;
		//if(i == 1) com = 1;

		esta[i] = com;

		for(int j = k ; j < adj[i].size();j++){
			cout << com << ' ' << i << endl;
			com++;
		}

		fim[i] = com;
	}





}
