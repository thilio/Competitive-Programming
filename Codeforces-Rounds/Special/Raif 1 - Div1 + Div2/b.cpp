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

	int T;
	cin >> T;
	while(T--){
		int n; string s;
		cin >> n >> s;

		bool all_cl = true;
		bool all_an = true;

		for(auto x: s){
			if(x == '<') all_cl = false;
			if(x == '>') all_an = false;
		}

		if(all_cl || all_an){
			cout << n << endl;
			continue;
		}

		int ans = 0;
		fr(i, n){
			if(s[i] == '-' || s[(i - 1 + n)%n] == '-') ans++;
		}

		cout << ans << endl;
	}

}
