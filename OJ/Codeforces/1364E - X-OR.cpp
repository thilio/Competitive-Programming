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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int n;
int z[20];
int idx;
int ans[3000];

int memo[3000][3000];

int ran(int N){
	return uniform_int_distribution<int>(1, N)(rng);
}

int query(int i,int j){

	if(memo[j][i] != -1) return memo[i][j];
	cout << '?' << ' ' << i << ' ' << j << endl;
	int x;
	cin >> x;

	memo[i][j] = memo[j][i] = x;

	return x;
}

void build_z(){

	int comp = 0;

	while(comp < 11){
		//dbg(comp);
		int i,j;
		i = j= 0;
		while(i == j){
			i = ran(n);
			j = ran(n);
		}
		int x = query(i,j);

		fr(k,11){
			if ((x & (1 << k)) == 0)
				if(z[k] == 0){
					z[k] = i;
					comp++;
				}
		}
	}

}

int magic(int ind){
	int ans = (1 << 11) - 1;

	fr(i,11){
		if(ind != z[i])
			ans = ans&query(ind,z[i]);
		else if(ans&(1 << i)){
			ans = ans^(1 << i);
		}
	}

	return ans;
}

void find_0(){
	idx = 1;
	int val = magic(idx);

	for(int i = 2; i <= n;i++){
		int x = query(idx,i);
		if((val|x) == val){
			idx = i;
			val = magic(i);
		}
	}
}

void build_ans(){
	frr(i,n){
		if(i != idx)
			ans[i] = query(i,idx);
	}
}

int main(){

	fastio;
	cin >> n;

	ms(memo,-1);

	build_z();
	find_0();
	build_ans();

	cout << '!' << ' ';
	frr(i,n) cout << ans[i] << ' ';
	gnl;

}
