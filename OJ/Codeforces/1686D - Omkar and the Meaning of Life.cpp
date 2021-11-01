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

int n;
int last;

int perm[110];

int query(vi &v){
	cout << '?';
	for(auto x: v) cout << ' ' << x;
	gnl;
	int k;
	cin >> k;
	return k;
}

bool rep(int k){
	vi v;
	fr(i, n - 1) v.pb(1);
	v.pb(k);
	int ans = query(v);
	if(ans == 0) return false;
	else return true;
}

int find_last(){

	for(int l = 2; l <= n; l++){
		if(!rep(l)) return n + 2 - l;
	}

	return 1;
}

int where(int k){
	vi v;
	fr(i, n - 1){
		v.pb(n + 1 - k);
	}
	v.pb(n + 1 - last);

	return query(v);
}

int main(){

	fastio;

	cin >> n;

	last = find_last();
	perm[n] = last;

	frr(i, n){
		if(i != last)
			perm[where(i)] = i;
	}

	cout << '!';
	frr(i, n) cout << ' ' << perm[i];
	gnl;

}
