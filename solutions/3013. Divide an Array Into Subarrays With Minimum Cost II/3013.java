class Multiset {
  public void add(int num) {
    map.merge(num, 1, Integer::sum);
    ++sz;
  }

  public void remove(int num) {
    map.merge(num, -1, Integer::sum);
    if (map.get(num) == 0)
      map.remove(num);
    --sz;
  }

  public int min() {
    return map.firstEntry().getKey();
  }

  public int max() {
    return map.lastEntry().getKey();
  }

  public int size() {
    return sz;
  }

  public boolean contains(int num) {
    return map.containsKey(num);
  }

  private TreeMap<Integer, Integer> map = new TreeMap<>();
  private int sz = 0;
}

class Solution {
  public long minimumCost(int[] nums, int k, int dist) {
    // Equivalently, the problem is to find nums[0] + the minimum sum of the top
    // k - 1 numbers in nums[i..i + dist], where i > 0 and i + dist < n.
    long windowSum = 0;
    Multiset selected = new Multiset();
    Multiset candidates = new Multiset();

    for (int i = 1; i <= dist + 1; ++i) {
      windowSum += nums[i];
      selected.add(nums[i]);
    }

    windowSum = balance(windowSum, selected, candidates, k);
    long minWindowSum = windowSum;

    for (int i = dist + 2; i < nums.length; ++i) {
      final int outOfScope = nums[i - dist - 1];
      if (selected.contains(outOfScope)) {
        windowSum -= outOfScope;
        selected.remove(outOfScope);
      } else {
        candidates.remove(outOfScope);
      }
      if (nums[i] < selected.max()) { // nums[i] is a better number.
        windowSum += nums[i];
        selected.add(nums[i]);
      } else {
        candidates.add(nums[i]);
      }
      windowSum = balance(windowSum, selected, candidates, k);
      minWindowSum = Math.min(minWindowSum, windowSum);
    }

    return nums[0] + minWindowSum;
  }

  // Returns the updated `windowSum` by balancing the multiset `selected` to
  // keep the top k - 1 numbers.
  private long balance(long windowSum, Multiset selected, Multiset candidates, int k) {
    while (selected.size() < k - 1) {
      final int minCandidate = candidates.min();
      windowSum += minCandidate;
      selected.add(minCandidate);
      candidates.remove(minCandidate);
    }
    while (selected.size() > k - 1) {
      final int maxSelected = selected.max();
      windowSum -= maxSelected;
      selected.remove(maxSelected);
      candidates.add(maxSelected);
    }
    return windowSum;
  }
}
