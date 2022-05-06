void main(int ac, char **av)
{
	char *uVar1;
	void **ppcVar2;
	
	uVar1 = malloc(64);
	ppcVar2 = (code **)malloc(4);
	*ppcVar2 = m;
	strcpy(uVar1, av[1]);
	(**ppcVar2)();
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