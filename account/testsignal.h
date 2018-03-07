#ifndef TESTSIGNAL_H
#define TESTSIGNAL_H

#include <QObject>

class TestSignal: public QObject
{
    Q_OBJECT
private:
    int number;
    
public:
    TestSignal();
    int getNum();
    
public slots:
    void setNum(int n);

};

#endif // TESTSIGNAL_H
