/*
Input: 6 × 5 matrix filled with O (Open cell), X (Blocked Cell), and M (Landmine).
 
O   M   O   O   X
O   X   X   O   M
O   O   O   O   O
O   X   X   X   O
O   O   M   O   O
O   X   X   M   O
 
Output:
 
1   0   1   2  -1
2  -1  -1   1   0
3   4   3   2   1
3  -1  -1  -1   2
2   1   0   1   2
3  -1  -1   0   1

link:https://www.techiedelight.com/find-shortest-distance-every-cell-landmine-maze/

*/
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
 
// `M × N` matrix
#define M 6
#define N 5
 
// A Queue Node
struct Node
{
    int x;          // stores x–coordinate of a matrix cell
    int y;          // stores y–coordinate of a matrix cell
    int distance;   // stores the distance of `(x, y)` from mine
};
 
// check if specified row and column are valid matrix index
bool isValid(int i, int j) {
    return (i >= 0 && i < M) && (j >= 0 && j < N);
}
 
// check if the current cell is an open area, and its
// distance from the mine is not yet calculated
bool isSafe(int i, int j, char mat[][N], int result[][N]) {
    return mat[i][j] == 'O' && result[i][j] == -1;
}
 
// Replace all O's in a matrix with their shortest distance
// from the nearest mine
void updateDistance(char mat[][N], int result[][N])
{
    // initialize an empty queue
    queue<Node> Q;
 
    // find all mines location and add them to the queue
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // if the current cell represents a mine
            if (mat[i][j] == 'M')
            {
                Q.push({i, j, 0});
 
                // update mine distance as 0
                result[i][j] = 0;
            }
            // otherwise, initialize the mine distance by -1
            else {
                result[i][j] = -1;
            }
        }
    }
 
    // arrays to get indices of four adjacent cells of a given cell
    int R[] = { 0, -1, 0, 1 };
    int C[] = { -1, 0, 1, 0 };
 
    // do for each node in the queue
    while (!Q.empty())
    {
        // process front cell in the queue
        int x = Q.front().x;
        int y = Q.front().y;
        int distance = Q.front().distance;
 
        // dequeue front cell
        Q.pop();
 
        // update the four adjacent cells of the front node in the queue
        for (int i = 0; i < 4; i++)
        {
            // enqueue adjacent cell if it is valid, unvisited,
            // and has a path through it
            if (isValid(x + R[i], y + C[i]) &&
                isSafe(x + R[i], y + C[i], mat, result))
            {
                result[x + R[i]][y + C[i]] = distance + 1;
                Q.push({x + R[i], y + C[i], distance + 1});
            }
        }
    }
}
 
int main()
{
    char mat[][N] =
    {
        {'O', 'M', 'O', 'O', 'X'},
        {'O', 'X', 'X', 'O', 'M'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'X', 'X', 'O'},
        {'O', 'O', 'M', 'O', 'O'},
        {'O', 'X', 'X', 'M', 'O'}
    };
 
    int result[M][N];
    updateDistance(mat, result);
 
    // print results
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            cout << setw(5) << result[i][j];
        }
        cout << endl;
    }
 
    return 0;
}


