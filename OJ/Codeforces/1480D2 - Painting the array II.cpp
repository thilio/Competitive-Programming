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
int f[100100];
int last[100100];
int pre[100100];

int main(){

	fastio;

	vi v;
	int n;
	cin >> n;
	v.pb(-1);
	fr(i,n){
		int x;
		cin >> x;
		if(v[v.size() - 1] != x) v.pb(x);
	}
	n = v.size();
	n--;

	frr(i,n){
		pre[i] = last[v[i]];
		last[v[i]] = i;
	}

	//frr(i,n) dbg(pre[i]);

	f[0] = 0;
	f[1] = 1;

	int ans = n;
 
	for(int i = 2; i <= n; i++){
		f[i] = f[i - 1] + (v[i] != v[i - 2]);

		if(pre[i] > 0){
			f[i] = min(f[i], f[pre[i] + 1] + (i - pre[i] - 2));
		}

		ans = min(ans, f[i] + n - i);
	}

	//frr(i,n) dbg(f[i]);

	cout << ans << endl;

}
