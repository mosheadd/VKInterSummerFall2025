#pragma once

#include "vector"
#include "metrics.h"

using namespace std;

namespace mtr
{

	class Metricollection
	{
		vector<BaseMtr*> collection;

	public:
		~Metricollection();

		template<class T>
		void addMetric(string name, T initVal);
		template<class T>
		void setMetricVal(string name, T val);
		size_t getSize() const noexcept;

		BaseMtr* operator[](int ind) const;
		BaseMtr*& operator[](int ind);

	};

	template<class T>
	inline void Metricollection::addMetric(string name, T initVal)
	{
		Metric<T>* metric = new Metric<T>(name);
		metric->setValue(initVal);
		collection.push_back(metric);
	}

	template<class T>
	inline void Metricollection::setMetricVal(string name, T val)
	{
		for (int i = 0; i < collection.size(); i++)
		{
			if (collection[i]->getName() == name)
			{
				Metric<T>* metric = dynamic_cast<Metric<T>*>(collection[i]);
				metric->setValue(val);
				return;
			}
		}

		cout << "Could not find metric with name " << name << endl;

	}

}