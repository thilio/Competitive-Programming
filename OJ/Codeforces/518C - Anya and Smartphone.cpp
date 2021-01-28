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

	int n,m,k;
	int v[200200];
	int od[200200];

	cin >> n >> m >> k;

	frr(i,n){
		cin >> v[i];
		od[v[i]] = i;
	}

	ll ans = 0ll;

	fr(i,m){
		int app;
		cin >> app;
		int ond = od[app];
		ans += (ond + k - 1)/k;

		if(ond == 1) continue;

		int x = v[ond - 1];
		v[ond - 1] = v[ond];
		v[ond] = x;
		od[v[ond]] = ond;
		od[v[ond-1]] = ond - 1;

	}

	cout << ans << endl;

}
