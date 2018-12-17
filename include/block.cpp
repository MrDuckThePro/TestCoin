#include "block.h"

/// <summary>Constructor for a block</summary>
/// <param name="index">Position of the block in the blockchain</param>  
/// <param name="timestamp">Current UNIX timestamp of the block creation</param>  
/// <param name="prevHash">Hash of the previous block in the blockchain</param>  
/// <param name="data">Data to be stored in the block</param>  
block::block(int index, long timestamp, std::string prevHash, std::vector<std::string> data)
{
	//We add all the values to the block
	this->index = index;
	this->timestamp = timestamp;
	this->prevHash = prevHash;
	this->data = data;

	//We use all this data (minus the index) to generate a hash that identifies this block
	this->hash = calculateHash();
}

/// <summary>Calculate the hash of the current block with SHA256</summary>
/// <returns>Hexadecimal string with the hash of the current block</returns> 
std::string block::calculateHash()
{
	//First we need to convert the data vector into a string
	std::string dat;
	for (const auto &piece : data) dat += piece;

	//We create a string with all the info from the block to hash it
	std::string src_str = std::to_string(index) + prevHash + std::to_string(timestamp) + dat;


	//Then we hash it using the SHA256 algorithm implemented in picosha2 and we return it as an hexadecimal string
	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
	std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());

	return hex_str;
}

std::string block::getHash()
{
	return hash;
}

std::string block::getPrevHash()
{
	return prevHash;
}
