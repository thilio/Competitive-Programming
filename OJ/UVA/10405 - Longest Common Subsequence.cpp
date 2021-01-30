#include <bits/stdc++.h>
using namespace std;

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
const ll llINF = 0x3f3f3f3f3f3f3f;

int memo[2000][2000];
string s,t;

int dp (int i,int j){
	if (i==t.size() || j ==s.size())
		return 0;
	if (memo[i][j] == -1){
		int &resp = memo[i][j];
		resp = -INF;
		if (t[i] == s[j])
			resp = 1 + dp (i+1,j+1);
		else
			resp = max(dp(i+1,j),dp(i,j+1));
	}

	return (memo[i][j]);
}

int main(){

	while(getline(cin,t)){
		
		getline(cin,s);
		
		ms(memo,-1);
		cout << dp (0,0) << endl;
	}

	return (0);

}