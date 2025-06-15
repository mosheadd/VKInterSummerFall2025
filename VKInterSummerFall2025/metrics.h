#pragma once

#include "iostream"
#include "string"
#include "vector"
//#include "filewriting.h"

using namespace std;

namespace mtr
{

	class BaseMtr
	{
	protected:
		string name;

		BaseMtr(string name) : name(name) {};
	public:
		virtual const string getName() const noexcept = 0;
		virtual const string toString() const noexcept = 0;
	};

	template<class T>
	class Metric : public BaseMtr
	{
	protected:
		T value;

	public:
		Metric(string name) : BaseMtr(name)
		{
			value = T();
			cout << "Metric created with name " << name << endl;
		}

		const string getName() const noexcept
		{
			return name;
		};
		const T getValue() const noexcept
		{
			return value;
		};

		void setValue(T value)
		{
			this->value = value;
		}

		const string toString() const noexcept {
			return to_string(value);
		}

	};

}
