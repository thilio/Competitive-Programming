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

	ll n,s;
	cin >> n >> s;
	ll v[200100];
	fr(i,n) cin >> v[i];
	ll sum = 0ll;
	fr(i,n) sum += v[i];

	fr(i,n){
		ll d = v[i];
		ll ret = 0;

		if((sum - d + 1) < s)
			ret += s - (sum - d + 1);

		ll ret2 = 0ll;
		if((d + n - 1) > s){
			ret2 = (d + n - 1) - s;
		}

		ll ret1 = ret + ret2;

		cout << ret1<< ' ';
	}

	gnl;


}
