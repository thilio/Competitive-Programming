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

int n, T;
int nh, nv;
vector<pair<ll, pll >> hori, vert;
vector<int> ordem[2][700];
pll inter[700][700];
pll start;

void read(){
	int sx, sy, ex , ey;

	fr(i,n){
		cin >> sx >> sy >> ex >> ey;
		if(sx == ex){
			int st = min(sy, ey);
			int en = max(sy, ey);
			vert.pb(mp(sx, mp(st, en)));
		}
		else{
			int st = min(sx, ex);
			int en = max(sx, ex);
			hori.pb(mp(sy, mp(st, en)));
		}
		if(i == 0){
			start = mp(sx, sy);
		}
	}
}

bool intersec_hv(int i, int j){ // i hori e j vert
	pair<ll, pll> h = hori[i];
	pair<ll, pll> v = vert[j];

	if(h.snd.fst <= v.fst && v.fst <= h.snd.snd){
		if(v.snd.fst <= h.fst && h.fst <= v.snd.snd)
			return true;
	}

	return false;
}

ll go(int i, int dir, pll estou, bool fim){
	if(fim && (estou == start)) return 0;
	if(dir == 0){
		int j = 0;
		while(j < ordem[0][i].size() && vert[ordem[0][i][j]].fst <= estou.fst) j++;
		if(j == ordem[0][i].size()){
			ll delta = hori[i].snd.snd - estou.fst;
			return delta + go(i, 2, mp(hori[i].snd.snd, hori[i].fst), true);
		}
		else{
			ll delta = vert[ordem[0][i][j]].fst - estou.fst;
			return delta + go(ordem[0][i][j], 3, inter[i][ordem[0][i][j]], true);
		}
	}

	if(dir == 1){
		int j = ordem[1][i].size() - 1;
		while(j >= 0 && hori[ordem[1][i][j]].fst >= estou.snd) j--;
		if(j == -1){
			ll delta = estou.snd - vert[i].snd.fst;
			return delta + go(i, 3 , mp(vert[i].fst, vert[i].snd.fst), true);
		}
		else{
			ll delta = estou.snd - hori[ordem[1][i][j]].fst;
			return delta + go(ordem[1][i][j], 0, inter[ordem[1][i][j]][i], true);
		}
	}

	if(dir == 2){
		int j = ordem[0][i].size() - 1;
		while(j >= 0 && vert[ordem[0][i][j]].fst >= estou.fst) j--;
		if(j == -1){
			ll delta = estou.fst - hori[i].snd.fst;
			return delta + go(i, 0 , mp(hori[i].snd.fst, hori[i].fst), true);
		}
		else{
			ll delta = estou.fst - vert[ordem[0][i][j]].fst;
			return delta + go(ordem[0][i][j], 1, inter[i][ordem[0][i][j]], true);
		}
	}

	if(dir == 3){
		int j = 0;
		while(j < ordem[1][i].size() && hori[ordem[1][i][j]].fst <= estou.snd) j++;
		if(j == ordem[1][i].size()){
			ll delta = vert[i].snd.snd - estou.snd;
			return delta + go(i, 1 , mp(vert[i].fst, vert[i].snd.snd), true);
		}
		else{
			ll delta = hori[ordem[1][i][j]].fst - estou.snd;
			return delta + go(ordem[1][i][j], 2, inter[ordem[1][i][j]][i], true);
		}
	}

	return 0;
}

