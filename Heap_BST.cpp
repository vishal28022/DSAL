#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> findMinMaxMarks(const vector<int> &marks)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    priority_queue<int> maxHeap;

    for (int mark : marks)
    {
        minHeap.push(mark);
        maxHeap.push(mark);
    }

    int minMark = minHeap.top();
    int maxMark = maxHeap.top();

    return make_pair(maxMark, minMark);
}

int main()
{
    vector<int> marks = {85, 92, 78, 89, 95, 81, 87, 90, 84};

    pair<int, int> result = findMinMaxMarks(marks);

    cout << "Maximum marks obtained: " << result.first << endl;
    cout << "Minimum marks obtained: " << result.second << endl;

    return 0;
}