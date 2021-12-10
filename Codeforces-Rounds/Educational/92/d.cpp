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

ll n, k;

ll solve(){
	pair<ll, ll> a, b;

	cin >> n >> k;
	cin >> a.fst >> a.snd >> b.fst >> b.snd;

	if(a.fst > b.fst) swap(a, b);

	ll lenb = b.snd - b.fst;
	ll lena = a.snd - a.fst;

	if(b.snd <= a.snd){ // is contained
		if(k <= n*lenb) return 0;
		if(k <= n*lena){
			return k - n*lenb;
		}
		else{
			return n*(lena - lenb) + 2*(k - n*lena); 
		}
	}
	else if(b.fst <= a.snd){
		ll leni = a.snd - b.fst;
		ll lenu = b.snd - a.fst;

		if(k <= n*leni) return 0;
		if(k <= n*lenu) return k - n*leni;
		return n*(lenu - leni) + 2*(k - n*lenu);
	}
	else{
		ll d = b.fst - a.snd;
		ll lenu = b.snd - a.fst;

		ll ans = llINF;
		ll cost = 0;

		for(int i = 1; i <= n; i++){
			cost += d;

			if(k <= lenu){
				ans = min(ans, cost + k);
			}
			else{
				cost += lenu;
				k -= lenu;
				ans = min(ans, cost + 2*k);
			}
		}

		return ans;
	}
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cout <<	solve() << endl;
	}

}
