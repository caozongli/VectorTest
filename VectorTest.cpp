#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "ArrayTest.cpp"
using namespace std;

namespace jj02
{
void test_vector(long& value)
{
    cout << "\ntest_vector()........\n";
vector<string> c;
char buf[10];

clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(exception& p){
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds:" << clock()-timeStart << endl;
    cout << "vector.size()=" << c.size() << endl;
    cout << "vector.front()=" << c.front() << endl;
    cout << "vector.back()=" << c.back() << endl;
    cout << "vector.data()=" << c.data() << endl;
    cout << "vector.capacity()=" << c.capacity() << endl;

string target = get_a_target_string();
    {
    timeStart = clock();
auto pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(), milli-seconds:" << clock()-timeStart << endl;

    if(pItem!=c.end())
        cout << "found," << *pItem << endl;
    else
        cout << "not found!" << endl;
    }

    {
    timeStart = clock();
    sort(c.begin(), c.end());
string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStrings);
    cout << "sort()+bsearch(), milli-seconds:" << clock()-timeStart << endl;

    if(pItem!=NULL)
        cout << "found, "<< *pItem << endl;
    else
        cout << "not found!" << endl;
    }
}

}

// int main()
// {
//    long value = 1000000;
//     jj02::test_vector(value);
//     system("pause");
//     return 0;
// }
