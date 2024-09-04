#ifndef REFERENCE_COUNT_H
#define REFERENCE_COUNT_H

#include "Counter.h" // Counter
#include <utility>


template <typename Type>
class ReferenceCount{
private:
	Type* ptr = nullptr;
	Counter count;
	/// <summary>
	/// Servira para actualizar el contador.
	/// </summary>
	Counter* count_ptr = nullptr;

public:

	ReferenceCount(Type value) : ptr(new Type(value)) {
		this->count_ptr = &count;
		this->count.AumentCount();
	}

	~ReferenceCount() {
		this->count_ptr->DecrementCount();

		if (count.IsZeroCounter() == true) {
			delete this->ptr;
			this->count_ptr = nullptr;
		}
	}

	ReferenceCount(ReferenceCount& other) {
		this->ptr = other.ptr;
		this->count_ptr = &other.count;
		this->count = other.count;

		this->count_ptr->AumentCount();

	}

	ReferenceCount& operator=(ReferenceCount& other){
		this->ptr = other.ptr;
		this->count_ptr = &other.count;
		this->count = other.count;

		this->count_ptr->AumentCount();

		return *this;
	}

	ReferenceCount(ReferenceCount&&  other) {
		this->ptr = other.ptr;
		this->count_ptr = other.count_ptr;
		this->count = other.count;	

		other.ptr = nullptr;
		other.count_ptr = nullptr;
		//other.count.DecrementCount();
		
	}

	ReferenceCount&& operator=(ReferenceCount&& other) {
		this->ptr = other.ptr;
		this->count_ptr = other.count_ptr;
		this->count = other.count;

		other.ptr = nullptr;
		other.count_ptr = nullptr;
		//other.count.DecrementCount();

		return *this;
	}

	int GetCount() const { return this->count_ptr->GetCounter(); }

	void Release()
	{
		this->count_ptr->DecrementCount();
		

		if (this->count.IsZeroCounter() == true)
		{
			delete this->ptr;
			ptr = nullptr;
			count_ptr = nullptr;
		}
	}

	Type* operator->() const { 
		return ptr; 
	}
	Type& operator*() const { 
		return *this->ptr; 
	}
	// T &operator&() const { return this->ptr; }

	/// Compara dos de la misma ckase
	bool operator==(const ReferenceCount& other) const
	{
		return this->ptr == other.ptr;
	}


};


#endif // 
