declare global {
  interface Array<T> {
    upperBound(target: number): number;
  }
}

Array.prototype.upperBound = function (target): number {
  let l = 0;
  let r = this.length - 1;
  while (l < r) {
    const m = (l + r + 1) >> 1;
    if (this[m] > target) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return this[l] == target ? l : -1;
};
