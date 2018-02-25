/*
 * Account implementation file
 * Author: Jose Quirarte
 * Date 2/24/18
 *
 * */
#include "account.h"


bool Account::failure = false;
bool Account::success = true;

/* PURPOSE:  The default constructor of Account.
 * Author: Jose Quirarte
 * Date:   2/24/18
 * */
Account::Account()
{
    m_budget = 0;
    m_spendings = 0;
    m_savings = 0;
    savingsPercentage = 0;
}

/* PURPOSE:  verifyNumber will check to see if the user inputted
 * value is valid. It will return failure if the value is negative.
 * Otherwise, returns success
 *
 * PARAMETER: input is a number that the user enters
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
bool Account::verifyNumber(int input)
{
    //We dont want a negative input
    if(input < 0)
        return failure;

    return success;
}

/* PURPOSE: It will set the monthly budget to what the user enters as an input,
 * if the input is valid. If the input is invalid, It will return failure.
 * Otherwise sets the monthly budget, informs a slot of the change and returns success.
 *
 * PARAMETER: b is the what the user wants to set the monthly budget to.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
bool Account::setBudget(int b)
{
    if(verifyNumber(b) == failure)
        return failure;

    m_budget = b;
    emit budgetChanged(b);
    return success;
}

/* PURPOSE: It will set monthly savings to the product of
 * monthly budget and savingsPercent (after savingsPercent has been converted).
 * If savingsPercent is not a valid input, then it returns failure.
 * Otherwise the product is set to monthly savings,
 * it informs a slot of the change, and returns success;
 *
 * PARAMETER: savingsPercent is the percentage of the budget the user wants to save
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */

bool Account::setSavings(int savingsPercent)
{
   if(verifyNumber(savingsPercent) == failure)
        return failure;

   savingsPercentage = savingsPercent;
   m_savings = m_budget * ((double) savingsPercent / 100);
   emit savingsChanged(m_budget * ((double)savingsPercent / 100));
   return success;

}

/* PURPOSE: It will set the monthly spendings to what the user enters as an input,
 * if the input is valid. If the input is invalid, It will return failure.
 * Otherwise sets the monthly spendings, informs a slot of the change and returns success.
 *
 * PARAMETER: spendings is the what the user wants to set the monthly spending to.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
bool Account::setSpendings(int spendings)
{
    if(verifyNumber(spendings) == failure)
        return failure;

    m_spendings = spendings;
    emit spendingsChanged(spendings);
    return success;
}

/* PURPOSE: It will return the monthly budget.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
int Account::getBudget() const
{
    return m_budget;
}

/* PURPOSE: It will return the monthly savings.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
int Account::getSavings() const
{
    return m_savings;
}

/* PURPOSE: It will return the monthly spendings.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
int Account::getSpendings() const
{
    return m_spendings;
}

/* PURPOSE: It will return the savings Percentage.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
int Account::getSavingsPercent() const
{
    return savingsPercentage;
}

