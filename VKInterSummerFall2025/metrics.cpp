#include "metrics.h"


namespace mtr
{

	Metric::Metric(string name) : name(name) {};

	string Metric::getName() const noexcept {
		return name;
	}

	CPULoad::CPULoad(string name, int N) : Metric(name), N(N) {};

	double CPULoad::metric() const {
		return (double)coresloaded / (double)timepassed;
	}

	void CPULoad::measure(int val)
	{
		coresloaded += val;
		timepassed++;
	}

}
