type JSONValue =
  | {}
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

type Item = { [key: string]: JSONValue } & {
  id: number;
};

function join(arr1: Item[], arr2: Item[]): Item[] {
  const idToObj: { [key: number]: Item } = {};
  for (const item of arr1) {
    idToObj[item.id] = item;
  }
  for (const item of arr2) {
    if (idToObj[item.id] === undefined) {
      idToObj[item.id] = item;
    } else {
      for (const key of Object.keys(item)) {
        idToObj[item.id][key] = item[key];
      }
    }
  }
  const ans = Object.values(idToObj);
  ans.sort((a, b) => a.id - b.id);
  return ans;
}
