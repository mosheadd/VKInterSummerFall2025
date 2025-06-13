#pragma once

#include "string"

using namespace std;

namespace mtr
{

	class Metric
	{
	protected:
		string name;

		Metric(string name);

	public:
		string getName() const noexcept;
		virtual double metric() const = 0;
		virtual void measure(int val) = 0;

	};


	class CPULoad : public Metric
	{
		static int coresloaded;
		static int timepassed;
		
		int N;
	public:
		CPULoad(string name, int N);

		double metric() const;
		void measure(int val);

	};

}
