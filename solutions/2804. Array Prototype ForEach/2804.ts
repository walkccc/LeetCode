type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Callback = (
  currentValue: JSONValue,
  index: number,
  array: JSONValue[]
) => any;
type Context = Record<string, JSONValue>;

Array.prototype.forEach = function (
  callback: Callback,
  context: Context
): void {
  for (let i = 0; i < this.length; ++i) {
    callback.call(context, this[i], i, this);
  }
};
