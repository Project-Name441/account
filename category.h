/*Category will have a name specified by the user and will contain a vector
 * full of transactions that belong to a specific category
 * change to what Team wants
 *
 * Author: Jose Quirarte
 * Date: 3/5/18
 *
 * */


#ifndef CATEGORY_H
#define CATEGORY_H
#include <vector>
#include <QString>
using namespace std;

#include "transaction.h"

class Category
{
private:
    QString name;                     //name of category
    vector<Transaction> Transactions;

public:
    Category();
    void setCategoryName(QString s);
    QString getCategoryName() const;
    void addTransaction(QString category, QString name, QString date, double amount, QString type);
    //void editTransaction(int index);  talk to group about how to implement this function
    void removeTransaction(int index);     //removes a transaction from the category
    int totalTransactions() const;           //adds up all of the amounts of every transaction in one category
    int getTotalNumOfTransactions()const;    // returns the number of transactions within a category
};

#endif // CATEGORY_H
