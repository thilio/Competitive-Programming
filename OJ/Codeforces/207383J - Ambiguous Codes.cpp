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

int n;

string its[6000];
bool prop[6000];

unordered_map<string,int> full; // N PRECISA MAS ACELERA
unordered_map<string,int> suf; // N PRECISA MAS ACELERA

string words[6000];

vii adj[10010];

int dist[10010];
set<pii> S;

void limpa(){
	fr(i,6000){
		adj[i].clear();
		dist[i] = INF;
		prop[i] = false;
		its[i] = "";
		words[i] = "";
	}
	full.clear();
	suf.clear();
	S.clear();
}

void tent1(string& t,string& q,string& l){
	l.clear();

	fr(i,q.size()){
		if(q[i] != t[i]) return;
	}

	for(int i = q.size(); i < t.size();i++) l.pb(t[i]);

}

int Dijkstra(int v){

	dist[v] = 0;
	S.insert(mp(0,v));


	int resp = INF;

	while(!S.empty()){
		auto it = S.begin();
		int u = (*it).snd;
		int d = (*it).fst;
		S.erase(it);

		fr(i,adj[u].size()){
			int v = adj[u][i].fst;
			if(v == 0){
				resp = min(resp,d + adj[u][i].snd);
			}
			if(dist[v] > d + adj[u][i].snd){
				dist[v] = d + adj[u][i].snd;
				S.insert(mp(dist[v],v));
			}
		}
	}

	return resp;

}

int main(){

	fastio;
	cin >> n;

	while(n != 0){

		limpa();

		string s;
		s = "";

		
	 	its[1] = s;
		prop[1] = false;

		suf[s] = 1;
		getline(cin,s);

		int ind = 2;

		fr(i,n){
			getline(cin,s);
			words[i] = s;
			string q;
			string t;

			for(int j = s.size()- 1;j > 0;j--){
				t = s[j];
				q.insert(0,t);
				if(suf[q] == 0){
					suf[q] = ind;
			 		its[ind] = q;
					prop[ind] = false;
					ind++;
				}
			}

			full[s] = ind;
		 	its[ind] = s;
			prop[ind] = (true);
			ind++;
		}

		fr(i,n){
			string t = words[i];
			int vtx = full[t];

			adj[1].pb(mp(vtx,t.size()));
		}

		for(int i = 2; i < ind;i++){
			fr(j,n){
				

				int n1 = its[i].size();
				int n2 = words[j].size();

				if(prop[i]){
					if(n1 == n2) continue;
				}

				if(n1 == n2){
					if (its[i] == words[j]){
						adj[i].pb(mp(0,0));
					}
				}

				string k;

				if(n1>n2){
					tent1(its[i],words[j],k);
					if(k.size() != 0){
						adj[i].pb(mp(suf[k],0));
						if(full.count(k))
							adj[i].pb(mp(full[k],0));
					}
					
				}

				if(n2>n1){
					tent1(words[j],its[i],k);
					if(k.size() != 0){
						adj[i].pb(mp(suf[k],n2-n1));
						if(full.count(k))
							adj[i].pb(mp(full[k],n2-n1));
					}


				}

			}
		}

		int ans = Dijkstra(1);

		if(ans == INF) ans = -1;

		cout << ans << endl;

		cin >> n;
	}

}
