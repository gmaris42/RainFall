
int main(int ac, char **av)
{
	N *first;
	N *other;
	int ret
	
	if (ac < 2)
	{
		exit(1);
	}
	fist = new N(5);
	other = new N(5);
	first.setAnnotation(av[1]);
	ret = (***other)(other, first));
	return (ret);
}

void N::setAnnotation(N *this,char *str)
{
	unsigned int len;
	
	len = strlen(str);
	memcpy(this + 4, str, len);
	return;
}
