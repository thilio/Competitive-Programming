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
int n,x,y;
pii v[212345];
string s;

bool boo(int k){
	fr(i,n-k+1){
		pii a;
		pii b;

		a.fst = v[i].fst;
		a.snd = v[i].snd;

		b.fst = v[n].fst - v[i+k].fst;
		b.snd = v[n].snd - v[i+k].snd;

		pii s;
		s.fst = a.fst + b.fst;
		s.snd = a.snd + b.snd;

		s.fst-=x;
		s.snd-=y;

		if(abs(s.fst) + abs(s.snd) <= k) return (true); 
	}
	return (false);
}

int main(){

	fastio;
	
	cin >> n;
	getline(cin,s);
	getline(cin,s);
	cin >> x >> y;
	
	if(abs(x) + abs(y) > n){
		cout << -1 << endl;
		return (0);
	}
	if((abs(x) + abs(y) + n)%2 == 1){
		cout << -1 << endl;
		return (0);
	}

	v[0].fst = 0;
	v[0].snd = 0;

	fr(i,n){
		pii a;

		a.fst = v[i].fst;
		a.snd = v[i].snd;

		if (s[i] == 'R'){
			a.fst++;
		}

		if (s[i] == 'L'){
			a.fst--;
		}

		if (s[i] == 'U'){
			a.snd++;
		}

		if (s[i] == 'D'){
			a.snd--;
		}

		v[i+1] = a;
	}

	//if (v[n] == mp(x,y)){
	//	cout << '0' << endl;
	//	return (0);
	//}

	int ini = 0;
	int fim = n;
	int best = n;
	
	while(ini<= fim){
		int mid = (ini+fim)/2;
		if(boo(mid)){
			best = mid;
			fim = mid - 1;
		}
		else
			ini = mid + 1;
	}

	cout << best << endl;


}
