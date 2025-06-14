#include "metrics.h"


namespace mtr
{


	BaseMtr::BaseMtr(string name) : name(name)
	{
	}

	template<class T>
	Metric<T>::Metric(string name) : BaseMtr(name)
	{
		cout << "Metric created\n";
	}

	template<class T>
	const string Metric<T>::getName() const noexcept
	{
		return name;
	}

	template<class T>
	const T Metric<T>::getValue() const noexcept
	{
		return value;
	}

	template<class T>
	void Metric<T>::setValue(T value)
	{
		this->value = value;
	}


}
