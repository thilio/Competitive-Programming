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
int ansr[200200];
int ansl[200200];
int s[200200];
int t[200200];

int esp;

int main(){

	fastio;
	int n;
	cin >> n;
	

	int resp = 0;

	frr(i,n){
		int a;
		cin >> s[i];
	}
	frr(i,n){
		int a;
		cin >> a;
		t[a] = i;
	}

	frr(i,n){
		int x = s[i];
		int y = t[s[i]];

		x = i;

		if(x == y){
			esp++;
			resp = max(resp,esp);
		}

		if(x > y){
			ansl[x-y]++;
			ansr[n-x+y]++;
			resp = max(ansl[x-y],resp);
			resp = max(ansr[n-x+y],resp);
		}
		if(y > x){
			ansr[y-x]++;
			ansl[n-y+x]++;
			resp = max(ansr[y-x],resp);
			resp = max(ansl[n-y+x],resp);
		}
	}

	cout << resp << endl;



}
