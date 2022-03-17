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

vector<ll> v;
int n;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		v.resize(n);

		fr(i, n) cin >> v[i];
		sort(all(v));

		ll sumpref = v[0];
		ll sumsuf = 0;

		int p = 1;
		int q = n - 1;

		bool ok = false;
		while(p < q){
			sumpref += v[p];
			sumsuf += v[q];
			if(sumsuf > sumpref) ok = true;
			p++;
			q--;
		} 

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
