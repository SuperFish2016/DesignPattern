#include <iostream>

// 目标接口
class ITarget
{
public:
    virtual void haveHDMI() = 0;
};

// 原有接口（接口需要被适配的类）
class IAdaptee
{
public:
    virtual void haveVGA() = 0;
};

class ConcreteAdaptee : public IAdaptee
{
public:
    virtual void haveVGA() {
        std::cout << "I implement a vga output." << std::endl;
    }
};

// 对象适配器，更符合松耦合精神
class Adaptor : public ITarget
{
protected:
    IAdaptee* pAdaptee; // 此处是组合，
public:
    Adaptor(IAdaptee* pA) { pAdaptee = pA; }
    virtual void haveHDMI()
    {
        std::cout << "I am adaptor to convert the adaptee vga -> hdmi." << std::endl;
        // 一系列转换工作
        // pAdaptee->haveVGA();
    }
};

int main()
{
    IAdaptee* ptrAdaptee = new ConcreteAdaptee();
    ITarget*  ptrTarget  = new Adaptor(ptrAdaptee);
    // 最终的目标是：通过一个适配器来在新环境中使用adaptee的原有的接口
    ptrTarget->haveHDMI();
}

