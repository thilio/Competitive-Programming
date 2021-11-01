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
const int MOD =  998244353;

bool pos[1001][1001];
ll opt[1001];
int n, k;

int main(){

	fastio;

	cin >> n >> k;

	ms(pos, true);

	frr(i, k){
		char c; int val;
		cin >> c >> val;

		for(int j = 1; j <= k; j++){
			pos[val][j] = false;
		}
		pos[val][i] = true;

		if(c == 'L'){
			for(int j = 1; j < val; j++){
				pos[j][i] = false;
			}
		}
		else{
			for(int j = n; j > val; j--){
				pos[j][i] = false;
			}
		}
	}

	frr(i, n){
		frr(j, k) opt[i] += pos[i][j];
	}

	//frr(i, n) dbg(opt[i]);

	ll ans = 1;

	frr(i, n){
		ans = (ans*opt[i])%MOD;
	}

	cout << ans << endl;





}
