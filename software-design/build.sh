set -e
SCRIPT_DIR=$(dirname $0)
BUILD_DIR=$SCRIPT_DIR/build

pushd $SCRIPT_DIR
cmake -S . -B $BUILD_DIR -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./cmake/avr-gcc-toolchain.cmake
popd

pushd $BUILD_DIR
make
popd
