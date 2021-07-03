#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <map>
#include "ArrayTest.cpp"
using namespace std;

namespace jj07
{
void test_multimap(long& value)
{
    cout << "\ntest_multiset()............\n";
multimap<long, string> c;
char buf[10];

clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand());
            c.insert(pair<long, string>(i, buf));
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

long target = get_a_target_long();
    timeStart = clock();
auto pItem = c.find(target);
    cout << "c.find(), milli-seconds:" << clock()-timeStart << endl;

    if(pItem!=c.end())
    {
        cout << "found, " << (*pItem).second << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
//     timeStart = clock();
//  auto pTtem = c.find(target);
//     cout << "c.find, milli-seconds:" << clock()-timeStart << endl;
//     if(pItem!=c.end())
//     {
//         cout << "found, " << *pItem << endl;
//     }
//     else
//     {
//         cout << "not found!" << endl;
//     }
}
}

int main()
{
    long p = 1000000;
    jj07::test_multimap(p);
    system("pause");
    return 0;
}