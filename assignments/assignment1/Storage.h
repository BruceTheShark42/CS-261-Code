#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <algorithm>

template<typename T>
class Storage
{
public:
	Storage(const std::string& name)
		: name(name) {}
	
	inline std::vector<T>& get() { return data; }
	inline const std::vector<T>& get() const { return data; }
	
	inline void add(const std::string& dataName) { data.emplace_back(dataName); }
	inline void remove(const std::string& dataName) { auto it = std::find(data.begin(), data.end(), dataName); if (it != data.end()) data.erase(it); }
	inline bool has(const std::string& dataName) const { return std::find(data.begin(), data.end(), dataName) != data.end(); }
	
	inline T& get(const std::string& dataName) { return *std::find(data.begin(), data.end(), dataName); }
	inline const T& get(const std::string& dataName) const { return *std::find(data.begin(), data.end(), dataName); }
	
	inline const std::string& getName() const noexcept { return name; }
	
	inline bool operator==(const Storage& storage) const noexcept { return name == storage.name; }
	inline bool operator<(const Storage& storage) const noexcept { return name < storage.name; }
private:
	std::string name;
	std::vector<T> data;
};

#endif
