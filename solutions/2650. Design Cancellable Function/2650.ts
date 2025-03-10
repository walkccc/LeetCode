function cancellable<T>(
  generator: Generator<Promise<any>, T, unknown>
): [() => void, Promise<T>] {
  let cancel = () => {};
  const cancelPromise = new Promise<never>((_, reject) => {
    cancel = () => reject('Cancelled');
  });

  const promise = (async (): Promise<T> => {
    let next = generator.next();
    while (!next.done) {
      try {
        next = generator.next(await Promise.race([next.value, cancelPromise]));
      } catch (e) {
        next = generator.throw(e);
      }
    }
    return next.value;
  })();

  return [cancel, promise];
}
