#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool dfs(const vector<vector<char>>& board, const string& word, int x, int y,int k, bool vis[][151]) {
	if (k == word.size())
		return 1;
	int row = board.size();
	int col = board[0].size();
	int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };
	for (int i = 0; i < 8; ++i)
	{
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if (tmpx < 0 || tmpx >= row)
			continue;
		if (tmpy < 0 || tmpy >= col)
			continue;
		if (vis[tmpx][tmpy])
			continue;
		if (board[tmpx][tmpy] != word[k])
			continue;
		vis[tmpx][tmpy]=1;
		if (dfs(board, word, tmpx, tmpy, k + 1, vis))
		{
			return 1;
		}
		vis[tmpx][tmpy] = 0;
	}
	return 0;
}
bool check_word(const vector<vector<char>>& board, const string& word)
{
	int row = board.size();
	int col = board[0].size();
	bool flag = 0;
	bool vis[151][151] = {};
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++) {
			if (board[i][j] == word[0]) {
				vis[i][j] = 1;
				flag = dfs(board, word, i, j, 1, vis);
				vis[i][j] = 0;
			}
			if (flag)
				return flag;
		}
	return 0;
}
int main(void)
{
	vector<vector<char>> board;
	string word;
	bool res;
	cin >> word;
	board.push_back({ 'N','B','R','A' });
	board.push_back({ 'C','R', 'P','A' });
	board.push_back({ 'L', 'A','A', 'P' });
	board.push_back({ 'S', 'O', 'A', 'A' });

	res = check_word(board, word);

	cout << res << endl;
	return 0;
}