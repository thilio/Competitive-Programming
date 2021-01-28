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

int p[200200];

int main(){

	fastio;
	int T;
	cin >> T;
	vii ans;
	while(T--){
		ll n;
		cin >> n;
		ans.clear();
		frr(i,n) p[i] = i;
		ll resp = 0;

		frr(i, n - 1){
			if(i == 1){
				swap(p[1], p[n]);
				resp += (n - 1)*(n - 1);
				ans.pb(mp(1,n));
				continue;
			}

			ll dist = n - (i/2) - 1;
			if(i%2 == 0){
				swap(p[1], p[dist+1]);
				ans.pb(mp(dist + 1,1));
			}
			else{
				swap(p[n], p[n - dist]);
				ans.pb(mp(n - dist, n));
			}
			resp += dist*dist;
		}

		cout << resp << endl;
		frr(i,n) cout << p[i] << ' ';
		gnl;
		cout << n - 1 << endl;
		reverse(all(ans));
		for(auto x : ans){
			cout << x.fst << ' ' << x.snd << endl;
		}

	}

}
