#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
	int count = 0;

public:
	Counter() { this->count = 0; }

	///@brief Aumenta el contador.
	void AumentCount();
	///@brief Disminuye el contador.
	void DecrementCount();

	/// @brief Delvuelve el valor del contador.
	int GetCounter() const { return this->count; }
	/// <summary>
	/// Delvuelve true, si el contador es menor o igual a cero.
	/// </summary>
	/// <returns></returns>
	bool IsZeroCounter() const;
};

#endif