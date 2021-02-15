#include "bits/stdc++.h"
using namespace std;

struct trie{
	int cnt,wrd;
	map<char,trie> m;
	trie(){
		cnt = 0;wrd = 0;
		m.clear();
	}
	void add(string &s,int i){ // add string to trie
		cnt++;
		if(i == s.size()){
			wrd++;
			return;
		}
		if(!m.count(s[i])){
			m[s[i]] = trie();
		}
		m[s[i]].add(s,i+1);
	}
	
	bool remove(string &s,int i){ //true if s was in the trie, then remove it
		if(i == s.size()){
			if(wrd){
				wrd--;
				cnt--;
				return true;
			}
			return false;
		}

		if(!m.count(s[i])) return false;
		if(m[s[i]].remove(s,i+1)){
			cnt--;
			return true;
		}
	}
	bool find(string &s,int i){ // True if s is in the trie
		if(i == s.size()){
			if(wrd) return true;
			return false;
		}
		if(!m.count(s[i])) return false;
		return(m[s[i]].find(s,i+1));

	}
};

int main(){

}
