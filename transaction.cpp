#include "transaction.h"


/*
 *Default constructor
 * Author: Jose Quirarte
 * Date: 3/5/18
 * */
Transaction::Transaction()
{
transactionAmount = 0.00;
transactionCategory = "";
transactionDate = "";
transactionName = "";
transactionType = "";
}

QString Transaction::getTransactionType() const
{
    return transactionType;
}
int Transaction::getTransactionAmount() const
{
    return transactionAmount;
}

QString Transaction::getTransactionCategory() const
{
    return transactionCategory;
}

QString Transaction::getTransactionDate() const
{
    return transactionDate;
}

QString Transaction::getTransactionName() const
{
    return transactionName;
}

void Transaction::setTransactionAmount(int number)
{
    transactionAmount = number;
}

void Transaction::setTransactionCategory(QString category)
{
    transactionCategory = s;
}

void Transaction::setTransactionName(QString name)
{
    transactionName = s;
}

void Transaction::setTransactionDate(QString date)
{
    transactionDate = date;
}

void Transaction::setTransactionType(QString type)
{
    transactionType = s;
}
