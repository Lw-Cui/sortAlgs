#ifndef _QSORT_H_
#define _QSORT_H_
#include <vector>

extern "C" {
    void sort(std::vector<int> &array);
    const char *self();
}
#endif
