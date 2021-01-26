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

int f[120];
int v[120];
char ans[120];

int main(){

	fastio;
	int n;
	cin >> n;
	int a;

	fr(i,n) ans[i] = 'Z';

	set<int> ob;
	fr(i,n){
		cin >> a;
		f[a]++;
		v[i] = a;
	} 
	int obri=0;
	int op=0;

	frr(i,100){
		if(f[i] == 1){
			obri++;
			ob.insert(i);
		}
		if(f[i] >2) op++;
	}

	//dbg(obri);

	if(obri %2 == 1 && op == 0){
		cout << "NO"<<endl;
		return 0;
	}
	cout << "YES" << endl;
	if(obri == 0){
		fr(i,n) cout <<'A';
		gnl;
		return 0;
	}

	if(obri%2 == 1){
		int aux;
		fr(i,n){
			if(f[v[i]] > 2){
				aux = v[i];
				break;
			}
		}
	//	dbg(aux);

		bool ok = false;

		fr(i,n){
			if(v[i] == aux && ok == false){
				ans[i]='B';
				ok = true;
				continue;
			}
			if(v[i] == aux && ok){
				ans[i] = 'A';
			}
		}
	}
	bool alt = true;

	fr(i,n){
		if(ans[i] != 'Z') continue;
		if(ob.find(v[i]) != ob.end() && alt == true){
			ans[i] = 'A';
			alt = false;
			continue;
		}
		if(ob.find(v[i]) != ob.end() && alt == false){
			ans[i] = 'B';
			alt = true;
			continue;
		}

		ans[i] = 'A';
	}

	fr(i,n){
		cout <<ans[i];
	}
	gnl;



}
