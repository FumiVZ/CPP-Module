#include "Base.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base::Base(Base const &src)
{
	*this = src;
}

Base &Base::operator=(Base const &src)
{
	(void)src;
	return *this;
}

Base *Base::generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "Generate: A" << std::endl;
		return new A;
	}
	else if (random == 1)
	{
		std::cout << "Generate: B" << std::endl;
		return new B;
	}
	std::cout << "Generate: C" << std::endl;
	return new C;
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &bc)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &bc)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
