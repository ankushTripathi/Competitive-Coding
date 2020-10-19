#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * 6 3
 * 1 3 9 9 27 81
 * 
 * 
 */

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

	unordered_map<long,long> leftMap;
	unordered_map<long,long> rightMap;

	for(long x : arr)
	{
		if(rightMap.find(x) == rightMap.end())
		{
			rightMap[x] = 0;
		}
		rightMap[x]++;
	}

	long result = 0;
	for(long x : arr)
	{
		long rhs = x * r;
		long lhs = (x % r == 0)? x/r : 0;
		long leftCount = 0;
		long rightCount = 0;

		rightMap[x]--;
		if(rightMap.find(rhs) != rightMap.end())
		{
			rightCount = rightMap[rhs];
		}
		if(leftMap.find(lhs) != leftMap.end())
		{
			leftCount = leftMap[lhs];
		}

		result += leftCount * rightCount;
		
		if(leftMap.find(x) == leftMap.end())
		{
			leftMap[x] = 0;
		}
		leftMap[x]++;
	}

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

