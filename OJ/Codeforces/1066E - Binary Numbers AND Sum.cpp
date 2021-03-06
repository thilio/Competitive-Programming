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
const int MOD = 998244353;

int main(){

	fastio;

	ll n,m;

	cin >> n >> m;

	string a,b;
	getline(cin,a);
	getline(cin,a);
	getline(cin,b);

	ll A[200200],B[200100];

	fr(i,n) A[i] = a[n-i-1] - '0';
	fr(i,m) B[i] = b[m - i - 1] - '0';

	for(int i = m-2; i >= 0; i--){
		B[i] += B[i+1];
	}

//fr(i,m) dbg(B[i]);

	ll ans = 0ll;
	ll pot = 1ll;

	fr(i,min(m,n)){
		if(A[i] == 1){
			ans += B[i]*pot;
			ans %= MOD;
		}

		pot*=2;
		pot%= MOD;
	}

	cout << ans << endl;



}
