#include <dlfcn.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstdio>
using namespace std;
typedef void (*Mp)(vector<int> &);
typedef const char *(*Self)();
const char *ALGS = "sort";
const char *NAME = "self";

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

void load_algs(vector<void *> &handle, vector<pair<Self, Mp> > &algs) {
    Mp method = NULL;
    Self self = NULL;

    for (int i = 0; i < handle.size(); i++) {
        if ((self = (Self)dlsym(handle[i], NAME)) == NULL) {
            printf("Open Error %s\n", dlerror());
            continue;
        }

        if ((method = (Mp)dlsym(handle[i], ALGS)) == NULL) {
            printf("Open Error %s\n", dlerror());
            continue;
        }
        algs.push_back(make_pair(self, method));
    }
}

void destruct_handle(vector<void *> &handle) {
    for (int i = 0; i < handle.size(); i++)
        dlclose(handle[i]);
    handle.clear();
}

bool is_correct(vector<int> &array) {
    for (int i = 1; i < array.size(); i++)
        if (array[i - 1] > array[i])
            return false;
    return true;
}

vector<int> random(int num) {
    vector<int> random_variable;

    srand(time(NULL));
    while (num--) 
        random_variable.push_back(rand());

    return random_variable;
}

int main(int argc, char *argv[]) {
    if (argc < 3) return 0;

    vector<pair<Self, Mp> > algs;
    vector<void *> handle;

    load_handle(handle, argc - 1, argv + 1);
    load_algs(handle, algs);

    
    vector<int> origin = random(5000);

    for (int i = 0; i < algs.size(); i++) {
        vector<int> data = origin;
        (*algs[i].second)(data);

        /*
        for (int i = 0; i < data.size(); i++)
            printf("%d ", data[i]);
        */

        const char *name = (*algs[i].first)();
        if (is_correct(data))
            printf("%s Success!\n", name);
        else 
            printf("%s Failed.\n", name);
    }

    destruct_handle(handle);
    return 0;
}
