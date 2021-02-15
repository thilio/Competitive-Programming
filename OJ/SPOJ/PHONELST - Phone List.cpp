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

struct trie{
	int cnt,wrd;
	map<char,trie> m;
	trie(){
		cnt = 0;wrd = 0;
		m.clear();
	}
	bool add(string &s,int i){ // add string to trie
		if(wrd) return false;
		cnt++;
		if(i == s.size()){
			if(cnt > 1) return false;
			wrd++;
			return true;
		}
		if(!m.count(s[i])){
			m[s[i]] = trie();
		}
		return m[s[i]].add(s,i+1);
	}
};

int main(){

	fastio;
	int test;
	cin >> test;
	while(test--){
		bool ok = true;
		trie T = trie();
		int n;
		cin >> n;
		fr(i,n){
			string s;
			cin >> s;
			ok = ok&T.add(s,0);
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

}
