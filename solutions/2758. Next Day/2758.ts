declare global {
  interface Date {
    nextDay(): string;
  }
}

Date.prototype.nextDay = function () {
  const today = new Date(this.getTime());
  today.setDate(today.getDate() + 1);
  return today.toISOString().split('T')[0];
};
