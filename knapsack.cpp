
#include <iostream>
#include <cmath>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(double profits[], int weight[], int numItems, int maxWeight);

int main()
{
    int numItems = 100;
    double profits[numItems];
    int weight[numItems];
    int maxWeight = 335732;

    for(int i=0; i < numItems; i++){
        weight[i] = int((1000 * pow(i+1,0.5)));
        profits[i] = ( i+1/(1000 * pow(i+1,0.5)));
    }


   int result = knapSack(profits, weight, numItems, maxWeight);

   cout << result << endl;


    return 0;
}

int knapSack(double profits[], int weight[], int numItems, int maxWeight)
{
    int x = numItems + 1;
    int y = maxWeight + 1;
   
    int ** table = new int * [x] ;

    for(size_t i = 0; i < numItems+1; i++){
        table[i] = new int[y];
    }

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


    // for(int i=0; i < numItems+1; i++){
    //     for(int x = 0; x <  maxWeight+1; x++){
    //         cout << table[i][x] << endl;
    //     }
    // }
    
    return table[numItems][maxWeight];
}
