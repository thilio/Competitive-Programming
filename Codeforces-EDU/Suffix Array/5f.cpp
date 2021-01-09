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
vector<int> pi,ci,lcpi;
vector<int> pv,cv,lcpv;

int sti[400400][22];
int stv[400400][22];
int lg[400400];

int N;

void build_st(){
	lg[1] = 0;
	for(int i = 2;i <= 400300; i++){
		lg[i] = lg[i/2] + 1;
	}

	for(int i = 0; i < lcp.size(); i++){
		sti[i][0] = lcpi[i];
		stv[i][0] = lcpv[i];
	}

	for(int j = 1 ; j < 22; j++){
		for(int i = 0; i + (1ll << j) <= lcp.size(); i++){
			sti[i][j] = min(sti[i][j - 1], sti[i + (1ll << (j - 1))][j-1]);
			stv[i][j] = min(stv[i][j - 1], stv[i + (1ll << (j - 1))][j-1]);
		}
	}
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
	s.pb('$');
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
	lcp.resize(n);

	int k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;

		lcp[pi] = k;
		k = max(0,k - 1);
	}
}

int query_sti(int l, int r){
	int k = r - l + 1;
	k = lg[k];
	return min(sti[l][k],sti[r - (1ll << k) + 1][k]);
}

int query_stv(int l, int r){
	int k = r - l + 1;
	k = lg[k];
	return min(stv[l][k],stv[r - (1ll << k) + 1][k]);
}

int query_lcpi(int l,int r){
	int lp = ci[l];
	int rp = ci[r + 1];
	return query_sti(min(lp,rp) + 1,max(lp,rp));
}

int query_lcpv(int l,int r){
	r = N - 1 - r;
	l = N - 1 - l;
	int rp = cv[r];
	int lp = cv[l + 1];

	return query_stv(min(lp,rp) + 1,max(lp,rp)); 
}

void start(){
	string s;
	getline(cin,s);
	N = s.size();
	build(s);
	build_lcp(s);
	pi = p;ci = c;lcpi = lcp;
	
	s.pop_back();

	reverse(all(s));
	build(s);
	build_lcp(s);
	pv = p;cv = c;lcpv=lcp;
	
	build_st();
}

int chunk(int L){
	int resp = -1;
	for(int i = 0; i + L - 1 < N; i+=L){
		int x = query_lcpi(i, i + L - 1);
		int y = query_lcpv(i, i + L - 1);
		resp = max(resp, (x + y + L)/L);
	}
	return resp;
}


int main(){

	fastio;
	start();

	int ans = 1;
	frr(i,N){
		ans = max(ans, chunk(i));
	}

	cout << ans << endl;


}
