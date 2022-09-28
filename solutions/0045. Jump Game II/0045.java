class Solution {
  public int jump(int[] nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    // implicit BFS
    for (int i = 0; i < nums.length - 1; ++i) {
      farthest = Math.max(farthest, i + nums[i]);
      if (farthest >= nums.length - 1) {
        ++ans;
        break;
      }
      if (i == end) {   // visited all the items on the current level
        ++ans;          // increment the level
        end = farthest; // make the queue size for the next level
      }
    }

    return ans;
  }
}
