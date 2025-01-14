declare global {
  interface String {
    replicate(times: number): string;
  }
}

String.prototype.replicate = function (times): string {
  return Array(times).fill(this).join('');
};
