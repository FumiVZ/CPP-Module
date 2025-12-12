#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int value;
};

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &src);
	public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
