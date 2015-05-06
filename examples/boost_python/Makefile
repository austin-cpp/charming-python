PROJECT=boost_python

## Directory variables
self_dir          := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
cwd               := $(shell pwd)
BUILD_DIR         := $(cwd)/build
DIST_DIR          := $(cwd)/dist
project_build_dir := $(BUILD_DIR)/$(PROJECT)
project_dist_dir  := $(DIST_DIR)/$(PROJECT)

source_files := $(addprefix $(self_dir)src/, \
  sample.cpp             \
  task.cpp               \
  task_list.cpp          \
  task_list_observer.cpp \
)

all: build

build: | $(project_build_dir) $(project_dist_dir)

	$(CXX) $(source_files) \
    -std=c++11 -fPIC \
    -Wall -Werror -pedantic \
    -I$(cwd)/sample/include -I/opt/python-2.7/include/python2.7 -isystem/opt/boost/include \
    -L$(DIST_DIR)/sample -L/opt/boost/lib \
    -lsample -lboost_python \
    -shared -o $(project_dist_dir)/sample.so
	cp $(DIST_DIR)/sample/libsample.so $(project_dist_dir)
	cp /opt/boost/lib/libboost_python.so.1.57.0 $(project_dist_dir)

$(project_build_dir) $(project_dist_dir):
	@mkdir -p $@

clean:
	@rm -rf $(project_build_dir) $(project_dist_dir)

.PHONY: all build clean