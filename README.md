Ltrace and LD_DEBUG example project
========================================

Build
======

libmy.so
---------
g++ -Wall -std=c++11 -shared -fPIC -o libplugin.so plugin.cpp

libplugin.so
--------------
g++ -Wall -std=c++11 -shared -fPIC -o libplugin.so plugin.cpp

main
-----
export LD_LIBRARY_PATH=`pwd`
g++ -Wall -std=c++11 -O3 main.cpp -s -o main libmy.so -ldl

Tracing
========
LD_BIND_NOW='true' LD_DEBUG_OUTPUT=~/Projects/libso/ld_debug.txt LD_DEBUG=all ltrace -n 2 -a 200 -A 200 -C -f -i -o ~/Projects/libso/trace.txt -s 200 -S ./main
