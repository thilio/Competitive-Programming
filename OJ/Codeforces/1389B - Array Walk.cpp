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

int n, k, z;
int a[100100];

int memo[100100][10];

int dp(int p, int falta, int esq){
	if(falta == 0) return 0;
	if(falta == 1){
		if(esq == z || p == 1) return a[p + 1];
		else return max(a[p + 1], a[p - 1]);
	}

	int &pdm = memo[p][esq];
	if(pdm != -1) return pdm;

	if(esq == z || p == 1){
		pdm = a[p + 1] + dp(p + 1, falta - 1, esq);
	}
	else{
		pdm = max(a[p] + a[p - 1] + dp(p, falta - 2, esq + 1), a[p + 1] + dp(p + 1, falta - 1, esq));
	}

	return pdm;

}

void solve(){
	cin >> n >> k >> z;

	frr(i, n) cin >> a[i];

	cout <<a[1] + dp(1, k, 0) << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 10; j++) memo[i][j] = -1;
	}
}


int main(){

	fastio;
	int T;
	cin >> T;

	ms(memo, - 1);

	while(T--){
		solve();
	}

}
