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

	int n, m;

	cin >> n >> m;

	ll a[200200];
	ll b[200200];

	fr(i, n) cin >> a[i];
	fr(i, m) cin >> b[i];

	sort(a, a + n);	
	vector<ll> v;

	fr(i, n){
		if(v.empty() || a[i] != v[(int)v.size() - 1]) v.pb(a[i]);
	}

	n = v.size();

	if(n == 1){
		fr(j, m){
			cout << v[0] + b[j] << ' '; 
		}
		gnl;
		return 0;
	}

	ll g = v[1] - v[0];
	for(int i = 1; i < n; i++){
		g = __gcd(g, v[i] - v[0]);
	}

	fr(j, m){
		cout << __gcd(g, v[0] + b[j]) << ' ';
	}
	gnl;


}
