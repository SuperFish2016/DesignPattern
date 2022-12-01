#include <QCoreApplication>

void foo(const char** p)
{

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    foo((const char**)argv);
    return a.exec();
}
