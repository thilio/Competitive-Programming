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

int n,m;
pair<char,char> mat[60][60];
vector<pair<char,char>> missing;

char rnk[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char suit[4] = {'C','D','H','S'};

pii sol1;
pii sol2;

bool is_good(int r,int c){
	set<char> ran;
	set<char> sui;

	if(r > n-2 || c > m - 2) return false;

	for(int i = r ; i <= r + 2;i++){
		for(int j = c; j <= c + 2;j++){
			ran.insert(mat[i][j].fst);
			sui.insert(mat[i][j].snd);
		}
	}

	if(ran.size() == 9 || sui.size() == 1) return true;
	return false;
}

bool tenta(int i,int j,int k,int l){
	if(abs(i-k) < 3 && abs(j - l) < 3) return false;
	return (is_good(i,j) && is_good(k,l));
}

bool solve(){

	bool ok = false;

	frr(i,n){
		frr(j,m){
			frr(k,n){
				frr(l,m){
					ok = tenta(i,j,k,l);
					if(ok){
						sol1.fst = i;
						sol1.snd = j;
						sol2.fst = k;
						sol2.snd = l;
						return true;
					}
				}
			}
		}
	}

	return false;


}

pii loc(char a,char b){
	frr(i,n){
		frr(j,m){
			if(mat[i][j].fst == a && mat[i][j].snd == b){
				return mp(i,j);
			}
		}
	}

	return mp(-1,-1);
}


bool is_in(char a,char b){
	frr(i,n){
		frr(j,m){
			if(mat[i][j].fst == a && mat[i][j].snd == b) return true;
		}
	}

	return false;
}

int main(){

	fastio;
	cin >> n >> m;
	string s;
	getline(cin,s);


	frr(i,n){
		getline(cin,s);
		int j = 0;
		while(j < m){
			mat[i][j+1].fst = s[3*j];
			mat[i][j+1].snd = s[3*j + 1]; 
			j++;
		}
	}


	fr(i,13){
		fr(j,4){
			pair<char,char> pp;
			pp.fst = rnk[i];
			pp.snd = suit[j];
			if(!is_in(pp.fst,pp.snd)) missing.pb(pp);
		}
	}

	fr(i,missing.size()){
		//cout << missing[i].fst << missing[i].snd << endl;
	}

	if(!is_in('J','1') && !is_in('J','2')){
		if(solve()){
			cout << "Solution exists.\n";
			cout << "There are no jokers.\n";
			cout << "Put the first square to (" << sol1.fst << ", " << sol1.snd << ").\n";
			cout << "Put the second square to (" << sol2.fst << ", " << sol2.snd << ").\n";
			return 0;
		}
		else{
			cout << "No solution.\n";
		}

	}

	if(is_in('J','1') && !is_in('J','2')){
		pii whe = loc('J','1');
		fr(i,missing.size()){
			pair<char,char> card = missing[i];
			mat[whe.fst][whe.snd] = card;
			if(solve()){
				cout << "Solution exists.\n";
				cout << "Replace J1 with " << card.fst << card.snd << '.' << endl;
				cout << "Put the first square to (" << sol1.fst << ", " << sol1.snd << ").\n";
				cout << "Put the second square to (" << sol2.fst << ", " << sol2.snd << ").\n";
				return 0;
			}

		}

		cout << "No solution.\n";
		
	}

	if(!is_in('J','1') && is_in('J','2')){
		pii whe = loc('J','2');
		fr(i,missing.size()){
			pair<char,char> card = missing[i];
			mat[whe.fst][whe.snd] = card;
			if(solve()){
				cout << "Solution exists.\n";
				cout << "Replace J2 with " << card.fst << card.snd << '.' << endl;
				cout << "Put the first square to (" << sol1.fst << ", " << sol1.snd << ").\n";
				cout << "Put the second square to (" << sol2.fst << ", " << sol2.snd << ").\n";
				return 0;
			}

		}

		cout << "No solution.\n";

		
	}

	if(is_in('J','1') && is_in('J','2')){
		//olar;
		pii whe1 = loc('J','1');
		pii whe2 = loc('J','2');
		fr(i,missing.size()){
			fr(j,missing.size()){
				if(i==j) continue;
				pair<char,char> card1 = missing[i];
				pair<char,char> card2 = missing[j];
				mat[whe1.fst][whe1.snd] = card1;
				mat[whe2.fst][whe2.snd] = card2;
				if(solve()){
					cout << "Solution exists.\n";
					cout << "Replace J1 with " << card1.fst << card1.snd << " and J2 with " << card2.fst << card2.snd << '.'<< endl;
					cout << "Put the first square to (" << sol1.fst << ", " << sol1.snd << ").\n";
					cout << "Put the second square to (" << sol2.fst << ", " << sol2.snd << ").\n";
					return 0;
				}
			}

		}

		cout << "No solution.\n";
		
	}

}
