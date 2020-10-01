class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    if (n == 0) return tasks.size();

    vector<int> count(26);

    for (const char task : tasks)
      ++count[task - 'A'];

    const int maxCount = *max_element(begin(count), end(count));
    // put tasks w/ maxCount in slot first
    const int maxTaskOccupy = (maxCount - 1) * (n + 1);
    // get # of tasks with same count as maxCount,
    // we'll append them after maxTaskOccupy
    const int sameCountAsMaxCount = count_if(
        begin(count), end(count), [maxCount](int c) { return c == maxCount; });

    return max(maxTaskOccupy + sameCountAsMaxCount, (int)tasks.size());
  }
};