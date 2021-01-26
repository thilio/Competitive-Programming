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

int a[200100];

int mx[200100];
int k,l;

int main(){

	fastio;
	int t,n,m;
	cin >> t;
	while(t--){

		k = 0;
		l = 0;
		cin >> n;
		fr(i,n){ 
			cin >> a[i];
			k = max(k,a[i]);
		}

		cin >> m;
		
		
		fr(i,m){
			int u,v;
			cin >> u >> v;
			mx[v] = max(mx[v],u);
			l = max(l,v);
		}

		//dbg(mx[1]);

		for(int i = l; i >= 0; i--){
			mx[i] = max(mx[i],mx[i+1]);
		}

		if(k > mx[1]){
			cout << -1 << endl;
			for(int i = l+2; i >= 0;i--) mx[i] = 0;
			continue;
		}

		int day,sta;
		day = 0;
		sta = 0;

		int i = 0;
		while(i<n){
			sta = 1;
			int pow = a[i];
			while(mx[sta] >= pow && i < n){
				sta++;
				i++;
				pow = max(pow,a[i]);
			}
			day++;
		}

		cout << day << endl;

		for(int i = l+2; i >= 0;i--) mx[i] = 0;

	}

}
