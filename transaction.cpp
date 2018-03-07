#include "transaction.h"

Transaction::Transaction()
{
transactionAmount = 0.00;
transactionCategory = "";
transactionDate = "";
transactionName = "";
transactionType = "";
}

QString Transaction::getTransactionType()
{
    return transactionType;
}
double Transaction::getTransactionAmount()
{
    return transactionAmount;
}

QString Transaction::getTransactionCategory()
{
    return transactionCategory;
}

QString Transaction::getTransactionDate()
{
    return transactionDate;
}

QString Transaction::getTransactionName()
{
    return transactionName;
}

void Transaction::setTransactionAmount(double number)
{
    transactionAmount = number;
}

void Transaction::setTransactionCategory(QString s)
{
    transactionCategory = s;
}

void Transaction::setTransactionName(QString s)
{
    transactionName = s;
}

void Transaction::setTransactionDate(QString s)
{
    transactionDate = s;
}

void Transaction::setTransactionType(QString s)
{
    transactionType = s;
}
