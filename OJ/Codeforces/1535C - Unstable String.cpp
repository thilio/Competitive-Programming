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

string s;
ll ans;
int n;

bool aa[200100];	

ll f(ll x){
	return (x*(x + 1))/2;
}

int start(ll j){
	int pos = n;
	int fix = -1;
	ll i;

	for(i = j; i < n; i++){
		if(fix == -1){
			if(s[i] == '0') fix = 0;
			if(s[i] == '1') fix = 1;
		}
		else{
			if(s[i] == '0' + fix){
				i--;
				break;
			}
			else{
				fix = 1 - fix;
			}
		}
		if(s[i] != '?'){
			pos = i;
		}
	}

	if(i == n){
		ans += f(n - j);
		return n;
	}

	ans += f(i - j + 1);

	aa[i] = true;

	return pos + 1;
}

int main(){

	fastio;

	int T;
	cin >> T;
	getline(cin, s);
	while(T--){
		getline(cin, s);
		n = s.size();

		fr(i, n + 2) aa[i] = false;

		ll p = 0;
		ans = 0;

		while(p < n){
			p = start(p);
		//	dbg(p);
	//		dbg(ans);
		}

	//	fr(i, n) dbg(aa[i]);

		p = 0;
		while(p < n){
			if(s[p] != '?'){
				p++;
				continue;
			}
			int q = p;
			while(q < n && s[q] == '?') q++;
			q--;
			if(aa[q]) ans -= f(q - p + 1);
			p = q + 1;
		}


		cout << ans << endl;
	}

}
