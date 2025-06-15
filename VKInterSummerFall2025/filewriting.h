#pragma once
#include "iostream"
#include "fstream"
#include "vector"
#include "collection.h"
#include "chrono"
#include "iomanip"
#include "ctime"

using namespace std::chrono;
using namespace std;


namespace mtr
{

	class Writer
	{
		
		string filepath;
		ofstream file;

	public:
		Writer();
		Writer(string filepath);

		void changeFilepath(string filepath);
		void write(const Metricollection& coll);

	};

}
