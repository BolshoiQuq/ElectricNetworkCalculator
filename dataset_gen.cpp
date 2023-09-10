#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main() {
    int n=0, k=0;
    double U[100], I[100];
    char c;
    fstream f;
    string s, in="nout_graph.txt", out="nout_dataset.txt";

    cout << "Number of lines\n";
    cin >> n;

    cout << "Required line\n";
    cin >> k;

    cout << "Choose input file\n";
    cin >> in;

    cout << "Choose output file\n";
    cin >> out;

    --k;

    f.open(in, ios::in);
    for (int i=0; i<100; ++i)
    {
        for (int j=0; j<k; ++j)
            getline(f, s);
        f >> c;
        if (c=='[' or c==']' or c=='{' or c=='}')
        {
            U[i]=0;
            I[i]=0;
        } else
        if (c=='R' or c=='C' or c=='L')
        {
            f >> c;
            f >> U[i];
            f >> c;
            f >> I[i];
            f >> c;
        }
        for (int j=0; j<n-k; ++j)
            getline(f, s);
    }
    f.close();

    f.open(out, ios::out);
    for (int i=0; i<100; ++i)
    {
        f << "[" << i << ";" << U[i] << "]\n";
    }
    f << "------------------------\n";
    for (int i=0; i<100; ++i)
    {
        f << "[" << i << ";" << I[i] << "]\n";
    }
    f.close();

    return 0;
}
