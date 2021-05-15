class MyCircularQueue {
    vector<int> cq;
    int front;
    int rear;
    int size;
   const int maxSize;
public:
    MyCircularQueue(int k): front(0), rear(-1), size(0), maxSize(k), cq(vector<int>(k,-1))
    {}

    bool enQueue(int value) {
        if (isFull())
            return false;
        else
        {   
            if (++rear == maxSize)
                rear = 0;
            cq[rear] = value;
            size++;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        else
        {
            if (++front == maxSize)
                front = 0;
            size--;
            return true;
        }
    }

    int Front() {
        if (isEmpty())
            return -1;
        return cq[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return cq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }
};
