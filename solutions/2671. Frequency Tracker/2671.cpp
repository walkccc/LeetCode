class FrequencyTracker {
 public:
  void add(int number) {
    if (count[number] > 0)
      --freqCount[count[number]];
    ++count[number];
    ++freqCount[count[number]];
  }

  void deleteOne(int number) {
    if (count[number] == 0)
      return;
    --freqCount[count[number]];
    --count[number];
    ++freqCount[count[number]];
  }

  bool hasFrequency(int frequency) {
    return freqCount[frequency] > 0;
  }

 private:
  unordered_map<int, int> count;
  unordered_map<int, int> freqCount;
};
