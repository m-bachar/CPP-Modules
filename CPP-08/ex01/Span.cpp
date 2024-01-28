#include "Span.hpp"

Span::Span()
{
	std::cout << GREEN << " * Span " << RESET << "default constructor called !" << std::endl;
	N_ = N;
}

Span::Span(unsigned int N__)
{
	std::cout << GREEN << " * Span " << RESET << "parametrized constructor called !" << std::endl;
	N_ = N__;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	N_ = obj.N_;
	lst = obj.lst;
	return *this;
}

void Span::addNumber(int nbr)
{
	int	i = lst.size();
	if (i >= (int)N_)
		throw TooManyElementsException();
	lst.push_back(nbr);
}

int Span::shortestSpan()
{
	if (lst.empty() || lst.size() == 1)
		throw NoElementsFoundException();

	lst.sort();
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator it_ = lst.begin();
	it_++;
	int diff = *it_ - *it;
	it_ = lst.begin();
	for (it_++; it_ != lst.end(); it_++)
	{
		std::distance(lst.begin(), it);
		std::distance(lst.begin(), it_);
		if (*it_ - *it < diff)
			diff = *it_ - *it;
		it++;
	}
	return diff;
}

int Span::longestSpan()
{
	if (lst.empty() || lst.size() == 1)
		throw NoElementsFoundException();

	lst.sort();
	return lst.back() - lst.front();
}

void Span::addNumbers(std::list<int> cont)
{
	if (cont.size() + lst.size() > N_)
		throw TooManyElementsException();
	lst.insert(lst.begin(), cont.begin(), cont.end());
}

Span::~Span()
{
	std::cout << RED << " * Span " << RESET << "destructor called !" << std::endl;
}
