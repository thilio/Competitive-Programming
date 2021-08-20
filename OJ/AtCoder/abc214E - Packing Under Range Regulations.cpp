#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define endl '\n'
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

vii v;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		v.clear();
		fr(i, n){
			int l, r;
			cin >> l >> r;
			v.pb({l, r});
		}

		sort(all(v));

		priority_queue<int, vi, greater<int>> pq;

		int p = 1;
		int i = 0;
		bool ok = true;
		
		while(i < n){
			p = v[i].fst;
			pq.push(v[i].snd);
			i++;
			while(!pq.empty()){
				while(i < n && v[i].fst <= p){
					pq.push(v[i].snd);
					i++;
				}
				int k = pq.top();
				pq.pop();
				if(k < p){
					ok = false;
					i = INF;
					break;
				}
				else{
					p++;
				}
			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	

}
