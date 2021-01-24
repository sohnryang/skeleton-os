all: clean loader.img

run: loader.img
	qemu-system-i386 -drive format=raw,file=loader.img

loader.img: loader.S
	nasm loader.S -o loader.img

clean:
	rm -f *.elf *.img *.o
