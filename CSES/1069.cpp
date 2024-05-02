// Repetitions
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string msg;

    int ret = 1, atu = 1;

    cin >> msg;

    for (int i = 1; i < (int) msg.length(); i++)
    {
        if (msg[i] == msg[i-1])
        {
            atu++;
            if (atu > ret)
                ret = atu;
        }
        else
            atu = 1;
    }

    cout << ret << endl;
    
    return 0;
}