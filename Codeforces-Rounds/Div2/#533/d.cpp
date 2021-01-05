#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(ll i=0;i<n;i++)
#define frr(i,n)	for(ll i=1;i<=n;i++)

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

const ll INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
ll n,m,p;
ll v[10];
char mat[1010][1010];
ll d[1010][1010][10];
ll vis[1010][1010];
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
queue<pair<pii,int>> q[10];

bool is(ll i,ll j){
	if(i >= n ||i < 0||j >= m |  j < 0) return false;
	if (mat[i][j] == '#') return false;
	if(mat[i][j] == '.') return true;
	return false;
}

bool dist(ll s,ll ct){

	bool ok = false;
	
	if(ct == 1){
		fr(i,n){
			fr(j,m){
				if(mat[i][j] == '0' + s){
					q[s].push(mp(mp(i,j),0));
				}
			}
		}
	}

	while(!q[s].empty()){
		ok = true;
		pair<pii,int> aux = q[s].front();
		if(v[s]*ct < aux.snd) break;
		q[s].pop();
		ll x = aux.fst.fst;
		ll y = aux.fst.snd;
		ll dd = aux.snd;

		if(vis[x][y]== 1) continue;
		vis[x][y] = 1;
		mat[x][y] = '0' + s;
		d[x][y][s] = dd;

		fr(i,4){
			if(is(x + dx[i],y + dy[i])){
				if(vis[x + dx[i]][y + dy[i]] == 0){
					q[s].push(mp(mp(x + dx[i],y + dy[i]),dd + 1));

				}
			}
		}
	}

	return ok;


}

int main(){

	fastio;
	cin >> n >> m >> p;
	frr(i,p) cin >> v[i];
	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			mat[i][j] = s[j];
		}
	}

	ms(d,INF);

	frr(ct,m*n){
		bool aux = false;
		frr(i,p){
			aux = aux |dist(i,ct);
		}
		if(aux == false)break;
	}
	

	ll ans[10];
	ms(ans,0);


	fr(i,n){
		fr(j,m){
			frr(k,p){
				if(mat[i][j] == '0' + k) ans[k]++;
			}
		}
	}

	frr(i,p) cout << ans[i] << ' ';
	gnl;
}
