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
const int MOD = 1e9+7;

int n;
char tab[300300][8];
bool go[300300][9];
int memo[300300][256];
bool dd;

int pd(int i, int mask){
	if(memo[i][mask] != -1){
		return memo[i][mask];
	}
	int &pdm = memo[i][mask];

	int w = 0;
	for(int j = 1; j <= 8; j++){
		if(go[i][j] && !(mask&(1 << (j - 1)))) w = 1;
	}
	//if(dd) dbg(w);
	if(i == 1){
		pdm = w;
		return pdm;
	}

	mask = (mask<<1)%256;
	mask += w;

	pdm = pd(i - 1, mask);
	return pdm;
}


int main(){

	fastio;
	cin >> n;

	ms(memo, -1);

	frr(i, n){
		string s;
		cin >> s;

		fr(j, 8) tab[i][j] = s[j];
	}

	frr(i, n){
		frr(j, 8){
			if(i + j > n) continue;
			int ig = 0;
			fr(k, 8) if(tab[i][k] == tab[i + j][k]) ig++;
			if(ig >= j) go[i][j] = true;
		}
	}

	frr(i, n){
	//	if(i == 10) dd = true;
		if(pd(i, 255)) cout << '1';
		else cout << '2';
	}
	gnl;



}
