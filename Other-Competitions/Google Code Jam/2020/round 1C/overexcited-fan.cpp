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

int dist(int x,int y){
	return abs(x) + abs(y);
}
int main(){

	fastio;

	int T;
	cin >> T;
	int g = 1;
	while(T--){
		int x,y;
		cin >> x >> y;
		string t;
		string s;
		getline(cin,t);

		fr(i,t.size()){
			if(t[i] >= 'A' && t[i] <= 'Z') s.pb(t[i]);
		}

		int ans = -1;

		fr(i,s.size()){
			if(s[i] == 'N') y++;
			if(s[i] == 'S') y--;
			if(s[i] == 'E') x++;
			if(s[i] == 'W') x--;

			//dbg(x);dbg(y);

			if(dist(x,y) <= i + 1 && ans == -1){
				ans = i + 1;
			}

		}

		cout << "Case #" << g++ << ": ";

		if(ans == -1) cout << "IMPOSSIBLE";
		else cout << ans;

		gnl;



		
	}

}
