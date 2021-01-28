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

	cout<< setprecision(10) << fixed;

	ll n,p;
	cin >> n >> p;

	double v[100100];

	fr(i,n){
		ll l,r;
		cin >> l >> r;

		int k = ((l + p -1)/p)*p;

		double x = (r - k)/p + 1;
		double y = r - l + 1;

		if(k > r) x = 0;

		v[i] = x/y;
	}

	//fr(i,n) dbg(v[i]);

	double ans = 0.0;

	fr(i,n){
		ans += v[i] + v[(i+1)%n] - v[i]*v[(i+1)%n];
	}

	cout << (2000.0)*ans << endl;

}
