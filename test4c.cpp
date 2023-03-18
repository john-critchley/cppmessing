#include <stdio.h>
#include <time.h>
#include <vector>
#include <memory>

#define DEL delete
#define LINE puts("------------")

typedef class a
{
public:
	a(void)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	a(const class a & that)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	virtual ~a()
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	virtual void print(void) const
		= 0;
	const class a & me(void) const
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
		return *this;
	}
	virtual class a * another(void) const
		= 0;
} * my_a_type;
class ab:public a
{
	time_t tm;
public:
	void print(void) const
	{	puts("AB");
		printf("%ld\n", tm);
	}
	ab(const class ab & that)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
		tm=that.tm;
	}
	ab(void)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
		tm=time(0);
	}
	~ab()
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	virtual class a * another(void) const
	{	return new ab(*this);
	}
};
class ac:public a
{
public:
	void print(void) const
	{	puts("AC");
	}
	ac(const class ac & that)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	ac(void)
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	~ac()
	{	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
	}
	virtual class a * another(void) const
	{	return new ac();
	}
};
class my
{
public:
	my(void)
	{
		std::vector<a *> vec_a={new ab, new ac};
		std::vector<a *> vec_b;
		for (a * i: vec_a)
			vec_b.push_back(i->another());
		for (a * i: vec_a)
			i->print();
		LINE;
		for (a * i: vec_b)
			i->print();
		LINE;
		for (a * i: vec_a)
			DEL i;
		for (a * i: vec_b)
			DEL i;
	}
} static my;
int main(int argc, char * * argv)
{
	printf("%s %d %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__);
}
