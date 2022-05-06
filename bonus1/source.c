int main(int ac,char **av)
{
  int	nb;
  char 	buffer[40];

  nb = atoi(av[1]);
  if (nb < 10)
  {
    memcpy(buff, argv[2], nb * 4);

    if (nb == 1464814662)
      execl("/bin/sh", "sh", 0);
    return 0;
  }
  else
  	return 1;
}