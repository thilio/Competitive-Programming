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
#define endl '\n'

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
const ll M1 = 1e9+7;
const ll M2 = 999997967;
const ll P1 = 31;
const ll P2 = 37;

int n, k;
string s;
string t;
ll H1[2000100], H2[2000100];
ll expe1[2000100];
ll expe2[2000100];
ll invexpe1[2000100];
ll invexpe2[2000100];

ll ht1 , ht2;

bool ok = true;

ll expe(ll b, ll e, ll M){
	if(e == 0) return 1;
	ll ans = expe(b, e/2, M);
	ans = (ans*ans)%M;
	if(e&1) ans = (ans*b)%M;
	return ans;
}

void solve(){

	ht1 = ht2 = 0;

	if(!ok) gnl;

	ok = false;

	fr(i, n){
		ll letra = s[i] - 'a' + 1;
		H1[i] = letra*expe1[i];
		H2[i] = letra*expe2[i];
		H1[i] %= M1;
		H2[i] %= M2;
		if(i != 0){
			H1[i] = (H1[i] + H1[i - 1])%M1;
			H2[i] = (H2[i] + H2[i - 1])%M2;
		}
		if(i < k){
			letra = t[i] - 'a' + 1;
			ht1 += letra*expe1[i];
			ht2 += letra*expe2[i];
			ht1 %= M1;
			ht2 %= M2;
		}
	}


	for(int i = 0; i + k <= n; i++){
		pll a = {H1[i + k - 1], H2[i + k - 1]};
		if(i != 0){
			a.fst = (a.fst + M1 - H1[i - 1])%M1;
			a.snd = (a.snd + M2 - H2[i - 1])%M2;
		}

		a.fst = (a.fst*invexpe1[i])%M1;
		a.snd = (a.snd*invexpe2[i])%M2;


		if(a.fst == ht1 && a.snd == ht2){
			cout << i << endl;
		}
	}
}

void pre(){

	expe1[0] = 1;
	expe2[0] = 1;

	for(int i = 1; i <= 2000000; i++){
		expe1[i] = (expe1[i - 1]*P1)%M1;
		expe2[i] = (expe2[i - 1]*P2)%M2;
	}

	invexpe1[0] = 1;
	invexpe2[0] = 1;

	ll p1 = expe(P1, M1 - 2, M1);
	ll p2 = expe(P2, M2 - 2, M2);

	for(int i = 1; i <= 2000000; i++){
		invexpe1[i] = (invexpe1[i - 1]*p1)%M1;
		invexpe2[i] = (invexpe2[i - 1]*p2)%M2;
	}
}

int main(){

	fastio;

	pre();

	while(cin >> n){
		cin >> t;
		cin >> s;
		k = t.size();
		n = s.size();
		solve();
	}

}
