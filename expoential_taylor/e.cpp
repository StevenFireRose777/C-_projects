#include <iostream>

// Compile: g++ -g -Wall -Werror -Wextra e.cpp -o e



// e^x taylor series: 1 + x + x^2/2! + x^3/3! + ... + x^n / n!

// 4! = 4 x 3 x 2 x 1
// 1! = 1
// 0! = 1


using namespace std;

int factorial_recursive(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n * factorial_recursive(n - 1); // multiplying ascending terms
}

double d_power(double x, int n)
{
    // 3^2 = 3 X 3
    // 6^6 = 6 x 6 x 6 x 6 x 6 

    if(n == 0) return 1;

    return x * d_power(x, n - 1); 
}


double e_taylor_reucursive(double x, int n)
{
    if(n == 1)
    {
        return x;
    }
    return (d_power(x, n) / factorial_recursive(n)) + e_taylor_reucursive(x, n - 1);
}

double _e_taylor(double x, int n)
{
    // return 1 + x + (d_power(x, n) / factorial_recursive(n));

    if(n == 0) return 1;

    double total = 1 + e_taylor_reucursive(x, n);
    return total;
    
}

int main(void)
{

    cout << _e_taylor(1, 20) << endl;
    // e_taylor(x,n)
    return 0;
}
