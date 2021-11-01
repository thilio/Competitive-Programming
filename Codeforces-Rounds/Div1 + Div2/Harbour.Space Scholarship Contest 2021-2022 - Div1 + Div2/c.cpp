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

int test(vector<int>& t){
	int p1, p2, s1, s2;

	p1 = p2 = 5;
	s1 = s2 = 0;

	for(int i = 0; i < 10; i++){
		if((i&1) == 0){
			s1 += t[i];
			p1--;
		}
		else{
			s2 += t[i];
			p2--;
		}

		//dbg(s2); dbg(s1);

		if(p1 + s1 < s2) return i + 1;
		if(p2 + s2 < s1) return i + 1;
	}

	return 10;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		string s;
		vector<int> t;
		cin >> s;

		int cnt = 0;
		int ans = 10;
		for(auto x: s) if(x == '?') cnt++;

		for(int mask = 0; mask < (1ll << cnt); mask++){
			t.clear();
			int p = 0;
			fr(i, 10){
				if(s[i] == '1' || s[i] == '0') t.pb(s[i] - '0');
				else{
					t.pb(mask&(1 << p));
					p++;
				}
			}
			for(auto &x: t) if(x >= 1) x = 1;

			//for(auto x: t) cout << x;
			//gnl;
			//cout << test(t) << endl;


			ans = min(ans, test(t));
		}

		cout << ans << endl;
	}

}
