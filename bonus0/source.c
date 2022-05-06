undefined4 main(void)
{
	undefined local_3a [54];
	
	pp(local_3a);
	puts(local_3a);
	return 0;
}

void pp(char param_1[54])
{
	char cVar1;
	uint uVar2;
	char *pcVar3;
	byte bVar4;
	undefined local_34 [20];
	undefined local_20 [20];
	
	bVar4 = 0;
	p(local_34, " - ");
	p(local_20, " - ");
	strcpy(param_1,local_34);
	uVar2 = 4294967295;
	pcVar3 = param_1;
	do {
		if (uVar2 == 0) break;
		uVar2 = uVar2 - 1;
		cVar1 = *pcVar3;
		pcVar3 = pcVar3 + (uint)bVar4 * -2 + 1;
	} while (cVar1 != '\0');
	*(undefined2 *)(param_1 + (~uVar2 - 1)) = 0x20;
	strcat(param_1,local_20);
	return;
}

void p(undefined4 param_1,undefined4 param_2)
{
	undefined *puVar1;
	undefined local_100c [4104];

	puts(param_2);
	read(0,local_100c, 4096);
	puVar1 = (undefined *)strchr(local_100c,10);
	*puVar1 = 0;
	strncpy(param_1,local_100c,20);
	return;
}