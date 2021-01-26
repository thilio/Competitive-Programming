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
typedef vector< vector<ll> > matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll n,m;

matrix operator * (matrix a,matrix b){
	matrix ans;
	int c,d,e;
	c = a.size();
	d = b.size();
	e = b[0].size();

	ans.resize(a.size());
	fr(i,c) ans[i].resize(e);

	fr(i,c){
		fr(j,e){
			fr(k,d){
				ans[i][j] += a[i][k]*b[k][j];
				ans[i][j] %= MOD;
			}
		}

	}

	return ans;


}

matrix fast(matrix a,ll exp){
	if(exp == 1) return a;
	matrix ans = fast(a,exp/2);
	ans = ans*ans;
	if(exp%2) ans = ans*a;
	return ans;
}

int main(){

	fastio;
	cin >> n >> m;
	ll ans;
	if(n < m)
		ans = 1;
	else if(n == m) ans = 2;
	else{

		matrix base;
		base.resize(101);
		fr(i,101) base[i].resize(101);

		base[0][0] = 1;
		base[0][m-1] = 1;
		for(int i = 1;i<101;i++){
			for(int j = 0;j < 101;j++){
				if(i == j + 1)
					base[i][j] = 1;
			}
		}

		matrix z;
		z.resize(101);
		fr(i,101) z[i].resize(1);

		z[0][0] = 2;
		frr(i,99) z[i][0] = 1;

		matrix res = fast(base,n-m)*z;

		ans = res[0][0];

	}

	cout << ans << endl;

}
