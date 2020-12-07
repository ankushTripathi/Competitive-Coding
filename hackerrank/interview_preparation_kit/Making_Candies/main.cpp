#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

vector<string> split_string(string);

// Complete the minimumPasses function below.
long minimumPasses(long m, long w, long p, long n) {

	ull machines = m;
	ull workers = w;
	ull price = p;
	ull target = n;

	ull passes = 0,candies = 0,power = 0,result = ULLONG_MAX;

	while(true){

		passes++;
		power = machines*workers;
		candies += power;

		result = min(result,(ull)(passes + ceil((((double)target - (double)candies))/((double)power))));
		
		if(passes >= result) break;
		if(candies >= target) break;

		if(candies >= price){

			ull purchase = candies/price;
			candies -= purchase*price;

			purchase += machines + workers;
			machines = purchase/2;
			workers = purchase - machines;
		}
		else{
			ull steps = ceil(((double)(price - candies))/((double)(power))) - 1;
			passes += steps;
		      	candies += steps*power;
		}
	}

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    long m = stol(mwpn[0]);

    long w = stol(mwpn[1]);

    long p = stol(mwpn[2]);

    long n = stol(mwpn[3]);

    long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

