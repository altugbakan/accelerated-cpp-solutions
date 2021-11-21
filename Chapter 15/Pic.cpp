#include <iostream>
#include <vector>
#include <string>
#include "Pic.h"

using std::ostream;
using std::endl;
using std::vector;
using std::string;

// code is taken from §15.2.1/279
Picture frame(const Picture& pic, char bordertb,
    char borderlr, char borderc)
{
    return new Frame_Pic(pic.p, bordertb, borderlr, borderc);
}

// code is taken from §15.2.1/280
Picture hcat(const Picture& l, const Picture& r)
{
    return new HCat_Pic(l.p, r.p);
}

// code is taken from §15.2.1/280
Picture vcat(const Picture& t, const Picture& b)
{
    return new VCat_Pic(t.p, b.p);
}

// code is taken from §15.2.1/280
Picture::Picture(const vector<string>& v): p(new String_Pic(v)) { }

// code is taken from §15.2.1/280
ostream& operator<<(ostream& os, const Picture& picture)
{
    const Pic_base::ht_sz ht = picture.p->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
        picture.p->display(os, i, false);
        os << endl;
    }
    return os;
}

// code is taken from §15.2.2/281
Pic_base::wd_sz String_Pic::width() const
{
    Pic_base::wd_sz n = 0;
    for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
        n = std::max(n, data[i].size());
    return n;
}

// code is taken from §15.2.2/282
void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    wd_sz start = 0;

    // write the row if we're still in range
    if (row < height()) {
        os << data[row];
        start = data[row].size();
    }

    // pad the output if necessary
    if (do_pad)
        pad(os, start, width());
}

// code is taken from §15.2.4/284
void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    wd_sz w = 0;
    if (row < top->height()) {
        // we are in the top subpicture
        top->display(os, row, do_pad);
        w = top->width();
    } else if (row < height()) {
        // we are in the bottom subpicture
        bottom->display(os, row - top->height(), do_pad);
        w = bottom->width();
    }
    if (do_pad)
        pad(os, w, width());
}

// Q5
void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    if (left->height() >= right->height())
    {
        // find the difference
        ht_sz diff = left->height() - right->height();

        // display left since it is larger
        left->display(os, row, do_pad);

        // display right if placement is correct
        if (row >= diff / 2)
            right->display(os, row - diff / 2, do_pad);
    } else {
        // find the difference
        ht_sz diff = right->height() - left->height();

        // display left if placement is correct,
        // or display the padding
        if (row >= diff / 2)
            left->display(os, row - diff / 2, true);
        else
            left->display(os, left->height(), true);

        // display right since it is larger
        right->display(os, row, do_pad);
    }
}

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
    if (row >= height()) {

        // out of range
        if (do_pad)
            pad(os, 0, width());

    } else {
        if (row == 0 || row == height() - 1) {
            
            // top or bottom row
            os << c << string(width() - 2, tb) << c; // Q2

        } else if (row == 1 || row == height() - 2) {

            // second from top or bottom row
            os << lr; // Q2
            pad(os, 1, width() - 1);
            os << lr; // Q2

        } else {

            // interior row
            os << lr << " "; // Q2
            p->display(os, row - 2, true);
            os << " " << lr; // Q2

        }
    }
}

// Q4
void Frame_Pic::reframe(const char bordertb, const char borderlr,
    const char borderc)
{
    tb = bordertb;
    lr = borderlr;
    c = borderc;

    p->reframe(bordertb, borderlr, borderc);
}

// Q4
void HCat_Pic::reframe(const char bordertb, const char borderlr,
    const char borderc)
{
    left->reframe(bordertb, borderlr, borderc);
    right->reframe(bordertb, borderlr, borderc);
}

// Q4
void VCat_Pic::reframe(const char bordertb, const char borderlr,
    const char borderc)
{
    top->reframe(bordertb, borderlr, borderc);
    bottom->reframe(bordertb, borderlr, borderc);
}