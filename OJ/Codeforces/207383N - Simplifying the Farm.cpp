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
typedef pair<ll,pii> aresta;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
ll ans = 1;
int n,m;
int pai[100100];
int sz[100100];
ll peso;
vector<aresta> edge;

int find(int v){
	if(v == pai[v]) return v;
	return pai[v] = find(pai[v]);
}

void merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(sz[u] > sz[v]) swap(u,v);
	pai[u] = v;
	sz[v] += sz[u];
}

void init(int n){
	frr(i,n){
		pai[i] = i;
		sz[i] = 1;
	}
}
bool same(pii a,pii b){
	if(a == b) return true;
	if(a.fst == b.snd && b.fst == a.snd) return true;

	return false;
}

ll kruskal(){
	vector<aresta> v;
	vector<aresta> vl;
	int i = 0;
	while(i<m){
		vl.clear();
		v.clear();
		fr(j,3){
			if(i>=m) continue;
			aresta at = edge[i];
			if(vl.size() == 0){
				vl.pb(at);
				i++;
			}
			else if(at.fst == vl[0].fst){
				vl.pb(at);
				i++;
			}
		}
		//dbg(vl.size());
		
		fr(j,vl.size()){
			if(find(vl[j].snd.fst) != find(vl[j].snd.snd)){
				v.pb(vl[j]);
			}
		}

		if(v.size() == 1){
			merge(v[0].snd.fst,v[0].snd.snd);
			peso += v[0].fst;
		}

		if(v.size() == 2){
			merge(v[0].snd.fst,v[0].snd.snd);
			peso += v[0].fst;
			if(find(v[1].snd.fst) == find(v[1].snd.snd)){
				ans *= 2;
				ans %= MOD;
			}
			else{
				merge(v[1].snd.fst,v[1].snd.snd);
				peso+= v[1].fst;
			}
		}
		if(v.size() == 3){
			set<int> s;
			s.clear();
			fr(j,3){
				v[j].snd.fst = find(v[j].snd.fst);
				v[j].snd.snd = find(v[j].snd.snd);
				s.insert(v[j].snd.fst);
				s.insert(v[j].snd.snd);
			}

			if(s.size() == 2){
				merge(v[0].snd.fst,v[0].snd.snd);
				peso += v[0].fst;
				ans*=3;
				ans %= MOD;
				continue;
			}
			if(same(v[0].snd,v[1].snd)){
				merge(v[0].snd.fst,v[0].snd.snd);
				peso += v[0].fst;
				merge(v[2].snd.fst,v[2].snd.snd);
				peso += v[2].fst;
				ans*=2;
				ans%=MOD;
				continue;

			}
			if(same(v[1].snd,v[2].snd)){
				merge(v[0].snd.fst,v[0].snd.snd);
				peso += v[0].fst;
				merge(v[2].snd.fst,v[2].snd.snd);
				peso += v[2].fst;
				ans*=2;
				ans%=MOD;
				continue;
				
			}
			if(same(v[0].snd,v[2].snd)){
				merge(v[0].snd.fst,v[0].snd.snd);
				peso += v[0].fst;
				merge(v[1].snd.fst,v[1].snd.snd);
				peso += v[1].fst;
				ans*=2;
				ans%=MOD;
				continue;
			}
			if(s.size() == 3){
				merge(v[0].snd.fst,v[0].snd.snd);
				peso += v[0].fst;
				merge(v[1].snd.fst,v[1].snd.snd);
				peso += v[1].fst;
				ans*=3;
				ans%=MOD;

			}
			if(s.size() >= 4){
				fr(j,3){
					merge(v[j].snd.fst,v[j].snd.snd);
					peso+= v[j].fst;
				}
			}
		}

	}
	return ans;
	
}

int main(){

	fastio;
	cin >> n >> m;
	init(n);

	fr(i,m){
		int a,b,p;
		aresta at;
		cin >> a >> b >> p;
		at.fst = p;
		at.snd = mp(a,b);
		edge.pb(at);
	}

	sort(all(edge));
	ll x = kruskal();

	cout << peso<< ' '<< x << endl;

}
