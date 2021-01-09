#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

/*
&& is new in C++11. int&& a means "a" is an r-value reference. && is normally only used to declare a parameter of a function. And it only takes a r-value expression. If you don't know what an r-value is, the simple explanation is that it doesn't have a memory address. E.g. the number 6, and character 'v' are both r-values. int a, a is an l-value, however (a+2) is an r-value. For example:

void foo(int&& a)
{
//Some magical code...
}

int main()
{
int b;
foo(b); //Error. An rValue reference cannot be pointed to a lValue.
foo(5); //Compiles with no error.
foo(b+3); //Compiles with no error.

int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
int&& d = 5; //Compiles with no error.
}
*/

#if 1 //this example is used to demonstrate how to use unique_ptr from the C++ STL
class Tony {
public:
	string GetFullName() {
		return "Tony " + last_name_;
	}
	void SetLastName(string lastname) {
		last_name_ = lastname;
	}
private:
	string last_name_;
};

class Movie {
public:
	unique_ptr<Tony> MakeTony() {
		auto tony_ptr = make_unique<Tony>();
		auto attached_tony_ptr = AttachActor(move(tony_ptr));
		return attached_tony_ptr;
	}
	vector<string> GetActorsList() {
		return actors_list_;
	}

private:
	unique_ptr<Tony> AttachActor(unique_ptr<Tony> tony_ptr) {
		tony_ptr->SetLastName("Garcia");
		actors_list_.push_back(tony_ptr->GetFullName());
		return tony_ptr;   // Implicit move
	}

	vector<string> actors_list_;
};


int testUniquePtr(int argc, char** argv) {
	auto movie = make_unique<Movie>();
	auto tony = movie->MakeTony();
	cout << "Newly added: " << tony->GetFullName() << endl;
	for (const auto& actor_name : movie->GetActorsList()) {
		cout << "Movie actors: " << actor_name << endl;
	}
}

#else  //user-defined unique_ptr

/*
Link:  http://www.vishalchovatiya.com/unique_ptr-with-example-in-c/
std::unique_ptr is the C++11 replacement for std::auto_ptr. It is used to manage use to manage any dynamically allocated object not shared 
by multiple objects. That is, std::unique_ptr should completely own the object it manages, not share that ownership with other classes.

We can convert our smart_ptr we designed above into std::unique_ptr. And for that one thing, we can do is delete the 
copy constructor & assignment operator so that no one can copy smart pointer.

As we are not allowing a copy of smart pointer we can’t pass our smart pointer to any function by value or return by value.
And this is not good design.

To pass or return by value, we can add move constructor & move assignment operator, so that while passing or returning by value,
we would have to transfer ownership through move semantics. This way we can also ensure single ownership throughout the lifetime of the object.
*/
template<class T>
class smart_ptr
{
	T* m_ptr;
public:
	smart_ptr(T* ptr = nullptr) : m_ptr(ptr) {}
	~smart_ptr()
	{
		delete m_ptr;
	}
	// Copy constructor
	smart_ptr(const smart_ptr& a) = delete;
	// Move constructor
	smart_ptr(smart_ptr&& a) : m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}
	// Copy assignment
	smart_ptr& operator=(const smart_ptr& a) = delete;
	// Move assignment
	smart_ptr& operator=(smart_ptr&& a)
	{
		if (&a == this)
			return *this;
		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
smart_ptr<Resource> func(smart_ptr<Resource> temp)
{
	// Do something
	return temp;
}
int testUniquePtr()
{
	smart_ptr<Resource> res1(new Resource);
	// smart_ptr<Resource> res3 = res1; // Won't compile, as copy contructor is deleted
	smart_ptr<Resource> res3 = func(std::move(res1)); // calls move semantics
	return 0;
}

#endif

#endif