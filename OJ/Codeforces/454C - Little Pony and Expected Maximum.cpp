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

double fast(double bas,int exp){
	if(exp == 1) return bas;
	double ans = fast(bas,exp/2);
	ans = ans*ans;

	if(exp&1) ans *= bas;

	return ans;
}

int main(){

	fastio;
	int m,n;

	cin >> m >> n;

	double ans = 0.0;

	frr(i,m){
		ans += i*fast((double(i)/double(m)),n);
		ans -= i*fast((double(i-1)/double(m)),n);
	}

	cout << setprecision(9) << ans << endl;

}
