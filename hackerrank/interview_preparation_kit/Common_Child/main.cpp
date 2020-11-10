#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

	int n = s1.length();
	int lcs[2][n+1];

	int bi = 0;
	for(int i=0;i<=n;i++){

		bi = i&1;
		for(int j=0;j<=n;j++){

			if(i == 0 || j == 0)
				lcs[bi][j] = 0;
			else if(s1[i-1] == s2[j-1])
				lcs[bi][j] = 1 + lcs[1 - bi][j-1];
			else
				lcs[bi][j] = max(lcs[bi][j-1],lcs[1 - bi][j]);
		}
	}

	return lcs[bi][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

