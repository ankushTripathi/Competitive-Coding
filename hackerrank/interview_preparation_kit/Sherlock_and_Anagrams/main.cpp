#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

	int n = s.length();
	map<vector<int>,int> mp;

	for(int i=0;i<n;i++)
	{
		vector<int> freq(26,0);
		for(int j=i;j<n;j++)
		{
			freq[(s[j] - 'a')]++;
			mp[freq]++;
		}
	}

	int result = 0;
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		int cnt = it->second;
		result += (cnt * (cnt - 1))/2;
	}
	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

