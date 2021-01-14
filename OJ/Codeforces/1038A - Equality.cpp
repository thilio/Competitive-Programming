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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
	int fre[26];
int main(){
	int n,k;
	cin >> n >>k;
	getchar();
	string s;
	getline(cin,s);
	//dbg (s);
	fr(i,n){
		fre[s[i] - 'A']++;
	}
	//dbg (fre[0]);
	int mini = 1000000;
	fr(i,k){

		mini = min(fre[i],mini);
	}


	cout << mini*k << endl;

}