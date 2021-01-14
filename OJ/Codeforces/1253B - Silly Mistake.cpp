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

int esta[1000100];
int last[1000100];

vi ans;

int main(){

	fastio;

	int n;
	cin >> n;
	int ct = 1;
	int dia = 0;
	int Q = 0; 

	bool ok = true;

	fr(i,n){
		int a;
		cin >> a;
		if(a < 0){
			a = -a;
			if(esta[a] == 0)
				ok = false;
			else esta[a] = 0;
			Q--;
		}
		else{
			if(esta[a] == 1) ok = false;
			else{
				if(Q == 0 && i != 0){
					ct++;
					last[a] = ct;
					esta[a] = 1;
					ans.pb(dia);
					dia = 0;
				}
				else{
					if (last[a] < ct){
						last[a] = ct;
						esta[a] = 1;
					}
					else ok = false;
				}			
			
			}
			Q++;
		}
		dia++;
	}

	if(Q != 0) ok = false;

	if(ok){
		cout << ans.size() + 1 << endl;
		fr(i,ans.size()) cout << ans[i] << ' ';
		cout << dia << endl;
	}
	else cout << -1 << endl;

}
