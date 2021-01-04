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

int v[100100],l[100100], r[100100];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		frr(i,n) cin >> v[i];

		if(n == 1){
			cout <<"YES" << endl;
			continue;
		}

		frr(i,n) l[i] = r[i] = 0;

		frr(i,n - 1){
			if(v[i + 1] > v[i]){
				r[i + 1] = v[i + 1] - v[i];
			}
			else
				l[i] = v[i] - v[i + 1];
		}

		ll suml = 0;
		frr(i,n) suml += l[i];

		ll sumr = 0;

		frr(i,n){
			sumr += r[i];
			v[i] -= sumr + suml;
			suml -= l[i];
		}

		bool eq = true;

		frr(i,n) if(v[i] != v[1]) eq = false;
		if(v[1] < 0) eq = false;

		if(eq) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

}
