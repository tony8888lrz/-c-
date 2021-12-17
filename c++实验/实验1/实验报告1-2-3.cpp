#include <iostream>
#include <cstdlib> 

using namespace std;
void shot(bool& targetAlive, double precision);
int startDuel();//step d ,strategy:菜的都先杀最强的,但是aaron故意错过第一枪，来保证自己第一轮不死 


const int DUENUM = 1000;
double characc= 1, bobacc= 0.5, aaronacc= (1/3.0);

int main()
{
	int i;
	int winner;
	double aaronwin=0, bobwin=0, charwin=0;
	for (i=0; i < DUENUM; i++)
	{
		winner = startDuel();
		if (winner == 0)
		{
			aaronwin++;
		}
		else if (winner == 1)
		{
			bobwin++;
		}
		else if (winner == 2)
		{
			charwin++;
		}
	}
	cout << "Using the strategy of shooting at the best shooter  alive, but"  <<" Aaron intentionally misses on the first shot:" << endl;
	cout<< "Aaron's Wins: " << aaronwin << endl;
	cout<< "Bob's Wins: " << bobwin << endl;
	cout<< "Charlie's Wins: " << charwin << endl << endl;
	cout << "Aaron  win percentage: " << (aaronwin/DUENUM) << endl;
	cout << "Bob win percentage: " << (bobwin/DUENUM) << endl;
	cout << "Charlie win percentage: " << (charwin/DUENUM) << endl;

	return 0;
}

void shot(bool& targetAlive, double precision)
{
	double r;
	if (targetAlive == true)
	{
		r = rand() % 100; 
	if (r < (precision * 100))
	{
		targetAlive = false;
	}
	}
}

int startDuel()
{
	bool aliveAaron = true, aliveBob = true,
								aliveCharlie = true;
	while ((aliveAaron && aliveBob) || 
				(aliveAaron &&aliveCharlie) ||
							(aliveBob &&aliveCharlie))
	{

		if (aliveBob)
		{
		if (aliveCharlie)
		{
			shot(aliveCharlie, bobacc);
		}
		else if (aliveAaron)
		{
			shot(aliveAaron, bobacc);
		}
		}
		if (aliveCharlie)
		{
		if (aliveBob)
		{
			shot(aliveBob, characc);
		}
		else if (aliveAaron)
		{
			shot(aliveAaron, characc);
		}
		}
	
		if (aliveAaron)
		{
		if (aliveCharlie)
		{
		shot(aliveCharlie,aaronacc);
		}
		else if (aliveBob)
		{
		shot(aliveBob, aaronacc);
		}
	}
	}
	if (aliveAaron) return 0;
	else if (aliveBob) return 1;
	else if (aliveCharlie) return 2;
}
