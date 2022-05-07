char c[68];

int main(int ac, char **av)
{
	char *str;
	FILE *file
	char *strbis;
	
	str = malloc(8);
	*str = 1;
	strbis = malloc(8);
	*strbis = 2;
	strcpy(str[1], av[1]);
	strcpy(strbis[1], av[2]);
	file = fopen("/home/user/level8/.pass", "r");
	fgets(c, 68, file);
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