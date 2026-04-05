class SumMultiset {
  public TreeMap<Integer, Integer> nums = new TreeMap<>();
  public long sum = 0;
  public int size = 0;

  public void insert(int val) {
    nums.merge(val, 1, Integer::sum);
    sum += val;
    ++size;
  }

  public void erase(int val) {
    nums.merge(val, -1, Integer::sum);
    if (nums.get(val) == 0)
      nums.remove(val);
    sum -= val;
    --size;
  }
}

class MedianTracker {
  public MedianTracker(int k) {
    this.k = k;
  }

  public void add(int val) {
    below.insert(val);
    balance();
  }

  public void remove(int val) {
    if (below.nums.containsKey(val))
      below.erase(val);
    else
      above.erase(val);
  }

  public long getCost() {
    return above.sum - below.sum - (k % 2 == 1 ? above.nums.firstKey() : 0L);
  }

  private SumMultiset below = new SumMultiset();
  private SumMultiset above = new SumMultiset();
  private int k;

  private void balance() {
    // Move excessive numbers from `below` to `above`.
    while (below.size > k / 2) {
      final int mx = below.nums.lastKey();
      below.erase(mx);
      above.insert(mx);
    }

    // Balance `below` and `above`.
    while (!above.nums.isEmpty()) {
      final int mx = below.nums.lastKey();
      final int mn = above.nums.firstKey();
      if (mx <= mn)
        break;
      below.erase(mx);
      above.erase(mn);
      below.insert(mn);
      above.insert(mx);
    }
  }
}

class Solution {
  public long minOperations(int[] nums, int k) {
    MedianTracker tracker = new MedianTracker(k);

    for (int i = 0; i < k; ++i)
      tracker.add(nums[i]);

    long ans = tracker.getCost();

    for (int i = k; i < nums.length; ++i) {
      tracker.remove(nums[i - k]);
      tracker.add(nums[i]);
      ans = Math.min(ans, tracker.getCost());
    }

    return ans;
  }
}
