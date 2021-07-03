#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct LinkedPointer{
    void* ptr;
    LinkedPointer* Next;
};

class A
{
    // virtual void test();
    // virtual void test2();
    // A():age(1), sex(true), bchild(false){}
    // void SetAge(int age) { this->age = age; }
    // static void* operator new(size_t size)
    // {
    //     return malloc(size);
    // }

    // static void operator delete(void *p, size_t size)
    // {
    //     free(p);
    // }

private:
    int age;
    bool bchild;
    bool sex;
public:
    struct Obj{struct Obj* Next;};
    static Obj* Header;
    A():age(0), sex(true), bchild(false)
    {

    }
    void* operator new(size_t size);
    void operator delete(void* p, size_t size);
    static LinkedPointer *linkedPtr;
    static bool IsValidPtr(void* ptr)
    {
        if(linkedPtr->ptr<=ptr && ptr<(((char*)linkedPtr->ptr)+16))
        {
            return true;
        }
        return false;
    }
    static int mallocCount;
};
LinkedPointer* A::linkedPtr = nullptr;
int A::mallocCount = 0;

A::Obj* A::Header = nullptr;

static void* A::operator new(size_t size)
{
    if(nullptr == Header)
    {
        if(mallocCount>=1)
        {
            return ::operator new(size);
        }
        size_t total = size * 2;
        void * temp = malloc(total);
        if(nullptr == temp) 
        {
            return nullptr;
        }
        mallocCount++;
        Header = (Obj*) temp;
        Obj* tempItem = Header;
        for(int i=1; i<2; i++)
        {
            void* ptr = (char*)tempItem + size;
            tempItem->Next = (Obj*)ptr;
            tempItem = tempItem->Next;
        }
        tempItem->Next = nullptr;
        LinkedPointer* linkPtr = new LinkedPointer();
        linkPtr->ptr = temp;
        if(nullptr == linkedPtr)
        {
            linkedPtr = linkPtr;
        }
        else
        {
            linkedPtr->Next = linkedPtr;
        }
    }
    Obj* Ret = Header;
    Header = Header->Next;
    return Ret;
}

static void A::operator delete(void* p, size_t size)
{
    if(!IsValidPtr(p))
    {
        ::operator delete(p);
        return;
    }
    if(nullptr==Header)
    {
        Header = (Obj*)p;
    }
    ((Obj*)p)->Next = Header;
    Header->Next = (Obj*)p;
}

struct ff{struct ff *next;};

int main()
{
    A* a1 = new A();
    A* a2 = new A();
    A* a3 = new A();

    delete a1;
    delete a2;
    delete a3;

    cout << sizeof(ff) << endl;
    system("pause");
    return 0;
}
