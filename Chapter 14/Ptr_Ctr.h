#ifndef GUARD_Ptr
#define GUARD_Ptr

typedef unsigned long long size_t;

class Counter {
public:
    Counter(): refptr(new size_t(1)) { }
    Counter(size_t s): refptr(new size_t(s)) { }
    Counter(const Counter& c): refptr(new size_t(*c.refptr)) { }
    ~Counter() { if (*--refptr == 0) delete refptr; }

    operator size_t() const { return *refptr; }

    Counter& operator=(const Counter& rhs) {
        if(refptr == 0)
            delete refptr;
        refptr = rhs.refptr;
        return *this;
    }

    Counter& operator++() {
        if(!refptr)
            refptr = new size_t(1);
        else
            ++*refptr;
        return *this;
    }

    Counter operator++(int) { 
        Counter ret(*this);
        if(!refptr)
            refptr = new size_t(1);
        else
            ++*refptr;
        return ret;
    }

    Counter& operator--() {
        if(--*refptr == 0)
            delete refptr;
        return *this;
    }

    Counter operator--(int) { 
        Counter ret(*this);
        if(--*refptr == 0)
            delete refptr;
        return ret;
    }
private:
    size_t* refptr;
};

// code is taken from §14.3/263
template <class T> class Ptr {
public:
    void make_unique() {
        if (ctr != 1) {
            --ctr;
            p = p? clone(p): 0;
        }
    }

    Ptr(): p(0), ctr(1) { }
    Ptr(T* t): p(t), ctr(1) { }
    Ptr(const Ptr& h): p(h.p), ctr(h.ctr) { ++ctr; }

    Ptr& operator=(const Ptr&);
    ~Ptr() { }
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

    bool operator==(const Ptr& rhs) { return rhs.p == this->p; }

private:
    T* p;
    Counter ctr;
};

// code is taken from §14.4.1/266
template <class T> T* clone(const T* tp)
{
    return tp->clone();
}

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    // free the left-hand side, destroying pointers if appropriate
    if (--ctr == 0) {
        delete p;
    }

    // copy the values from right-hand side
    p = rhs.p;
    ctr = rhs.ctr;
    
    return *this;
}
#endif