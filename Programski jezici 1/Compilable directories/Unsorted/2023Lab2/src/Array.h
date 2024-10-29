namespace PJ1Lab{

    // todo: dinamicka realokacija sa new i delete

    class Array{
    private:
        int capacity;
        int isize;
        double *array;
    public:
        Array(int capacity = 1);
        ~Array();

        int size() const;
        void append(double value);
        bool insertAt(int index, double value);
        bool removeAt(int index);
        double& at(int index, bool& success) const;
        double& at(int index) const;
        void dispose();
    };
};