#include <iostream>
#include <queue>
#include "QueueKReverse.h"
using namespace std;

int main()
{
    int n, k;
    cout<<"Input: "<<endl;
    cin >> n >> k;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Output: " << endl;

    reverseFirstK(q, k);

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
        if (!q.empty())
        {
            cout << " ";

        }
    }
    cout << endl;

    return 0;
}