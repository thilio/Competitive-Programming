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
ll n, q, perm, v[200200];
ll acum[200200], fat[20];
vector<int> disp;
int lim;

void update(){
	disp.clear();
	for(int i = lim; i <= n; i++) disp.pb(i);

	ll x = perm;
	
	for(int i = lim; i <= n; i++){
		ll w = x/fat[n - i];
		v[i] = disp[w];
		x %= fat[n - i];
		disp.erase(disp.begin() + w);
	}

	for(int i = lim; i <= n; i++) acum[i] = v[i] + acum[i - 1];
}

void fate(){
	fat[0] = 1;

	frr(i,15) fat[i] = i*fat[i - 1];
}

int main(){

	fastio;

	cin >> n >> q;
	lim = max(1ll, n - 15);

	fate();

	frr(i,n) v[i] = i;
	frr(i,n) acum[i] = v[i] + acum[i - 1];

	fr(i,q){
		int op; 
		cin >> op;
		if(op == 1){
			int l,r;
			cin >> l >> r;
			update();
			cout << acum[r] - acum[l - 1] << endl;
		}
		else{
			ll x;
			cin >> x;
			perm += x;
		}
	}

}
