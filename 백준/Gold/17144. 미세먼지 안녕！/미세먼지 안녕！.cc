#include <iostream>
#include <algorithm>
using namespace std;
int room[51][51];
int temp[51][51];
int r, c;
int purifier;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void diffusion()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (room[i][j] == -1 || room[i][j] == 0) continue;
            int diffCount = 0;
            int diffValue = room[i][j] / 5;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || nx > r || ny < 1 || ny > c || room[nx][ny] == -1) continue;
                temp[nx][ny] += diffValue;
                room[i][j] -= diffValue;
            }
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            room[i][j] += temp[i][j];
        }
    }
}
void purify()
{
    for (int i = 2; i < c; i++) temp[purifier][i + 1] = room[purifier][i];
    for (int i = purifier; i > 1; i--) temp[i - 1][c] = room[i][c];
    for (int i = c; i > 1; i--) temp[1][i - 1] = room[1][i];
    for (int i = 1; i < purifier - 1; i++) temp[i + 1][1] = room[i][1];

    for (int i = 2; i < c; i++) temp[purifier + 1][i + 1] = room[purifier + 1][i];
    for (int i = purifier + 1; i < r; i++) temp[i + 1][c] = room[i][c];
    for (int i = c; i > 1; i--) temp[r][i - 1] = room[r][i];
    for (int i = r; i > purifier + 1; i--) temp[i - 1][1] = room[i][1];

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == 1 || i == r || j == 1 || j == c || i == purifier || i == purifier + 1)
            {
                if (room[i][j] == -1) continue;
                room[i][j] = temp[i][j];
            } 
        }
    }
    room[purifier][2] = 0;
    room[purifier + 1][2] = 0; 
}
int main()
{
    int t;
    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1) if(!purifier) purifier = i;
        }
    }
    while(t--)
    {
        diffusion();
        fill(&temp[0][0], &temp[0][0] + 2601, 0);
        purify();
        fill(&temp[0][0], &temp[0][0] + 2601, 0);
    }
    int res = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (room[i][j] == -1) continue;
            res += room[i][j];
        }
    }
    cout << res;
    return 0;
}