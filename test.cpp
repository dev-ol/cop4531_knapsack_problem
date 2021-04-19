/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
// Driver code
int main()
{
    int numItems = 10;
    int val[numItems] ={0};
    int wt[numItems] = {0};
    int W = 2000;

     for(int i=0; i < numItems; i++){
        wt[i] = int((1000 * sqrt(i+1)));
        //cout << wt[i] << endl;
        val[i] = i+1; //( i+1/(1000 * pow(i+1,0.5)));
    }
    int n = sizeof(val) / sizeof(val[0]);


    cout << knapSack(W, wt, val, n);
    return 0;
}
 