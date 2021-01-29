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

struct reta{
	pii ang;
	pii lin;
	bool vert;

	bool operator < (const reta& x) const{
		if(x.vert < vert) return true;
		if(x.vert > vert) return false;
		if(x.ang < ang) return true;
		if (x.ang > ang) return false;
		if(x.lin < lin) return true;
		return false;

	}

	bool operator == (const reta& x) const{
		if(x.vert != vert) return 0;
		if(x.ang != ang) return 0;
		if(x.lin != lin) return 0;
		return 1;

	}
};

typedef struct reta reta;

int n;
pii v[3000];
vector<reta> vv;
vector<reta> res;
map<int,int> rev;

pii simpl(pii a){
	bool neg = false;
	if(a.fst < 0) neg  = true;
	if(neg) a.fst = - a.fst;
	int g = __gcd(a.fst,a.snd);
	pii b;
	b.fst = a.fst/g;
	if(neg) b.fst = -b.fst;
	b.snd = a.snd/g;

	return b;
}

ll bin (ll k){
	if (k < 3) return 0;

	ll ans = k;
	ans *= k - 1;
	ans *= k - 2;
	ans /= 6;

	return ans;

}

void build(){
	fr(i,2500){
		rev[i*(i-1)] = i;
	}
}

void print(reta r){
	cout << r.vert << endl;
	cout << r.ang.fst << '/' << r.ang.snd<< endl;
	cout << r.lin.fst << '/' << r.lin.snd<<endl;;
	gnl;
}

int main(){

	fastio;
	cin >> n;
	
	fr(i,n){
		cin >> v[i].fst >> v[i].snd;
	}

	if( n < 3){
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;

	fr(i,n){
		vv.clear();
		res.clear();
		fr(j,n){
			if (i == j) continue;
						
			
			reta r;
			if(v[i].fst == v[j].fst){
				r.vert = true;
				r.ang = mp(0,0);
				r.lin = mp(0,0);
				
				vv.pb(r);
				continue;
			}
			r.vert = false;
			pii x,y;
			x = v[i];y = v[j];
			if(x.fst > y.fst) swap(x,y);
			r.ang = simpl(mp(y.snd - x.snd,y.fst - x.fst));
			r.lin = simpl(mp(x.snd*r.ang.snd - x.fst*r.ang.fst,r.ang.snd));
			vv.pb(r);
		}

		sort(all(vv));
		ll x = vv.size();

		ans += x*(x-1)/2;

		int j = 1;
		fr(i,vv.size() - 1){
			if(vv[i] == vv[i+1]) j++;
			else{ 
				ans -= j*(j-1)/2;
				j = 1;
			}
		}
		ans -= j*(j-1)/2;


	}	

	cout << ans/3 << endl;
	
}
