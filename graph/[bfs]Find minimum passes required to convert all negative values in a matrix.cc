/*
link:https://www.techiedelight.com/find-minimum-passes-required-convert-negative-values-matrix/
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
 
// `M × N` matrix
#define M 4
#define N 5
 
// Data structure to store the cell coordinates of the matrix
struct Point {
    int x, y;
};
 
// Function to check whether given coordinates is a valid cell or not
bool isValid(int i, int j) {
    return (i >= 0 && i < M) && (j >= 0 && j < N);
}
 
// Below arrays detail all four possible movements from a cell
// (top, right, bottom, and left)
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
 
// Returns true if the matrix contains at least one negative value
bool hasNegative(int mat[][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] < 0) {
                return true;
            }
        }
    }
 
    return false;
}
 
// Find the minimum number of passes required to convert all negative values
// in the given matrix to positive
int convert(int mat[][N])
{
    // create a queue to store cell coordinates of positive integers
    queue<Point> Q;
 
    // enqueue cell coordinates of all positive numbers in the matrix
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] > 0) {
                Q.push({i, j});
            }
        }
    }
 
    // to keep track of the time taken to make all numbers positive
    int passes = 0;
 
    // loop till all reachable negative numbers in the matrix are processed
    while (!Q.empty())
    {
        // use two queues to separate positive numbers involved in the
        // previous pass with positive numbers involved in the current pass
        queue<Point> q;
 
        // copy contents of the original queue `Q` to another queue `q` and
        // empty the original queue
        swap(Q, q);
 
        /* Start of the current pass */
 
        // process all cells in the queue
        while (!q.empty())
        {
            // pop front node and process it
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
 
            // check all four adjacent cells of the current cell
            for (int k = 0; k < 4; k++)
            {
                // if the current adjacent cell is valid and has a negative value
                if (isValid(x + row[k], y + col[k]) &&
                    mat[x + row[k]][y + col[k]] < 0)
                {
                    // make the value positive
                    mat[x + row[k]][y + col[k]] = -mat[x + row[k]][y + col[k]];
 
                    // enqueue adjacent cell
                    Q.push({x + row[k], y + col[k]});
                }
            }
        }
 
        /* End of the current pass */
 
        // increment number of passes by 1
        passes++;
    }
 
    // return number of passes or
    // infinity if the matrix has an unreachable cell which is negative
    return hasNegative(mat) ? INT_MAX : (passes - 1);
}
 
int main()
{
    int mat[][N] =
    {
        { -1, -9, 0, -1, 0 },
        { -8, -3, -2, 9, -7 },
        { 2, 0, 0, -6, 0 },
        { 0, -7, -3, 5, -4 }
    };
 
    int pass = convert(mat);
    if (pass != INT_MAX) {
        cout << "The total number of passes required is " << pass;
    }
    else {
        cout << "Invalid Input";
    }
 
    return 0;
}


