void main(int param_1,int param_2)
{
	N *this;
	code **this_00;
	
	if (param_1 < 2) {
						/* WARNING: Subroutine does not return */
		_exit(1);
	}
	this = (N *)operator.new(0x6c);
	N::N(this,5);
	this_00 = (code **)operator.new(0x6c);
	N::N((N *)this_00,6);
	N::setAnnotation(this,*(char **)(param_2 + 4));
	(**(code **)*this_00)(this_00,this);
	return;
}

void __thiscall N::setAnnotation(N *this,char *param_1)
{
	undefined4 uVar1;
	
	uVar1 = strlen(param_1);
	memcpy(this + 4,param_1,uVar1);
	return;
}
