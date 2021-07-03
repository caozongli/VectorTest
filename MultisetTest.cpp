#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>
#include "VectorTest.cpp"
using namespace std;

namespace jj06
{
void test_multiset(long& value)
{
    cout << "\ntest_multiset()............\n";
multiset<string> c;
char buf[10];

clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand());
            c.insert(string(buf));
        }
        catch(exception& p)
        {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds:" << (clock()-timeStart) << endl;
    cout << "multiset.size()=" << c.size() << endl;
    cout << "multiset.max_size()=" << c.max_size() << endl;

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
 auto pTtem = c.find(target);
    cout << "c.find, milli-seconds:" << clock()-timeStart << endl;
    if(pItem!=c.end())
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
}
}

int main()
{
    long p = 1000000;
    jj06::test_multiset(p);
    system("pause");
    return 0;
}