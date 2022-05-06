undefined4 main(int argc, char** argv)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  char buff_read [16];
  undefined local_57;
  undefined local_56 [66];
  int fd;
  
  bVar4 = 0;
  fd = fopen("/home/user/end/.pass","r");
  iVar2 = 33;
  puVar3 = buff_read;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  if ((fd == 0) || (argc != 2)) {
    uVar1 = 0xffffffff;
  }
  else {
    fread(buff_read,1,66,fd);
    local_57 = 0;
    iVar2 = atoi(argv[1]);
    buff_read[iVar2] = '\0';
    fread(local_56,1,0x41,fd);
    fclose(fd);
    iVar2 = strcmp(buff_read,argv[1]);
    if (iVar2 == 0) {
      execl("/bin/sh","sh",0);
    }
    else {
      puts(local_56);
    }
    uVar1 = 0;
  }
  return uVar1;
}