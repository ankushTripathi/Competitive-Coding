#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


long merge(vector<int> &arr,int start,int end,int mid)
{
	int i = start;
	int j = mid+1;
	vector<int> c;
	long count = 0;

	while(i <= mid && j<=end)
	{
		if(arr[i] <= arr[j])
		{
			c.push_back(arr[i++]);
		}
		else
		{
			count += (mid - i + 1);
			c.push_back(arr[j++]);
		}
	}

	while(i<=mid)
	{
		c.push_back(arr[i++]);
	}

	while(j<=end)
	{
		c.push_back(arr[j++]);
	}

	for(int k=0,l=start;k<c.size();k++,l++)
	{
		arr[l] = c[k];
	}

	return count;
}

long _countInversions(vector<int> &arr,int start,int end)
{
	long count = 0;
	if(start < end)
	{
		int mid = (start + end)/2;
		count += _countInversions(arr,start,mid);
		count += _countInversions(arr,mid+1,end);
		count += merge(arr,start,end,mid);
	}
	return count;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {

	return _countInversions(arr,0,arr.size()-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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

