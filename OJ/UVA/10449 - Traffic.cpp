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

typedef tuple<int,int,ll> pi;
ll v[300],d[400];
vector<pi> ed;
int t = 1;

int main(){

	fastio;
	int n;
	while(cin >> n){
		ed.clear();
		frr(i,n){
			d[i] = llINF;
		}
		d[1] = 0;
		frr(i,n) cin >> v[i];
		int m;
		cin >> m;
		fr(i,m){
			int a,b;
			cin >> a >> b;
			pi e = make_tuple(a,b,(v[b] - v[a])*(v[b] - v[a])*(v[b] - v[a]));
			
			ed.pb(e);
		}

		fr(i,n-1){
			fr(j,m){
				int u = get<0>(ed[j]);
				int w = get<1>(ed[j]);
				ll c = get<2>(ed[j]);

				if(d[u] == llINF) continue;
				if(d[w] > d[u] + c){
					d[w] = d[u] + c;
				}
			}

		}

		set<int> s;
		s.clear();

		//dbg(d[2]);

		fr(j,m){
			int u = get<0>(ed[j]);
			int w = get<1>(ed[j]);
			ll c = get<2>(ed[j]);

			if(d[u] == llINF) continue;
			if(d[w] > d[u] + c){
				d[w] = d[u] + c;
				s.insert(w);
				//dbg(w);
			}
		}

		for(auto x : s) d[x] = -1;

		int q;
		cin >> q;
		cout << "Set #"<<t++<<endl;
		fr(i,q){
			int a;
			cin >> a;
			if(d[a] < 3 || d[a] > 1e10) cout << "?" << endl;
			else cout << d[a] << endl;
		}

	}

}
