/*
拷贝构造函数
深拷贝
浅拷贝

Singleton 单例设计模式

*/


// (guard)防卫式声明
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <cmath>

// forward declarations 前置声明
class ostream;
class complex;

// class declarations 类声明
class complex  // class head
{   // class body
public:
    // 构造函数constructor (ctor)
    // :可以有多个-->overload(重载)
    // 没有返回值
    complex (double r = 0, double i = 0) //可以选择输入2,1,0个变量
        : re (r), im (i)  //initialization list(初值列, 初始列)
    { } // 大括号不写任何东西
    // 这个构造函数不能重载成如下:
    // complex () : re(0), im(0) { }
    // 因为函数有默认值


    complex& operator += (const complex&); 
    // 参数传递 pass by reference : complex&       传递引用 相当于传指针
    //         pass by reference : const complex& 传参且不让改变内容
    //         pass by value : double r             传值
    // 好处 速度快 指针4字节

    // 返回值传递 return by reference 


    // 函数类内定义默认inline
    // const 修饰 不会改变数据内容的函数
    // 不加const :
    // const const complex c1(2,1);
    // cout << c1.real();
    // 会报错
    double real () const { return re; }
    // 可以对real重载例如:
    // void real(double r) { re = r; } 不能加const
    // 编译器会给两个函数取不同的名字

    double imag () const { return im; }

    // 成员函数是该类其他对象的友元函数
    // 相同 class 的各個 objects 互為 friends (友元)
    int func(const complex& param)
    { return param.re + param.im; }

protected:

private:
    double re, im;

    // 友元 打破封装
    friend complex& __doapl (complex*, const complex&);
};


inline complex&
// 第一个参数会改动 第二个不会改动(要加const)
// do assignment plus
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl(this, r);
}

#endif
