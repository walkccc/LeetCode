declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function (
  rowsCount: number,
  colsCount: number
): number[][] {
  if (rowsCount * colsCount != this.length) {
    return [];
  }
  const ans: number[][] = [];
  for (let i = 0; i < rowsCount; ++i) {
    ans.push([]);
  }
  for (let i = 0; i < rowsCount; ++i)
    for (let j = 0; j < colsCount; ++j) {
      const k = j * rowsCount + (j % 2 == 0 ? i : rowsCount - 1 - i);
      ans[i][j] = this[k];
    }
  return ans;
};
