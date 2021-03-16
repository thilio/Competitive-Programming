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

int n,m;

vi v;
vi t[250250];

void print(){
	cout << "Yes" << endl;
	for(auto x: v){
		cout << x << ' ';
	}
	gnl;
	exit(0);
}

bool tenta(){
	bool ok = true;
	fr(i,n){
		int dife = 0;
		fr(j,m){
			dife += (v[j] != t[i][j]);
		}
		if(dife > 2) return false;
		//if(i > 6) olar;
	}
	return true;
}

void go(vi &dif){
	int delta = dif.size();
	if(tenta()) print();

	//for(auto x: dif) cout << x;
	//	gnl;


	if(delta == 2){
		return;
	}

	vi at;
	fr(i,n){
		at.clear();
		fr(j,m){
			if(v[j] != t[i][j]) at.pb(j);
		}
		if(delta == 0){
			if(at.size() >= 5) return;
			if(at.size() == 4){
				fr(mask, 16){
					if(__builtin_popcount(mask) == 2){
						fr(k, 4){
							if((1 << k)&mask) dif.pb(at[k]);
						}
						assert(dif.size() == 2);
						vi save = {v[dif[0]], v[dif[1]]};
						v[dif[0]] = t[i][dif[0]];
						v[dif[1]] = t[i][dif[1]];
						go(dif);
						v[dif[0]] = save[0];
						v[dif[1]] = save[1];
						dif.clear();
					}
				}
				return;
			}
			if(at.size() == 3){
				fr(mask, 8){
					if(__builtin_popcount(mask) == 2){
						fr(k, 3){
							if((1 << k)&mask) dif.pb(at[k]);
						}
						assert(dif.size() == 2);
						vi save = {v[dif[0]], v[dif[1]]};
						v[dif[0]] = t[i][dif[0]];
						v[dif[1]] = t[i][dif[1]];
						go(dif);
						v[dif[0]] = save[0];
						v[dif[1]] = save[1];
						dif.clear();
					}
					if(__builtin_popcount(mask) == 1){
						fr(k, 3){
							if((1 << k)&mask) dif.pb(at[k]);
						}
						assert(dif.size() == 1);
						int save = v[dif[0]];
						v[dif[0]] = t[i][dif[0]];
						go(dif);
						v[dif[0]] = save;
						dif.clear();
					}
				}
				return;
			}
		}
		if(delta == 1){
			if(at.size() >= 4) return;
			if(at.size() == 3){
				fr(mask, 8){
					if(__builtin_popcount(mask) == 1){
						fr(k, 3){
							if((1 << k)&mask) dif.pb(at[k]);
						}
						if(dif[0] == dif[1]){
							dif.pop_back();
							continue;
						}
						assert(dif.size() == 2);
						int save = v[dif[1]];
						v[dif[1]] = t[i][dif[1]];
						go(dif);
						v[dif[1]] = save;
						dif.pop_back();
					}
				}
				return;
			}
			
		}

	}

}

int main(){

	fastio;

	cin >> n >> m;

	fr(i,m){
		int x;
		cin >> x;
		v.pb(x); 
	}
	n--;
	fr(i,n){
		fr(j,m){
			int x;
			cin >> x;
			t[i].pb(x);
		}
	}

	vi dif;

	go(dif);

	cout << "No" << endl;

}
