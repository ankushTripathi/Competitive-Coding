#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {

	int n = h.size();
	stack<int> stk;
	vector<int> left(n,-1);
	vector<int> right(n,n);

	for(int i=0;i<n;i++){

		while(!stk.empty() && h[stk.top()] > h[i]){

			right[stk.top()] = i-1;
			stk.pop();
		}

		stk.push(i);
	}

	while(!stk.empty()){

		right[stk.top()]--;
		stk.pop();
	}

	for(int i=n-1;i>=0;i--){

		while(!stk.empty() && h[stk.top()] > h[i]){

			left[stk.top()] = i+1;
			stk.pop();
		}

		stk.push(i);
	}

	while(!stk.empty()){

		left[stk.top()]++;
		stk.pop();
	}


	long result = 0;
	for(int i=0;i<n;i++){

		result = max(result,(long)h[i] * (long)(right[i] - left[i] + 1));
	}

	return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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

