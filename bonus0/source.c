int main(void)
{
	char buff [54];
	
	pp(buff);
	puts(buff);
	return (0);
}

void pp(char buff[54])
{
  char str1[20];
  char str2[20];

  p(str1, " - ");
  p(str2, " - ");

  	strcpy(buff, str1);
	buff[strlen(buff)] = 32;

  strcat(buff, str2);
  return;
}

void p(char *str, char *str2)
{
	int useless;
	char buffer [4104];

	puts(str2);
	read(0, buffer, 4096);
	useless = strchr(buffer, '\n');
	useless = 0;
	strncpy(str, buffer,20);
	return;
}