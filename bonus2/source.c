int language = 0;

int greetuser(char *msg)
{
  char hello[20];

  if (language == 1)
    strcpy(hello, "Hyvää päivää ");
  else if (language == 2)
    strcpy(hello, "Goedemiddag! ");
  else if (language == 0)
    strcpy(hello, "Hello! ");
  strcat(hello, msg);
  return (puts(hello));
}

int main(int ac,char **av)
{
  int ret;
  char str1[40];
  char str2[32];
  char *lang;

  if (argc == 3)
  {
    strncpy(str1, av[1], 40);
    strncpy(str2, av[2], 23);

    lang = getenv("LANG");
    if (lang)
    {
      if (memcmp(lang, "fi", 2) == 0)
        language = 1;
      else if (memcmp(lang, "nl", 2) == 0)
          language = 2;
    }
    return (greetuser(av[1]));
  }
  return (1);
}
