#ifndef MINER_H
#define MINER_H

#include <string>

class Miner
{
public:
	Miner(int id, const std::string& resource);
	virtual ~Miner() = default;
	
	void start() const;
	void stop() const;
	virtual void detect() const = 0;
	virtual void collect() const = 0;
protected:
	int id;
	std::string resource;
};

#endif
