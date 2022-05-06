int main(int ac, char **av)
{
	char *puVar1;
	FILE *uVar2;
	char *puVar3;
	
	puVar1 = malloc(8);
	*puVar1 = 1;
	uVar2 = malloc(8);
	puVar1[1] = uVar2;
	puVar3 = malloc(8);
	*puVar3 = 2;
	uVar2 = malloc(8);
	puVar3[1] = uVar2;
	strcpy(puVar1[1], av[1]);
	strcpy(puVar3[1], av[2]);
	uVar2 = fopen("/home/user/level8/.pass", "r");
	fgets(c, 68, uVar2);
	puts("~~");
	return 0;
}
void m(void)
{
	unsigned int uVar1;
	
	uVar1 = time(0);
	printf("%s - %d\n", c, uVar1);
	return;
}