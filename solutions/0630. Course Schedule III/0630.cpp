class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    int time = 0;
    sort(begin(courses), end(courses),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });
    priority_queue<int> maxHeap;

    for (const auto& c : courses) {
      const int duration = c[0];
      const int lastDay = c[1];
      maxHeap.push(duration);
      time += c[0];
      // if current course could not be taken, check if it's able to swap with a
      // previously taken course with larger duration, to increase the time
      // available to take upcoming courses
      if (time > lastDay)
        time -= maxHeap.top(), maxHeap.pop();
    }

    return maxHeap.size();
  }
};
