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
#define endl '\n'

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
int level;
int v[2000];

void solve(){
	cin >> n;
	level = 1;
	frr(i, n) v[i] = 0;

	fr(i, n){
		int x;
		cin >> x;
		int j;
		for(j = level; j >= 1; j--){
			if(v[j] == x - 1) break;
			v[j] = 0;
		}
		v[j] = x;
		level = j;
		frr(i, level - 1){
			cout << v[i] << '.';
		}
		cout << v[level] << endl;
		level++;
	}

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		solve();
	}

}
