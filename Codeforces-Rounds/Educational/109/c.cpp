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

int n, m;
int v[300300];

pii save[300300];
int ori[300300];

int dir[300300];
map<int, int> ans;

vi pp, ii;

int col(int i, int j){
	if(dir[i] == 1 && dir[j] == 1){
		return (m - v[j] + m - v[i])/2;
	}
	if(dir[i] == -1 && dir[j] == 1){
		return (m + m - v[j] + v[i])/2;
	}
	if(dir[i] == 1 && dir[j] == -1){
		return (v[j] - v[i])/2;
	}
	if(dir[i] == -1 && dir[j] == -1){
		return (v[i] + v[j])/2;
	}
	return INF;
}

void solve(vi& a){
	stack<int> q;

	fr(i, a.size()){
		if(q.empty()) q.push(a[i]);
		else{
			if(dir[a[i]] == 1) q.push(a[i]);
			else{
				int x = q.top();
				q.pop();
				ans[v[x]] = ans[v[a[i]]] = col(x, a[i]);
			}
		}
	}

	//dbg(q.size());

	while(q.size() > 1){
		//olar;
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans[v[x]] = ans[v[y]] = col(y, x);
		//dbg(x);
		//dbg(y);
	//	dbg(col(x, y));
	}

	if(!q.empty()){
		int x = q.top();
		q.pop();
		ans[v[x]] = -1;
	}
}

void work(){
	pp.clear();
	ii.clear();
	ans.clear();

	cin >> n >> m;
	frr(i, n){
		cin >> save[i].fst;
	}
	frr(i, n){
		char c;
		cin >> c;
		if(c == 'L') save[i].snd = -1;
		if(c == 'R') save[i].snd =  1;
	}


	frr(i, n) ori[i] = save[i].fst;
	sort(save + 1, save + n + 1);

	frr(i, n){
		v[i] = save[i].fst;
		dir[i] = save[i].snd;
	}
	
	frr(i, n){
		if(v[i]%2 == 0) pp.pb(i);
		else ii.pb(i);
	}

	solve(pp);
	solve(ii);

	frr(i, n) cout << ans[ori[i]] << ' ';
	gnl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		work();
	}

}
