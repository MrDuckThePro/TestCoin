#include <blockchain.h>

/// <summary>Constructor for a new blockchain</summary>
blockchain::blockchain()
{
	//As soon as we start our new blockchain, we generate the first block,
	//as it can't have a previous hash, and we push it to the chain
	blocks.push_back(createGenesisBlock());
}

/// <summary>Retrieve last block in the chain</summary>
/// <returns>Last block of the chain</returns> 
block blockchain::getLatestBlock()
{
	//We need to know the last block before adding a new one, as it needs the hash of the preious one
	return blocks[blocks.size() - 1];
}

/// <summary>Add new block to the chain</summary>
/// <param name="index">Data to be stored</param>  
void blockchain::addBlock(std::vector<std::string> data)
{
	//Just generate a new block with the data we want and the hash of the last block
	block newBlock = block(blocks.size(), std::time(0), getLatestBlock().getHash(), data);
	
	//Then we push it to the chain
	blocks.push_back(newBlock);
}

/// <summary>Check for the integrity of the chain</summary>
/// <returns>True for a valid blockchain, False if there is a mismatch in the hashes</returns> 
bool blockchain::isChainValid()
{
	//We check all the blocks in the chain to make sure all of them are valid by
	//comparing the hashes of them
	for(int i = 1; i < blocks.size(); i++)
	{
		block currentBlock = blocks[i];
		block previousBlock = blocks[i - 1];
		
		//Assigned hash and calculated hash should be the same
		if (currentBlock.getHash() != currentBlock.calculateHash()) 
		{
			return false;
		}
		
		//Check consistency of stored hashes through the blocks
		if (currentBlock.getPrevHash() != previousBlock.getHash())
		{
			return false;
		}

	}
	return true;

}
/// <summary>Generate the first block of a new chain</summary>
/// <returns>First block for a chain</returns> 
block blockchain::createGenesisBlock()
{
	//We use this function for making the first block of the chain, usin "Genesis Block" as
	// the hash of the "previous" non-existent block
	return block(0, std::time(0), "Genesis Block", (std::vector<std::string>) 0);
}