#include <bits/stdc++.h>
#define SAFE_MAX INT_MAX-1 
using namespace std;

vector<string> split_string(string);


enum dirs{TOP=1,DOWN,LEFT,RIGHT};

int _minimumMoves(vector<vector<int>> helper,int i,int j,int tx,int ty,int dir){

	if(i == tx && j == ty)
		return 0;

	cout<<i<<" "<<j<<" "<<dir<<endl;
	helper[i][j] = 1;
	int result = SAFE_MAX;
	if(i-1 >= 0 && helper[i-1][j] == 0){

		result = min(result, (dir == TOP)? _minimumMoves(helper,i-1,j,tx,ty,dir) : _minimumMoves(helper,i-1,j,tx,ty,TOP) + 1);
	}
	if(i+1 < helper.size() && helper[i+1][j] == 0){

		result = min(result, (dir == DOWN)? _minimumMoves(helper,i+1,j,tx,ty,dir) : _minimumMoves(helper,i+1,j,tx,ty,DOWN) + 1);
	}
	if(j-1 >= 0 && helper[i][j-1] == 0){

		result = min(result, (dir == LEFT)? _minimumMoves(helper,i,j-1,tx,ty,dir) : _minimumMoves(helper,i,j-1,tx,ty,LEFT)+1);
	}
	if(j+1 < helper.size() && helper[i][j+1] == 0){

		result = min(result, (dir == RIGHT)? _minimumMoves(helper,i,j+1,tx,ty,dir) : _minimumMoves(helper,i,j+1,tx,ty,RIGHT)+1);
	}

	return result;	
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int sx, int sy, int gx, int gy) {

	vector<vector<int>> helper;
	for(string row : grid){

		vector<int> r;
		for(char ch : row){

			if(ch == 'X')
				r.push_back(1);
			else
				r.push_back(0);
		}

		helper.push_back(r);
	}

	helper[sx][sy] = 1;
	int result = SAFE_MAX;
	if(sx-1 >= 0 && helper[sx-1][sy] == 0)
		result = min(result,_minimumMoves(helper,sx-1,sy,gx,gy,TOP)+1);
	if(sx+1 < helper.size() && helper[sx+1][sy] == 0)
		result = min(result,_minimumMoves(helper,sx+1,sy,gx,gy,DOWN)+1);
	if(sy-1 >= 0 && helper[sx][sy-1] == 0)
		result = min(result,_minimumMoves(helper,sx,sy-1,gx,gy,LEFT)+1);
	if(sy+1 < helper.size() && helper[sx][sy+1] == 0)
		result = min(result,_minimumMoves(helper,sx,sy+1,gx,gy,RIGHT)+1);

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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