pll go_f(int i, int dir, pll estou, int tempo){
	if(tempo == 0) return estou;

	if(dir == 0){
		int j = 0;
		while(j < ordem[0][i].size() && vert[ordem[0][i][j]].fst <= estou.fst) j++;
		if(j == ordem[0][i].size()){
			ll delta = hori[i].snd.snd - estou.fst;
			if(tempo < delta){
				return mp(estou.fst + tempo, estou.snd);
			}
			return go_f(i, 2, mp(hori[i].snd.snd, hori[i].fst), tempo - delta);
		}
		else{
			ll delta = vert[ordem[0][i][j]].fst - estou.fst;
			if(tempo < delta){
				return mp(estou.fst + tempo, estou.snd);
			}
			return go_f(ordem[0][i][j], 3, inter[i][ordem[0][i][j]], tempo - delta);
		}
	}

	if(dir == 1){
		int j = ordem[1][i].size() - 1;
		while(j >= 0 && hori[ordem[1][i][j]].fst >= estou.snd) j--;
		if(j == -1){
			ll delta = estou.snd - vert[i].snd.fst;
			if(tempo < delta){
				return mp(estou.fst, estou.snd - tempo);
			}
			return go_f(i, 3 , mp(vert[i].fst, vert[i].snd.fst), tempo - delta);
		}
		else{
			ll delta = estou.snd - hori[ordem[1][i][j]].fst;
			if(tempo < delta){
				return mp(estou.fst, estou.snd - tempo);
			}
			return go_f(ordem[1][i][j], 0, inter[ordem[1][i][j]][i], tempo - delta);
		}
	}

	if(dir == 2){
		int j = ordem[0][i].size() - 1;
		while(j >= 0 && vert[ordem[0][i][j]].fst >= estou.fst) j--;
		if(j == -1){
			ll delta = estou.fst - hori[i].snd.fst;
			if(tempo < delta){
				return mp(estou.fst - tempo, estou.snd);
			}
			return go_f(i, 0 , mp(hori[i].snd.fst, hori[i].fst), tempo - delta);
		}
		else{
			ll delta = estou.fst - vert[ordem[0][i][j]].fst;
			if(tempo < delta){
				return mp(estou.fst - tempo, estou.snd);
			}
			return go_f(ordem[0][i][j], 1, inter[i][ordem[0][i][j]], tempo - delta);
		}
	}

	if(dir == 3){
		int j = 0;
		while(j < ordem[1][i].size() && hori[ordem[1][i][j]].fst <= estou.snd) j++;
	
		if(j == ordem[1][i].size()){
			ll delta = vert[i].snd.snd - estou.snd;
			if(tempo < delta){
				return mp(estou.fst, estou.snd + tempo);
			}
			return go_f(i, 1 , mp(vert[i].fst, vert[i].snd.snd),tempo - delta);
		}
		else{
			ll delta = hori[ordem[1][i][j]].fst - estou.snd;
			if(tempo < delta){
				return mp(estou.fst, estou.snd + tempo);
			}
			return go_f(ordem[1][i][j], 2, inter[ordem[1][i][j]][i], tempo - delta);
		}
	}

	return {0, 0};
}

int main(){

	fastio;
	cin >> n >> T;
	read();
	sort(all(hori));
	sort(all(vert));

	nh = hori.size();
	nv = vert.size();

	fr(i, nh){
		fr(j, nv){
			if(intersec_hv(i, j)){
				ordem[0][i].pb(j);
				inter[i][j] = mp(vert[j].fst, hori[i].fst);
			} 
				
		}
	}

	fr(i, nv){
		fr(j, nh){
			if(intersec_hv(j, i)) ordem[1][i].pb(j);
		}
	}
	int dir;
	int qual;
	fr(i, nh){
		if(start.snd == hori[i].fst){
			if(start.fst == hori[i].snd.fst){
				qual = i;
				dir = 0;
			}
			if(start.fst == hori[i].snd.snd){
				qual = i;
				dir = 2;
			}
		}
	}

	fr(i, nv){
		if(start.fst == vert[i].fst){
			if(start.snd == vert[i].snd.fst){
				qual = i;
				dir = 3;
			}
			if(start.snd == vert[i].snd.snd){
				qual = i;
				dir = 1;
			}
		}
	}
	
	ll sz = go(qual, dir, start, false);

	T %= sz;

	pll ans = go_f(qual, dir, start, T);

	cout << ans.fst << ' ' << ans.snd << endl;

}
