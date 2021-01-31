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


vector<tuple<int,int,int>> v;
int d[100101][220];
map<string,int> si;
int t = 1;

void solve(){
	if(t!=1) gnl;
	cout << "Scenario #" << t++ << endl;

	v.clear();
	si.clear();

	int n,m;
	cin >> n;
	
	ms(d,INF);

	
	d[0][0] = 0;
	
	string s;
	fr(i,n){
		cin >> s;
		si[s] = i;
	}

	cin >> m;
	string t;
	int ct;

	fr(i,m){
		cin >> s >> t >> ct;
		tuple<int,int,int> e = make_tuple(si[s],si[t],ct);
		v.pb(e);
	}

	frr(j,100100){

		fr(k,n){
			d[j][k] = d[j-1][k];
		}

		for(auto x : v){
			int u = get<0>(x);
			int w = get<1>(x);
			int c = get<2>(x);
			
			if(d[j-1][u] + c < d[j][w])
				d[j][w] = d[j-1][u] + c;			
		}

		



	}	

	int q;
	cin >> q;
	
	fr(i,q){
		int a;
		cin >> a;

		if(d[a+1][n-1] >= INF){
			cout << "No satisfactory flights"<<endl;
		}
		else{
			cout << "Total cost of flight(s) is $"<<d[a+1][n-1]<<endl;
		}


	}


}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		solve();
	}	

}
