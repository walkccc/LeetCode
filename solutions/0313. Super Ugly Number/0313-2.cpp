struct UglyNum {
  int prime;
  int index;   // point to the next index of uglyNums
  long value;  // prime * uglyNums[index]
  UglyNum(int prime, int index, long value)
      : prime(prime), index(index), value(value) {}
};

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    auto compare = [&](const UglyNum& a, const UglyNum& b) {
      return a.value > b.value;
    };
    priority_queue<UglyNum, vector<UglyNum>, decltype(compare)> minHeap(
        compare);
    vector<int> uglyNums{1};

    for (const int prime : primes)
      minHeap.emplace(prime, 1, prime * uglyNums[0]);

    while (uglyNums.size() < n) {
      uglyNums.push_back(minHeap.top().value);
      while (minHeap.top().value == uglyNums.back()) {
        const auto [prime, index, _] = minHeap.top();
        minHeap.pop();
        minHeap.emplace(prime, index + 1,
                        prime * static_cast<long>(uglyNums[index]));
      }
    }

    return uglyNums.back();
  }
};
