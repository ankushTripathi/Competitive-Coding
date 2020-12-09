#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {

	stack<char> stk;
	string result = "YES";
	for(char ch : s){

		if(ch == '{' || ch == '[' || ch == '('){

			stk.push(ch);
		}
		else{

			if(stk.empty()){

				result = "NO";
				break;
			}

			if(stk.top() == '{' && ch != '}'){

				result = "NO";
				break;
			}
			else if(stk.top() == '[' && ch != ']'){

				result = "NO";
				break;
			}
			else if(stk.top() == '(' && ch != ')'){

				result = "NO";
				break;
			}
			else{
				stk.pop();
			}
		}
	}

	if(!stk.empty()) result = "NO";

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

