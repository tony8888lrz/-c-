template<class T>
class Stack
{
    private:
        T* storage;
        int capacity;
        int n;

    public:

        void resize(int capacity_r)
        {
            T* temp = new T[capacity_r]; //according to the parameter dynamic allocate the memory
            for(int i = 0;i<n;i++)
            {
                temp[i] = storage[i];
            }
            delete[] storage; // after using it ,must delete
            storage = temp;
            capacity = capacity_r;
        }

        Stack() // construcor
        {
            capacity = 1;
            storage = new T[1];
            n = 0;
        }

        ~Stack() //析构
        {
            delete[] storage;
        }

        void push(T i) //in
        {
            if(n == capacity)
            {
                resize(capacity * 2);
            }
            storage[n++] = i; //2 steps
        }

        T pop() //out
        {
            T i = storage[--n]; //2 steps
            if(n>0 && n == capacity/4)
            {
                resize(capacity/2);
            }
            return i;
        }
};