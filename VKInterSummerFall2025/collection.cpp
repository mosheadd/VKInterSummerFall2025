#include "collection.h"

namespace mtr
{

	Metricollection::~Metricollection()
	{
		for (size_t i = 0; i < collection.size(); i++)
			delete collection[i];
	}

	size_t Metricollection::getSize() const noexcept
	{
		return collection.size();
	}

	BaseMtr* Metricollection::operator[](int ind) const
	{
		if (ind < 0 || ind > collection.size())
			throw exception("index out of range");
		return collection[ind];
	}

	BaseMtr*& Metricollection::operator[](int ind)
	{
		if (ind < 0 || ind > collection.size())
			throw exception("index out of range");
		return collection[ind];
	}

}