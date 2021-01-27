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

int n;
int v[100100];
int memo[100100][2];
string s;

int pd(int ind, int menor){
	if(ind == n) return 0;

	int &pdm = memo[ind][menor];

	if(pdm != -1) return pdm;

	pdm = 0;

	if(menor){
		pdm = pd(ind+1,menor) + v[ind];
		return pdm;
	}

	if(s[ind] == '0'){
		pdm = pd(ind + 1,menor);
		return pdm;
	}

	int ans1 = pd(ind + 1,0) + v[ind];
	int ans2 = pd(ind+1,1);

	pdm = max(ans1,ans2);

	return pdm;
}

int main(){

	fastio;
	cin >> n;

	for(int i = n -1; i >= 0; i--){
		cin >> v[i];
	}

	fr(i,100100){
		fr(j,2){
			memo[i][j] = -1;
		}
	}

	
	getline(cin,s);
	getline(cin,s);

	reverse(all(s));

	cout << pd(0,0) << endl;




}
