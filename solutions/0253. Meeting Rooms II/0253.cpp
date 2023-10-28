class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    ranges::sort(intervals);

    // Store end times of each room.
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const vector<int>& interval : intervals) {
      // No overlap, we can reuse the same room.
      if (!minHeap.empty() && interval[0] >= minHeap.top())
        minHeap.pop();
      minHeap.push(interval[1]);
    }

    return minHeap.size();
  }
};
