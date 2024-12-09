type Fn = (accum: number, curr: number) => number;

function reduce(nums: number[], fn: Fn, init: number): number {
  let ans = init;
  for (const num of nums) {
    ans = fn(ans, num);
  }
  return ans;
}
