void main(undefined4 param_1,int param_2)
{
	undefined4 uVar1;
	code **ppcVar2;
	
	uVar1 = malloc(64);
	ppcVar2 = (code **)malloc(4);
	*ppcVar2 = m;
	strcpy(uVar1,*(undefined4 *)(param_2 + 4));
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