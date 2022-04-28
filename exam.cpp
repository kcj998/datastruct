#include <iostream>
class A
{
public:
    A(int i)
    {
        a=i;
        std::cout<<"Constructor called.A\n";}
        ~A()
        {std::cout<<"Destructor called.A\n";}
        void Print()
        {std::cout<<a<<std::endl;}
private:
    int a;
};
class B
{
public:
    B(int i)
    {
        b=i; std::cout<<"Constructor called.B\n";
    }
    ~B()
    {
        std::cout<<"Destructor called.B\n";
    }
    void Print()
    { std::cout<<b<<std::endl;}
private:
    int b;
};
class C
{
public:
    C(int i)
    {
        std::cout<<"Constructor called.C\n";
    }
    ~C()
    {
        std::cout<<"Destructor called.C\n";
    }
    int Getc()
    {
        return c;
    }
private:
    int c;
};
class D: public B , public A
{
public:
    D(int i, int j, int k, int I):B(i),A(j),c(I)
    {
        d=k;std::cout<<"Constructor called.D\n";
    }
    ~D()
    {
        std::cout<<"Destructor called.D\n";
    }
    void Print()
    {
        A::Print();
        B::Print();
        std::cout<<d<<','<<c.Getc()<<std::endl;
    }
private:
    int d;
    C c;
};
int main()
{
    D d(5,6,7,8);
    d.Print();
    B b(2);
    b.Print();
    b = d;
    b.Print();
    return 0;
};
