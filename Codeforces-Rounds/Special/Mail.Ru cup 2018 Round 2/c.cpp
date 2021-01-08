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

ll la,ra,ta;
ll lb,rb,tb;
ll p;

ll mx (ll a, ll b){
	if(a>b) return a;
	return (b);
}

ll mn (ll a, ll b){
	if(a<b) return a;
	return (b);
}

ll dist(ll k){
	ll l,r;
	l = la + k*p;
	r = ra + k*p;
	
	ll aux = min(r,rb) - max(lb,l) + 1;

	return (mx(0,aux));


}



int main(){
	fastio;
	
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	
	p = __gcd(ta,tb);


	ll s = (lb - la)/p;

	ll s1 = s + 1;
	ll s2 = s - 1;

	ll miin;
	miin = dist(s);
	miin = mx(miin,dist(s1));
	miin = mx(miin,dist(s2));

	cout <<mx(0,miin)<<endl;




}