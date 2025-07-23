type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (
  arr: MultiDimensionalArray,
  n: number
): MultiDimensionalArray {
  function dfs(arr: number | MultiDimensionalArray, n: number) {
    if (typeof arr === 'number') {
      ans.push(arr);
    } else if (n === 0) {
      for (const element of arr) {
        ans.push(element);
      }
    } else {
      for (const element of arr) {
        dfs(element, n - 1);
      }
    }
  }
  const ans: MultiDimensionalArray = [];
  dfs(arr, n);
  return ans;
};
