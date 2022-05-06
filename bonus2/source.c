int language = 0;

undefined4 main(int param_1,int param_2)
{
	undefined4 uVar1;
	int iVar2;
	undefined4 *puVar3;
	undefined4 **ppuVar4;
	byte bVar5;
	undefined4 *local_b0;
	undefined *local_ac;
	undefined4 local_a8;
	undefined4 local_60 [10];
	undefined4 auStack56 [9];
	undefined4 *local_14;
	
	bVar5 = 0;
	if (param_1 == 3) {
		iVar2 = 0x13;
		puVar3 = local_60;
		while (iVar2 != 0) {
		iVar2 = iVar2 + -1;
		*puVar3 = 0;
		puVar3 = puVar3 + 1;
		}
		local_ac = *(undefined **)(param_2 + 4);
		local_a8 = 0x28;
		local_b0 = local_60;
		strncpy();
		local_ac = *(undefined **)(param_2 + 8);
		local_a8 = 0x20;
		local_b0 = auStack56;
		strncpy();
		local_14 = getenv("LANG");
		if (local_14 != (undefined4 *)0x0) {
		local_a8 = 2;
		local_ac = "fi";
		local_b0 = local_14;
		iVar2 = memcmp();
		if (iVar2 == 0) {
			language = 1;
		}
		else {
			local_a8 = 2;
			local_ac = "nl";
			local_b0 = local_14;
			iVar2 = memcmp();
			if (iVar2 == 0) {
			language = 2;
			}
		}
		}
		iVar2 = 0x13;
		puVar3 = local_60;
		ppuVar4 = &local_b0;
		while (iVar2 != 0) {
		iVar2 = iVar2 + -1;
		*ppuVar4 = (undefined4 *)*puVar3;
		puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
		ppuVar4 = ppuVar4 + (uint)bVar5 * -2 + 1;
		}
		uVar1 = greetuser();
	}
	else {
		uVar1 = 1;
	}
	return uVar1;
}

void greetuser(void)

{
	undefined4 local_4c;
	undefined4 local_48;
	undefined4 local_44;
	undefined4 local_40;
	undefined2 local_3c;
	undefined local_3a;
	
	if (language == 1) {
		local_4c = "Hyvää päivää ";
	}
	else {
		if (language == 2) {
			local_4c = "Goedemiddag! "
		}
		else {
		if (language == 0) {
			local_4c = "Hello "
		}
		}
	}
	strcat(&local_4c,&stack0x00000004);
	puts(&local_4c);
	return;
}