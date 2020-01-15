#include <iostream>
#include <vector>
#include <string>
using namespace std;

int fill_oneBlock(vector<vector<int>>& board, const int h, const int w);
// fill_oneBlock에서 h, w 를 받아오는데 board.size()< board[0].size()로 알아낼 수 있다.
int size_board(vector<vector<int>>& board);
bool first_one(vector<vector<int>>& board, const int w, const int p, const int q);

int main(void)
{
    int n_test, h, w;
    int result = 0;
    cin >> n_test;
    
    string temp;
    while(n_test--)
    {
        cin >> h >> w;
        vector<vector<int>> board(h, vector<int>(w,0));
        for(int i=0; i<h; i++)
        {
            cin >> temp;
            for(int j=0; j<w; j++)
                board[i][j] = (temp[j] == '#') ? 0 : 1;
        }
        result = fill_oneBlock(board, h, w);
        cout << result << endl;
    }
    return 0;
}

int size_board(vector<vector<int>>& board)
{
    int count = 0;
    for (vector<int> row : board)
        for (int unit : row)
            count += unit;
    return count;
}

int fill_oneBlock(vector<vector<int>>& board, const int h, const int w)
{
    int size = size_board(board);
    int count = 0;
    if (size % 3 != 0)
    {
        // cout << "size is not multiply of 3" << endl;
        return 0;
    }
    if (size == 0)
    {
        // cout << "find case" << endl;
        return 1;
    }
    for (int i=0; i<h-1; i++)
    {
        for (int j=0; j<w; j++)
        {
            if (!first_one(board, w, i, j))
            {
                // cout << i << " " << j << " " << "not first_one" << endl;
            }
            else
            {
                if (board[i][j])
                {
                    if(j == 0)
                    {
                        // cout << "j is 0" << endl;
                        if (board[i][j+1] && board[i+1][j+1])
                        {
                            board[i][j] = board[i][j+1] = board[i+1][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i][j+1] = board[i+1][j+1] = 1;
                        }
                        if (board[i+1][j] && board[i+1][j+1])
                        {
                            board[i][j] = board[i+1][j] = board[i+1][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i+1][j+1] = 1;
                        }
                        if (board[i][j+1] && board[i+1][j])
                        {
                            board[i][j] = board[i+1][j] = board[i][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i][j+1] = 1;                        
                        }
                    }
                    else if (j==w-1)
                    {
                        // cout << "j is w-1" << endl;
                        if (board[i+1][j] && board[i+1][j-1])
                        {
                            board[i][j] = board[i+1][j] = board[i+1][j-1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i+1][j-1] = 1;
                        }
                    }
                    else
                    {
                        if (board[i][j+1] && board[i+1][j+1])
                        {
                            // cout << "case 1" << endl;
                            board[i][j] = board[i][j+1] = board[i+1][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i][j+1] = board[i+1][j+1] = 1;
                        }
                        if (board[i+1][j] && board[i+1][j+1])
                        {
                            // cout << "case 2" << endl;
                            board[i][j] = board[i+1][j] = board[i+1][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i+1][j+1] = 1;
                        }
                        if (board[i+1][j] && board[i+1][j-1])
                        {
                            // cout << "case 3" << endl;
                            board[i][j] = board[i+1][j] = board[i+1][j-1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i+1][j-1] = 1;
                        }
                        if (board[i][j+1] && board[i+1][j])
                        {
                            // cout << "case 4" << endl;
                            board[i][j] = board[i+1][j] = board[i][j+1] = 0;
                            count += fill_oneBlock(board, h, w);
                            board[i][j] = board[i+1][j] = board[i][j+1] = 1;                        
                        }
                    }          
                }
            }
        }

    }
    // cout << "count is " << count << endl;
    return count;
}

bool first_one(vector<vector<int>>& board, const int w, const int p, const int q)
{
    for (int i=0;i<p;i++)
        for (int j=0;j<w;j++)
            if (board[i][j])
                return false;
    for (int j=0;j<q;j++)
        if (board[p][j])
            return false;
    return true;
}

/*
 * index가 벗어나는 경우를 if문으로 처리했는데 index안에 들어가는 값을 미리 계산해서 막는 방식이 코드 줄인다
 * 좀 더 자세히 말하면 fill 하는게 가능한지 판단하고 덮는 함수를 따로 만듬
 * 제일 위, 왼쪽 칸을 찾고 난 후에는 break로 빠져나오면 됨. 굳이 끝까지 볼 필요 없음.
 */