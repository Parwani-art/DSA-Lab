#pragma once
using namespace std;
#include <queue>

// reverses the first k elements of the queue q.
// If k <= 0 or k > q.size(), the queue is unchanged.
void reverseFirstK(queue<int>& q, int k);