#include "QueueKReverse.h"
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k)
{
    int n = (int)q.size();
    if (k <= 0 || k > n) return;

    stack<int> st;

    // 1) Remove first k elements from queue and push to stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // 2) Pop from stack and enqueue back (this reverses first k)
    while (!st.empty()) 
    {
        q.push(st.top());
        st.pop();
    }

    // 3) Move the remaining (n-k) elements to the back to keep their order
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}