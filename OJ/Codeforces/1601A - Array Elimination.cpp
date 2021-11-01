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
int a[200200];

void solve(){
	cin >> n;

	int g = 0;
	fr(i, n) cin >> a[i];

	for(int i = 0; i < 30; i++){
		int ct = 0;
		fr(j, n){
			if(a[j]&(1ll << i)) ct++;
		}
		g = __gcd(g, ct);
	}

	frr(i, n){
		if(g%i == 0) cout << i << ' ';
	}
	gnl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--) solve();

}
