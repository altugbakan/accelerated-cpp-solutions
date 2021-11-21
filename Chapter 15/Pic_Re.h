#ifndef GUARD_Pic
#define GUARD_Pic

#include <iostream>
#include "../Chapter 14/Ptr.h"
#include "../Chapter 12/Vec.h"
#include "../Chapter 12/Str.h"

class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    // no public interface (except for the destructor)
    typedef Vec<Str>::size_type ht_sz;
    typedef Str::size_type wd_sz;

    // this class is an abstract base class
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
    virtual ~Pic_base() { }
    virtual void reframe(const char, const char, const char) = 0; // Q4

protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
        while (beg != end) {
            os << " ";
            ++beg;
        }
    }
};

class Frame_Pic: public Pic_base {
    friend Picture frame(const Picture&, const char,
    const char, const char);

    char tb, lr, c; // Q2, Q3

    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic, const char bordertb,
        const char borderlr, const char borderc):
        p(pic), tb(bordertb), lr(borderlr), c(borderc) { }
    
    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(const char, const char, const char); // Q4
};

class VCat_Pic: public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):
        top(t), bottom(b) { }

    wd_sz width() const
        { return std::max(top->width(), bottom->width()); }
    ht_sz height() const
        { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(const char, const char, const char); // Q4
};

class HCat_Pic: public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):
        left(l), right(r) { }

    wd_sz width() const { return left->width() + right->width(); };
    ht_sz height() const
        { return std::max(left->height(), right->height()); }
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(const char, const char, const char); // Q4
};

class String_Pic: public Pic_base {
    friend class Picture;
    Vec<Str> data;
    String_Pic(const Vec<Str>& v): data(v) { }

    ht_sz height() const { return data.size(); }
    wd_sz width() const;
    void display(std::ostream&, ht_sz, bool) const;
    void reframe(const char, const char, const char) { } // Q4
};

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&, const char,
        const char, const char);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);

public:
    Picture(const Vec<Str>& =
        Vec<Str>());
    void reframe(const char bordertb, const char borderlr,
        const char borderc) { p->reframe(bordertb, borderlr, borderc); } // Q4
private:
    Picture(Pic_base* ptr): p(ptr) { }
    Ptr<Pic_base> p;
};

Picture frame(const Picture&, const char = '*',
    const char = '*', const char = '*'); // Q03
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif