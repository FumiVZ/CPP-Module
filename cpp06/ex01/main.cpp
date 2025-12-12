#include "Serializer.hpp"

int main()
{
	Data originalData;
	originalData.value = 150;
	uintptr_t raw = Serializer::serialize(&originalData);
	Data *deserializedData = Serializer::deserialize(raw);

	std::cout << "Original value: " << originalData.value << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized value: " << deserializedData->value << std::endl;
	return 0;
}