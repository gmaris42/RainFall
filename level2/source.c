	void p(void)
	{
		uint var;
		char buffer[76];
		
		fflush(buffer);
		gets(buffer)
		if ((var & 0xb0000000) == 0xb0000000) {
			printf("(%p)\n", var);
							/* WARNING: Subroutine does not return */
			_exit(1);
		}
		puts(buffer);
		strdup(buffer);
		return;
	}