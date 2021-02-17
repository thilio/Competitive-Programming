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
	pair<bool, bool> dfs(){
		bool force_w, force_l;
		force_w = false;
		force_l = false;
		int i = 0;
		for(auto &x: m){
			i++;
			pair<bool, bool> son = x.snd.dfs();
			force_w |= (!son.fst);
			force_l |= (!son.snd); 
		}
		if(i == 0){
			return mp(false, true);
		}
		else return mp(force_w, force_l);

	}
};

int main(){

	fastio;

	int n,k;
	cin >> n >> k;
	trie T = trie();
	fr(i,n){
		string s;
		cin >> s;
		T.add(s,0);
	}

	pair<bool, bool> ans = T.dfs();

	if(ans == mp(true,true)){
		cout << "First" << endl;
	}
	if(ans == mp(true,false)){
		if(k%2) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	if(ans == mp(false,true)){
		cout << "Second" << endl;
	}
	if(ans == mp(false,false)){
		cout << "Second" << endl;
	}
}
