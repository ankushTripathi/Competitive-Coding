#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {

    long result = n;

    for(int i=0;i<n;i++){

	    int nextIndex = i;
	    while((nextIndex + 1 < n) && s[nextIndex + 1] == s[i]) nextIndex++;

	    if(i != nextIndex){

		    long length = nextIndex - i;
		    result += (length * (length + 1))/2;

		    i = nextIndex;
	    }
	    else{
		    int step = 1;
		    while(((i+step < n) && (i-step >= 0)) && s[i+step] == s[i-step] && s[i+step] == s[i+1]){
			    step++;
			    result++;
		    }
	    }

    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

