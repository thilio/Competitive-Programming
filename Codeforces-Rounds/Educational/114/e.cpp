#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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
const int MOD = 998244353;

ll n, m, k;
ll pot[1000100];

map<pii, int> tab;
pair<int, int> line[1000100];
pair<int, int> col[1000100];

int fixedl, fixedc;
int totc1, totc2;
int vstrip, hstrip;

void clear(int x, int y){
	if(!tab.count({x, y})) return;
	if(tab[{x, y}] == -1) return;

	int t = tab[{x, y}];
	tab[{x, y}] = -1;

	int chess;

	if((x + y)%2){
		if(t == 1) chess = 1;
		else chess = 2;
	}
	else{
		if(t == 0) chess = 1;
		else chess = 2;
	}

	if(chess == 1){
		totc1--;
		line[x].fst--;
		if(line[x].fst == 0 && line[x].snd > 0) vstrip--;
		if(line[x].fst == 0 && line[x].snd == 0) fixedl--;
		col[y].fst--;
		if(col[y].fst == 0 && col[y].snd > 0) hstrip--;
		if(col[y].fst == 0 && col[y].snd == 0) fixedc--;
	}

	if(chess == 2){
		totc2--;
		line[x].snd--;
		if(line[x].fst > 0 && line[x].snd == 0) vstrip--;
		if(line[x].fst == 0 && line[x].snd == 0) fixedl--;
		col[y].snd--;
		if(col[y].fst > 0  && col[y].snd == 0) hstrip--;
		if(col[y].fst == 0 && col[y].snd == 0) fixedc--;
	}
}

void add(int x, int y, int t){
	tab[{x, y}] = t;

	int chess;
	if((x + y)%2){
		if(t == 1) chess = 1;
		else chess = 2;
	}
	else{
		if(t == 0) chess = 1;
		else chess = 2;
	}

	if(chess == 1){
		totc1++;
		line[x].fst++;
		if(line[x].fst == 1 && line[x].snd > 0) vstrip++;
		if(line[x].fst == 1 && line[x].snd == 0) fixedl++;
		col[y].fst++;
		if(col[y].fst == 1 && col[y].snd > 0) hstrip++;
		if(col[y].fst == 1 && col[y].snd == 0) fixedc++;
	}

	if(chess == 2){
		totc2++;
		line[x].snd++;
		if(line[x].fst > 0 && line[x].snd == 1) vstrip++;
		if(line[x].fst == 0 && line[x].snd == 1) fixedl++;
		col[y].snd++;
		if(col[y].fst > 0  && col[y].snd == 1) hstrip++;
		if(col[y].fst == 0 && col[y].snd == 1) fixedc++;
	}
}

int main(){

	fastio;
	cin >> n >> m >> k;

	pot[0] = 1;
	for(int i =1; i <= 1000000; i++) pot[i] = (2*pot[i - 1])%MOD; 

	for(int i = 0; i < k ; i++){
		int x, y, t;
		cin >> x >> y >> t;

		if(t == -1){
			clear(x, y);
		}
		else{
			clear(x, y);
			add(x, y, t);
		}

		if(vstrip > 0 && hstrip > 0){
			cout << 0 << endl;
		}
		else if(vstrip > 0){
			cout << pot[m - fixedc] << endl;
		}
		else if(hstrip > 0){
			cout << pot[n - fixedl] << endl;
		}
		else{
			ll ans = pot[n - fixedl] + pot[m - fixedc];
			if(totc1 > 0 && totc2 > 0);
			else if(totc1 + totc2 != 0) ans--;
			else ans -= 2;
			ans = (ans + MOD)%MOD;
			cout << ans << endl;
		}
	}
}
