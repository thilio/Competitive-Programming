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

int ma[500005],mf[500005];

int main(){

	fastio;
	int n;
	int ans = 0;
	

	string s;
	stack<char> p;

	cin >> n;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);

		fr(i,s.size()){
			if(p.empty()) p.push(s[i]);
			else if(s[i] == '(') p.push(s[i]);
			else{
				if(p.top() == ')') p.push (s[i]);
				else p.pop();
			}
		}

		int cta=0;
		int ctf=0;

		while(!p.empty()){
			char c = p.top();
			p.pop();
			if(c == '(') cta++;
			else ctf++;
		}

		if(cta == 0 && ctf == 0) ans++;

		else if(cta == 0){
			mf[ctf]++;
		}

		else if(ctf==0){
			ma[cta]++;
		}
	}

	ans /= 2;

	fr(i,500001){
		ans+=min(ma[i],mf[i]);
	}

	cout << ans << endl;



}
