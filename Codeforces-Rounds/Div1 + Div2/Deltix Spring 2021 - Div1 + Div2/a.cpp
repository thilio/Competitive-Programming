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
string s;
int v[3000];
int ans[3000];


int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		cin >> s;

		frr(i, n + 2) v[i] = 0;

		frr(i, n){
			if(s[i - 1] == '1') v[i] = 1;
			else v[i] = 0;
		}

		//	dbg(s);
		
		queue<int> q;
		queue<int> p;
		frr(i, n) if(v[i] == 1) q.push(i);

		int ct = 0;
		while(!q.empty() && ct <= m){
			ct++;
			while(!q.empty()){
				//dbg(q.front());
				p.push(q.front());
				v[q.front()] = 1;
				q.pop();
			}
			while(!p.empty()){
				int x = p.front();
				p.pop();
				if(x != 1 && v[x - 1] == 0 && v[x - 2] == 0){
					q.push(x - 1);
				}
				if(x != n && v[x + 1] == 0 && v[x + 2] == 0){
					q.push(x + 1);
				}
			}
		}

		frr(i, n) cout << v[i];
		gnl;
	}	

}
