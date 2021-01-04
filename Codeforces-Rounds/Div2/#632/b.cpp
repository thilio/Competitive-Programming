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

int a[100100];
int b[100100];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		fr(i,n) cin >> a[i];
		fr(i,n) cin >> b[i];

		bool showp = false;
		bool shown = false;

		bool certo = true;

		fr(i,n){
			if(a[i] > b[i] && shown == false)
				certo = false;
			if(a[i] < b[i] && showp == false) 
				certo = false;

			if(a[i] == 1) showp = true;
			if(a[i] == -1) shown = true;

		}

		if(certo) cout << "YES";
		else cout << "NO";
		gnl;
	
	}

}
