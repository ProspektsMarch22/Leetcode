int	mySqrt(int x)
{
	long int	root;

	root = 0;
	while ((root * root) <= x)
	{
		if (root * root == x)
			return (root);
		root++;
	}
	return (--root);
}
