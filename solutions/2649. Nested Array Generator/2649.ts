type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(
  arr: MultidimensionalArray
): Generator<number, void, unknown> {
  for (const item of arr) {
    if (typeof item === 'number') {
      yield item;
    } else {
      yield* inorderTraversal(item);
    }
  }
}
