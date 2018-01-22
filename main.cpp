#include "lib.hpp"
#include "plugin.hpp"

#include <dlfcn.h>

int main(int, char **)
{
    void* handler = dlopen("libplugin.so", RTLD_NOW);
    char* error;

    if (0 == handler)
    {
        return 100;
    }

    dlerror();

    int (*plugin_function)();

    *(void**) (&plugin_function) = dlsym(handler, "plugin_function");

    if ((error = dlerror()) != 0)  {
        return 200;
    }

    const int plugin_result = (*plugin_function)();
    if (0 != dlclose(handler))
    {
        return 300;
    }
    return plugin_result + library_function();
}

