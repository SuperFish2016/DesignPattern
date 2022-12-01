#include "singleton.h"

#include <QCoreApplication>

std::atomic<Singleton*> Singleton::m_instance_v4;
std::mutex Singleton::m_mutex;
//版本1: 线程非安全版本
Singleton* Singleton::getInstance_v1()
{
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

//版本2: 线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance_v2()
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> locker(mutex);
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}
//版本3: 双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance_v3()
{
    if(m_instance==nullptr){
        static std::mutex mutex;
        std::lock_guard<std::mutex> locker(mutex);
        if (m_instance == nullptr) {
            // m_instance = new SingleTon();是用来创建对象。这一行代码可以分解为如下三行伪代码：
            // memory = allocate();     //1.分配对象内存空间
            // ctorInstance(memory);    //2.初始化对象
            // m_instance = memory;     //3.设置instance指向刚分配的内存地址
            // 2和3不存在数据依赖性，所以可能会被重排序
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

//版本4: C++ 11版本之后的跨平台实现 (volatile)
// members for version 4

Singleton* Singleton::getInstance_v4()
{
    Singleton* tmp = m_instance_v4.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance_v4.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            m_instance_v4.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}




Singleton* Singleton::m_instance = nullptr;
