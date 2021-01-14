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

int v[10010];
int acum[10010];
int main(){

	fastio;
	int t;
	string s;
	cin >> t;

	getline(cin,s);
	while(t--){
		getline(cin,s);
		int n = s.size();

		fr(i,n){
			v[i] = s[i] - '0';
		}

		acum[0] = v[0];
		frr(i,n-1){
			acum[i] = acum[i-1] + v[i];
		}

		int x = acum[n-1];

		int best = min(x,n-x);

		for(int i = n -1 ;i >= 0; i--){
			int c1;
			int c0;

			int p = acum[i];
			int q = x - acum[i];

			c1 = (i + 1 - p) + q;
			c0 = p + (n - 1 - i - q);

			int c =min(c1,c0);
			best = min(best,c);
		}


		cout << best << endl;

	}

}
