#include <iostream>
#include <vector>
using namespace std;

string message = "strongest";
string word = "one";
vector<vector<int>> vect(word.size() + 1, vector<int>(message.size() + 1));

void create(unsigned int n, unsigned int m)
{
    if (n == 0 || m == 0)
    {
        vect[n][m] = 0;
    }
    else if (message[m - 1] == word[n - 1])
    {
        vect[n][m] = vect[n - 1][m - 1] + 1;
    }
    else
    {
        vect[n][m] = max(vect[n - 1][m], vect[n][m - 1]);
    }
    if (m < message.size())
    {
        create(n, m + 1);
    }
    else
    {
        m = 0;
        if (n < word.size())
        {
            create(n + 1, m);
        }
    }
}

void printmatrix()
{
    for (unsigned int i = 0; i < word.size() + 1; i++)
    {
        for (unsigned int j = 0; j < message.size() + 1; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

void commonlength()
{
    cout << "Length of common String : " << vect[word.size()][message.size()] << endl;
}

void printstring(unsigned int n, unsigned int m)
{
    if (vect[n][m] == 0)
    {
        cout << "";
    }
    else if (vect[n][m] == vect[n - 1][m - 1] + 1)
    {
        printstring(n - 1, m - 1);
        cout << word[n - 1];
    }
    else if (vect[n][m] == vect[n - 1][m])
    {
        printstring(n - 1, m);
    }
    else if (vect[n][m] == vect[n][m - 1])
    {
        printstring(n, m - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    create(0, 0);
    cout << "Matrix : " << endl;
    printmatrix();
    commonlength();
    cout << "Common String : ";
    printstring(word.size(), message.size());
    return 0;
}
