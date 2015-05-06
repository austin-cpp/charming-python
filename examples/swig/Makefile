PROJECT=swig

## Directory variables
self_dir          := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
cwd               := $(shell pwd)
BUILD_DIR         := $(cwd)/build
DIST_DIR          := $(cwd)/dist
project_build_dir := $(BUILD_DIR)/$(PROJECT)
project_dist_dir  := $(DIST_DIR)/$(PROJECT)

all: build

build: | $(project_build_dir) $(project_dist_dir)

	cd $(project_build_dir) && \
  swig -c++ -python -I/charming/sample/include -outcurrentdir -outdir $(project_dist_dir) $(self_dir)interface/sample.i
	$(CXX) $(project_build_dir)/sample_wrap.cxx \
    -std=c++11 -fPIC \
    -Wall -Werror -pedantic \
    -I$(cwd)/sample/include -I/opt/python-2.7/include/python2.7 \
    -L$(DIST_DIR)/sample -lsample \
    -shared -o $(project_dist_dir)/_sample.so
	cp $(DIST_DIR)/sample/libsample.so $(project_dist_dir)

$(project_build_dir) $(project_dist_dir):
	@mkdir -p $@

clean:
	@rm -rf $(project_build_dir) $(project_dist_dir)

.PHONY: all build clean