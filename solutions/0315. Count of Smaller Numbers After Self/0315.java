class Item {
  public int num;
  public int index;

  public Item(int num, int index) {
    this.num = num;
    this.index = index;
  }
}

class Solution {
  public List<Integer> countSmaller(int[] nums) {
    final int n = nums.length;

    List<Integer> ans = new ArrayList<>();
    int[] count = new int[n];
    Item[] items = new Item[n];

    for (int i = 0; i < n; ++i)
      items[i] = new Item(nums[i], i);

    mergeSort(items, 0, n - 1, count);

    for (final int c : count)
      ans.add(c);

    return ans;
  }

  private void mergeSort(Item[] items, int l, int r, int[] count) {
    if (l >= r)
      return;

    final int m = l + (r - l) / 2;
    mergeSort(items, l, m, count);
    mergeSort(items, m + 1, r, count);
    merge(items, l, m, r, count);
  }

  private void merge(Item[] items, int l, int m, int r, int[] count) {
    Item[] sorted = new Item[r - l + 1];
    int k = 0; // point to the sorted's beginning
    int i = l; // point to the left's beginning
    int j = m + 1; // point to the right's beginning
    int rightCount = 0; // # of nums < items[i].num

    while (i <= m && j <= r)
      if (items[i].num > items[j].num) {
        ++rightCount;
        sorted[k++] = items[j++];
      } else {
        count[items[i].index] += rightCount;
        sorted[k++] = items[i++];
      }

    // put possible remaining left part to the sorted array
    while (i <= m) {
      count[items[i].index] += rightCount;
      sorted[k++] = items[i++];
    }

    // put possible remaining right part to the sorted array
    while (j <= r)
      sorted[k++] = items[j++];

    System.arraycopy(sorted, 0, items, l, sorted.length);
  }
}