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
const int MAXN = 500100;

int k;
int tipo[MAXN];

int n;
int p[MAXN], c[MAXN], lcp[MAXN], cnt[MAXN], p_new[MAXN], c_new[MAXN];
pair <int,int> a[MAXN];

void count_sort(){
	fill(cnt, cnt + n + 1, 0);

	for(int i = 0; i < n; i++) cnt[c[i] + 1]++;

	cnt[0] = 0;
	for(int i = 1; i < n; i++){
		cnt[i] += cnt[i-1];
	}

	for(int i =0; i < n; i++){
		int j = c[p[i]];
		p_new[cnt[j]] = p[i];
		cnt[j]++;
	}

	for(int i = 0; i < n; i++){
		p[i] = p_new[i];
	}
}

void build(vector<ll> &s){ // Build the SA in p, and the LCP in the array lcp. Complexity O(n logn)
	s.push_back(0); // REMEMBER YOU ARE MODIFYING THE STRING
	n = s.size();

	for(int i = 0; i < n; i++) a[i] = {s[i],i};
	sort(a, a + n);

	p[0] = n - 1;
	c[p[0]] = 0;

	for(int i = 1; i < n; i++){
		p[i] = a[i].second;
		c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	int k = 0;
	while((1 << k) < n){
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n)%n;
		}

		count_sort();

		c_new[p[0]] = 0;
		for(int i = 1; i < n; i++){
			pair<int,int> at = {c[p[i]], c[(p[i] + (1 << k))%n]};
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k))%n]};
			c_new[p[i]] = c_new[p[i-1]] + (at != prev);
		}
		for(int i =0; i < n; i++) c[i] = c_new[i];
		k++;	
	}

	k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;
		lcp[pi] = k;
		k = max(0,k - 1);
	}
}

ll fexp (ll base, ll exp){
	if(exp == 0) return 1ll;
	ll ans = fexp(base, exp/2);
	ans = (ans*ans) % MOD;
	if(exp&1) ans = (ans*base)%MOD;
	return ans;
}

int main(){

	fastio;

	cin >> k;

	vector<ll> v;

	ll tot = 0;

	fr(i, k){
		int l;
		cin >> l;
		tot += l;
		fr(j, l){
			int x;
			cin >> x;
			v.pb(x);
		}
		v.pb(301);
	}

	build(v);

	priority_queue<int , vector<int>, greater<int>> pq;

	fr(i, v.size()){
		if(i == 0) pq.push(c[i]);
		else if(v[i - 1] == 301 && v[i] != 0) pq.push(c[i]);
	}

	int j = 0;
	ll resp = 0;


	while(!pq.empty()){
		int i = pq.top();
		pq.pop();

		int at = p[i];

		resp += v[at]*fexp(365ll, tot - j);
		resp %= MOD;

		at++;
		if(v[at] != 301) pq.push(c[at]);
		j++;
	}

	cout << resp << endl;

}

