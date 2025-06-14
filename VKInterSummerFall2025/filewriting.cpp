#include "filewriting.h"


namespace mtr
{
	Writer::Writer(string filepath) : filepath(filepath) {}

	void Writer::changeFilepath(string filepath)
	{
		this->filepath = filepath;
	}

	void Writer::write(const vector<unique_ptr<BaseMtr>>& metrics)
	{

		file.open(filepath);

	}
}
