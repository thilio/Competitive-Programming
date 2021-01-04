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

int main(){

	fastio;
	int n;
	cin >> n;

	set<int> s;
	map<int,int> m;
	vi v;

	fr(i,n){
		int at;
		cin >> at;
		m[at]++;
		v.pb(at);
	}

	sort(all(v));

	bool lose = false;

	if(n == 1 && v[0] == 0) lose = true;
	if(m[0] > 1) lose = true;

	fr(i,n){
		if (m[v[i]] > 1) s.insert(v[i]);
		if (m[v[i]] > 2) lose = true;
	}

	if(s.size() > 1) lose = true;
	if(s.size() == 1 && m[*(s.begin()) - 1] > 0) lose = true;

	if(lose){
		cout << "cslnb\n";
		return 0;
	}

	ll par = 0ll;

	fr(i,n){
		par += v[i] - i;
	}

	if(par%2 == 0) cout <<"cslnb\n";
	else cout << "sjfnb\n";

}
