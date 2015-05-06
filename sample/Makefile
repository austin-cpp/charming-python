PROJECT=sample

## Directory variables
self_dir          := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
cwd               := $(shell pwd)
BUILD_DIR         := $(cwd)/build
DIST_DIR          := $(cwd)/dist
project_build_dir := $(BUILD_DIR)/$(PROJECT)
project_dist_dir  := $(DIST_DIR)/$(PROJECT)

source_files := $(addprefix $(self_dir)src/, \
  task.cpp               \
  task_list.cpp          \
  task_list_observer.cpp \
)

all: build

build: | $(project_dist_dir)
	$(CXX) $(source_files) \
    -std=c++11 -fPIC \
    -Wall -Werror -pedantic \
    -I$(self_dir)include \
    -shared -o $(project_dist_dir)/libsample.so

$(project_build_dir) $(project_dist_dir):
	@mkdir -p $@

clean:
	@rm -rf $(project_build_dir) $(project_dist_dir)

.PHONY: all build clean