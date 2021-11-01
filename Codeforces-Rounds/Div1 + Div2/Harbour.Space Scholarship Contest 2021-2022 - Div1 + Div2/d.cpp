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

bool find(string& s, string& t, int p){
	int i = 0;
	int start = -1; 
	while(i < s.size()){
		if(s[i] == t[0] && i%2 == p%2){
			start = i;
			break;
		}
		i++;
	}
	if(start == -1) return false;

	//dbg(start);

	i = 1; // change index to t;

	int last = start;
	int at = start + 1;

	while(at < s.size() && i < t.size()){
		if(s[at] == t[i] && at%2 != last%2){
			last = at;
			at++;
			i++;
		}
		else{
			at++;
		}
	}

	//dbg(i);

	if(i == t.size()) return true;
	return false;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		string s, t;
		cin >> s >> t;

		int ns = s.size();
		int nt = t.size();
		bool ok;
		if(ns%2 == nt%2){
			ok = find(s, t, 0);
		} 
		else{
			ok = find(s, t, 1);
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
