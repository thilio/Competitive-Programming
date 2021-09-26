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

int n;
ll a;
ll b[100100];
map<ll, ll> tempo;
vector<pll> jogador[100100];
map<ll, vector<pll>> inter;
ll ans;

ll ninter;

vector<pll> resp;

void tent(ll x, ll last){
	ans += a*ninter*(x - last);

	for(auto y: inter[x]){
		ninter--;
		ans -= a;
		ans -= b[tempo[jogador[y.fst][y.snd].fst]];
		tempo[jogador[y.fst][y.snd].fst]--;
		ans += b[tempo[jogador[y.fst][y.snd].fst]]; 
		jogador[y.fst][y.snd].fst = jogador[y.fst][y.snd - 1].fst;
	}
}

int main(){

	fastio;

	cin >> n;

	frr(i, n){
		int k;
		cin >> k;

		int last = -1;
		int at;

		fr(j, k){
			cin >> at;
			if(at != last){
				jogador[i].pb({at, at});
				ninter++;
			}
			last = at;
		}
	}

	cin >> a;

	for(ll i = 1; i <= n; i++){
		ll aux;
		cin >> aux;
		b[i] = i*aux;
	}


	set<ll> S;

	frr(i, n){
		fr(j, jogador[i].size()){
			ans += a;
			if(j != 0){
				ll x = jogador[i][j].fst - jogador[i][j - 1].fst;
				S.insert(x);
				inter[x].pb({i, j});
			}
			tempo[jogador[i][j].fst]++;
		}
	}

	for(auto x: tempo){
		ans += b[x.snd];
	}

	resp.pb({ans, 0});

	ll last = 0;

	for(auto x: S){
		tent(x, last);

		if(ans == resp[0].fst){
			resp.pb({ans, x});
		}
		else if(ans < resp[0].fst){
			resp.clear();
			resp.pb({ans, x});
		}

		last = x;
	}

	cout << resp[0].fst << ' ' << resp.size() << endl;

	for(auto x: resp) cout << x.snd + 1 << ' ';
	gnl;



}
