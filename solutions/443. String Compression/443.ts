function compress(chars: string[]): number {
    let compressed = [];

    let prev = chars[0], i = 1, count = 1, l = chars.length;

    for (; i < l; ++i) {
        const curr = chars[i];
        if (prev === curr) {
            ++count;
        } else {
            compressed.push(prev);
            if (count > 1) compressed.push(...count.toString().split(''));
            prev = curr;
            count = 1;
        }
    }
    
    compressed.push(prev);
    if (count > 1) compressed.push(...count.toString().split(''));

    if (chars.length < compressed.length) {
        return chars.length;
    }

    chars.length = 0;
    chars.push(...compressed);
    return compressed.length;
}
