#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Base
{
public:
	Base();
	virtual ~Base();
	Base(Base const &src);
	Base &operator=(Base const &src);
	void identify(Base *p);
	void identify(Base &p);
	Base *generate(void);
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
