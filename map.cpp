#include "map.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "game.h"
using namespace std;
int ghg=0;
int ade=0;
int codo3[20][25]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,2,2,2,2,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,2,2,2,2,2,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,2,1,0,0,2,2,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,1,1,1,0,1,1,1,0,2,2,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,1,1,0,1,1,1,0,1,0,2,2,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0,0,1,1,2,2,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,1,1,0,1,1,1,1,1,2,2,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,1,1,1,0,2,2,2,2,1,1,1,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,2,2,2,2,0,0,1,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,1,2,2,1,1,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,1,0,2,2,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,1,0,2,2,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,2,2,1,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,2,1,0,0,2,2,0,0,1,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,2,2,2,2,2,1,1,0,1,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,2,2,2,2,0,1,0,1,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int lvl1[20][25]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int gamo[20][25]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,2,0,0,0,1,0,0,0,1,0,2,2,2,2,0},
	{0,1,0,0,0,0,1,0,0,2,0,2,0,0,1,1,0,1,1,0,2,0,0,0,0},
	{0,1,0,0,0,0,0,0,2,0,0,0,2,0,1,0,1,0,1,0,2,2,2,0,0},
	{0,1,0,0,1,1,1,0,2,2,2,2,2,0,1,0,0,0,1,0,2,0,0,0,0},
	{0,1,0,0,0,0,1,0,2,0,0,0,2,0,1,0,0,0,1,0,2,0,0,0,0},
	{0,0,1,1,1,1,0,0,2,0,0,0,2,0,1,0,0,0,1,0,2,2,2,2,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,2,2,2,0,0,1,0,0,0,1,0,2,2,2,2,0,1,1,1,1,0,0},
	{0,2,0,0,0,0,2,0,1,0,0,0,1,0,2,0,0,0,0,1,0,0,0,1,0},
	{0,2,0,0,0,0,2,0,1,0,0,0,1,0,2,2,2,0,0,1,1,1,1,0,0},
	{0,2,0,0,0,0,2,0,1,0,0,0,1,0,2,0,0,0,0,1,0,1,0,0,0},
	{0,2,0,0,0,0,2,0,0,1,0,1,0,0,2,0,0,0,0,1,0,0,1,0,0},
	{0,0,2,2,2,2,0,0,0,0,1,0,0,0,2,2,2,2,0,1,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int vic[20][25]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,2,0,0,0,0,0,2,0,0,1,0,0,0,0,2,2,2,2,0,0,0,0},
	{0,0,0,2,0,0,0,0,0,2,0,0,1,0,0,0,2,0,0,0,0,2,0,0,0},
	{0,0,0,2,0,0,0,0,0,2,0,0,1,0,0,2,0,0,0,0,0,0,2,0,0},
	{0,0,0,2,0,0,0,0,0,2,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,2,0,0,0,0,0,2,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,0,0,0,2,0,0,0,1,0,0,2,0,0,0,0,0,0,2,0,0},
	{0,0,0,0,0,2,0,2,0,0,0,0,1,0,0,0,2,0,0,0,0,2,0,0,0},
	{0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,0,0,2,2,2,2,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,2,2,2,0,0,0,1,1,1,1,1,0,0,2,0,0,0,2},
	{0,0,1,0,0,0,2,0,0,0,2,0,0,1,0,0,0,0,1,0,2,0,0,0,2},
	{0,0,1,0,0,2,0,0,0,0,0,2,0,1,0,0,0,0,1,0,2,0,0,0,2},
	{0,0,1,0,0,2,0,0,0,0,0,2,0,1,1,1,1,1,0,0,0,2,0,2,0},
	{0,0,1,0,0,2,0,0,0,0,0,2,0,1,0,1,0,0,0,0,0,0,2,0,0},
	{0,0,1,0,0,2,0,0,0,0,0,2,0,1,0,0,1,0,0,0,0,0,2,0,0},
	{0,0,1,0,0,0,2,0,0,0,2,0,0,1,0,0,0,1,0,0,0,0,2,0,0},
	{0,0,1,0,0,0,0,2,2,2,0,0,0,1,0,0,0,0,1,0,0,0,2,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
Map::Map()
{
	dirt=TextureManager::LoadTexture("dirt.bmp");
	grass=TextureManager::LoadTexture("grass.bmp");
	water=TextureManager::LoadTexture("water.bmp");
	src.x=src.y=0;
	src.w=dest.w=32;
	src.h=dest.h=32;
	dest.x=dest.y=0;
}
void Map::LoadMap(int arr[20][25])
{
	for(int row=0;row<20;row=row+1)
	{
		for(int col=0;col<25;col=col+1)
		{
			map[row][col]=arr[row][col];
		}
	}
}
void Map::DrawMap()
{
	if(!ggov())
	{
		LoadMap(lvl1);
	}
	if(ggov())
	{
		LoadMap(gamo);
	}
	if(ggov()&&finn())
	{
		LoadMap(vic);
	}
	int type=0;
	for(int row=0;row<20;row=row+1)
	{
		for(int col=0;col<25;col=col+1)
		{
			type=map[row][col];
			dest.x=col*32;
			dest.y=row*32;
			switch(type)
			{
				case 0:
					TextureManager::Draw(dirt,src,dest);
					break;
				case 1:
					TextureManager::Draw(grass,src,dest);
					break;
				case 2:
					TextureManager::Draw(water,src,dest);
					break;
				default:
					break;
			}
		}
	}
}
void Map::upd()
{
	static int ccn=0;
	ccn=ccn+1;
	if((ccn<=200&&ccn>=196)||(ccn<=400&&ccn>=396))
	{
		for(int iiii=0;iiii<20;iiii++)
			{
				for(int jjjj=0;jjjj<25;jjjj++)
				{
					if(lvl1[iiii][jjjj]==1)
					{
						lvl1[iiii][jjjj]=2;
					}
					else if(lvl1[iiii][jjjj]==2)
					{
						lvl1[iiii][jjjj]=1;
					}
				}
			}
	}
	if(ccn>=400&&ccn<480)
	{
		if(ccn%16==0||ccn%16==1||ccn%16==2||ccn%16==3||ccn%16==4||ccn%16==5||ccn%16==6||ccn%16==7)
		{
			lvl1[3][11]=1;
			lvl1[3][13]=1;
			lvl1[16][11]=1;
			lvl1[16][13]=1;
		}
		if(ccn%16==8||ccn%16==9||ccn%16==10||ccn%16==11||ccn%16==12||ccn%16==13||ccn%16==14||ccn%16==15)
		{
			lvl1[3][11]=0;
			lvl1[3][13]=0;
			lvl1[16][11]=0;
			lvl1[16][13]=0;
		}
	}
	if(ccn>=480&&ccn<500)
	{
		if(ccn%2==0)
		{
			lvl1[3][11]=1;
			lvl1[3][13]=1;
			lvl1[16][11]=1;
			lvl1[16][13]=1;
		}
		if(ccn%2==1)
		{
			lvl1[3][11]=0;
			lvl1[3][13]=0;
			lvl1[16][11]=0;
			lvl1[16][13]=0;
		}
	}
	if(ccn>=500)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	
	static int vvi=0;
	if(ggov()&&!finn())
	{
		vvi=vvi+1;
		if(vvi>=25)
		{
			for(int iiii=0;iiii<20;iiii++)
			{
				for(int jjjj=0;jjjj<25;jjjj++)
				{
					if((iiii+jjjj)%4==0)
					{
						gamo[iiii][jjjj]=0;
					}
					if(vvi>=50&&(iiii+jjjj)%4==1)
					{
						gamo[iiii][jjjj]=0;
					}
					if(vvi>=75&&(iiii+jjjj)%4==2)
					{
						gamo[iiii][jjjj]=0;
					}
					if(vvi>=100&&(iiii+jjjj)%4==3)
					{
						gamo[iiii][jjjj]=0;
					}
				}
			}	
		}
	}
	if(finn())
	{
		vvi=vvi+1;
		if(vvi%4==0)
		{
			for(int iiii=0;iiii<20;iiii++)
			{
				for(int jjjj=0;jjjj<25;jjjj++)
				{
					if(vic[iiii][jjjj]==1)
					{
						vic[iiii][jjjj]=2;
					}
					else if(vic[iiii][jjjj]==2)
					{
						vic[iiii][jjjj]=1;
					}
				}
			}	
		}
	}
}
