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

string s;
int n;

int main(){

	fastio;
	cin >> n;
	getline(cin,s);
	getline(cin,s);

	if( n%2 || s[0] == ')'){
		cout << ":(" << endl;
		return 0;
	}

	int ab,fe;

	ab = fe = 0;

	fr(i,n){
		if(s[i] == '(') ab++;
		if(s[i] == ')') fe++;
	}

	if(ab > n/2 || fe > n/2){
		cout << ":(\n";
		return 0;
	}

	fr(i,n){
		if(s[i] == '?'){
			if(ab < n/2){
				s[i] = '(';
				ab++;
			}
			else s[i] = ')';
		}
	}

	int at = 0;

	bool ok = true;

	fr(i,n){
		if(i != 0 && at == 0) ok = false;
		if(at < 0) ok = false;
		if(s[i] == '(') at++;
		else at--;

	}

	if(ok){
		cout << s << endl;
	}

	else{
		cout << ":(" << endl;
	}

}
