#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "account.h"
using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Account obj;
    obj.setBudget(2500);
    obj.setSavings(50);
    obj.setSpendings(500);
    cout << "budget: " << obj.getBudget() << endl;
    cout << "savings: " << obj.getSavings() << endl;
    cout << "Percent: " << obj.getSavingsPercent() << " % " << endl;
    cout << "spendings: " << obj.getSpendings() << endl;
    return 0;
    //return a.exec();
}
