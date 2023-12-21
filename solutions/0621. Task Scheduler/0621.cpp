class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    if (n == 0)
      return tasks.size();

    vector<int> count(26);

    for (const char task : tasks)
      ++count[task - 'A'];

    const int maxFreq = ranges::max(count);
    // Put the most frequent task in the slot first.
    const int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
    // Get the number of tasks with the same frequency as `maxFreq`, we'll
    // append them after the `maxFreqTaskOccupy`.
    const int nMaxFreq = ranges::count(count, maxFreq);
    // max(
    //   the most frequent task is frequent enough to force some idle slots,
    //   the most frequent task is not frequent enough to force idle slots
    // )
    return max(maxFreqTaskOccupy + nMaxFreq, static_cast<int>(tasks.size()));
  }
};
