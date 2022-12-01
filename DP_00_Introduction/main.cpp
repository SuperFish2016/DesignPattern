#include <QCoreApplication>
#include "NL_VERSION.hpp"
#include "DP_VERSION.hpp"

// 设计模式需要考虑，代码未来变化的情况：
// 新增一个类，经过设计模式的代码会最小的成本来改变代码，尽可能通过新增而不是改变原代码。

// 两种方案对比：需求变化时，如要增加Circle
//  方法一，需要增加一个Circle类，要对UI的多处进行更改
//  方法二，需要增加要给继承Shape的类,override 父类的虚函数 Draw, UI函数改动的就比较少

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NLWindow w;
    std::cout << "--------------------- Normal Version --------------------------" << std::endl;
    w.addShape();
    w.paintShape();

    std::cout << "------------------------ DP Version -------------------------" << std::endl;
    DP::DPWindow w1;
    w1.addShape();
    w1.paintShape();
    return a.exec();
}


