	void p(void)
	{
		uint var;
		char local_50 [76];
		
		fflush(stdout);
		gets(local_50)
		if ((var & 0xb0000000) == 0xb0000000) {
			printf("(%p)\n", var);
							/* WARNING: Subroutine does not return */
			_exit(1);
		}
		puts(local_50);
		strdup(local_50);
		return;
	}