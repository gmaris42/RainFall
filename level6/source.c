void main(int ac, char **av)
{
	char *str;
	void **ptr;
	
	str = malloc(64);
	ptr = (code **)malloc(4);
	*ptr = m;
	strcpy(str, av[1]);
	(**ptr)();
	return;
}
void m()
{
	put("Nope");
}
void n(void)
{
	system("/bin/cat /home/user/level7/.pass");
	return;
}