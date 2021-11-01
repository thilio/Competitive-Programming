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

int n;
int sq;

ll memo[100010][500]; // tamanho máximo do primeiro intervalo que vai dar certo
ll v[100100];

int sqrt_safe(int n){
	ll j = 1;
	while ((j*(j + 1)) / 2 <= n) j++;
	return j;
}

ll query(int l, int r){
	ll ans = v[r];
	if(l != 0) ans -= v[l - 1];
	return ans;
}

ll dp(int i, int j){
	ll &pdm = memo[i][j];

	if(pdm != -1) return pdm;

	if(i == n) return -llINF;
	
	if(j == 1){
		if(i == n - 1) pdm = query(n - 1, n - 1);
		else pdm = max(query(i, i), dp(i + 1, j));
		return pdm;
	}

	if(i + j - 1 >= n) return pdm = -llINF;

	pdm = dp(i + 1, j);

	ll sum = query(i, i + j - 1);

	if(dp(i + j, j - 1) > sum){
		pdm = max(pdm, sum);
	}

	return pdm;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){	
		cin >> n;

		sq  = sqrt_safe(n);

		for(int i = 0; i <= n + 1; i++){
			for(int j = 0; j <= sq + 1; j++){
				memo[i][j] = -1;
			}
		}

		fr(i, n) cin >> v[i];
		for(int i = 1; i < n; i++) v[i] += v[i - 1];

		for(int j = sq; j > 0; j--){
			if(dp(0, j) >= 0){
				cout << j << endl;
				break;
			}
		}

		//for(int i = n - 1; i >= 0; i--) dbg(memo[i][2]);

	}

}
