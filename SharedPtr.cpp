#include "sharedPtr.h"

Counter::Counter() : m_count(0)
{
}

Counter::~Counter()
{
}

void Counter::operator++()
{
	m_count++;
}
void Counter::operator++(int)
{
	m_count++;
}
void Counter::operator--()
{
	m_count--;
}
void Counter::operator--(int)
{
	m_count--;
}
int Counter::getCount() const
{
	return m_count;
}

/* class definition for Shared_Ptr */
//default constructor
template <typename T>
Shared_Ptr<T>::Shared_Ptr() : m_ptr(0), m_counter(0)
{
	m_counter = new Counter();
	if (m_counter != NULL)
		(*m_counter)++;
}

//customerized constructor
template <typename T>
Shared_Ptr<T>::Shared_Ptr(T* ptr)
{
	m_ptr = ptr;
	m_counter = new Counter();
	if (m_counter != NULL)
		(*m_counter)++;
}

//copy constructor
template <typename T>
Shared_Ptr<T>::Shared_Ptr(const Shared_Ptr<T>& other)
{
	//if (other == *this) return *this;
	m_counter = other.m_counter;
	m_ptr = other.m_ptr;

	(*m_counter)++;
}

//assignment operator
template <typename T>
Shared_Ptr<T>& Shared_Ptr<T>::operator=(const Shared_Ptr<T>& other)
{
	if (this == &other) return *this;

	(*m_counter)--;
	if (m_counter->getCount() == 0)
	{
		delete m_counter;
		delete m_ptr;
	}

	m_counter = other.m_counter;
	m_ptr = other.m_ptr;

	(*m_counter)++;

	return *this;
}

//get function
template <typename T>
T* Shared_Ptr<T>::getPtr() const
{
	return m_ptr;
}

//deference
template <typename T>
T& Shared_Ptr<T>::operator*()
{
	return *m_ptr;
}

template <typename T>
T* Shared_Ptr<T>::operator->()
{
	return m_ptr;
}

template <typename T>
Shared_Ptr<T>::~Shared_Ptr()
{
	(*m_counter)--;
	if (m_counter->getCount() == 0)
	{
		delete m_counter;
		delete m_ptr;
	}
}

void testSharedPtr()
{

}