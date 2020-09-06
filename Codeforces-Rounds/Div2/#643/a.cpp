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

int mind(ll n){
	int mn = 9;
	while(n!=0){
		int k = n%10;
		if(k < mn)mn = k;
		n /=10;

	}

	return mn;
}

int maxd(ll n){
	int mx = 0;
	while(n!=0){
		int k = n%10;
		if(k > mx)mx = k;
		n /=10;

	}

	return mx;
}

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		ll a;
		ll k;
		cin >> a >> k;

		int i = 1;

		while(mind(a) != 0 && i < k){
			a += maxd(a)*mind(a);
			i++;
		}

		cout << a << endl;
		
	}



}
