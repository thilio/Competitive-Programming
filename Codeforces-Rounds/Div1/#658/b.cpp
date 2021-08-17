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
int inv[4020];
int v[4020];

vi tam;

bool memo[4040][4040];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		frr(i, 2*n){
			cin >> v[i];
			inv[v[i]] = i;
		}

		tam.clear();

		int est = 2*n + 1;
		for(int i = 2*n; i >= 1; i--){
			int p = inv[i];
			if(p > est) continue;
			tam.pb(est - p);
			est = p;
		}

		fr(i, 2*n + 1) fr(j, 2*n + 1) memo[i][j] = false;
		memo[0][0] = true;


		for(int i = 1; i < tam.size(); i++){
			int p = tam[i];

			for(int j = 0; j < n + 1; j++){
				if(memo[i - 1][j]) memo[i][j] = true;
				if(p <= j && memo[i - 1][j - p]) memo[i][j] = true;
			}
		}

		if(memo[tam.size() - 1][n]) cout << "YES" << endl;
		else cout << "NO" << endl;



	}

}
