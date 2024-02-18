type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
  const next = () => functions[n++]?.().then(next);
  return Promise.all(functions.slice(0, n).map((f) => f().then(next)));
}
