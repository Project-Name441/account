/*
 * The Account class will set the user's inputted data into the appropiate members,
 * keep track of their tabs, and update the diagrams through
 * the use of slots and signals.
 *
 * Author: Jose Quirarte
 * Date: 2/24/18
 * */


#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject> //allows usage of signals and slots

class Account : public QObject
{
    Q_OBJECT

private:

    int m_budget;                     //stores monthly budget
    int savingsPercentage;            //will be used to calculate monthly savings
    int m_savings;                    //stores monthly savings
    //vector<tabs> tabs;              //could be used later
    int m_spendings;                  //stores monthly spendings
    static bool failure;
    static bool success;

public:

    Account();                        //default constructor

    bool verifyNumber(int input);     //will make sure inputs are not negative
    //void addTab(...);               //could be used later

    //getters
    int getBudget() const;
    int getSavings() const;
    int getSpendings() const;
    int getSavingsPercent() const;

    //invokeMenu();                   //could be used later
    //invokeChart();                  //could be used later

public slots:
    //setters
    bool setBudget(int b);
    bool setSpendings(int spendings);
    bool setSavings(int savingPercent);

signals:
    //the following functions will send out signals to make changes to diagrams
    void budgetChanged(int b);
    void spendingsChanged(int spendings);
    void savingsChanged(int savings);

};

#endif // ACCOUNT_H
