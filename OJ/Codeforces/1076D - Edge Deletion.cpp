// upsolving//

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
vector<pll> v[312345];
ll d[300010];
int vis[300011],alt[300011],pai[300011];
vii are;

void djikstra(int u){
	set< pair<ll,int> > S;
	d[u] = 0ll;
	alt[u] = 0;
	vis[u] = 1;

	S.insert({0ll,u});

	while(!S.empty()){
		pair<ll,int> at = *S.begin();
		S.erase(S.begin());
		fr(i,v[at.snd].size()){
				if(d[v[at.snd][i].snd] > d[at.snd] + v[at.snd][i].fst){
					if (S.find({d[v[at.snd][i].snd],v[at.snd][i].snd}) != S.end()){
						S.erase({d[v[at.snd][i].snd],v[at.snd][i].snd});
					}
					d[v[at.snd][i].snd] = d[at.snd] + v[at.snd][i].fst;
					S.insert({d[v[at.snd][i].snd],v[at.snd][i].snd});
					alt[v[at.snd][i].snd] = alt[at.snd] + 1;
					pai[v[at.snd][i].snd] = at.snd;
				}
		}
		
	}



}



int main(){

	fastio;
	int n,m,k;
	cin >> n >> m >> k;

	fr(i,m){
		int a,b,w;
		cin >> a >> b >> w;
		v[a].pb(mp(w,b));
		v[b].pb(mp(w,a));
		are.pb(mp(a,b));
	}

	fr(i,n+2){
		d[i] = llINF;
	}

	djikstra(1);

	map<pii,int> usei;

	frr(i,n){
		if(pai[i] != 0){
			usei[{i,pai[i]}] = 1;
			usei[{pai[i],i}] = 1;

		}
	}

	set<pll> util;

	frr(i,n)
		util.insert({alt[i],i});

	int mm = 0;
	fr(i,m){
		if (usei[{are[i].fst,are[i].snd}] == 1)
			mm++;
	}
	//dbg(mm);
	
	if(mm<=k){
		cout << mm << endl;
		fr(i,m){
			if (usei[{are[i].fst,are[i].snd}] == 1)
				cout << i+1 <<' ';
		}
		gnl;
		return(0);
	}

	while(mm>k){
		pll a = *(util.rbegin());
		mm--;
		usei[{a.snd,pai[a.snd]}] = 0;
		usei[{pai[a.snd],a.snd}] = 0;
		util.erase(a);

	}

	if(mm<=k){
		cout << mm << endl;
		fr(i,m){
			if (usei[{are[i].fst,are[i].snd}] == 1)
				cout << i +1<<' ';
		}
		gnl;
		return(0);
	}

	gnl;


	//frr(i,n){
	//	cout << d[i] <<' '<<pai[i]<<' '<<alt[i]<< endl;
	//}



}
