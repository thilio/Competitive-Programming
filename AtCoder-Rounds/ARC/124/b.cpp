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
int a[3000], b[3000];

set<int> ja; 

bool test(int x){
	if(ja.find(x) != ja.end()){
		return false;
	}
	ja.insert(x);

	vector<int> bl, al;
	al.clear(); bl.clear();
	fr(i, n){
		al.pb(a[i]^x);
		bl.pb(b[i]);
	}

	sort(all(al));
	sort(all(bl));

	return (al == bl);

}

int main(){

	fastio;

	cin >> n;

	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	vi ans;

	fr(i, n){
		if(test(a[0]^b[i])) ans.pb(a[0]^b[i]);
	}

	sort(all(ans));

	cout << ans.size() << endl;

	for(auto x: ans) cout << x << endl;

}
