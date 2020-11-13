#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {

	unordered_map<char,int> freq;
	for(char ch : s){

		freq[ch]++;
	}


	reverse(s.begin(),s.end());
	
	unordered_map<char,int> available(freq), used;
	string result = "";

	for(char ch : s){

		if(used.find(ch) == used.end() || used[ch] < freq[ch]/2){

			if(used.find(ch) == used.end())
				used[ch] = 0;

			while((result.length() > 0) && (ch < result.back()) && (available[result.back()] + used[result.back()] > freq[result.back()]/2)){

				used[result.back()]--;
				result.pop_back();
			}

			result += ch;
			available[ch]--;
			used[ch]++;
		}
		else{

			available[ch]--;
		}
	}

	return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

