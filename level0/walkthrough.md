get the binary on host
* `scp -P 4242 level0@192.168.56.107:./level0 ./binary/level0`

decompile using ghidra\
main fonction is
```c
	int main(undefined4 param_1,int param_2)
	{
		int iVar1;
		undefined4 local_20;
		undefined4 local_1c;
		undefined4 local_18;
		undefined4 local_14;
		
		iVar1 = atoi(*(undefined4 *)(param_2 + 4));
		if (iVar1 == 0x1a7) {
			local_20 = strdup("/bin/sh");
			local_1c = 0;
			local_14 = getegid();
			local_18 = geteuid();
			setresgid(local_14,local_14,local_14);
			setresuid(local_18,local_18,local_18);
			execv("/bin/sh",&local_20);
		}
		else {
			fwrite("No !\n",1,5,stderr);
		}
		return 0;
	}
```
0x1a7 is 423 in decimal\
So we can execute level0 with 423 as param and it will execv abash with level1 permission.
```
$ ./level0 423
$ whoami
	level1
$ cat /home/user/level1.pas
	1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```