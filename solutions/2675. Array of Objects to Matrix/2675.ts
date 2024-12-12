function jsonToMatrix(arr: any[]): (string | number | boolean | null)[][] {
  const isObject = (o: any) => o !== null && typeof o === 'object';

  // Returns the keys of a JSON-like object by recursively unwrapping the nests.
  const getKeys = (json: any): string[] => {
    if (!isObject(json)) {
      return [''];
    }
    return Object.keys(json).reduce((acc: string[], currKey: string) => {
      return (
        acc.push(
          ...getKeys(json[currKey]).map((nextKey: string) =>
            nextKey === '' ? currKey : `${currKey}.${nextKey}`
          )
        ),
        acc
      );
    }, []);
  };

  const sortedKeys: string[] = [
    ...arr.reduce((acc: Set<string>, curr: any) => {
      getKeys(curr).forEach((key: string) => acc.add(key));
      return acc;
    }, new Set<string>()),
  ].sort();

  // Returns the value of `obj` keyed by `nestedKey`.
  const getValue = (
    obj: any,
    nestedKey: string
  ): string | number | boolean | null => {
    let value: any = obj;
    for (const key of nestedKey.split('.')) {
      if (!isObject(value) || !(key in value)) {
        return '';
      }
      value = value[key];
    }
    return isObject(value) ? '' : value;
  };

  const matrix: (string | number | boolean | null)[][] = [sortedKeys];
  arr.forEach((obj: any) => {
    matrix.push(
      sortedKeys.map((nestedKey: string) => getValue(obj, nestedKey))
    );
  });

  return matrix;
}
