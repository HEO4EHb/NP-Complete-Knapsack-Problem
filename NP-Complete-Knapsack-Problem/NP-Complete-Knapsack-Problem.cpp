#include <iostream>

using namespace std;

// функция для возврата максимального из двух чисел
int max(int a, int b) { return (a > b) ? a : b; }

// возвращает максимальное значение которое можно положить в рюкзак размера W
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // если вес n-ного предмета больше чем вместимость W рюказка
    // тогда мы не можем положить предмет
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Возвращаем максимум из двух случаев:
    // (1) n-ный предмет вместился 
    // (2) или не вместился
    else
        return max(
            val[n - 1]
            + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}


int main()
{
    int profit[] = { 60, 100, 120 };//ценность
    int weight[] = { 10, 20, 30 };//вес
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << "profit= " << knapSack(W, weight, profit,n) << endl;    
    return 0;
}

