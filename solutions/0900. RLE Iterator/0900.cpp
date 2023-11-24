class RLEIterator {
 public:
  RLEIterator(vector<int>& encoding) : encoding(encoding) {}

  int next(int n) {
    while (index < encoding.size() && encoding[index] < n) {
      n -= encoding[index];
      index += 2;
    }

    if (index == encoding.size())
      return -1;

    encoding[index] -= n;
    return encoding[index + 1];
  }

 private:
  int index = 0;
  vector<int> encoding;
};
