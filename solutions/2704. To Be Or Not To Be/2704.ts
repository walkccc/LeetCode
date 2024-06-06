type ToBeOrNotToBe = {
  toBe: (val: any) => boolean;
  notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
  return {
    toBe: function (val2: any) {
      if (val === val2) {
        return true;
      }
      throw 'Not Equal';
    },
    notToBe: function (val2: any) {
      if (val !== val2) {
        return true;
      }
      throw 'Equal';
    },
  };
}
