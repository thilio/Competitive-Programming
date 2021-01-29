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

int n,m,k;
string s;

int dist[30][30];

int memo[100100][30];
int cost[100100][30];


void floyd(){

	fr(k,m){
		fr(i,m){
			fr(j,m){
				//fr(l,m){
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);	
				//}
				
			}
		}
	}

}

int dp(int i,int last){
	//dbg(i);
	if(i == n) return 0;

	int& pdm = memo[i][last];

	if(pdm != -1){
		return pdm;
	}

	pdm = INF;

	if(i != 0)
		pdm = dp(i+1,last) + dist[s[i] - 'a'][last];

	if(i >= n-k + 1){
		return pdm;
	}
	//dbg(i);

	fr(j,m){
		int aux = cost[i][j];
		aux += dp(i+k,j);
		pdm = min(pdm,aux);
	}

	return pdm;
}

void pre(){

	fr(j,m){
		for(int l = 0; l < k; l++){
			cost[0][j] += dist[s[l] - 'a'][j];
		}
		for(int l = 1; l < n -k + 1;l++){
			cost[l][j] = cost[l-1][j] - dist[s[l-1] - 'a'][j] + dist[s[l+k-1] - 'a'][j];
		}
	}


}


int main(){

	fastio;

	cin >> n >> m >> k;
	getline(cin,s);
	getline(cin,s);

	fr(i,m){
		fr(j,m){
			cin >> dist[i][j];
		}
	}

	floyd();
	pre();
	ms(memo,-1);

	cout << dp(0,0) << endl;


}
