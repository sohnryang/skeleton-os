all: clean loader.img

loader.img: loader.S
	nasm loader.S -o loader.img

clean:
	rm -f *.elf *.img *.o
