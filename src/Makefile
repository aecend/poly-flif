# CXXFLAGS := $(shell pkg-config --cflags zlib libpng)
# LDFLAGS := $(shell pkg-config --libs zlib libpng)

CXX=em++

EM_SCRIPT_OPTIONS=-s EXPORTED_FUNCTIONS='["_mainy"]' -s TOTAL_MEMORY=100000000 --js-library flif-library.js

# optimisation options
EM_SCRIPT_OPTIONS+= -s NO_FILESYSTEM=1 -s NO_BROWSER=1
EM_SCRIPT_OPTIONS+= -s NODE_STDOUT_FLUSH_WORKAROUND=0 -s INVOKE_RUN=0
EM_SCRIPT_OPTIONS+= -s ASSERTIONS=0
EM_SCRIPT_OPTIONS+= --closure 1
EM_SCRIPT_OPTIONS+=-s ASM_JS=2

#EM_SCRIPT_OPTIONS+=-s MODULARIZE=1
EM_SCRIPT_OPTIONS+=-s AGGRESSIVE_VARIABLE_ELIMINATION=1
EM_SCRIPT_OPTIONS+=-s RUNNING_JS_OPTS=1
EM_SCRIPT_OPTIONS+=-s DISABLE_EXCEPTION_CATCHING=1
EM_SCRIPT_OPTIONS+=-s NO_EXIT_RUNTIME=1
EM_SCRIPT_OPTIONS+= -s USE_SDL=0
EM_SCRIPT_OPTIONS+=--memory-init-file 0

CXXFLAGS += ${EM_SCRIPT_OPTIONS}

em-out/flif.html: maniac/*.hpp maniac/*.cpp image/*.hpp image/*.cpp transform/*.hpp transform/*.cpp flif-em.cpp flif-enc.cpp flif-dec.cpp common.cpp flif-enc.hpp flif-dec.hpp common.hpp flif_config.h fileio.hpp bufferio.h io.hpp io.cpp config.h Makefile flif-library.js
	${CXX} -std=gnu++11 $(CXXFLAGS) $(LDFLAGS) -DDECODER_ONLY -DNDEBUG -Oz -g0 -Wall maniac/chance.cpp image/color_range.cpp transform/factory.cpp flif-em.cpp common.cpp flif-dec.cpp io.cpp image/crc32k.cpp -o em-out/flif.html

