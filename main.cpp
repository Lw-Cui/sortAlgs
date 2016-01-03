#include <dlfcn.h>
#include <vector>
#include <cstdio>
using namespace std;
typedef void (*Mp)(void);

void load_handle(vector<void *> &handle, int num, char *so[]) {
    void *lib_handle = NULL;
    for (int i = 0; i < num; i++) {
        if ((lib_handle = dlopen(so[i], RTLD_NOW)) == NULL) {
            printf("Open Error %s\n", dlerror());
            continue;
        }
        handle.push_back(lib_handle);
    }
}

void load_algs(vector<void *> &handle, vector<Mp> &algs, char *func) {
    Mp method = NULL;

    for (int i = 0; i < handle.size(); i++) {
        if ((method = (Mp)dlsym(handle[i], func)) == NULL) {
            printf("Open Error %s\n", dlerror());
            continue;
        }
        algs.push_back(method);
    }
}

void destruct_handle(vector<void *> &handle) {
    for (int i = 0; i < handle.size(); i++)
        dlclose(handle[i]);
    handle.clear();
}

int main(int argc, char *argv[]) {
    vector<Mp> algs;
    vector<void *> handle;

    if (argc < 3) return 0;

    load_handle(handle, argc - 2, argv + 2);
    load_algs(handle, algs, argv[1]);

    for (int i = 0; i < algs.size(); i++)
        (*algs[i])();

    destruct_handle(handle);

    return 0;
}
