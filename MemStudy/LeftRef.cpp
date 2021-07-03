#include <iostream>
using namespace std;

int main()
{
    int leftValue = 1;
    int &leftRef = leftValue;
    const int &leftRef2 = 1;
    int && rightRef = 1;
    int&& rightRef2 = std::move(leftValue);

    int& leftRef3 = std::forward<int&>(1);
    int&& rightRef6 = std::forward<int>(leftValue);
    int&& rightRef7 = std::forward<int&&>(leftValue);

    cout << sizeof(A) << endl;
    return 0;
}