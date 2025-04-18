class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    int time = 0;
    priority_queue<int> maxHeap;

    ranges::sort(courses, ranges::less{},
                 [](const vector<int>& course) { return course[1]; });

    for (const vector<int>& course : courses) {
      const int duration = course[0];
      const int lastDay = course[1];
      maxHeap.push(duration);
      time += duration;
      // If the current course cannot be taken, check if it can be swapped with
      // a previously taken course that has a larger duration to increase the
      // time available to take upcoming courses.
      if (time > lastDay)
        time -= maxHeap.top(), maxHeap.pop();
    }

    return maxHeap.size();
  }
};
