BUILD_TOOL = ninja
CMAKE_GENERATOR = Ninja
CMAKE_BUILD_TYPE ?= Debug
CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE)

.PHONY: all
all: pycrab

.PHONY: pycrab
pycrab: build/.ran-cmake
	$(BUILD_TOOL) -C build

build/.ran-cmake:
	mkdir -p build
	touch $@
	cd build && cmake -G $(CMAKE_GENERATOR) $(CMAKE_FLAGS) ../

.PHONY: test
test: pycrab test/pycrab.so
	pytest test

test/pycrab.so:
	ln -sr build/pycrab.so test/pycrab.so

clean:
	$(BUILD_TOOL) -C build clean

distclean:
	rm -rf build
	rm -rf test/*.so
