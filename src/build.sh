set -e
. ./config.sh

cd kernel
make
cd ..

cd libc
make
cd ..

make 
make install

grub-mkrescue -o mos.iso sysroot
