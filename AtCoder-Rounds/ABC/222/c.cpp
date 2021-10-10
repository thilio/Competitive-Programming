#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
//#define endl '\n'
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

int n, m;

vector<pii> rodada[200];
char play[200][200];

int game(char a, char b){ // 1 if a wins, 2 if draw, 3 if b wins
	if(a == b) return 2;
	if(a == 'G' && b == 'C') return 1;
	if(a == 'C' && b == 'P') return 1;
	if(a == 'P' && b == 'G') return 1;
	return 3;
}

void go(int i){
	for(int j = 1; j <= n; j++){
		int p1 = rodada[i][2*j - 2].snd;
		int p2 = rodada[i][2*j - 1].snd;

		int w1 = rodada[i][2*j - 2].fst;
		int w2 = rodada[i][2*j - 1].fst;

		int x = game(play[p1][i], play[p2][i]);
		//dbg(x);
		if(x == 1){
			rodada[i + 1].pb({w1 - 1, p1});
			rodada[i + 1].pb({w2, p2});
		}
		if(x == 2){
			rodada[i + 1].pb({w1, p1});
			rodada[i + 1].pb({w2, p2});
		}
		if(x == 3){
			rodada[i + 1].pb({w1, p1});
			rodada[i + 1].pb({w2 - 1, p2});
		}
	}
}

int main(){

	fastio;

	cin >> n >> m;

	string s;

	getline(cin, s);

	frr(i, 2*n){
		
		getline(cin, s);
		//	dbg(s);
		frr(j, m){
			play[i][j] = s[j - 1];
		}
	}

	frr(i, 2*n){
		rodada[1].pb({0, i});
	}

	for(int i = 1; i <= m; i++){
		//dbg(i);
		//for(auto x: rodada[i]) dbg(x.snd);


		go(i);
		sort(all(rodada[i + 1]));
	}

	for(auto x: rodada[m + 1]){
		cout << x.snd << endl;
	}

}
