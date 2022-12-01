#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>
#include <iostream>
#include <atomic>

// 关于静态成员函数需要知道的几点：
// 1，static 成员函数不能使用non-static成员变量
// 2，static 成员函数只能访问static成员变量

class Singleton{
private:
    Singleton() = default;
    Singleton(const Singleton& other) = delete;
public:
    void print()
    {
        std::cout << "I am a singleton instance." << std::endl;
    }
public:

    //版本1: 线程非安全版本
    static Singleton* getInstance_v1();

    //版本2: 线程安全版本，但锁的代价过高
    static Singleton* getInstance_v2();

    //版本3: 双检查锁，但由于内存读写reorder不安全
    static Singleton* getInstance_v3();

    //版本4: C++ 11版本之后的跨平台实现 (volatile)
    static Singleton* getInstance_v4();

private:
    static Singleton* m_instance;

    // static 成员变量在使用之前必须在cpp中进行一个初始化操作。
    // member for getInstance_v4
    static std::atomic<Singleton*> m_instance_v4;
    // 不考虑该单例，如果使用静态的mutex，那么可以肯定的是所有该类对象都能访问这个mutex。
    // 那么多线程的优势就不存在了 ?
    static std::mutex m_mutex;
};

#endif // SINGLETON_H
