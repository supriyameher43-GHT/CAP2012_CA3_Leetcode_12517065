
class MyCircularDeque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int count;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = 0;
        rear = -1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + size) % size;
        }

        arr[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }

        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            rear = (rear - 1 + size) % size;
        }

        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};
