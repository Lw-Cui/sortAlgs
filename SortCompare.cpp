#include <cassert>
#include <ctime>
#include <random>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <regex>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
using namespace std;
typedef void (*Mp)(vector<int> &);
typedef const char *(*Self)();
const char *ALGS = "sort";
const char *NAME = "self";
const char *LIBDIR = "./lib";

void load_handle(std::vector<void *> &handle, const char *dir) {
    void *lib_handle = NULL;
    DIR *pDir;
    char lib_name[100];
    struct dirent* ptr;
    if (!(pDir = opendir(dir))) return;
    const regex pattern("lib(\\w+).so");
    while ((ptr = readdir(pDir)) != NULL)
        if (regex_match(ptr->d_name, pattern)) {
            int n = snprintf(lib_name, sizeof(lib_name), "%s/%s", dir, ptr->d_name);
            if (n < 0 || (lib_handle = dlopen(lib_name, RTLD_NOW)) == NULL) {
                printf("Open Error %s\n", dlerror());
            } else {
                handle.push_back(lib_handle);
            }
        }
    closedir(pDir);
}

void load_handle(vector<void *> &handle, int num, char *so[]) {
    void *lib_handle = NULL;
	char lib_name[100];
    for (int i = 0; i < num; i++) {
		int n = snprintf(lib_name, sizeof(lib_name), "lib%s.so", so[i] + 2);
		assert(n >= 0 && "overflow");
        if ((lib_handle = dlopen(lib_name, RTLD_NOW)) == NULL) {
            printf("Open Error %s\n", dlerror());
            continue;
        }
        handle.push_back(lib_handle);
    }
}

void load_algs(vector<void *> &handle, vector<pair<Self, Mp> > &algs) {
    Mp method = NULL;
    Self self = NULL;

    for (size_t i = 0; i < handle.size(); i++) {
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
    for (size_t i = 0; i < handle.size(); i++)
        dlclose(handle[i]);
    handle.clear();
}

bool is_correct(vector<int> &array, long long check_sum) {
    for (size_t i = 1; i < array.size(); i++)
        if (array[i - 1] > array[i])
            return false;

	long long sum = 0;
	for (size_t i = 0; i < array.size(); i++)
		sum += array[i];

	return sum == check_sum? true: false;
}

vector<int> random(int num) {
    default_random_engine generator;
#if BINOMIAL
    binomial_distribution<int> distribution(num);
#elif POISSON
    poisson_distribution<int> distribution(num / 3);
#else
    uniform_int_distribution<int> distribution(1,num);
#endif
    auto dice = bind (distribution, generator);
    vector<int> random_variable;

    while (num--) 
        random_variable.push_back(dice());

    return random_variable;
}

int main(int argc, char *argv[]) {
    //if (argc < 3) return 0;

    vector<pair<Self, Mp> > algs;
    vector<void *> handle;

    //load_handle(handle, argc - 1, argv + 1);
    load_handle(handle, LIBDIR);
    load_algs(handle, algs);

    for (int num = 1; num < 10; num += 3) {
        multimap<double, const char *> res;
        vector<int> origin = random(num * 10000);

		long long check_sum = 0;
		for (size_t i = 0; i < origin.size(); i++)
			check_sum += origin[i];
        printf("\nFor %d integers\n", num * 10000);

        for (size_t i = 0; i < algs.size(); i++) {
            vector<int> data = origin;

            clock_t start = clock();
            (*algs[i].second)(data);
            clock_t finish = clock();

            if (is_correct(data, check_sum))
                res.insert(make_pair((double)(finish - start) / CLOCKS_PER_SEC,
                            (*algs[i].first)()));
        }

        typedef multimap<double, const char *>::iterator multip;
        for (multip p = res.begin(); p != res.end();) {
            multip last = p++;
            if (p == res.end()) break;
            printf("    %s is %.2f times faster than %s\n",
                    last->second, p->first / last->first, p->second);
        }
    }

    destruct_handle(handle);
    return 0;
}
