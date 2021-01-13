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
int n,m,k;
int v[212345];

bool teste (int c){
	int i,j;
	i = c; j = 0;

	while (i < n && j < m){
		int cx = k;

		while(i < n && v[i] <= cx){
			cx -= v[i];
			i++;
		}

		if (i==n) return (true);
		else j++;
	}
	return (false);

}

int main(){

	fastio;

	cin >> n >> m >> k;

	fr(i,n)
		cin >> v[i];

	int best = n;
	int l = 0;int r = n-1;

	while (l<=r){
		int ent = 0;
		int mid = (l + r)/2;
		if (teste(mid)){
			best = mid;
			r = mid - 1;
			ent = 1;
		}
		else
			l = mid + 1;
		//dbg(mid);
		//dbg(ent);

	}


	cout <<n - best << endl;

}
