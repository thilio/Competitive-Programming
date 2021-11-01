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

int v[1010];
int n;

int main(){

	fastio;
	string s;
	cin >> s;

	n = s.size();

	fr(i, n) if(s[i] == ')') v[i]++;

	for(int i = n - 1; i >= 0; i--) v[i] += v[i + 1];

	int ind = -1;
	int p = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			p++;
			if(v[i] >= p) ind = i;
		}
	}

	if(ind == -1) cout << 0 << endl;
	else{
		cout << 1 << endl;
		vi ans;
		p = 0;
		for(int i = 0; i <= ind; i++){
			if(s[i] == '('){
				ans.pb(i);
				p++;
			}
		}

		for(int i = n - 1; i > ind; i--){
			if(s[i] == ')' && p > 0){
				ans.pb(i);
				p--;
			}
		}

		sort(all(ans));
		cout << ans.size() <<endl;

		for(auto x: ans){
			cout << x + 1 << ' ';
		}
		gnl;
	} 

}
