class Stack<ItemType> {
    items_: ItemType[];

    constructor() {
        this.items_ = [];
    }

    pushToTop(item: ItemType): void {
        this.items_.push(item);
    }

    peekFromTop(): ItemType | undefined {
        return this.items_[this.size() - 1];
    }

    popFromTop(): ItemType | undefined {
        return this.items_.pop();
    }

    size(): number {
        return this.items_.length;
    }

    isEmpty(): boolean {
        return this.size() === 0;
    }
}

// FIFO
// 1 <-- push
// 1 2 <-- push
// 1 2 3 <-- push
// 1 2 <-- pop
// 1 <-- pop

// LIFO
// 1 <-- push
// 1 2 <-- push
// 1 2 3 <-- push
//   2 3 <-- shift
//     3 <-- shift

class MyQueue<ItemType = number> {
    stack_: Stack<ItemType>;

    constructor() {
        this.stack_ = new Stack<ItemType>();
    }

    push(x: ItemType): void {
        this.stack_.pushToTop(x);
    }

    pop(): ItemType {
        const other = new Stack<ItemType>();
        while (!this.stack_.isEmpty()) {
            other.pushToTop(this.stack_.popFromTop());
        }
        const retVal = other.popFromTop();
        while (!other.isEmpty()) {
            this.stack_.pushToTop(other.popFromTop());
        }
        return retVal;
    }

    peek(): ItemType {
        const other = new Stack<ItemType>();
        while (!this.stack_.isEmpty()) {
            other.pushToTop(this.stack_.popFromTop());
        }
        const retVal = other.peekFromTop();
        while (!other.isEmpty()) {
            this.stack_.pushToTop(other.popFromTop());
        }
        return retVal;
    }

    empty(): boolean {
        return this.stack_.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
