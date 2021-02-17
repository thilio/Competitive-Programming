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

int var = 0;
int freq[300300];

struct trie{
	int cnt,wrd;
	map<int,trie> m;
	trie(){
		cnt = 0;wrd = 0;
		m.clear();
	}
	void add(int &k, int i){ // add string to trie
		cnt++;
		if(i < 0){
			wrd++;
			return;
		}

		int bit = k&(1 << i);
		if(bit > 0) bit = 1;
		
		if(!m.count(bit)){
			m[bit] = trie();
		}
		m[bit].add(k,i-1);
	}
	int find(int i){
		if(i < 0) return 0;
		int ans = 0;

		int bit = var&(1ll << i);
		if(bit > 0) bit = 1;

		if(m[bit].cnt == (1<<i)){
			ans = (1 << i); 
			if(m.count(1 - bit)) ans += m[1 - bit].find(i - 1);
			return ans;
		}
		if(m.count(bit)) ans = m[bit].find(i - 1);
		return ans;
	}
};

int main(){

	fastio;

	int n,m;
	cin >> n >> m;
	trie T = trie();
	fr(i,n){
		int x;
		cin >> x;
		if(freq[x] == 0){
			freq[x] = 1;
			T.add(x,20);
		}
		
	}
	fr(i,m){
		int x;
		cin >> x;
		var ^= x;
		cout << T.find(20) << endl;
	}

}
