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

ll seg[4000400];
ll color[1000100];

int n, m;

void update(int node, int l, int r, int i, ll val){
	if(i < l || i > r) return;
	if(l == r){
		seg[node] += val;
		return;
	}
	int m = (l + r)/2;
	update(2*node, l, m, i, val);
	update(2*node + 1,m + 1, r, i, val);

	seg[node] = seg[2*node] + seg[2*node + 1];
}

ll query(int node, int l, int r, int a, int b){
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	return query(2*node, l, m, a, b) + 
		   query(2*node + 1,m + 1, r, a, b);
}

void update(int l, int r, ll val){
	update(1, 1, n, r + 1, -val);
	update(1, 1, n, l, val);
}
ll query(int i){
	return query(1, 1, n, 1, i);
}

int main(){

	fastio;

	cin >> n >> m;

	set<array<int, 3>> S;

	S.insert({1, n, 1});

	fr(i, m){
		string s;
		cin >> s;

		if(s == "Add"){
			ll c, x;
			cin >> c >> x;
			color[c] += x;
		}
		if(s == "Query"){
			int i;
			cin >> i;
			auto it = S.lower_bound({i, n + 1, n + 1});
			it--;
			cout << query(i) + color[(*it)[2]] << endl;
		}
		if(s == "Color"){
			int l, r, c;
			cin >> l >> r >> c;

			auto it = S.lower_bound({l ,n + 1, n + 1});
			it--;

			if((*it)[0] != l){
				array<int, 3> old = (*it);
				S.erase(it);
				S.insert({old[0], l - 1, old[2]});
				S.insert({l, old[1], old[2]});

			}	

			it = S.upper_bound({r, n + 1, n + 1});
			it--;	

			if((*it)[1] != r){
				array<int, 3> old = (*it);
				S.erase(it);
				S.insert({old[0], r , old[2]});
				S.insert({r + 1, old[1], old[2]});
			}
			
			it = S.lower_bound({l ,l, -1});
			while(it != S.end() && (*it)[0] <= r){
				array<int, 3> old = (*it);
				update(old[0], old[1], color[old[2]]);
				update(old[0], old[1], -color[c]);
				S.erase(it);
				it = S.lower_bound({l ,l, -1});
			}

			S.insert({l, r, c});		
		}
	}

}
