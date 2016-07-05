#ifndef _INTERFACE_
#define _INTERFACE_
#include <vector>
extern "C" {
    void sort(std::vector<int> &array);
    const char *self();
}
#endif
