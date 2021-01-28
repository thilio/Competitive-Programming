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
	int n,m,a,b;
	cin >> n >> m >> a >> b;

	int ra,rb;
	ra = (a + m -1)/m;
	rb = (b + m -1)/m;

	int ca,cb;

	ca = a%m;
	cb = b%m;

	if(ca == 0) ca = m;
	if(cb == 0) cb = m;

	if(b == n) b = rb*m;


	int ans = 3;
	if(a == (ra - 1)*m + 1) ans--;
	if(b == (rb*m)) ans--;



	if(ra == rb) ans = 1;
	if(abs(ra-rb) == 1) ans =min(2,ans);
	if(ca - cb == 0 && (ca == 1 || ca == m)) ans =min(2,ans);
	if(ca - cb == 1) ans = min(2,ans);

	cout << ans << endl;

}
