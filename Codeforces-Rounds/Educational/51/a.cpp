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

void solve(){
	getline(cin,s);
	int ok1,ok2,ok3;
	ok1=ok2=ok3=0;

	fr(i,s.size()){
		if(s[i] >='a' && s[i]<='z') ok1++;
		if(s[i] >='A' && s[i]<='Z') ok2++;
		if(s[i] >= '0' && s[i] <= '9') ok3++;
	}

	if(ok1 && ok2 && ok3) cout << s << endl;

	if(!ok1){
		if(!ok2){
			s[0]='a';
			s[1] = 'A';
			cout << s <<endl;
			return;
		}

		if(!ok3){
			s[0]='a';
			s[1] = '0';
			cout << s <<endl;
			return;
		}


		if(ok3 > 1){
			fr(i,s.size()){
				if(s[i] >='0' && s[i] <='9'){
					s[i] = 'a';
					break;
				}
			}
			cout << s <<endl;
			return;
		}
		if(ok2 > 1){
			fr(i,s.size()){
				if(s[i] >='A' && s[i] <='Z'){
					s[i] = 'a';
					break;
				}
			}
			cout << s <<endl;
			return;
		}
	}
	if(!ok2){
		if(!ok3){
			s[0] = 'A';
			s[1] = '1';
			cout << s << endl;
			return;
		}

		if(ok3>1){
			fr(i,s.size()){
				if(s[i] >='0' && s[i] <='9'){
					s[i] = 'A';
					break;
				}
			}
			cout << s << endl;
			return;
		}
		if(ok1>1){
			fr(i,s.size()){
				if(s[i] >='a' && s[i] <='z'){
					s[i] = 'A';
					break;
				}
			}
			cout << s << endl;
			return;
		}
	}

	if(!ok3){
		if(ok2>1){
			fr(i,s.size()){
				if(s[i] >='A' && s[i] <='Z'){
					s[i] = '0';
					break;
				}
			}
			cout << s << endl;
			return;
		}
		if(ok1>1){
			fr(i,s.size()){
				if(s[i] >='a' && s[i] <='z'){
					s[i] = '0';
					break;
				}
			}
			cout << s << endl;
			return;
		}

	}

}
int main(){

	fastio;
	int T;
	cin >> T;
	getline(cin,s);
	while(T--){
		solve();
	}

}
