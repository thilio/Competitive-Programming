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
int v[100100];

set<pii> linha2;
set<pii> linha3; 

vector<pii> ans;

void finish(){
	cout << -1 << endl;
	exit(0);
}


int main(){

	fastio;
	
	cin >> n;

	frr(i, n) cin >> v[i];
	int k = 1;

	for(int i = n; i > 0; i--){
		if(v[i] == 0) continue;
		if(v[i] == 1){
			ans.pb({i, k});
			linha2.insert({k, i});
			k++;
		}
		if(v[i] == 2){
			if(linha2.empty()){
				finish();
			}
	//		dbg(linha2.size());
			auto it = linha2.begin();
			int aux = (*it).fst;
		//	dbg(aux);
			linha2.erase(it);
			ans.pb({i, aux});
			linha3.insert({aux, i});

		}
		if(v[i] == 3){
			if(!linha3.empty()){
				auto it = linha3.begin();
				pii aux = (*it);
				linha3.erase(it);
				ans.pb({i, k});
				ans.pb({aux.snd, k});
				linha3.insert({k,i});
				k++;
			}
			else if(!linha2.empty()){
				//dbg(linha2.size());
				auto it = linha2.begin();
				pii aux = (*it);
				linha2.erase(it);
				//dbg(aux.fst);
				ans.pb({i, k});
				ans.pb({aux.snd, k});
				linha3.insert({k, i});
				k++;
			}
			else{
				finish();
			}
		}
	}

	for(auto &x: ans){
		swap(x.fst, x.snd);
		x.fst = n + 1 - x.fst;
	}

	cout << ans.size() << endl;
	for(auto x: ans){
		cout << x.fst << ' ' << x.snd << endl;
	}
}
