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
typedef vector< vector<char> > matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n, m;

ll sum[300300];

ll fast(ll b, ll e){
	if(e == 0) return 1ll;
	ll ans = fast(b, e/2);
	ans = (ans * ans) %MOD;
	if(e&1) ans = (ans*b)%MOD;
	return ans; 
}

ll conta(matrix A){
	ll w = 0;
	fr(i, n) fr(j, m) if(A[i][j] == 'o') w++;
	//dbg(w);

	ll wlin;
	ll resp = 0;

	fr(i, n){
		wlin = 0;
		fr(j, m - 1){
			if(A[i][j] == 'o' && A[i][j + 1] == 'o'){
				if(wlin == 0){
					resp = (resp + fast(2, w - 2))%MOD;
				}
				else{
					resp = (resp + sum[wlin]*fast(2, w - 2 - wlin))%MOD;
				}
			}
			if(A[i][j] == 'o') wlin++;
			else wlin = 0;
		}
	}
	//dbg(resp);
	return resp;
}

void pre(){
	sum[1] = 1;
	sum[2] = 3;

	for(int i = 3; i<= 300000; i++){
		sum[i] = fast(2, i - 1) + sum[i - 2];
		sum[i] %= MOD;
	}	
}


int main(){

	fastio;

	matrix A;
	//int n, m;
	cin >> n >> m;

	pre();

	A.resize(n);
	fr(i, n) A[i].resize(m);


	string s;
	getline(cin, s);
	fr(i, n){
		getline(cin, s);
		fr(j, m) A[i][j] = s[j];
	}

	ll ans = conta(A);
	//dbg(ans);
	matrix B;

	B.resize(m);
	fr(i, m) B[i].resize(n);

	fr(i, m) fr(j, n) B[i][j] = A[j][i];

	swap(m , n);
	ans = (ans + conta(B))%MOD;

	cout << ans << endl;
}
