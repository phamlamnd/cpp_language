#include <iostream>

using namespace std;

namespace first 
{
    void print()
    {
        cout << "first namespace" << endl;
    }
}

namespace second 
{
    void print()
    {
        cout << "second namespace" << endl;
    }
}

void print()
{
    cout << "over namespace" << endl;
}

using namespace first;
using namespace second;

int main(int argc, char const *argv[])
{
    first::print();

    return 0;
}
