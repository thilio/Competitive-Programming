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
string s;

int nxt[2][1001000];

vector<int> p[2][1001000];

int main(){

	fastio;

	cin >> n;
	cin >> s;

	int nxt0 = n; int nxt1 = n;

	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '0') nxt0 = i;
		if(s[i] == '1') nxt1 = i;	
		nxt[0][i] = nxt0 - i;
		nxt[1][i] = nxt1 - i;
	}

	for(int i = 0; i < n; i++){
		if((s[i] == '1' || s[i] == '?') && (i == 0 || s[i - 1] == '0')){
			int k = nxt[0][i];
			for (int j = 1; j <= k; j++) p[1][j].pb(i);
		}
		if((s[i] == '0' || s[i] == '?') && (i == 0 || s[i - 1] == '1')){
			int k = nxt[1][i];
			for (int j = 1; j <= k; j++) p[1][j].pb(i);
		}
	}


	for(int i = 1; i <= n; i++){
		p[0][i].pb(n + 1); p[1][i].pb(n + 1);
	}

	for(int x = 1; x <= n; x++){
		//olar;
		int ans = 0;
		int pos = 0;

		while(pos < n){
			if(nxt[0][pos] >= x || nxt[1][pos] >= x){
				pos += x;
				ans++;
			}
			else{
				auto it0 = lower_bound(all(p[0][x]), pos);
				auto it1 = lower_bound(all(p[1][x]), pos);

				int p0 = *it0;
				int p1 = *it1;

				pos = min(p0, p1) + x;
				if(pos < n + 1) ans++;
			}
		}

		cout << ans << ' ';
	}
	gnl;

}
