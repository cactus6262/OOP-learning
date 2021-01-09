#ifndef SHAREDPTR_HPP
#define SHAREPTR_HPP
void testSharedPtr();
class Counter
{
public:
	Counter();
	Counter(const Counter& other) = delete;
	Counter& operator=(const Counter& other) = delete;
	~Counter();

	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
	int getCount() const;

private:
	int m_count;
};

template <typename T>
class Shared_Ptr
{
public:
	Shared_Ptr();
	Shared_Ptr(T* ptr);
	Shared_Ptr(const Shared_Ptr<T>& other);
	Shared_Ptr& operator=(const Shared_Ptr<T>& other);
	T* getPtr() const;
	T& operator*();
	T* operator->();
	~Shared_Ptr();
private:
	Counter* m_counter;
	T* m_ptr;
};
#endif
