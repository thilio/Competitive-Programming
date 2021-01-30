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
	int m,n,N;
	cin >> N;

	n = N/2;
	m = N-n;

	ll a,b;
	cin >> a >> b;

	long long v[20],t[20];
	
	fr(i,n)
		cin >> v[i];

	fr(i,m)
		cin >> t[i];

	vector<ll> ans;

	for(int i = 0 ; i <(1<<n) ; i++){
		ll sum = 0;
		
		for(int j=0;j<n;j++){
			ll x = i&(1<<j);
			if (x != 0)
				sum += v[j];
		}

		ans.pb(sum);
	}

	vector<ll> res;

	for(int i = 0 ; i <(1<<m) ; i++){
		ll sum = 0;
		
		for(int j=0;j<m;j++){
			ll x = i&(1<<j);
			if (x != 0)
				sum += t[j];
		}

		res.pb(sum);
	}

	
	


	sort(ans.begin(),ans.end());
	
	
	
	ll tot = 0;
	for(int i = 0;i<res.size();i++){
		auto low = lower_bound(ans.begin(),ans.end(),a - res[i]);
		auto up = upper_bound(ans.begin(),ans.end(),b -res[i]);
	 	
		tot += up - low;
	}

	cout << tot << endl;




}
