#include "filewriting.h"


namespace mtr
{
	Writer::Writer(string filepath) : filepath(filepath) {}

	void Writer::changeFilepath(string filepath)
	{
		this->filepath = filepath;
	}

	void Writer::write(const Metricollection& coll)
	{

		file.open(filepath, ios::app);
		if (!file.is_open())
		{
			string err = "could not open file " + filepath;
			throw exception(err.c_str());
		}

		auto now = chrono::system_clock::now();
		auto now_time = chrono::system_clock::to_time_t(now);

		struct tm tm_buffer;
		localtime_s(&tm_buffer, &now_time);
		file << std::put_time(&tm_buffer, "%Y-%m-%d %H:%M:%S") << " ";

		size_t collsize = coll.getSize();

		string strtowrite = "";
		for (int i = 0; i < collsize; i++)
		{
			BaseMtr* m = coll[i];
			file << '"' << m->getName() << '"' << " " << m->toString() << " ";
		}
		file << "\n";

		file.close();

	}
}
