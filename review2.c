#include <stdio.h>

void determineRate(double initDep, float *pRate, int *pYears);
double computeTotalInvestment(double amount, float rate, int duration);

int main()
{
    double deposit, finalVal;
    float rate;
    int years;

    printf("How much do you plan to deposit? ");
    scanf("%lf", &deposit);

    determineRate(deposit, &rate, &years);
    printf("You are entitled to %.2f annual interest rate for %d years\n",
           rate, years);
    finalVal = computeTotalInvestment(deposit, rate, years);
    printf("That means your initial %.2f will become %.2f after %d years\n",
           deposit, finalVal, years);

    return 0;
}

void determineRate(double initDep, float *pRate, int *years)
{
    if (initDep >= 1000000)
    {
        *pRate = 0.03, *years = 5;
    }
    else if (initDep >= 750000)
    {
        *pRate = 0.015, *years = 3;
    }
    else if (initDep >= 100000)
    {
        *pRate = 0.0075, *years = 3;
    }
    else if (initDep > 50000)
    {
        *pRate = 0.0055, *years = 5;
    }
    else
    {
        *pRate = 0, *years = 0;
    }

}

double computeTotalInvestment(double amount, float rate, int duration)
{
    for (int i = 0; i < duration; i++)
    {
        amount += (rate * amount);
    }
    
    return amount;
}