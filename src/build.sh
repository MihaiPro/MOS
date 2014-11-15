set -e
. ./config.sh

make
make install

grub-mkrescue -o mos.iso sysroot
