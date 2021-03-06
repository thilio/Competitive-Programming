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
string l; string r;	
int n;

bool cond(){
	bool zero = false;
	for(int i = n - 2; i >= 0; i--){
		if(l[i] == '0') zero = true;
	}
	if(!zero) return false;
	for(int i = n - 2; i>= 0; i--){
		if(l[i] == '0'){
			l[i] = '1';
			break;
		}
		l[i] = '0';
	}

	for(int i = 0; i < n; i++){
		if(l[i] < r[i]) return true;
		if(r[i] < l[i]) return false;
	}

	return true;
}

int main(){

	fastio;
	cin >> n;
	cin >> l >> r;

	if(r[0] != l[0]){
		fr(i,n) cout << 1;
		gnl;
	}
	else if(r[n - 1] == '1'){
		cout << r << endl;
	}
	else{
		if(cond()) r[n-1] = '1';
		cout << r << endl;
	}

}
