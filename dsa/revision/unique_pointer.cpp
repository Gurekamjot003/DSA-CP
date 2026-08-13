#include <iostream>
#include <string>
#include <utility>
using namespace std;

// A simplified version of std::unique_ptr
// It owns a dynamically allocated object and deletes it automatically.

template <typename T>
class UniquePtr
{
private:
    T *ptr; // raw pointer that this class owns

public:
    // 1) Constructor
    // Creates a unique pointer and takes ownership of an existing raw pointer.
    explicit UniquePtr(T *p = nullptr) : ptr(p) {}

    // 2) Copy constructor and copy assignment are disabled.
    // A unique pointer must have only one owner, so copying is not allowed.
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // Example of disabled copy usage (kept as comment for revision):
    // UniquePtr<int> a(new int(10));
    // UniquePtr<int> b = a;      // error: copy constructor is deleted
    // a = b;                    // error: copy assignment is deleted

    // 3) Move constructor
    // Transfers ownership from another unique pointer without copying.
    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    // 4) Move assignment
    // Releases current ownership, then takes ownership from another unique pointer.
    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;      // free old memory
            ptr = other.ptr; // take ownership
            other.ptr = nullptr;
        }
        return *this;
    }

    // 5) Destructor
    // Automatically deletes the owned object when the unique pointer goes out of scope.
    ~UniquePtr()
    {
        delete ptr;
    }

    // 6) Dereference operator
    // Allows us to use *ptr as if it were a normal object.
    T &operator*() const
    {
        return *ptr;
    }

    // 7) Arrow operator
    // Useful for accessing members of an object pointed to by ptr.
    T *operator->() const
    {
        return ptr;
    }

    // 8) get()
    // Returns the raw pointer without releasing ownership.
    T *get() const
    {
        return ptr;
    }

    // 9) release()
    // Gives up ownership and returns the raw pointer.
    // The caller becomes responsible for deleting it.
    T *release()
    {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // 10) reset()
    // Deletes the current object and replaces it with a new one.
    void reset(T *p = nullptr)
    {
        delete ptr;
        ptr = p;
    }

    // 11) bool conversion
    // Checks whether the pointer is holding something valid.
    explicit operator bool() const
    {
        return ptr != nullptr;
    }
};

// Example class for operator-> demo
struct Person
{
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

int main()
{
    // Constructor example
    UniquePtr<int> p(new int(42));
    cout << "Constructor: " << *p << "\n";

    // Move constructor example
    UniquePtr<int> q = move(p);
    cout << "Move constructor: " << *q << "\n";

    // Move assignment example
    UniquePtr<int> r(new int(100));
    r = move(q);
    cout << "Move assignment: " << *r << "\n";

    // Dereference operator example
    cout << "Dereference: " << *r << "\n";

    // Arrow operator example
    UniquePtr<Person> person(new Person("Alice", 21));
    cout << "Arrow operator: " << person->name << " is " << person->age << "\n";

    // get() example
    Person *raw = person.get();
    cout << "get(): " << raw->name << "\n";

    // release() example
    Person *released = person.release();
    cout << "release(): " << released->name << "\n";
    delete released; // caller now owns and deletes this memory

    // reset() example
    UniquePtr<int> value(new int(7));
    value.reset(new int(99));
    cout << "reset(): " << *value << "\n";

    // bool conversion example
    if (value)
    {
        cout << "bool check: valid pointer\n";
    }

    return 0;
}
