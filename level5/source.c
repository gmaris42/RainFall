void main(void)
{
	n();
	return;
}

void n(void)
{
	char buffer[520];

	fgets(buffer, 512, stdin);
	printf("%s", buffer);
	exit(1);
}

void o(void)
{
	system("/bin/sh");
	exit(1);
}