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
const int MOD = 998244353;

int n;

ll dp[100100][10];
int a[100100];


int main(){

	fastio;

	cin >> n;
	fr(i, n) cin >> a[i];

	dp[0][a[0]] = 1;

	for(int i = 1; i < n; i++){
		for(int j = 0; j < 10; j++){
			dp[i][(a[i] + j)%10] = (dp[i][(a[i] + j)%10] + dp[i - 1][j])%MOD;
			dp[i][(a[i]*j)%10] = (dp[i][(a[i]*j)%10] + dp[i - 1][j])%MOD;
		}
	}

	for(int j = 0; j < 10; j++){
		cout << dp[n - 1][j] << endl;
	}


}
