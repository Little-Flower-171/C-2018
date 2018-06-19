/*
Returns the factorial of x.
Requires: 0 <= x && x <= 20
Otherwise the behavior is undefined
*/
long long fact(int x)
{
    long long res = 1;
    for (int i = 2; i <= x; ++i)
        res *= i;
    return res;
}
