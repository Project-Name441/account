#include <QString>
#include "category.h"
Category::Category()
{

}

void Category::addTransaction(QString category, QString name, QString date, double amount, QString type)
{
    Transaction temp;
    temp.setTransactionCategory(category);
    temp.setTransactionDate(date);
    temp.setTransactionName(name);
    temp.setTransactionAmount(amount);
    temp.setTransactionType(type);
    Transactions.push_back(temp);
}

double Category::totalTransactions()
{
    double total = 0;
    for(int i = 0; (unsigned)i < Transactions.size(); i++)
        total += Transactions[i].getTransactionAmount();

    return total;
}
