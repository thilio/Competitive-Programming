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

int p[30][100100];

bool rep[100100];
int final[100100];
int to[100100];
int ans[100100];

int saida;

void build(){
	for(int i = 1; i < 30; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}
}

void build_to(int r){
	frr(i, n) to[i] = i;

	for(int i = 0; i < 30; i++){
		if(r & (1 << i)){
			frr(j, n) to[j] = p[i][to[j]];
		}
	}
}

int main(){

	fastio;
	cin >> n;

	frr(i, n){
		cin >> p[0][i];
		if(rep[p[0][i]]) saida++;
		rep[p[0][i]] = true;
	}

	frr(i, n) rep[i] = false;

	build();

	int mx = -1;
	frr(i, n){
		cin >> final[i];
		if(final[i] <= n) rep[final[i]] = true;
		mx = max(mx, final[i]);
	}

	int r = (mx - n)/saida;

	build_to(r);

	set<int> fix, nfix;

	frr(i, n){
		if(rep[i]) fix.insert(i);
		else nfix.insert(i);
	}

	frr(i, n){
		int mn = final[to[i]];

		if(fix.find(mn) != fix.end()){
			ans[i] = mn;
			fix.erase(mn);
		}
		else{
			auto it = nfix.lower_bound(mn);

			ans[i] = *(it);

			nfix.erase(it);
		}
	}

	frr(i, n){
		cout << ans[i] << ' ';
	}
	gnl;


	


}
