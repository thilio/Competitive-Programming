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

int x,y,a,b,c;
vi A,B,C;

map<int,int> aa,bb;
set<int> AA,BB;

int main(){

	fastio;

	cin >> x >> y >> a >> b >> c;
	int l;
	fr(i,a){
		cin >> l;
		A.pb(l);
	}
	fr(i,b){
		cin >> l;
		B.pb(l);
	}
	fr(i,c){
		cin >> l;
		C.pb(l);
	}

	sort(all(A));
	sort(all(B));
	sort(all(C));


	reverse(all(A));
	reverse(all(B));

	fr(i,x){
		AA.insert(A[i]);
		aa[A[i]]++;
	}

	fr(i,y){
		BB.insert(B[i]);
		bb[B[i]]++;
	}

	int p = c - 1;

	while(p >= 0){
		int at = C[p];
		auto ita = AA.begin();
		auto itb = BB.begin();

		int ata = *(ita);
		int atb = *(itb);

		if(ata < atb){
			if(at <= ata) break;
			aa[ata]--;
			if(aa[ata] == 0) AA.erase(AA.begin());
			aa[at]++;
			AA.insert(at);

		}
		else{
			if(at <= atb) break;
			bb[atb]--;
			if(bb[atb] == 0) BB.erase(BB.begin());
			bb[at]++;
			BB.insert(at);
		}
		p--;
	}

	ll sum = 0;

	while(!AA.empty()){
		auto it = AA.begin();
		ll x = *(it);

		sum += x*aa[x];
		AA.erase(AA.begin());
	}
	while(!BB.empty()){
		auto it = BB.begin();
		ll x = *(it);

		sum += x*bb[x];
		BB.erase(BB.begin());
	}

	cout << sum << endl;



}
