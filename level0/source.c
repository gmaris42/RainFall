int main(int ac, char **av)
{
	int iVar1;
	int local_20;
	int local_1c;
	int local_18;
	int local_14;
	
	iVar1 = atoi((av[1]));
	if (iVar1 == 423) {
		local_20 = strdup("/bin/sh");
		local_1c = 0;
		local_14 = getegid();
		local_18 = geteuid();
		setresgid(local_14,local_14,local_14);
		setresuid(local_18,local_18,local_18);
		execv("/bin/sh",&local_20);
	}
	else {
		fwrite("No !\n",1,5,stderr);
	}
	return 0;
}