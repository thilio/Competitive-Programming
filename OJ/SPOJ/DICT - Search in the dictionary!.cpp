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
	void add(string &s,int i){ // add string to trie
		cnt++;
		if(i == s.size()){
			wrd++;
			return;
		}
		if(!m.count(s[i])){
			m[s[i]] = trie();
		}
		m[s[i]].add(s,i+1);
	}

	bool dfs(string &s, int i, string &p){
		if(i < s.size()){
			if(!m.count(s[i])) return false;
			p.pb(s[i]);
			return m[s[i]].dfs(s, i + 1, p);
		}
		else{
			bool ok = false;
			if(wrd > 0 && i > s.size()){
				cout << p << endl;
				ok = true;
			}
			for(auto &x: m){
				p.pb(x.fst);
				ok |= x.snd.dfs(s, i + 1,p);
				p.pop_back();
			}
			return ok;
		}
	}
};

int main(){

	fastio;
	trie T = trie();
	int n;
	cin >> n;

	fr(i,n){
		string s;
		cin >> s;
		T.add(s,0);
	}

	int k;
	cin >> k;

	string p;
	fr(i,k){
		string s;
		cin >> s;
		p.clear();
		cout << "Case #" << i + 1 <<':' << endl; 
		if(!T.dfs(s,0,p)) cout << "No match." << endl;
	}


}