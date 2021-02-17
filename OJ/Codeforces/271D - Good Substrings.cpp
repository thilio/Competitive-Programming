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
int k;
vi good;

struct trie{
	int cnt,wrd;
	map<char,trie> m;
	trie(){
		cnt = wrd = 0;
		m.clear();
	}

	void add(string &s,int i){
		if(i == s.size()){
			return;
		}
		if(!m.count(s[i])){
			m[s[i]] = trie();
		}
		m[s[i]].add(s,i+1);
	}

	ll find(int p){
		if(p > k) return 0ll;
		ll ans = 1;
		for(char i = 'a'; i <= 'z';i++){
			if(!m.count(i)) continue;
			if(!good[i - 'a']){
				ans += m[i].find(p+1);
			}
			else
				ans += m[i].find(p);
		}
		return ans;

	}
};

int main(){

	fastio;

	string s;
	string p;
	getline(cin,s);
	getline(cin,p);
	cin >> k;
	fr(i,p.size()){
		good.pb(p[i] - '0');
	}
	trie t = trie();
	fr(i,s.size()){
		t.add(s,i);
	}

	cout << t.find(0) - 1 << endl;



}
