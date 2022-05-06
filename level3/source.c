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