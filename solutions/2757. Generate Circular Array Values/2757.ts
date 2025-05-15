function* cycleGenerator(
  arr: number[],
  startIndex: number
): Generator<number, void, number> {
  const n = arr.length;
  let index = startIndex;
  while (true) {
    const jump = yield arr[index];
    index = (index + (jump % n) + n) % n;
  }
}
