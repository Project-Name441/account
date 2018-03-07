/*
 * Account implementation file
 * Author: Jose Quirarte
 * Date 2/24/18
 *
 * */
#include "account.h"


bool Account::failure = false;
bool Account::success = true;
Account* Account::_instance = 0;

/* PURPOSE:  The default constructor of Account.
 * Author: Jose Quirarte
 * Date:   2/24/18
 * */
Account::Account()
{

    // I hardcoded some numbers so that we dont have to use setters for testing purposes
    m_income = 4000;
    m_budget = 2000;
    m_spendings = 500;
    m_savings = 1000;
    savingsPercentage = 50;


}

/*PURPOSE: This function is used to make sure there is only one account per user?(probably a better way to
 * state this)
 * if an account has not been created make _instance point to a new account and return the pointer
 * otherwise just return instance since an account already exists
 * Author: Jose Quirarte
 * Date: 3/3/18
 *
 * */
Account* Account::Instance()
{

    if(_instance == 0)
        _instance = new Account();

    return _instance;
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

/* PURPOSE: It will set the monthly budget, informs a slot of the change and returns success
 * if certain conditions are met.
 * Otherwise returns failure.
 *
 * PARAMETER: b is the what the user wants to set the monthly budget to.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
bool Account::setBudget(int b)
{
    //we dont want m_budget and b to be the same in case of cyclic connections to avoid infinite looping
    //and we also want to make sure b is positive
    if(verifyNumber(b) == success && m_budget != b)
        {
            m_budget = b;
            emit accountModified();
            return success;
        }
    return failure;
}

/* PURPOSE: It will set monthly savings to the product of
 * monthly budget and savingsPercent (after savingsPercent has been converted),
 * it informs a slot of the change, and returns success if certain conditions are met;
 * otherwise returns failure.
 *
 * PARAMETER: savingsPercent is the percentage of the budget the user wants to save
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */

bool Account::setSavings(int savingsPercent)
{
    //we convert savingsPercent to decimal and then multiply it with the monthly budget to get
    // the new savings amount
    int new_savings = m_income * ((double) savingsPercent / 100);

    //we dont want m_savings and new_savings to be the same in case of cyclic connections to avoid infinte looping
    //and we also want to make sure new_savings is positive
    if(m_savings != new_savings && verifyNumber(new_savings) == success)
        {
            savingsPercentage = savingsPercent;
            m_savings = new_savings;
            emit accountModified();
            return success;
        }
    return failure;
}

/* PURPOSE: It will set the monthly spendings, inform a slot of the change and returns success
 * if certain conditions are met. Otherwise returns failure.
 *
 * PARAMETER: spendings is the what the user wants to set the monthly spending to.
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */
bool Account::setSpendings(int spendings)
{
    //we dont want m_spendings and spendings to be the same in case of cyclic connections to avoid infinite looping
    //and we also want to make it sure it's positive
    if(m_spendings != spendings && verifyNumber(spendings) == success)
    {
        m_spendings = spendings;
        emit accountModified();
        return success;
    }

    return failure;
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

//returns the number of categories the user has...fix later
int Account::getNumCategories() const
{
    int numOfCategories = 0;

    for(int i = 0; (unsigned)i < expenditures.size(); i++)
        numOfCategories++;

    return numOfCategories;
}


//returns an object of type Category
Category Account::getACategory(int index) const
{
    return expenditures[index];
}

void Account::addCategory(QString s)
{
    Category temp;
    temp.setCategoryName(s);
    expenditures.push_back(temp);
}

int Account::getTotalSpendingsFromAllCategories() const
{
    int total = 0;
    for(int i = 0; (unsigned)i < expenditures.size();i++)
        total+=expenditures[i].totalTransactions();

    return total;
}

bool Account::setIncome(int i)
{
    if(verifyNumber(i) == success && m_budget != i)
        {
            m_income = i;
            emit accountModified();
            return success;
        }
    return failure;
}

int Account::getIncome()
{
    return m_income;
}
