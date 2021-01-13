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
vi v;
vi vsort;

int main(){

	fastio;

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		v.clear();
		vsort.clear();
		fr(i,n){
			int x;
			cin >> x;
			v.pb(x);
			vsort.pb(x);
		}

		sort(all(vsort));
		int mn = vsort[0];

		int fl = 0;

		fr(i,n){
			if(v[i] == vsort[i]) continue;
			if(v[i]%mn == 0) continue;
			fl = 1;
		}

		if(fl) cout << "NO" << endl;
		else cout << "YES" << endl;

	}

}
