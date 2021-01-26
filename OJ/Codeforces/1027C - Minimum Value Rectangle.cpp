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

set<int> f;
vector<double> v;

double expr(double a,double b){
	return (a/b + b/a);
}

void solve(){
	v.clear();
	f.clear();
	int n;
	cin >> n;

	fr(i,n){
		int a;
		cin >> a;
		if(f.find(a) == f.end()) f.insert(a);
		else{
			f.erase(a);
			v.pb(a);
		}
	}

	sort(all(v));

	double mnd = INF;
	double val;
	double aux;

	//fr(i,v.size())
	//dbg(v[i]);

	fr(i,v.size() - 1){
		if ( expr(v[i],v[i+1])<= mnd){
			mnd = expr(v[i],v[i+1]);
			val = v[i];
			aux = v[i+1];
		}
	}

	cout << val <<' '<< val <<' '<< aux <<' ' << aux<<endl;


	

}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}

}
