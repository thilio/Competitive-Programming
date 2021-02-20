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

map<int,int> M;
set<int> S;

void remove(int x){
	bool antes = M.count(x - 1);
	bool depois = M.count(x + 1);

	if(!antes && !depois){
		M[x] = x;
		S.insert(x);
	}
	else if(antes && !depois){
		int com = M[x - 1];
		M.erase(x - 1);
		M[com] = x;
		M[x] = com;
	}
	else if(!antes && depois){
		int fim = M[x + 1];
		M.erase(x + 1);
		S.erase(x + 1);
		M[fim] = x;
		S.insert(x);
		M[x] = fim;
	}
	else if(antes && depois){
		int com = M[x - 1];
		int fim = M[x + 1];
		M.erase(x - 1);
		M.erase(x + 1);
		S.erase(x + 1);
		M[com] = fim;
		M[fim] = com;
	}
}

void add(int x){
	if(S.find(x) != S.end()){
		if(M[x] == x){
			M.erase(x);
			S.erase(x);
		}
		else{
			int fim = M[x];
			M.erase(x);
			S.erase(x);
			M[x + 1] = fim;
			S.insert(x + 1);
			M[fim] = x + 1;
		}
		return;
	}
	if(M.count(x)){
		int ini = M[x];
		M.erase(x);
		M[x - 1] = ini;
		M[ini] = x - 1;
	}
	else{
		auto it = S.lower_bound(x);
		it--;
		int com = (int)(*it);
		int fim = M[com];

		M[com] = x - 1;
		M[x - 1] = com;

		M[x + 1] = fim;
		M[fim] = x + 1;

		S.insert(x + 1);
	}
}

int main(){

	fastio;
	int T;
	int caso = 1;
	cin >> T;
	while(T--){
		cout << "Case " << caso++ << ":" << endl;
		S.clear();
		M.clear();
		int n,k,q;
		cin >> n >> k >> q;
		S.insert(k + 1);
		M[k + 1] = n;
		M[n] = k + 1;

		fr(i,q){
			int x,y;
			cin >> x >> y;
			remove(x);
			//if(M.count(2)) dbg(M[2]);
			//dbg(S.size());
			add(y);
			cout << S.size() << endl;
		}
	}

}
