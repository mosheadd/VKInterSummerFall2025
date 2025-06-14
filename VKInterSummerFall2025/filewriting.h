#pragma once
#include "iostream"
#include "fstream"
#include "vector"
#include "metrics.h"

using namespace std;


namespace mtr
{

	class Writer
	{
		
		string filepath;
		ofstream file;

	public:
		Writer(string filepath);

		void changeFilepath(string filepath);
		void write(const vector<unique_ptr<BaseMtr>>& metrics);

	};

}
