type Fn = (n: number, i: number) => any;

function filter(arr: number[], fn: Fn): number[] {
  const ans: number[] = [];
  arr.forEach((a, index) => {
    if (fn(a, index)) {
      ans.push(a);
    }
  });
  return ans;
}
