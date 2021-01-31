nasm -f elf32 kernel.asm -o ksm.o
gcc -m32 -c -ffreestanding kernel.c -o kc.o
gcc -m32 -c -ffreestanding encryption/encryption.c -o encrypt.o
gcc -m32 -c -ffreestanding drivers/kbd.c -o kbd.o
gcc -m32 -c -ffreestanding stdint.c -o stdint.o
gcc -m32 -c -ffreestanding dictc.c -o dict.o
ld -m elf_i386 -T link.ld -o kernel.bin ksm.o kc.o encrypt.o kbd.o stdint.o dict.o
qemu-system-i386 -kernel kernel.bin
cp kernel.bin MyOS/boot/kernel.bin
echo are you on a debian or redhat based distribution[r/d]:
read x
if [ $x == "d" ]
then
	grub-mkrescue -o myos.iso MyOS/
else
	grub2-mkrescue -o myos.iso MyOS/
fi
mv myos.iso ~/Documents/myos.iso
git add .
echo Would You like to enter a custom message[y/n]:
read x
if [ $x == "n" ]
then
	git commit -m "well wouldn't you like to know"
else
	echo Enter your message[e.g. Updated kernel.c]:
	read y
	git commit -m $y
fi
git push
qemu-system-i386 -cdrom ~/Documents/myos.iso
clear
