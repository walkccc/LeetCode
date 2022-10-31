class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    // Store end times of each room
    priority_queue<int, vector<int>, greater<>> minHeap;

    sort(begin(intervals), end(intervals));

    for (const vector<int>& interval : intervals) {
      if (!minHeap.empty() && interval[0] >= minHeap.top())
        minHeap.pop();  // No overlap, we can reuse the same room
      minHeap.push(interval[1]);
    }

    return minHeap.size();
  }
};
