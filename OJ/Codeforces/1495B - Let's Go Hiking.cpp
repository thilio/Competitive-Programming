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

int v[100100];
int n;

int up[100100];
int upr[100100];

int main(){

	fastio;

	cin >> n;

	if(n == 2){
		cout << 0 << endl;
		return 0;
	}

	fr(i,n){
		cin >> v[i];
	}

	int mx = 0;
	int id_mx;
	bool mult_mx = false; 

	for(int i = 1; i < n; i++){
		if(v[i] > v[i - 1]){
			up[i] = up[i - 1] + 1; 
		}
		else
			up[i] = 0;

		if(up[i] == mx){
			mult_mx = true;
		}
		if(up[i] > mx){
			id_mx = i;
			mx = up[i];
			mult_mx = false;
		}
	}

	int mxr = 0;
	int id_mxr = n - 1;
	bool mult_mxr = false;

	for(int i = n - 2; i >= 0; i--){
		if(v[i] > v[i + 1]){
			upr[i] = upr[i + 1] + 1; 
		}
		else
			upr[i] = 0;

		if(upr[i] == mxr){
			mult_mxr = true;
		}
		if(upr[i] > mxr){
			id_mxr = i;
			mxr = upr[i];
			mult_mxr = false;
		}
	}

	if(id_mx == id_mxr && mx == mxr && !mult_mxr && !mult_mx && mx%2 == 0){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}




}
