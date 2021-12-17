template<typename T>
class Stack
{
	T* storage_;
	int capacity_; //容量
	int n_;

	friend class Iterator;

private:

	void resize(int capacity) //dynamic
	{
		T* temp = new T[capacity];
		for (int i = 0; i < n_; ++i)
		{
			temp[i] = storage_[i];
		}
		delete[] storage_;
		storage_ = temp;
		capacity_ = capacity;
	}

	class Iterator
	{
		Stack* stack_;
		int n_;

	public:

		Iterator()
			: stack_(nullptr)
			, n_(-1)
		{

		}

		Iterator(Stack* stack)
			: stack_(stack)
			, n_(stack->capacity_ - 1)
		{

		}

		void operator++()
		{
			--n_;
		}

		bool operator!=(const Iterator& Other)
		{
			return n_ != Other.n_;
		}

		T& operator*()
		{
			return stack_->storage_[n_];
		}
	};

public:
	Stack() //构造函数
	{
		capacity_ = 1;
		storage_ = new T[1];
		n_ = 0;
	}

	~Stack() //析构函数
	{
		delete[] storage_;
	}

	void push(T item) //入栈
	{
		if (n_ == capacity_)
		{
			resize(capacity_ * 2);
		}
		storage_[n_++] = item;
	}

	T pop() //出栈
	{
		T item = storage_[--n_];
		if (n_ > 0 && n_ == capacity_ / 4)
		{
			resize(capacity_ / 2);
		}
		return item;
	}

	bool is_empty() const
	{
		return n_ == 0;
	}

	int size() const
	{
		return n_;
	}

	Iterator begin()
	{
		return Iterator(this);
	}

	Iterator end()
	{
		return Iterator();
	}
};
