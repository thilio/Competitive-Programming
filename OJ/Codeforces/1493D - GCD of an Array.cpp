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

ll n,q;
ll primo[200200];
set<pll> S[200200];
map<ll, ll> M[200200];

void precomp(){
	primo[1] = 1;
	for(int i = 2; i <= 200000; i++){
		if(primo[i] == 0){
			for(int j = i; j <= 200000; j += i){
				if(primo[j] == 0) primo[j] = i;
			}
		}
	}
}

int main(){

	fastio;

	cin >> n >> q;

	precomp();
	ll g;
	frr(i,n){
		ll x;
		cin >> x;
		if(i == 1) g = x;
		else g = __gcd(g,x);

		while(x != 1){
			int k = primo[x];
			int ct = 0;
			while(x%k == 0){
				x/= k;
				ct++;
			}
			M[i][k] = ct;
			S[k].insert(mp(ct, i));
		}
	}

	for(int i = 0; i < q; i++){
		int pos; ll x;
		cin >> pos >> x;

		while(x != 1){
			int k = primo[x];
			int ct = 0;
			while(x%k == 0){
				x/= k;
				ct++;
			}
			if(M[pos][k] != 0){
				ll old = M[pos][k];
				ll mn = 0;
				if(S[k].size() == n) mn = (*S[k].begin()).fst;
				S[k].erase(mp(old, pos));
				M[pos][k] += ct;
				S[k].insert(mp(M[pos][k], pos));
				ll new_mn = 0;
				if(S[k].size() == n) new_mn = (*S[k].begin()).fst;
				while(new_mn > mn){
					g*= k;
					new_mn--;
					g %= MOD;
				}
			}
			else{
				M[pos][k] = ct;
				ll mn = 0;
				if(S[k].size() == n) mn = (*S[k].begin()).fst;
				S[k].insert(mp(M[pos][k], pos));
				ll new_mn = 0;
				if(S[k].size() == n) new_mn = (*S[k].begin()).fst;
				while(new_mn > mn){
					g*=k;
					new_mn--;
					g %= MOD;
				}
			}
		}

		cout << g << endl;
	}

}
