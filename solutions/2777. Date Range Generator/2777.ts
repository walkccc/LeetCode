// Similar to 2758. Next Day
function* dateRangeGenerator(
  start: string,
  end: string,
  step: number
): Generator<string> {
  const startDate = new Date(start);
  const endDate = new Date(end);
  let currentDate = startDate;
  while (currentDate <= endDate) {
    yield currentDate.toISOString().split('T')[0];
    currentDate.setDate(currentDate.getDate() + step);
  }
}
