/***************************************************************************
**Name: depositProfitI
**Func: Deposited a specific amount of money into your bank account
**Input: float deposit, float rate, float threshold
**Return: int year
****************************************************************************/
int nYear = 0;
int depositProfitI(float fDeposit, float fRate, float fThreshold)
{
	if (fDeposit >= fThreshold)
	{
		return nYear;
	}
	else
	{
		nYear++;
		return depositProfitI(fDeposit * fRate / 100 + fDeposit, fRate, fThreshold);
	}
}