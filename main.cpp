#include <iostream>

#include <blockchain.h>

int main(int argc, char* argv[])
{
	//New blockchain
	blockchain chain = blockchain();

	//We need some data to store on the chain
	std::vector<std::string> data;
	std::string info;

	//Placeholder data pushed to the vector
	info = "foo1";
	data.push_back(info);
	info = "foo2";
	data.push_back(info);
	info = "foo3";
	data.push_back(info);
	//Add the vector to a block and add it to the chain
	chain.addBlock(data);
	//Clear the data from the vector
	data.clear();

	//And Repeat
	info = "bar1";
	data.push_back(info);
	info = "bar2";
	data.push_back(info);
	info = "bar3";
	data.push_back(info);
	chain.addBlock(data);
	data.clear();


	std::cin.ignore();
}
