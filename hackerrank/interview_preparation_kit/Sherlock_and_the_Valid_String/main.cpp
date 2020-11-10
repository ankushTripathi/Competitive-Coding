#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {

	unordered_map<char,int> freq;
	unordered_map<int,int> freq_count;

	for(char ch : s){

		freq[ch]++;
	}

	int min_freq = 999999;
	for(auto it = freq.begin();it != freq.end();it++){

		min_freq = min(min_freq,it->second);
		freq_count[it->second]++;
	}

	for(auto it=freq_count.begin(); it != freq_count.end(); it++)
	{
		cout<<it->first<<" : "<<it->second<<endl;
	}

	string result;
	if(freq_count.size() > 2)
		result = "NO";
	else if(freq_count.size() == 1)
		result = "YES";
	else{
		auto it1 = freq_count.begin();
		auto it2 = next(it1,1);
		
		if(it1->first > it2->first){

			auto tmp = it1;
			it1 = it2;
			it2 = tmp;
		}

		if(it1->first == 1 && it1->second == 1)
			result = "YES";
		else if(it2->first == it1->first + 1 && it2->second == 1)
			result = "YES";
		else
			result = "NO";
	}

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

