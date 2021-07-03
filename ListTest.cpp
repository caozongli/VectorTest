#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <list>
#include "VectorTest.cpp"
using namespace std;

namespace jj03
{
void test_list(long& value)
{
    cout << "\ntest_list()............\n";
list<string> c;
char buf[10];

clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(exception& p)
        {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds:" << (clock()-timeStart) << endl;
    cout << "list.size()=" << c.size() << endl;
    cout << "list.max_size()=" << c.max_size() << endl;
    cout << "list.front()=" << c.front() << endl;
    cout << "list.back()=" << c.back() << endl;


string target = get_a_target_string();
    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(), milli-seconds:" << clock()-timeStart << endl;

    if(pItem!=c.end())
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
    timeStart = clock();
    c.sort();
    cout << "c.sort, milli-seconds:" << clock()-timeStart << endl;

}
}

int main()
{
    long p = 1000000;
    jj03::test_list(p);
    system("pause");
    return 0;
}