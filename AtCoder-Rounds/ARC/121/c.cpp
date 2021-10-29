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

int p[1000];
ll n;
vi ans;
int op;

void faz(int k){
	ans.pb(k);
	op++;
	swap(p[k], p[k + 1]);
}

void forward(int j, int k){
	for(int i = j; i < k; i++){
		faz(i);
	}
}

void solve(int k){
	int j = 0;
	frr(i, n){
		if(p[i] == k) j = i;
	}
	if(j == k) return;
	if(j > k) assert(0);

	if(op%2 == j%2) forward(j, k);
	else{
		if(j >= 4){
			faz(j - 3);
			forward(j, k);
		}
		else if (j <= k - 2){
			faz(j + 1);
			forward(j, k);
		}
		else{
			faz(2);
			solve(4);
		}
	}
}

void solve_3(){
	int j = 0;
	frr(i, n){
		if(p[i] == 3) j = i;
	}
	if(j == 3 || j == 0) return;

	if(j == 1){
		if(op%2 == 1){
			faz(1); faz(2);
		}
		else{
			faz(2); faz(1); faz(2);
		}
	}
	if(j == 2){
		if(op%2 == 0) faz(2);
		else{
			faz(1); faz(2);
			faz(1); faz(2);
		}
	}
}

void solve_2(){
	if(p[1] == 1) return;
	
	if(op%2 == 1){
		faz(1);
	}
	else{
		faz(2);
		solve_3();
	}
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		ans.clear(); op = 1;
		cin >> n;
		frr(i, n) cin >> p[i];

		for(int i = n; i > 3; i--){
			solve(i);
		}

		solve_3();
		solve_2();

		assert(ans.size() <= n*n);
		frr(i, n) assert(p[i] == i);

		cout << ans.size() << endl;
		for(auto x: ans) cout << x << ' ';
		gnl;
	}

}
