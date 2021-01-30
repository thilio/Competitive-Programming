#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define kara cout << "karadola" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;

int n;
long long memo[11234];
string v;

long long dp (int i){
	if (i>=n - 1) return 1;
	long long &resp = memo[i];
	if (resp == -1){
		if (v[i] == '0') resp=0;
		else if (v[i] > '2') resp = (dp(i+1));
		else if (v[i+1] == '0') resp = (dp(i+2));
		else if (v[i] == '1') resp = (dp(i+1) + dp(i+2));
		else if (v[i]=='2' && v[i+1] < '7') resp= (dp(i+1) + dp(i+2));
		else resp = (dp(i+1));
	}
	return(resp);	
}


int main(){
	int T,g=1;
	getline (cin,v);
	while(v[0]!='0'){
		//cout << v << endl;
		n = v.size();
		
		ms(memo,-1);
		cout << dp(0) << endl;
		getline (cin,v);
	}


	return 0;
}