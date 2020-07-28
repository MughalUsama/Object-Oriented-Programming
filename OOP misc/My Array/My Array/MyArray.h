#ifndef MYARRAY_H
#define MYARRAY_H


template <class T>
class MyArray
{

private:

	int capacity;
	int noOfElements;
	T * data;

public:

	MyArray(int size = 5)
	{
		this->capacity = size;
		this->noOfElements = size;
		this->data = new T[capacity];

	}
	MyArray(const MyArray & ref)
	{
		capacity = ref.capacity;
		noOfElements = ref.noOfElements;
		if (ref.data != nullptr)
		{
			data = new int[capacity];
			for (int i = 0; i < noOfElements; i = i + 1)
			{
				data[i] = ref.data[i];
			}
		}
		else
		{
			data = ref.data;
		}

	}
	~MyArray()
	{
		capacity = 0;
		noOfElements = 0;
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	void input()
	{
		for (int i = 0; i < this->capacity; i++)
		{
			cout << "Enter element no " << i + 1<<": ";
			cin >> this->data[i];
		}
	}
	T & operator[](int index)
	{
		if (index >= 0 && index < capacity && data != nullptr)
		{
			return data[index];
		}
		exit(0);
	}

	MyArray& operator=(const MyArray & ref) {
		if (this != &ref && ref.data != nullptr)
		{
			this->~MyArray();
			this->capacity = ref.capacity;
			this->noOfElements = ref.noOfElements;
			this->data = new T[this->capacity];
			for (int i = 0; i < noOfElements; i = i + 1)
			{
				this->data[i] = ref.data[i];
			}
			
		}
		else
		{
			this->~MyArray();
			this->capacity = ref.capacity;
			this->noOfElements = ref.noOfElements;
		}
		return *this;
	}

	MyArray operator+(const MyArray & ref)
	{
		MyArray  arr;
		if (this->data != nullptr && ref.data != nullptr)
		{
			arr.~MyArray();
			arr.capacity = this->capacity + ref.capacity;
			arr.noOfElements = this->noOfElements + ref.noOfElements;
			arr.data = new T[arr.capacity];
			int count = 0;
			for (int i = 0; i < noOfElements; i = i + 1)
			{
				arr.data[count] = data[i];
				count = count + 1;
			}
			for (int i = 0; i < ref.noOfElements; i = i + 1)
			{
				arr.data[count] = ref.data[i];
				count = count + 1;
			}

		}
		else if (ref.data != nullptr)
		{
			arr = *this;
		}
		else if (this->data != nullptr)
		{
			arr = ref;
		}
		return arr;
	}

	void operator+=(const MyArray & ref)
	{
		if (this->data != nullptr && ref.data != nullptr)
		{
			T*dataa = this->data;
			this->capacity = this->capacity + ref.capacity;
			this->noOfElements = this->noOfElements + ref.noOfElements;
			this->data = new T[this->capacity];
			int count = 0;
			for (int i = 0; i < noOfElements; i = i + 1)
			{
				this->data[count] = dataa[i];
				count = count + 1;
			}
			for (int i = 0; i < ref.noOfElements; i = i + 1)
			{
				this->data[count] = ref.data[i];
				count = count + 1;
			}
			delete[] dataa;
			dataa = nullptr;
		}
		else if (this->data != nullptr)
		{
			*this = ref;
		}
	}

};

#endif 

