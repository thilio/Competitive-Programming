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

bool used[200100];

int main(){

	fastio;

	int n;
	cin >> n;

	vector<array<int, 4>> event;

	for(int i = 0; i < n; i++){
		int l, r, color;
		cin >> l >> r >> color;
		event.pb({l, r, color - 1, i});
		event.pb({r, INF, color - 1, i});
	}

	sort(all(event));

	int matching = 0;

	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq[2];
	for(auto x: event){
		int l, r, color, index;
		l = x[0];
		r = x[1];
		color = x[2];
		index = x[3];

		if(r == INF){
			if(!used[index]){
				used[index] = true;
				pq[color].pop();
				if(!pq[color^1].empty()){
					used[pq[color^1].top()[1]] = true;
					pq[color^1].pop();
					matching++;
				}
			}
			
		}
		else{
			pq[color].push({r, index});
		}
	}

	cout  << n - matching << endl;


}
