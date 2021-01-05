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
	string s;
	int k;
	getline(cin,s);
	//dbg(s);
	int n = s.size();
	cin >> k;

	int snow = -1;
	
	fr(i,n){
		if(s[i] == '*')
			snow = i;
	}

	int sp = 0;

	fr(i,n){
		if(s[i] == '*' || s[i] == '?')
			sp++;
	}

	int mn = n - 2*sp;

	if(mn > k){
		cout << "Impossible" << endl;
		return 0;
	}

	int mx = n - sp;

	if(k >= mn && k <= mx){
		int aux = mx - k;
		vector<char> ans;
		fr(i,s.size() - 1){
			if(s[i] == '*' || s[i] == '?' ) continue;
			if((s[i+1]== '*' || s[i+1]=='?') && (aux > 0)){
				aux--;
				continue;
			}
			ans.pb(s[i]);
		}
		ans.pb(s[n-1]);
		fr(i,ans.size() - 1){
			cout << ans[i];
		}
		if(ans[ans.size() - 1] != '*' && ans[ans.size() - 1] != '?') cout << ans[ans.size() - 1];

		gnl;
		return 0;
	}

	if(snow == -1){
		cout << "Impossible" << endl;
		return 0;
	}

	int aux = k - mn;
	bool ja = false;
	vector<char> ans;

	fr(i,s.size() - 1){
		if(s[i] == '*' || s[i] == '?' ) continue;
		if(s[i+1] == '*' && ja == false){
			fr(j,aux) ans.pb(s[i]);
			ja=true;
			continue;
		}
		if(s[i+1]=='*' || s[i+1] == '?') continue;
		ans.pb(s[i]);
	}

	ans.pb(s[n-1]);

	//dbg(ans.size());
	//olar;
	fr(i,ans.size()-1) cout << ans[i];
	if(ans[ans.size() - 1] != '*' && ans[ans.size() - 1] != '?') cout << ans[ans.size() - 1];
	gnl;



}
