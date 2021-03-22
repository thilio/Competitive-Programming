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

int n;
int v[100100];
int ant[100100];
int prox[100100];
bool elim[100100];
priority_queue<int, vector<int>, greater<int>> q;
queue<int> p;
vi ans;

void clear(){
	frr(i,n){
		ant[i] = i - 1;
		if(ant[i] == 0) ant[i] = n;
		prox[i] = i + 1;
		if(prox[i] == n + 1) prox[i] = 1;
		elim[i] = false;
	}
	while(!p.empty()) p.pop();
	while(!q.empty()) q.pop();
	ans.clear();
}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		clear();

		frr(i,n) cin >> v[i];

		frr(i,n){
			if(__gcd(v[i], v[prox[i]]) == 1) q.push(i);
		}

		while(true){
			if(q.empty()) break;

			while(!q.empty()){
				int x = q.top();
				q.pop();
				if(elim[x]) continue;

				if(__gcd(v[x], v[prox[x]]) == 1){
					elim[prox[x]] = true;
					p.push(prox[x]);
				}
			}

			while(!p.empty()){
				int x = p.front();
				p.pop();

				ans.pb(x);
				prox[ant[x]] = prox[x];
				ant[prox[x]] = ant[x];

				if(__gcd(v[ant[x]], v[prox[x]]) == 1) q.push(ant[x]);
			}
		}

		cout << ans.size() << ' ';
		for(auto x: ans) cout << x << ' ';
		gnl;
	
	}

}
