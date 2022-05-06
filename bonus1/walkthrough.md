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