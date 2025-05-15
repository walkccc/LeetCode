function createInfiniteObject(): Record<string, () => string> {
  return new Proxy(
    {},
    {
      get: (_, prop: string) => () => prop,
    }
  );
}
