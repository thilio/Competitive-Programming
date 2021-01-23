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

ll peso[100100];
ll grau[100100];
vector<pll> v;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		frr(i,n) grau[i] = peso[i] = 0; 
		frr(i,n) cin >> peso[i];
		frr(i,n -1){
			int u,v;
			cin >> u >> v;
			grau[u]++;
			grau[v]++;
		}

		ll ans = 0;

		frr(i,n){
			grau[i]--;
			ans += peso[i];
		}

		cout << ans << ' ';
		v.clear();

		frr(i,n){
			if(grau[i] == 0) continue;
			v.pb({peso[i], grau[i]});
		}

		sort(all(v));

		reverse(all(v));

		for(auto x : v){
			while(x.snd > 0){
				ans += x.fst;
				cout << ans << ' ';
				x.snd--;
			}
		}
		gnl;
	}

}
