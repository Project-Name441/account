/*Transaction will hold the information of a user's inputted transaction
 * 
 * Author: Jose Quirarte
 * Date: 3/5/18
 * */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>

class Transaction
{
private: 
   QString transactionCategory; //the category the transaction belongs to e.g. entertainment
   QString transactionName;     //the name of the transaction e.g. beer
   QString transactionDate;
   QString transactionType;     // whether it's an income or expense related transaction
   int transactionAmount;
   
public:
    Transaction();
    //setters
    void setTransactionCategory(QString s);
    void setTransactionName(QString s);
    void setTransactionDate(QString s);
    void setTransactionAmount(int number);
    void setTransactionType(QString s);
    
    //getters
    QString getTransactionName() const;
    QString getTransactionCategory() const;
    QString getTransactionDate() const;
    int getTransactionAmount() const;
    QString getTransactionType() const;
};

#endif // TRANSACTION_H
