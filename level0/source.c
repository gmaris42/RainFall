int main(undefined4 param_1,int param_2)
{
	int iVar1;
	undefined4 local_20;
	undefined4 local_1c;
	undefined4 local_18;
	undefined4 local_14;
	
	iVar1 = atoi(*(undefined4 *)(param_2 + 4));
	if (iVar1 == 0x1a7) {
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