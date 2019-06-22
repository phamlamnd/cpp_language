/***************************************************************************
**Name: bitRotateII
**Func: rotate 31 bit interger
**Input: integer n, rotate number r
**Return: integer n after rotate
****************************************************************************/
int bitRotateII(int n, int r)
{
	//rotate n to left r steps
	if (r >= 0)
	{
		for (int i = 1; i <= r % 31; i++)
		{
			n = (((n & (1 << 30)) >> 30) | ((n << 1) & (~(1 << 31))));
		}
	}
	//rotate n to right r steps
	else
	{
		for (int i = 1; i <= (-r) % 31; i++)
		{
			n = ((n & 1) << 30) | (n >> 1);
		}

	}
	return n;
}