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
	int n;
	cin >> n;
	int v[1000];
	fr(i,n) cin >> v[i];
	int ans[1000];
	ms(ans,-1);

	sort(v,v+n);

	fr(i,n){
		if(i%2 == 0) ans[i/2] = v[i];
	}

	int j=1;
	int ct = 1;
	while(j<n){
		ans[n-ct] = v[j];
		j+=2;
		ct++;
	}

	fr(i,n) cout << ans[i] << ' ';
	gnl;

}
