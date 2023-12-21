class Solution {
  public List<Integer> transformArray(int[] arr) {
    if (arr.length < 3)
      return Arrays.stream(arr).boxed().toList();

    int[] ans = new int[0];

    while (!Arrays.equals(ans, arr)) {
      ans = arr.clone();
      for (int i = 1; i < arr.length - 1; ++i)
        if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
          ++arr[i];
        else if (ans[i - 1] < ans[i] && ans[i] > ans[i + 1])
          --arr[i];
    }

    return Arrays.stream(ans).boxed().toList();
  }
}
