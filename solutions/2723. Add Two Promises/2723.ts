type P = Promise<number>;

async function addTwoPromises(promise1: P, promise2: P): P {
  const results = await Promise.all([promise1, promise2]);
  return results[0] + results[1];
}
