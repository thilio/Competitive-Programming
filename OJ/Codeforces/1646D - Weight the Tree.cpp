#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

array<int, 2> memo[200200][2];
vi adj[200200];

bool decisi[200200];

bool indep[200200];

int w[200200];

array<int, 2> dp(int v, int b, int p = -1){
	//dbg(v); dbg(b);
	if(memo[v][b][0] != -1) return memo[v][b];

	array<int, 2> &pdm = memo[v][b];
	pdm = {0, 0};

	bool folha = true;
	for(auto x: adj[v]){
		if(x != p){
			folha = false;
		}
	}

	if(folha){
		if(b)
			decisi[v] = true;
		pdm = {b, b};
		return pdm;
	}

	if(b == 0){
		pdm = {0, 0};
		array<int, 2> aux;
		for(auto x: adj[v]){
			if(x != p){
				aux = dp(x, 1, v);
				pdm[0] += aux[0];
				pdm[1] += aux[1]; 
			}
		}
	}
	else{
		pdm = dp(v, 0, p);
		array<int, 2> tent = {1, (int)adj[v].size()};
		for(auto x: adj[v])
			if(x != p){
				array<int, 2> aux = dp(x, 0, v);
				tent[0] += aux[0];
				tent[1] += aux[1]; 
			}

		if(tent[0] > pdm[0] || (tent[0] == pdm[0] && tent[1] < pdm[1])){
			pdm = tent;
			decisi[v] = true;
		}
		else decisi[v] = false;
	}
	return pdm;
}

void recover(int v, int b, int p = -1){

	if(b == 0 || (b == 1 && decisi[v] == 0)){
		for(auto x: adj[v]){
			if(x != p)
				recover(x, 1, v);
		}
	}
	else{
		
		indep[v] = true;
		for(auto x: adj[v]){
			if(x != p)
				recover(x, 0, v);
		}
		
	}


}

int main(){

	fastio;

	int n;
	cin >> n;

	if(n == 2){
		int a, b;
		cin >> a >> b;
		cout << "2 2"<< endl << "1 1" << endl;
		return 0;
	}

	fr(i, n - 1){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i, n) fr(j, 2) memo[i][j] = {-1, -1};

	dp(1, 0);
	dp(1, 1);

	frr(i, n){
		fr(j, 1){
		//	dbg(memo[i][1][0]);
		//	dbg(memo[i][1][1]);
		}
	}



	recover(1, 1);

	int sum = 0;
	int sz = 0;

	for(int i = 1; i <= n; i++){
		if(indep[i]){
			w[i] = adj[i].size();
			sz++;
		}
		else
			w[i] = 1;

		sum += w[i];
	}

	cout << sz << ' ' << sum << endl;

	frr(i, n){
		cout << w[i] <<  ' ';
	}
	gnl;

}
