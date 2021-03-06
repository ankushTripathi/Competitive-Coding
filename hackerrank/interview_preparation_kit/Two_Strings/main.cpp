#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

	unordered_map<char,bool> m;
	if(s2.length() > s1.length())
	{
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	for(char c : s1)
	{
		m[c] = true;
	}

	bool flag = false;
	for(char c : s2)
	{
		if(m.find(c) != m.end())
		{
			flag = true;
			break;
		}
	}

	return (flag)? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

