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

ll Nb,Ns,Nc;
ll nb,ns,nc;
ll pb,ps,pc;

ll tent(ll val){
	ll sum = 0ll;

	if((nb - val*Nb) < 0){
		sum += (val*Nb - nb)*pb;
	}

	if((ns - val*Ns) < 0){
		sum += (val*Ns - ns)*ps;
	}

	if((nc - val*Nc) < 0){
		sum += (val*Nc - nc)*pc;
	}

	return sum;
}

int main(){

	fastio;

	string s;
	getline(cin,s);

	
	Nb = Ns = Nc = 0ll;

	fr(i,s.size()){
		if(s[i] == 'B'){
			Nb++;
		}
		if(s[i] == 'S'){
			Ns++;
		}
		if(s[i] == 'C'){
			Nc++;
		}
	}

	
	cin >> nb >> ns >> nc;

	
	cin >> pb >> ps >> pc;

	ll r;
	cin >> r;

	ll l = 0ll;

	ll re = 1e15;

	ll best = 0;

	//dbg(tent(5));
	while(l <= re){
		ll m = (l + re)/2;

		if(tent(m) <= r){
			best = m;
			l = m + 1;
		}

		else re = m -1;
	}

	cout << best << endl;






}
