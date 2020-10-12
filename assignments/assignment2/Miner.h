#ifndef MINER_H
#define MINER_H

#include <string>
#include <fstream>

class Miner
{
public:
	Miner(int id, const std::string& resource);
	virtual ~Miner() = default;
	
	void start(std::ofstream& file) const;
	void stop(std::ofstream& file) const;
	virtual void detect(std::ofstream& file) const = 0;
	virtual void collect(std::ofstream& file) const = 0;
protected:
	int id;
	std::string resource;
};

#endif
