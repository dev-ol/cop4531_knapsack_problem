
#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int profits[], int weight[], int numItems, int maxWeight);

int main()
{

    int profits[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int numItems = sizeof(profits) / sizeof(profits[0]);
    int maxWeight = 50;

    int result = knapSack(profits, weight, numItems, maxWeight);

    cout << result << endl;

    return 0;
}

int knapSack(int profits[], int weight[], int numItems, int maxWeight)
{
    int table[numItems + 1][maxWeight + 1] = {
        {0, 0},
        {0, 0}};

    for (int i = 0; i < (numItems + 1); i++)
    {
        for (int x = 0; x < (maxWeight + 1); x++)
        {
            if (i == 0 || x == 0)
            {
                table[i][x] = 0;
            }
            else if (weight[i - 1] <= x)
            {
                table[i][x] = max(profits[i - 1] + table[i - 1][x - weight[i - 1]],
                                  table[i - 1][x]);
            }
            else
            {
                table[i][x] = table[i - 1][x];
            }
        }
    }

    return table[numItems][maxWeight];
}
8768929679