get the binary on host
* scp -P 4242 level5@192.168.56.107:./level5 ./binary/level5

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
        uVar2 = fopen("/home/user/level8/.pass", "r");
        fgets(c,68,uVar2);
        puts("~~");
        return 0;
    }
```