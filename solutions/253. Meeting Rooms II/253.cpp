class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    // Store the end times of each room.
    priority_queue<int, vector<int>, greater<>> minHeap;

    ranges::sort(intervals);

    for (const vector<int>& interval : intervals) {
      // There's no overlap, so we can reuse the same room.
      if (!minHeap.empty() && interval[0] >= minHeap.top())
        minHeap.pop();
      minHeap.push(interval[1]);
    }

    return minHeap.size();
  }
};
