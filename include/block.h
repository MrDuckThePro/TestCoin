#pragma once

#include <vector> //Needed fot storing the data

#include <picosha2.h> //Needed for hashing the block // https://github.com/okdshin/PicoSHA2

class block
{
public:

	block(int index, long timestamp, std::string prevHash, std::vector<std::string> data);
	std::string calculateHash();
	std::string getHash();
	std::string getPrevHash();

private:

	int index;
	long timestamp;
	std::vector<std::string> data;
	std::string prevHash;
	std::string hash;

};
