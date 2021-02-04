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

int n,m,k;
unordered_map<string,vi> pattern;

vi adj[100100];
int in[100100];

void brute(string& s,int aa){
	int ct = 0;
	vi pos;
	pos.clear();
	fr(i,k){
		if(s[i] == '_'){
			ct++;
			pos.pb(i);
		}
	}

	if(ct == 0){
		pattern[s].pb(aa);
	}

	if(ct == 1){
		fr(i1,26){
			fr(j,k){
				if(j == pos[0]) s[j] = 'a' + i1;
			}
			pattern[s].pb(aa);
		}
	}

	if(ct == 2){
		fr(i1,26){
			fr(i2,26){
				fr(j,k){
					if(j == pos[0]) s[j] = 'a' + i1;
					if(j == pos[1]) s[j] = 'a' + i2;
				}	
				pattern[s].pb(aa);
			}
		}
	}

	if(ct == 3){
		fr(i1,26){
			fr(i2,26){
				fr(i3,26){
					fr(j,k){
						if(j == pos[0]) s[j] = 'a' + i1;
						if(j == pos[1]) s[j] = 'a' + i2;
						if(j == pos[2]) s[j] = 'a' + i3;
					}	
					pattern[s].pb(aa);
				}
			}
		}
	}

	if(ct == 4){
		fr(i1,26){
			fr(i2,26){
				fr(i3,26){
					fr(i4,26){
						fr(j,k){
							if(j == pos[0]) s[j] = 'a' + i1;
							if(j == pos[1]) s[j] = 'a' + i2;
							if(j == pos[2]) s[j] = 'a' + i3;
							if(j == pos[3]) s[j] = 'a' + i4;
						}	
						pattern[s].pb(aa);
					}
				}
			}
		}
	}



}

int main(){

	fastio;

	cin >> n >> m >> k;
	string s;
	fr(i,n){
		cin >> s;
		brute(s, i);
	}
	fr(i,m){
		cin >> s;
		int x;
		cin >> x;
		x--;
		bool ok = false;
		for(auto t : pattern[s]){
			if(t != x){
				adj[x].pb(t);
				in[t]++;
			}
			if(t == x){
				ok = true;
			}
		}
		if (!ok){
			cout << "NO" << endl;
			return 0;
		}
	}

	vi topo;
	queue<int> q;

	fr(i,n) if(in[i] == 0){
		q.push(i);
		topo.push_back(i);
	}

	while(!q.empty()){
		int at = q.front();
		q.pop();
		for(auto xx: adj[at]){
			in[xx]--;
			if(in[xx] == 0){
				topo.push_back(xx);
				q.push(xx);
			}
		}
	}
	

	if(topo.size() != n){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for(auto xx : topo) cout << xx + 1 << ' ';
		gnl;
	}



}
