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

int a,b,c,d;

ll solve(int z){

	ll sum = 0;

	ll ub = min(b,z-b+1);
	ll lb = max(a,z-c);

	if(lb <= ub){
		ll k = c-z;
		sum += k*(ub - lb + 1);
		sum += ((lb + ub)*(ub -lb + 1))/2;
	}

	//dbg(sum);

	ll llb = max(lb,ub + 1);
	if(b >= llb)
		sum += (c-b+1)*(b - llb + 1);

	return sum;
}

int main(){

	fastio;

	cin >> a >> b >> c >> d;

	ll ans = 0;

	for(int i = c; i <= d; i++){
		ans += solve(i);
		//dbg(solve(i));
	}

	cout << ans << endl;

}
