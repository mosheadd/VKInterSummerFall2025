#pragma once

#include "string"
#include "vector"
#include "filewriting.h"

using namespace std;

namespace mtr
{

	class BaseMtr
	{
	protected:
		string name;

		BaseMtr(string name);
	public:
		virtual const string getName() const noexcept=0;
	};

	template<class T>
	class Metric : public BaseMtr
	{
	protected:
		T value;

	public:
		Metric(string name);

		const string getName() const noexcept;
		const T getValue() const noexcept;

		void setValue(T value);

	};

}
