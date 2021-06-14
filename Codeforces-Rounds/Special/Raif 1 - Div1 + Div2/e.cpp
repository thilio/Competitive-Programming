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

ll v[200200];

ll g(ll i, ll j){
	ll a = (v[i]/j)*(v[i]/j)*(j - v[i]%j);
	ll b = ((v[i] + j - 1)/j)*((v[i] + j - 1)/j)*(v[i]%j);
	return a + b;
}

ll f(int i, int j){
	if(j > v[i]) return -INF;
	return g(i, j - 1) - g(i, j);

}

int main(){

	fastio;

	int n, k;
	cin >> n >> k;

	ll sum = 0;
	frr(i, n){
		cin >> v[i];
		sum += v[i]*v[i];
	}

	int T = k - n;
	priority_queue<pair<ll, pii>> pq;

//	frr(i, n) dbg(f(i, 2));

	frr(i, n) pq.push(mp(f(i, 2), mp(i, 2)));

	frr(i , T){
		pair<ll, pii> at = pq.top();
		pq.pop();

		sum -= at.fst;
		int j = at.snd.fst;
		int t = at.snd.snd;

		pq.push(mp(f(j, t + 1), mp(j, t + 1)));
	}

	cout << sum << endl;

}
