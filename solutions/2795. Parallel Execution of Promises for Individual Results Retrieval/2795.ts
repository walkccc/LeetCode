type FulfilledObj = {
  status: 'fulfilled';
  value: string;
};
type RejectedObj = {
  status: 'rejected';
  reason: string;
};
type Obj = FulfilledObj | RejectedObj;

function promiseAllSettled(functions: Function[]): Promise<Obj[]> {
  return new Promise((resolve) => {
    const results: Obj[] = Array.from({ length: functions.length });
    let count = 0;
    functions.forEach((fn, index) => {
      fn()
        .then((value) => {
          results[index] = { status: 'fulfilled', value };
        })
        .catch((reason) => {
          results[index] = { status: 'rejected', reason };
        })
        .finally(() => {
          if (++count === functions.length) {
            resolve(results);
          }
        });
    });
  });
}
