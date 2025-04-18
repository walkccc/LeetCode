type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

declare global {
  interface Function {
    callPolyfill(
      context: Record<string, JSONValue>,
      ...args: JSONValue[]
    ): JSONValue;
  }
}

Function.prototype.callPolyfill = function (context, ...args): JSONValue {
  const fn = this;
  Object.defineProperty(context, '__fn__', {
    value: fn,
    enumerable: false,
  });
  const ans = (context.__fn__ as any)(...args);
  delete context.__fn__;
  return typeof ans !== 'undefined' ? ans : undefined;
};
