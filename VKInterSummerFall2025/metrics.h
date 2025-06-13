#pragma once

#include "string"

using namespace std;

namespace mtr
{

	class Metric
	{
		string name;

		int leftRangeLimit;
		int rightRangeLimit;

	public:
		string getName() const noexcept;
		virtual int metric() = 0;

	};

}
