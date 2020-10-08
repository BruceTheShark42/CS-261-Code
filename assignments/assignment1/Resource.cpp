#include "Resource.h"

Resource::Resource(const std::string& name)
	: name(name), total(0)
{
	for (int i = 0; i < 12; i++)
		months[i] = 0;
}

Resource::Resource(const Resource& resource)
	: name(resource.name), total(resource.total)
{
	for (int i = 0; i < 12; i++)
		months[i] = resource.months[i];
}

Resource& Resource::operator=(const Resource& resource)
{
	if (this != &resource)
	{
		name = resource.name;
		total = resource.total;
		
		for (int i = 0; i < 12; i++)
			months[i] = resource.months[i];
	}
	return *this;
}
