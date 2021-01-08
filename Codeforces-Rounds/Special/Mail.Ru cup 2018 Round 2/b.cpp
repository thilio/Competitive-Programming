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
ll v[112345];
int n,m,l;

void solve(){
	int ct = 0;
	fr(i,m){
		int a,b,c;
		ct = 0;
		if(v[1] > l) ct++;
		cin >> a;

		if(a== 0){
			if(ct) cout << '1'<<endl;
			else cout << '0' << endl;
		}
		else{
			cin >> b >> c;
			v[1] += c;
		}
	}
	//gnl;


}

int main(){
	fastio;
	
	cin >> n >>m >>l;
	

	frr(i,n)
		cin >> v[i];

	if(n==1){
		solve();
		return(0);
	}

	int ct = 0;

	if(v[n] > l) ct++;

	frr(i,n-1){
		if(v[i] > l && v[i+1]<= l)
			ct++;
	}

	fr(i,m){
		int a,b,c;
		cin >> a;
		if(a == 0)
			cout << ct << endl;
		else{
			cin >> b >> c;
			
			if(b==1){
				if(v[1] <= l && v[2] <= l && v[1] + c > l) ct++;
			}

			else if(b==n){
				if(v[n] <= l && v[n-1] <= l && v[n] + c > l) ct++;
			}

			else if (v[b] <=l && v[b] + c > l){
				if(v[b-1] > l && v[b+1] > l) ct--;
				if(v[b-1]<= l && v[b+1]<= l)ct++;
			}

			v[b]+= c;

		}

	}

	//gnl;



}