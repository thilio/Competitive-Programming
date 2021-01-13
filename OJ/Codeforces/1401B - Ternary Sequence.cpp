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
	int t;
	cin >> t;
	while(t--){
		int x1,y1,z1;
		int x2,y2,z2;

		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;

		int a1,a2,a3;
		a1 = min(z1,y2);
		a2 = min(y1,x2);
		a3 = min(x1,z2);
		int ans = 2*a1;
		z1 -= a1;
		y2 -= a1;
		y1 -= a2;
		x2 -= a2;
		x1 -= a3;
		z2 -= a3;

		if(y1 > 0 && z2 > 0) ans -= 2*min(y1,z2);

		cout << ans << endl;
	}

}
