class StatisticsTracker {
 public:
  void addNumber(int number) {
    q.push(number);
    ++count[number];
    sortedList.insert(number);
    modeMaxHeap.emplace(count[number], -number);
    sum += number;
  }

  void removeFirstAddedNumber() {
    const int number = q.front();
    q.pop();
    if (--count[number])
      count.erase(number);
    sortedList.erase(sortedList.find(number));
    // Note: No need to update the heap now; we'll clean up stale entries when
    // getting the mode.
    sum -= number;
  }

  int getMean() {
    return sum / q.size();
  }

  int getMedian() {
    auto it = sortedList.begin();
    advance(it, sortedList.size() / 2);
    return *it;
  }

  int getMode() {
    // Removes stale entries from the top of the heap.
    while (!modeMaxHeap.empty()) {
      const int frequency = modeMaxHeap.top().first;
      const int number = -modeMaxHeap.top().second;
      if (count.contains(number) && count[number] == frequency)
        return number;
      modeMaxHeap.pop();
    }
    throw;
  }

 private:
  queue<int> q;
  unordered_map<int, int> count;
  multiset<int> sortedList;
  priority_queue<pair<int, int>> modeMaxHeap;  // (frequency, number)
  long sum = 0;
};
