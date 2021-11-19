#ifndef GUARD_Ptr
#define GUARD_Ptr

// code is taken from §14.3/263
template <class T> class Ptr {
public:
    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p? clone(p): 0;
        }
    }

    Ptr(): p(0), refptr(new size_t(1)) { }
    Ptr(T* t): p(t), refptr(new size_t(1)) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }

    Ptr& operator=(const Ptr&);
    ~Ptr() {
        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }
    }
    operator bool() const { return p; }
    T& operator*() const {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ptr");
    }
    T* operator->() const {
        if (p)
            return p;
        throw std::runtime_error("unbound Ptr");
    }

private:
    T* p;
    std::size_t* refptr;
};

// code is taken from §14.4.1/266
template <class T> T* clone(const T* tp)
{
    return tp->clone();
}

// code is taken from §14.2/261, modified for Ptr
template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    ++*rhs.refptr;
    // free the left-hand side, destroying pointers if appropriate
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // copy the values from right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}
#endif