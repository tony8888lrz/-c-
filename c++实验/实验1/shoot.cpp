#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void shot(bool& targetAlive, double precision);//step a,引用传参

int startDuel();//step b ,strategy:菜的都先杀最强的 
// 返回值说明: 1代表charlie 赢, 2 代表bob 赢, 3 代表aaron 赢

bool charlielive, boblive, aaronlive;	//题上说明的全局变量
double characc= 1, bobacc= 0.5, aaronacc= (1/3.0);

int main()
{
	srand(time(0)); //随机种子

	double charpercent,bobpercent,aaronpercent;
	int charwin=0, bobwin=0,aaronwin=0,i,winner,alldead=0;

	for (i=1;i<=1000;i++)		//steps c
	{
		charlielive=true;		//每次循环前初始化 duel
		boblive=true;
		aaronlive=true;

		winner= startDuel();	

		if (winner == 1)
        {		
			aaronwin += 1;
        }
		if (winner == 2)
        {
			bobwin += 1;
        }
		if (winner == 3)
        {
			charwin += 1;
        }

	}

    //计算百分比
	charpercent=(charwin / 1000.0) * 100;
	bobpercent=(bobwin / 1000.0) * 100;
	aaronpercent=(aaronwin / 1000.0) * 100;

    //格式化输出
    cout << "Using the strategy of shooting at the best shooter  alive" << endl;
	cout<< "Aaron's Wins: " << aaronwin << endl;
	cout<< "Bob's Wins: " << bobwin << endl;
	cout<< "Charlie's Wins: " << charwin << endl << endl;

	cout<< "Aaron's Win Percentage: " << aaronpercent << endl;
	cout<< "Bob's Win Percentage: " << bobpercent << endl;
	cout<< "Charlie's Win Percentage: " << charpercent << endl << endl;

	return 0;
}

void shot(bool& targetAlive, double precision)
{
	double x;
	x=(rand() % 100) * 0.01;	
	if (x < precision)
    {	
		targetAlive= false;
    }
}


int startDuel()//step b ,strategy:菜的都先杀最强的
{
	int result=0;
						
	while (((charlielive) && (aaronlive) && (boblive)) || 
    ((charlielive) && (aaronlive) && (!boblive)) || 
		((aaronlive) && (boblive) && (!charlielive)) || 
        ((charlielive) && (boblive) && (!aaronlive))) //在这个循环条件中一人胜出
	{

        if ((charlielive) && (aaronlive) && (boblive))//第一轮
        {
            shot(charlielive, aaronacc);	//charlie 第一次
            if (charlielive)
            {				//charlie第一次没死
                shot(charlielive, bobacc);//charlie 第二次
            }
            else//charlie 死了
            {
                shot(aaronlive,bobacc);
            }
            if (charlielive) //charlie第二次没死
            {
                shot(boblive, characc);
            }
        }

        if ((!charlielive) && (boblive) && (aaronlive))//在第一轮中charlie死
        {
            shot(boblive, aaronacc);	
            if (boblive)
            {				
                shot(aaronlive, bobacc); //循环继续执行这次判断
            }	
            else
            {
                break; // aaron wins
            }
        }

        if ((charlielive) && (!boblive) && (aaronlive)) //第一轮中bob死
        {
            shot(charlielive, aaronacc);
            if (charlielive)
            {
                shot(aaronlive, characc);//charlie wins
            }
            else
            {
                break;//aaron wins
            }
        }

        if ((charlielive) && (!aaronlive) && (boblive))
        {
            shot(charlielive, bobacc);
            if (charlielive)
            {
                shot(boblive, characc);//charlie wins
            }
            else
            {
                break; // bob wins
            }
        }

    }

    if ((!charlielive) && (!boblive) && (aaronlive))
    {
        result=1;
    }
    else if ((!charlielive) && (boblive) && (!aaronlive))
    {
        result=2;
    }
    else if ((charlielive) && (!boblive) && (!aaronlive))
    {
        result=3;
    }

	return result;
}

