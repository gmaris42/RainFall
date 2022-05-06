void main(void)
{
	n();
	return;
}

void n(void)
{
	undefined local_20c [520];

	fgets(local_20c,512,stdin);
	printf(local_20c);

	exit(1);
}

void o(void)
{
	system("/bin/sh");
	exit(1);
}