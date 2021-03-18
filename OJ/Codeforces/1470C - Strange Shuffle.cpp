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

ll n, k;
ll query(int q){
	if(q == 0) q = n;
	cout << "? " << q << endl;

	ll x;
	cin >> x;
	return x; 
}

void resp(int p){
	cout << '!' << ' ' << p << endl;
}

int main(){

	fastio;

	
	cin >> n >> k;

	ll sq = sqrt(n) + 1;
	//sq = 21001;

	frr(i, sq) query(1);

	sq--;
	int index = -1;
	if(n < 100){
		frr(i,n) if(query(i) > k) index = i;
	}

	frr(j, sq + 1){
		if(index != -1) break;
		ll x = query((j*sq)%n + 1);

		if(x > k){
			index = (j*sq)%n + 1;
			break;
		}
	}

	assert(query(index) > k);

	ll x, y;
	x = y = -1;

	while(true){
		if(index == 0) index = n;
		if(x == -1) x = query(index);
		if(y == -1) y = query(index - 1);
		if(x >= k && y < k){
			resp(index);
			break;
		}

		index--;
		if(index == 0) index = n;
		x = y;
		y = -1;
	}



}
