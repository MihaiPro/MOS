export PREFIX="/home/mihai/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

export AS=$TARGET-as
export CC=$TARGET-gcc

export KERN_DIR="kernel"
export K_ARCH_DIR="$KERN_DIR/arch"
export K_INCL_DIR="$KERN_DIR/include"
