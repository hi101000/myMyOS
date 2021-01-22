nasm -f elf32 kernel.asm -o ksm.o
gcc -m32 -c -ffreestanding kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o kernel.bin ksm.o kc.o
qemu-system-i386 -kernel kernel.bin
cp kernel.bin MyOS/boot/kernel.bin
grub-mkrescue -o myos.iso MyOS/
git add .
echo Would You like to enter a custom message[y/n]:
read x
if [[$x -eq "n"]]
then
	git commit -a -m "stuff"
else
	echo Enter your message[e.g. Updated kernel.c]:
	read y
	git commit -a -m $y
fi
git push
#clear
