#include <karty.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    auto talia = utworzTalie();
    if (talia.size() == 52)
    {
        cout << "Test talii przebiegl poprawnie! (52 karty)" << endl;
    }
    else
    {
        cout << "Test talii przebiegl niepoprawnie!";
    }
    
    return 0;
}
