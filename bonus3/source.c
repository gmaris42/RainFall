int main(int argc,char **argv)
{
  FILE *file;
  char str1[66];
  char str2[65];

  fs = fopen("/home/user/end/.pass","r");

  if ((!fs) || (argc != 2))
    return -1;

  fread(str1, 1, 66, file);
  pass[atoi(argv[1])] = 0;

  fread(str2, 1, 65, file);
  fclose(file);

  if (strcmp(str1, argv[1]) == 0)
    execl("/bin/sh","sh",0);
  else
    puts(str2);

  return 0;
}