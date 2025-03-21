class Solution {
 public:
  // Similar to 253. Meeting Rooms II
  int minGroups(vector<vector<int>>& intervals) {
    // Stores `right`s.
    priority_queue<int, vector<int>, greater<>> minHeap;

    ranges::sort(intervals);

    for (const vector<int>& interval : intervals) {
      // There's no overlap, so we can reuse the same group.
      if (!minHeap.empty() && interval[0] > minHeap.top())
        minHeap.pop();
      minHeap.push(interval[1]);
    }

    return minHeap.size();
  }
};
