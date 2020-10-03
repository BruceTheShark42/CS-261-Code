#ifndef CATEGORY_H
#define CATEGORY_H

#include <unordered_map>
#include <vector>

#include <tuple>

// I originally had the value type hardcoded to an entry
// But I thought it would be worth it to abstract it that
// much more so it could be used for more than just entries.
template<typename K, typename V>
class Category
{
public:
	inline void add(const K& key, size_t index) noexcept { indices[key].push_back(index); }
	
	std::vector<V> get(const K& key, const std::vector<V>& entries) const
	{
		const auto& keyIndices = indices[key];
		
		std::vector<V> values;
		values.reserve(keyIndices.size());
		
		for (const auto index : keyIndices)
			values.push_back(entries[index]);
		
		return values;
	}
private:
	std::unordered_map<K, std::vector<size_t>> indices;
	
	//friend class Collection<V>;
};

template<typename... TS>
class Collection : public std::tuple<TS...>
{

};

#endif

