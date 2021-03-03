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

bool tent(string& s, int mask){
	int open = 0;
	for(auto x: s){
		int y = (int)(x - 'A');
		if(mask&(1 << y)) open++;
		else open--;
		if(open < 0) return false;
	}

	if(open == 0) return true;
	return false;
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		bool ok = false;
		fr(i,8){
			ok |= tent(s,i);
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
