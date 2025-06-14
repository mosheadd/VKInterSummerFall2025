#pragma once

#include "vector"
#include "filewriting.h"

using namespace std;

namespace mtr
{

	class Metricollection
	{
		vector<unique_ptr<BaseMtr>> metrics;
		Writer writer;

	public:
		template<class T>
		void addMetric(string name, T initVal);
		void write();

	};

	template<class T>
	inline void Metricollection::addMetric(string name, T initVal)
	{
		
	}

}