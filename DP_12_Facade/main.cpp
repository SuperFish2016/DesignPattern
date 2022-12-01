#include <QCoreApplication>
#include <iostream>
#include "singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Singleton* v1 = Singleton::getInstance_v1();
    Singleton* v2 = Singleton::getInstance_v2();
    Singleton* v3 = Singleton::getInstance_v3();
    Singleton* v4 = Singleton::getInstance_v4();
    std::cout << v1 << " " << v2 << " " << v3 << " " << v4 << std::endl;
    v1->print();
    return 0;
}
