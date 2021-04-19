
#include <iostream>
#include <cmath>

using namespace std;

int getMax(int left, int right);

int knapsack(int profits[], int weight[], int numItems, int maxWeight);

int main()
{
    int numItems = 100;
    int profits[numItems]; 
    int weight[numItems];
    int maxWeight = 335732;

    for(int i=0; i < numItems; i++){
        weight[i] = round((1000 * sqrt(i+1)));
        profits[i] = 1;
    }

   int result = knapsack(profits, weight, numItems, maxWeight);

    cout << result << endl;
    return 0;
}

int knapsack(int profits[], int weight[], int numItems, int maxWeight)
{
    int x = numItems + 1;
    int y = maxWeight + 1;
   
    int ** table = new int * [x] {0};

    for(size_t i = 0; i < numItems+1; i++){
        table[i] = new int[y]{0};
    }

    for (int i = 0; i <= numItems; i++)
    {
        for (int x = 0; x <= maxWeight; x++)
        {
            if (i == 0 || x == 0)
            {
                table[i][x] = 0;
            }
            else if (weight[i - 1] <= x)
            {
                table[i][x] = getMax(profits[i - 1] + table[i - 1][x - weight[i - 1]],
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


int getMax(int left, int right) { 
    
    return (left > right) ? left : right; 
    
}