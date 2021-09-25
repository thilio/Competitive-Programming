#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

	int T;
	cin >> T;
	while(T--){
		int a, b, c, m;
		cin >> a >> b >> c >> m;

		int mx = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);

		int mxx = max(max(a, b), c);
		int n = a + b + c;
		int mn = 0;

		if(mxx > (n + 1)/2){
			if(n%2 == 0) mn = 1;
			mn += 2*(mxx - n/2 - 1);
		}

		if(mn <= m && m <= mx) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
