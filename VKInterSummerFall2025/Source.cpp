#include "iostream"
#include "vector"
#include <windows.h>

#include "metrics.h"
#include "collection.h"
#include "filewriting.h"

using namespace std;

void bydefault() {
	cout << "Metrics programm.\nWrite '--help' or '-h' for help\n";
}

void help()
{
	cout << "Options:\n";
	cout << "'--help' or '-h' for help\n";
	cout << "'--one' or '-o' for example number one\n";
	cout << "'--two' or '-t' for example number two\n";
	cout << "write path to a file after '-o' or '-t', default is 'example1.txt' and 'example2.txt'\n";
}

void example1(string filepath="example1.txt")
{

	mtr::Metricollection coll;
	coll.addMetric("CPULoad", 0.0);
	coll.addMetric("HTTP requests RPS", 0);

	mtr::Writer writer(filepath);
	writer.write(coll);
	Sleep(2000);

	coll.setMetricVal("CPULoad", 0.97);
	coll.setMetricVal("HTTP requests RPS", 42);
	writer.write(coll);
	Sleep(1000);

	coll.setMetricVal("CPULoad", 1.12);
	coll.setMetricVal("HTTP requests RPS", 30);
	writer.write(coll);

	cout << "The output is successfully written in " << filepath << endl;

}

void ex2write(mtr::Metricollection& coll, mtr::Writer& writer, int c1, int c2, float cpu_us)
{
	coll.setMetricVal("Core0Temp", c1);
	coll.setMetricVal("Core1Temp", c2);
	coll.setMetricVal("CPU_Usage", cpu_us);
	writer.write(coll);
}

void example2(string filepath = "example2.txt")
{

	mtr::Metricollection coll;
	coll.addMetric("Core0Temp", 0);
	coll.addMetric("Core1Temp", 0);
	coll.addMetric("CPU_Usage", 0.f);

	mtr::Writer writer(filepath);
	writer.write(coll);

	ex2write(coll, writer, 31, 28, 4.4);
	Sleep(1000);

	ex2write(coll, writer, 30, 30, 4.9);
	Sleep(1000);

	ex2write(coll, writer, 29, 30, 4.0);
	Sleep(1000);

	ex2write(coll, writer, 35, 34,	7.8);
	Sleep(1000);

	ex2write(coll, writer, 45, 49, 15.6);
	Sleep(1000);

	cout << "The output is successfully written in " << filepath << endl;

}

int main(int argc, char* argv[])
{
	
	cout << argc << endl;

	if (argc == 1)
		bydefault();
	else
	{

		try
		{
			string arg = argv[1];
			if (arg == "-h" || arg == "--help")
				help();
			else if (arg == "-o" || arg == "--one")
			{
				if (argc > 2)
				{
					string filepath = argv[2];
					example1(filepath);
				}
				else
					example1();
			}
			else if (arg == "-t" || arg == "--two")
			{
				if (argc > 2)
				{
					string filepath = argv[2];
					example2(filepath);
				}
				else
					example2();
			}
		}
		catch (const exception& e) {
			cout << e.what();
		}
		catch (...) {
			cout << "unknown error\n";
		}
	}
	
	return 0;
}