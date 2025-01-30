class MinHeap {
    private items_: number[];

    constructor() {
        this.items_ = [];
    }

    empty(): boolean {
        return this.items_.length === 0;
    }

    push(val: number) {
        for (let i = 0; i < this.items_.length; ++i) {
            if (val <= this.items_[i]) {
                this.items_.splice(i, 0, val);
                return;
            }
        }
        this.items_.push(val);
    }

    pop(): number | undefined {
        return this.items_.shift();
    }

    top(): number | undefined {
        return this.items_[0];
    }
}

class DinnerPlates {
    private minHeap_: MinHeap;
    private capacity_: number;
    private stacks_: number[][];

    constructor(capacity: number) {
        this.capacity_ = capacity;

        this.minHeap_ = new MinHeap();
        this.minHeap_.push(0);

        this.stacks_ = [];
    }

    push(val: number): void {
        const index = this.minHeap_.top();

        if (index === this.stacks_.length) {
            this.stacks_.push([]);
        }

        this.stacks_[index].push(val);

        if (this.stacks_[index].length === this.capacity_) {
            this.minHeap_.pop();
            if (this.minHeap_.empty()) {
                this.minHeap_.push(this.stacks_.length);
            }
        }
    }

    pop(): number {
        while (this.stacks_.length > 0 && this.stacks_[this.stacks_.length - 1].length === 0) {
            this.stacks_.pop();
        }

        return this.popAtStack(this.stacks_.length - 1);  
    }

    popAtStack(index: number): number {
        if (!this.stacks_[index]?.length) {
            return -1;
        }
        
        if (this.stacks_[index].length === this.capacity_) {
            this.minHeap_.push(index);
        }

        return this.stacks_[index].pop();
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * var obj = new DinnerPlates(capacity)
 * obj.push(val)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAtStack(index)
 */
