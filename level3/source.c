unsigned int m;

void v(void)
{
  char buffer[520];
  
  fgets(buffer,520,stdin);
  printf("%s", buffer);
  if (m == 64)
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