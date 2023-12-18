#include <iostream>
// #include <windows.h>
#include <unistd.h>

using namespace std;
 
int main()
{
    int i, j, n = 0, c = 0;
    while(n != 3) 
    {
        n += 1;
        if (n == 3) 
        {
            // system("color 1");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < 30 - 2 * c; j++)
                    cout << ' ';
                for(j = 0; j < n - i; j++)
                    cout << ' ';
                for(j = 0; j < 2 * (i + 1) - 1; j++)
                    cout << '*';
                for(j = 0; j < 2 * (n - i); j++)
                    cout << ' ';
                for(j = 0; j < 2 * (1 + i) - 1; j++)
                    cout << '*';
                cout << '\n';
            }
            int x = (2 * (n + 1) - 1) * 2;
            for(i = 0; i < x / 2; i++)
            {
                for(j = 0; j < 30 - 2 * c; j++)
                    cout << ' ';
                for(j = 0; j < i; j++)
                    cout << ' ';
                for(j = 0; j < x - 2 * i; j++)
                    cout << '*';
                cout << '\n';
            }
            cout << '\n' << '\n' << '\n';
            c++;
            usleep(1000 * 1000);  // 1000毫秒的延遲
            if(n > 10) n=-1;
        }
    }
    return 0;
}