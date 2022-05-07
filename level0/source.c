int main(int ac, char **av)
{
  char *str;
  gid_t id;
  uid_t uid;
  char *av[2];

  if (atoi(av[1]) == 423)
  {
    str = strdup("/bin/sh");
    id = getegid();
    uid = geteuid();
    setresgid(id, id, id);
    setresuid(uid, uid, uid);
    av[0] = "sh";
    av[1] = 0;
    execv("/bin/sh", arg);
  }
  else
    fwrite("No !\n", 1, 5, stderr);
}