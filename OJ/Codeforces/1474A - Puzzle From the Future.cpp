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
int t[100100];
int s[100100];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;
		string aux;
		cin >> n;
		getline(cin,aux);
		getline(cin,aux);

		fr(i,n) s[i] = aux[i] - '0';

		fr(i,n){
			if(i == 0){
				t[i] = 1; 
			}
			else{
				if(s[i - 1] + t[i - 1] == s[i] + 1) t[i] = 0;
				else t[i] = 1;
			}
		}

		fr(i,n) cout << t[i];
		gnl;

	}

}
