#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

	unordered_map<char,int> freq;
	
	for(char ch : a){

		if(freq.find(ch) == freq.end()){

			freq[ch] = 0;
		}
		freq[ch]++;
	}

	for(char ch : b){

		if(freq.find(ch) == freq.end()){

			freq[ch] = 0;
		}
		freq[ch]--;
	}


	int result = 0;
	for(auto it = freq.begin(); it != freq.end(); it++){
	
		result += abs(it->second);
	}

	return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

