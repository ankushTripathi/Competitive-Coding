#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

class Node{

public :
	int data;
	int depth;

	Node *left;
	Node *right;

	Node(int data,int depth){

		this->data = data;
		this->depth = depth;

		this->left = NULL;
		this->right = NULL;
	}
};

void inorder(Node *root,vector<int> &row){

	if(root == NULL)
		return;

	inorder(root->left,row);
	row.push_back(root->data);
	inorder(root->right,row);
}

void swapNodes(Node *root, int k){

	if(root == NULL)
		return;

	if(root->depth%k == 0)
	{
		Node *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}

	swapNodes(root->left,k);

	swapNodes(root->right,k);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */

	queue<Node *> nodes;
	Node *root = new Node(1,1);
	nodes.push(root);

	int n = indexes.size();
	for(int i=0;i<n;i++)
	{
		Node *curr = nodes.front();
		nodes.pop();

		curr->left = (indexes[i][0] == -1)? NULL : new Node(indexes[i][0],curr->depth + 1);
		curr->right = (indexes[i][1] == -1)? NULL : new Node(indexes[i][1],curr->depth + 1);

		if(curr->left)
			nodes.push(curr->left);
		if(curr->right)
			nodes.push(curr->right);
	}

	//inorder(root);
	vector<vector<int>> result;
	
	for(int k : queries)
	{
		swapNodes(root,k);
		vector<int> row;
		inorder(root,row);
		result.push_back(row);
	}

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

