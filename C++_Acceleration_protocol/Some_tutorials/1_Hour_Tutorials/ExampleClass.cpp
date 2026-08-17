#include <iosream>
#include <string>
using namespace std;

class GoodClass
{
    string _str;

public:
    GoodClass(string str) : _str(str) // Good uses Initialization Lists
    {

    }
};

class BadClass
{
    string _str;
public:
    BadClass(string str)
    {
        _str = str; // No Initialization, simply assignment
    }
};

int main() 
// Both will work, one is simply better then the othe,
// and is more correct in C++

{
    BadClass cls("Whoa");
    return 0;
}