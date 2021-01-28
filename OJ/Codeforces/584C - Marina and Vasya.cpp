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

char dd(char a,char b){
	for(int i ='a'; i <= 'd';i++){
		if(i != a && i != b) return i;
	}

	return 'e';
}

int main(){

	fastio;
	int n,t;
	string a,b;
	cin >> n >> t;
	getline(cin,a);
	getline(cin,a);
	getline(cin,b);

	int dif,eq;
	dif = eq = 0;

	fr(i,n){
		if(a[i] == b[i]) eq++;
		else dif++;
	}

	if(t < (dif+1)/2){
		cout << -1 << endl;
		return 0;
	}

	string ans;

	if(t == (dif+1)/2){
		bool pri = true;
		if(dif%2 == 0) pri = false;
		bool sa = true;
		fr(i,n){
			if(a[i] == b[i]){
				ans.pb(a[i]);
				continue;
			}

			if(pri){
				ans.pb(dd(a[i],b[i]));
				pri= false;
			}

			else if(sa){
				ans.pb(a[i]);
				sa = false;
			}

			else{
				ans.pb(b[i]);
				sa = true;
			}
		}
	}

	if(t > (dif+1)/2 && t <= dif){
		int j = 2*t - dif;

		bool sa = true;

		fr(i,n){
			if(a[i] == b[i]){
				 ans.pb(a[i]);
			}
			else{
				if(j > 0){
					ans.pb(dd(a[i],b[i]));
					j--;
				}
				else{
					if(sa){
						ans.pb(a[i]);
						sa = false;
					}
					else{
						ans.pb(b[i]);
						sa = true;


				}
					}
			}
		}

	}

	if(t > dif){
		int j = t - dif;

		fr(i,n){
			if(a[i] == b[i]){
				if(j > 0){
					ans.pb(dd(a[i],b[i]));
					j--;
				}
				else ans.pb(a[i]);
			}
			else ans.pb(dd(a[i],b[i]));
		}
	}

	cout << ans << endl;

	

}
