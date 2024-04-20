let id = 0;
const idToTimeout = {};

function customInterval(fn: Function, delay: number, period: number): number {
  ++id;
  (function callFnWithCountPlusOne(count: number): void {
    const timeout = setTimeout(() => {
      fn();
      callFnWithCountPlusOne(count + 1);
    }, delay + period * count);
    idToTimeout[id] = timeout;
  })(0);
  return id;
}

function customClearInterval(id: number): void {
  clearTimeout(idToTimeout[id]);
}
