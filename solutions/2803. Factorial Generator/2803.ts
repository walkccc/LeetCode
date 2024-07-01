function* factorial(n: number): Generator<number> {
  if (n === 0) {
    yield 1;
  }
  let fact = 1;
  for (let i = 1; i <= n; ++i) {
    fact *= i;
    yield fact;
  }
}
