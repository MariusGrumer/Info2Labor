#pragma once

class CPhoneCard
{
public:
	CPhoneCard();
	void makeCall();
	void refill_15();
	void display();

private:
	unsigned int mCredit;
	int mStatus;

};