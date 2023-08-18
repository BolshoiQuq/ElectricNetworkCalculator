#include <iostream>
#include <cmath>

using namespace std;

void colorize(int R)
{
    int L=floor(log10(R))+1-2;
    R/=floor(pow(10, L));
    cout << R << " " << L;
}

int main()
{
    int R;
    cin >> R;
    colorize(R);
}
