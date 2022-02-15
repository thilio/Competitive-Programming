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

int n, m;
map<pii, int> bad;
map<int ,int> F;

vi freq[300300];

void reset(){
	bad.clear();
	F.clear();
	frr(i, n) freq[i].clear();

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		reset();

		fr(i, n){
			int x;
			cin >> x;
			F[x]++;
		}

		for(auto x: F){
			freq[x.snd].pb(x.fst);
		}
		frr(i, n){
			sort(all(freq[i]));
			reverse(all(freq[i]));
		}

		fr(i, m){
			int x, y;
			cin >> x >> y;
			bad[{x, y}] = bad[{y, x}] = 1;
		}

		ll ans = 0;

		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j < freq[i].size(); j++){
				ll x = freq[i][j];
				for(ll k = j + 1; k < freq[i].size(); k++){
					ll y = freq[i][k];
					if(!bad.count({x, y})){
						ans = max(ans, (x + y)*2*i);
						break;
					}
				}
				for(ll k = i - 1; k > 0; k--){
					for(ll l = 0; l < freq[k].size(); l++){
						ll y = freq[k][l];
						if(!bad.count({x, y})){
							ans = max(ans, (x + y)*(i + k));
							break;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

}
