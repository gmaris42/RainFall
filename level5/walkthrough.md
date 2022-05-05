get the binary on host
* scp -P 4242 level5@192.168.56.107:./level5 ./binary/level5

decompile using ghidras
```
	void main(void)
	{
		n();
		return;
	}

	void n(void)
	{
		undefined local_20c [520];
	
		fgets(local_20c,0x200,stdin);
		printf(local_20c);
		exit(1);
	}

	void o(void)
	{
		system("/bin/sh");
		exit(1);
	}
	
```