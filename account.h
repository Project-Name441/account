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
    //vector<Category> revenue;         //income transactions

    static bool failure;
    static bool success;
    static Account* _instance;        //used to point to a new or existing account
public:
    static Account* Instance();       //will be used to make sure there is only one account


    bool verifyNumber(int input);     //will make sure inputs are not negative
    void addCategory(QString s);      //adds a category to one of the vectors

    //getters
    int getBudget() const;
    int getSavings() const;

    int getSavingsPercent() const;
    int getNumCategories() const;                    //will return the number of categories in expenditures
    Category getACategory(int index) const;          // will return a category object specified by the index
    int getTotalSpendingsFromAllCategories() const;
    int getIncome();
    vector<Category> getExpenditures();              //returns the expenditures vector

    //invokeMenu();                   //could be used later
    //invokeChart();                  //could be used later

public slots:
    //setters
    bool setBudget(int b);
    bool setSavings(int savingPercent);
    bool setIncome(int i);

signals:
    //the following function will send out signal to inform diagrams to update themselves
    void accountModified();
};

#endif // ACCOUNT_H
