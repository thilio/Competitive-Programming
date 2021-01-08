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

int main(){

	fastio;
	ll n,m,k;
	cin >> n >> m >> k;
	ll v[101000];
	fr(i,n) cin >> v[i];
	vector<ll> dist;
	fr(i,n-1){
		dist.pb(v[i+1] - v[i]);
	}

	sort(all(dist));
	//fr(i,dist.size()) dbg(dist[i]);

	ll ans = v[n-1] - v[0] + 1;
	//dbg(ans);

	fr(i,k-1){
		ans -= dist[n-2-i] - 1;
	}

	cout << ans << endl;

}
