#include <QString>
#include "category.h"
Category::Category()
{
name = "";
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

//gets the total amount from all transactions
double Category::totalTransactions() const
{
    double total = 0;
    for(int i = 0; (unsigned)i < Transactions.size(); i++)
        total += Transactions[i].getTransactionAmount();

    return total;
}

void Category::setCategoryName(QString s)
{
    name = s;
}

QString Category::getCategoryName() const
{
    return name;
}
