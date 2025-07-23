function map(arr: number[], fn: (n: number, i: number) => number): number[] {
  const ans: number[] = [];
  arr.forEach((a, index) => {
    ans.push(fn(a, index));
  });
  return ans;
}
