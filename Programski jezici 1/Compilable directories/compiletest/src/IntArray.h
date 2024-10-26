class IntArray{
    private:
        int size;
        int *array;

        bool isFull() const;
        bool isEmpty() const;
    public:
        int maxSize;
        IntArray();
        ~IntArray();

        void writeAll() const;
        bool append(int value);
        int pop();
};