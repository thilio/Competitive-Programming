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

vector<int> p, c, lcp;
vector<pii> v;

int N;

int seg[11123456], sz;

void build_seg() {  // build the tree
  for (int i = sz - 1; i > 0; --i) 
  	seg[i] = min(seg[i<<1], seg[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = INF;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, seg[l++]);
		if (r&1) res = min(seg[--r], res);
	}
	return res;
}

void count_sort(){
	int n = p.size();

	vector<int> cnt(n);

	for(auto x : c) cnt[x]++;

	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; i++){
		pos[i] = pos[i-1] + cnt[i-1];
	}

	vector<int> p_new(n);
	for(auto x : p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}

	p = p_new;
}

void build(string &s){
	s.pb(' ');
	int n = s.size();

	p.resize(n);c.resize(n);

	vector<pair<char,int>> a(n);
	for(int i = 0; i < n; i++) a[i] = {s[i],i};
	sort(all(a));

	for(int i = 0; i < n; i++) p[i] = a[i].snd;
	c[p[0]] = 0;

	for(int i = 1; i < n; i++){
		c[p[i]] = c[p[i - 1]];
		if(a[i].fst != a[i-1].fst) c[p[i]]++;
	}

	int k = 0;
	while((1 << k) < n){
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n)%n;
		}

		count_sort();

		vector<int> c_new(n);
		c_new[p[0]] = 0;

		for(int i = 1; i < n; i++){
			pii at = {c[p[i]], c[(p[i] + (1 << k))%n]};
			pii prev = {c[p[i-1]], c[(p[i-1] + (1 << k))%n]};
			c_new[p[i]] = c_new[p[i-1]];
			if(at != prev) c_new[p[i]]++; 
		}

		c = c_new;
		k++;
	}
}

void build_lcp(string &s){
	int n = s.size();
  	sz = s.size();
	lcp.resize(n);

	int k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;

		lcp[pi] = k;
    	seg[pi + sz] = k;
		k = max(0,k - 1);
	}
  	build_seg();
}


bool comp(pii a,pii b){
	int pa = c[a.fst];
	int pb = c[b.fst];

	//cout << pa << ' ' << pb << endl;

	if(pa == pb){
		return a.snd < b.snd;
	}

	int com = query(min(pa, pb) + 1, max(pa, pb) + 1);

	if(com >= min(a.snd,b.snd)){
		if(a.snd < b.snd) return true;
		if(a.snd == b.snd) return a.fst < b.fst;
		if(a.snd > b.snd) return false;
	}

	if(pa < pb) return true;
	return false;
}

int main(){
	fastio;
	memset(seg, INF, sizeof seg);  
	string t;
	getline(cin,t);
	build(t);
	build_lcp(t);

	int n = t.size();
	N = n;
	int k;
	cin >> k;

	fr(i,k){
		int a,b;
		cin >> a >> b;
		a--;b--;
		v.pb(mp(a, b - a + 1));
	}

	sort(all(v), comp);

	for(auto x : v){
	 	cout << x.fst + 1 << ' ' << x.fst + x.snd << endl;
	}
}
