#ifndef CATEGORY_H
#define CATEGORY_H
#include <vector>
#include <QString>
using namespace std;

#include "transaction.h"

class Category
{
private:
    QString name;
    vector<Transaction> Transactions;

public:
    Category();
    void addTransaction(QString category, QString name, QString date, double amount, QString type);
    //void editTransaction(); will be done later...ask about how edit will know what transaction to edit
    //void removeTransaction(); will be done later...ask about how remove will know what transaction to edit
    double totalTransactions();           //adds up all of the amounts of every transaction in one spendings object
};

#endif // SPENDINGS_H
