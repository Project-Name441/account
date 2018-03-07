/*
 * The Account class will set the user's inputted data into the appropiate members,
 * keep track of their spendings, and update the diagrams through
 * the use of slots and signals.
 *
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */


#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>
#include <QObject> //allows usage of signals and slots
#include <QString>
using namespace std;

#include "category.h"

class Account : public QObject
{
    Q_OBJECT

protected:
    Account();
private:
    int m_income;                     //monthly income
    int m_budget;                     //stores monthly budget
    int savingsPercentage;            //will be used to calculate monthly savings
    int m_savings;                    //stores monthly savings
    vector<Category> expenditures;    //spendings
    vector<Category> revenue;         //income transactions
    int m_spendings;                  //we need to discuss this
    static bool failure;
    static bool success;
    static Account* _instance;        //used to point to a new or existing account
public:
    static Account* Instance();       //will be used to make sure there is only one account


    bool verifyNumber(int input);     //will make sure inputs are not negative
    void addCategory(QString s);               //could be used later

    //getters
    int getBudget() const;
    int getSavings() const;
    int getSpendings() const;     //might have to change this to something else talk to team

    int getSavingsPercent() const;
    int getNumCategories() const;                    //acts as getNumExpenses from the professors code
    Category getACategory(int index) const;        // acts as getExpense from the code
    double getTotalSpendingsFromAllCategories() const;

    //invokeMenu();                   //could be used later
    //invokeChart();                  //could be used later

public slots:
    //setters
    bool setBudget(int b);
    bool setSpendings(int spendings);  //might not be necessary
    bool setSavings(int savingPercent);

signals:
    //the following functions will send out signals to make changes to diagrams
    //only need one
    void accountModified();
};

#endif // ACCOUNT_H
