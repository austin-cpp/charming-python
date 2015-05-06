self_dir          := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all: build

compiler-image:
	docker build --tag charming/compiler $(self_dir)tools/compilers/gcc-4.9

python-image: compiler-image
	docker build --tag charming/python $(self_dir)tools/python/2.7

test-image: python-image
	docker build --rm --tag charming/tester $(self_dir)tools/tester

sample: compiler-image
	docker run --rm --volume $(self_dir):/charming --workdir /charming charming/compiler make -f sample/Makefile


example_targets :=

define example_template

$(1): $(1)-image $(1)-example $(1)-test

$(1)-image: python-image
	docker build --rm --tag charming/$(1) examples/$(1)/dockerfiles

$(1)-example: sample
	docker run --rm --volume $(self_dir):/charming --workdir /charming charming/$(1) make -f examples/$(1)/Makefile

$(1)-test: test-image
	docker run --rm --volume $(self_dir)dist/$(1):/charming/lib charming/tester

example_targets += $(1) $(1)-image $(1)-example $(1)-test

endef

examples = \
  boost_python \
  swig         \
  ${NULL}

$(foreach example, $(examples), \
  $(eval $(call example_template,$(example)) \
  ) \
)

build: $(examples)

clean:
	@rm -rf $(self_dir)build $(self_dir)dist


.PHONY: \
  clean \
  compiler-image python-image test-image \
  $(example_targets)
