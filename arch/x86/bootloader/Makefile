all: disk.img

run: disk.img
	qemu-system-i386 -drive format=raw,file=disk.img

disk.img: loader.bin kernel_entry.bin
	dd if=loader.bin of=disk.img
	dd if=kernel_entry.bin of=disk.img seek=1
	truncate -s 1024 disk.img

%.bin: %.S
	nasm -f bin $< -o $@

clean:
	rm -f *.elf *.img *.o *.bin
