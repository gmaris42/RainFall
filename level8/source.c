
char *auth = NULL;
char *service = NULL;

int main(void)
{
  char str[128];

  do
  {
    printf("%p, %p \n", auth, service);
    if (!fgets(str, 128, stdin))
      break;
    if (strncmp(str, "auth ", 5) == 0)
    {
      auth = (char *)malloc(4);
      char *authName = (str + 5);
      if (strlen(authName) < 31)
        strcpy(auth, authName);
    }
    else if (strncmp(str, "reset", 5) == 0)
    {
      if (auth)
        free(auth);
    }
    else if (strncmp(str, "service", 7) == 0)
    {
        service = strdup(str + 7);
    }
    else if (strncmp(str, "login", 5) == 0)
    {
      if ((&auth + 32) == &service)
        system("/bin/sh");
      else
        fwrite("Password:\n", 1, 10, stdout);
    }
  }
  while (true)
    ;
  return 0;
}