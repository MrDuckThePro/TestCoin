#pragma once

#include <ctime>

#include <block.h>

class blockchain
{
public:

	blockchain();
	block getLatestBlock();
	void addBlock(std::vector<std::string> data);
	bool isChainValid();

private:

	block createGenesisBlock();
	std::vector<block> blocks;


};
