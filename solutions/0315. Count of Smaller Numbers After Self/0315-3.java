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
    int[] ans = new int[n];
    Item[] items = new Item[n];

    for (int i = 0; i < n; ++i)
      items[i] = new Item(nums[i], i);

    mergeSort(items, 0, n - 1, ans);
    return Arrays.stream(ans).boxed().collect(Collectors.toList());
  }

  private void mergeSort(Item[] items, int l, int r, int[] ans) {
    if (l >= r)
      return;

    final int m = (l + r) / 2;
    mergeSort(items, l, m, ans);
    mergeSort(items, m + 1, r, ans);
    merge(items, l, m, r, ans);
  }

  private void merge(Item[] items, int l, int m, int r, int[] ans) {
    Item[] sorted = new Item[r - l + 1];
    int k = 0;          // sorted's index
    int i = l;          // left's index
    int j = m + 1;      // right's index
    int rightCount = 0; // the number of `nums` < items[i].num

    while (i <= m && j <= r)
      if (items[i].num > items[j].num) {
        ++rightCount;
        sorted[k++] = items[j++];
      } else {
        ans[items[i].index] += rightCount;
        sorted[k++] = items[i++];
      }

    // Put the possible remaining left part into the sorted array.
    while (i <= m) {
      ans[items[i].index] += rightCount;
      sorted[k++] = items[i++];
    }

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = items[j++];

    System.arraycopy(sorted, 0, items, l, sorted.length);
  }
}
