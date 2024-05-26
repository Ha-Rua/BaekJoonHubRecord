#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> dwarfs(9);
    for (int i = 0; i < 9; i++)
        cin >> dwarfs[i];
    for (int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            int sum = 0;
            for(int k = 0; k < 9; k++)
            {
                if(k!=i && k!=j)
                    sum += dwarfs[k];
            }
            if(sum == 100)
            {
                vector<int> sevendwarfs;
                for(int l = 0; l < 9; l++)
                {
                    if(l!=i && l!=j)
                        sevendwarfs.push_back(dwarfs[l]);
                }
                sort(sevendwarfs.begin(), sevendwarfs.end());
                for(int l = 0; l < 7; l++)
                    cout << sevendwarfs[l] << '\n';
                return 0;
            }
        }
    }
    return 0;
}