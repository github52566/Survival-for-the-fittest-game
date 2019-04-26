# include "iGraphics.h"

int manpos_x = 425 , manpos_y = 10 ,man_d = 1;
int x = 1 , y = 0, x_1 = 1, y_1 = 0,x2 = 0 , y2 = 0;
int t1 ,t2 ,t3,t4,t5,t6,t7,t8,t9;
int i, create =0, create1 = 0;
int screen = 0 , op = 0;
int r = 100, g = 50 , bl = 200;
int re = 0 ,ge = 0 , blu = 0;
int text_d_r = 1,text_d_g = 1, text_d_b = 1;
int text_d = 1;
int p_s = 0, g_d = 0;
char str[100], str1[100],score[1000] = "0", times[1000] = "0", lifes[2] = "5", sheilds[5], levels[2];
int count = -1 , f = 0,f1 = 0, s =0, l = 5 ,flag = 0 ,ti = 0;
int screen_x = 10 , screen_y = 30 , screen_d = 1;
int c_s = 0,hl_s = 0, s_s = 0,h_s = 0;

int enter = 0 ,len = 0;
int p = 1, count1 = -1;
int en = 0, node = 0;
int a_count = 1,l_x = 20;
int lo = 1;
int j = 4;
int level = 1;
int image_d = 0;
int lc,sc;
int she = 30, s_count = 0, s_v = 0,s_count1 = 30, s_f = 1;
int w_s;
int d_dy =-10, n_dy = 590,p_dx = 860;
bool play_s = true;
bool play_s1 =true;
bool play_s2 = true;
bool play_s3 = true;
bool play_s4 = true;
bool play_s5 = true;
FILE *namefile , *fp;

void menu();
void game();
void control();
void sound();
void help();
void highscore();
void username();
void gameover();
void win();
void pausemenu();
void restart();
void animation();
void loading();
void brick_create();
void sort();
void CopyFromFile();
void SaveToFile();
void showHighscore();
void extra();
void brickpreprocesslvl1();
void brickpreprocesslvl2();
void brickpreprocesslvl3();
void laslvl1();
void laslvl2();
void laslvl3();
void level1();
void level2();
void level3();
void name();

struct brick_and_coin
{
	int speed;
	int b_x;
	int b_y;
	int mark;
}b[600], c[600], c1[600];

struct highscores
{
	char name[100];
	int scores;

}h[5],temp;

struct life_and_sheild
{
	int speed1;
	int li_x;
	int li_y;
	int mark1;

}life[5],sheild[5];

void laslvl1()
{

	for(i = 0 ; i < 5 ;i++)
	{

		life[i].speed1 = (rand()%10)+10;
		life[i].li_x = rand()%800;
		life[i].li_y = 500;
		life[i].mark1 = 0;
		sheild[i].speed1 = (rand()%10)+5;
		sheild[i].li_x = rand()%800;
		sheild[i].li_y = 500;
		sheild[i].mark1 = 0;
	}

}
void laslvl2()
{

	for(i = 0 ; i < 3 ;i++)
	{

		life[i].speed1 = (rand()%15)+10;
		life[i].li_x = rand()%800;
		life[i].li_y = 500;
		life[i].mark1 = 0;
		sheild[i].speed1 = (rand()%15)+5;
		sheild[i].li_x = rand()%800;
		sheild[i].li_y = 500;
		sheild[i].mark1 = 0;
	}

}
void laslvl3()
{

	for(i = 0 ; i < 2 ;i++)
	{

		life[i].speed1 = (rand()%20)+10;
		life[i].li_x = rand()%800;
		life[i].li_y = 500;
		life[i].mark1 = 0;
		sheild[i].speed1 = (rand()%15)+10;
		sheild[i].li_x = rand()%800;
		sheild[i].li_y = 500;
		sheild[i].mark1 = 0;
	}

}
void level1()
{
		iShowBMP(0,30,"image\\building.bmp");
		iShowBMP(0,0,"image\\road.bmp");
		iShowBMP(0,500,"image\\board.bmp");
		iShowBMP(screen_x,screen_y,"image\\building1.bmp");
		iShowBMP2(768,512,"image\\pause.bmp",16777215);
		if(p_s)iShowBMP(768,512,"image\\pause1.bmp");
		iResumeTimer(t1);
		iResumeTimer(t2);
		iResumeTimer(t4);
		iResumeTimer(t5);
		iSetColor(0,0,0);
		iText(10,560,"Name : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,560,str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,560,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(650,560,score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(375,560,"Lifes :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450,560,lifes,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10,510,"Times : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,510,times,GLUT_BITMAP_TIMES_ROMAN_24);
		if(s_v)
		{
			iShowBMP2(375,510,"image\\sheild.bmp",0);
			iText(435,515,sheilds,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(580,510,"Level : ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(levels,"%d",level);
		iText(650,510,levels,GLUT_BITMAP_TIMES_ROMAN_24);
		if(x)iShowBMP2(manpos_x,manpos_y,"image\\shake1.bmp",16777215);
		if(y)iShowBMP2(manpos_x,manpos_y,"image\\shake2.bmp",16777215);
		if(x2)iShowBMP2(manpos_x,manpos_y,"image\\boxer1.bmp",0);
		if(y2)iShowBMP2(manpos_x,manpos_y,"image\\boxer2.bmp",0);

	
		for(i = 0 ; i < 300 ;i++)
		{
			if(b[i].mark == 1)
			{
				iShowBMP(b[i].b_x,b[i].b_y,"image\\brick.bmp");
				if((manpos_x >= b[i].b_x-40 && manpos_x <= b[i].b_x+64) && b[i].mark == 1 && (b[i].b_y <= manpos_y +80 && b[i].b_y >= 0))
				{
					if(s_f == 1)
					{
						if((manpos_y >= 0 && manpos_y < 40) && (b[i].b_y >= 10 && b[i].b_y < 80))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP2(manpos_x,manpos_y+70,"image\\opps.bmp",16777215);
							l--;
							sprintf_s(lifes,"%d",l);
							if(l == 0)screen = 8;
						}
					
						else if((manpos_y >= 40 && manpos_y <= 200) && (b[i].b_y >= 80 && b[i].b_y <= 200))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP(manpos_x, manpos_y+70,"image\\broke.bmp");
							s += 10;
							sprintf_s(score,"%d",s);
						}
						
					}
					else if(s_f == 0)
					{
						if(b[i].b_y <= 0)
						{
							if(flag == 0)
							{
								flag = 1;
								s += 20;
								sprintf_s(score,"%d",s);
								b[i].mark =0;	
							}
						}
					}
				}
				else if(b[i].b_y <= 0)
				{
					if(flag == 0)
					{
						if(create <= 299)
						{
							flag = 1;
							s++;
							sprintf_s(score,"%d",s);
							b[i].mark =0;
						}
					}
				}
			}
			op= 0;
			flag = 0;
		}			
		for(i = 0 ; i < 300 ;i++)
		{
			if(c[i].mark == 1)
				{
				iShowBMP2(c[i].b_x,c[i].b_y,"image\\coin.bmp",0);
				if((manpos_x >= c[i].b_x-40 && manpos_x <= c[i].b_x+40) && c[i].mark == 1 && (c[i].b_y <= manpos_y +80 && c[i].b_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (c[i].b_y >= 0 && c[i].b_y <= 200))
					{
						c[i].mark = 0;
						s += 100;
						sprintf_s(score,"%d",s);
					}	
				
				}
				if(c[i].b_y < 0)c[i].mark = 0;
			
			}
		}
		for(i = 0 ; i < 5 ; i++)
		{
			if(life[i].mark1 == 1)
			{
				iShowBMP2(life[i].li_x,life[i].li_y,"image\\heart.bmp",0);
				if((manpos_x >= life[i].li_x-30 && manpos_x <= life[i].li_x+70) && life[i].mark1 == 1 && (life[i].li_y <= manpos_y +80 && life[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (life[i].li_y >= 0 && life[i].li_y <= 200))
					{
						life[i].mark1 = 0;
						l++;
						sprintf_s(lifes,"%d",l);
					}
				}
				 if(life[i].li_y <= 0)
					life[i].mark1 = 0;

			}
			if(sheild[i].mark1 == 1)
			{
				iShowBMP2(sheild[i].li_x,sheild[i].li_y,"image\\sheild.bmp",0);
				if((manpos_x >= sheild[i].li_x-30 && manpos_x <= sheild[i].li_x+80) && sheild[i].mark1 == 1 && (sheild[i].li_y <= manpos_y +80 && sheild[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (sheild[i].li_y >= 0 && sheild[i].li_y <= 200))
					{
						sheild[i].mark1 = 0;
						s_v = 1;
						s_f = 0;
					}
				}
				 if(sheild[i].li_y <= 0)
					sheild[i].mark1 = 0;
			}

		}
}
void level2()
{
		iShowBMP(0,30,"image\\level2.bmp");
		iShowBMP(0,0,"image\\road.bmp");
		iShowBMP(0,500,"image\\board.bmp");
		iShowBMP(screen_x,screen_y,"image\\level21.bmp");
		iShowBMP2(768,512,"image\\pause.bmp",16777215);
		if(p_s)iShowBMP(768,512,"image\\pause1.bmp");
		iResumeTimer(t1);
		iResumeTimer(t2);
		iResumeTimer(t4);
		iResumeTimer(t5);
		iSetColor(0,0,0);
		iText(10,560,"Name : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,560,str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,560,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(650,560,score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(375,560,"Lifes :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450,560,lifes,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10,510,"Times : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,510,times,GLUT_BITMAP_TIMES_ROMAN_24);
		if(s_v)
		{
			iShowBMP2(375,510,"image\\sheild.bmp",0);
			iText(435,515,sheilds,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(580,510,"Levels : ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(levels,"%d",level);
		iText(680,510,levels,GLUT_BITMAP_TIMES_ROMAN_24);
		if(x)iShowBMP2(manpos_x,manpos_y,"image\\shake1.bmp",16777215);
		if(y)iShowBMP2(manpos_x,manpos_y,"image\\shake2.bmp",16777215);
		if(x2)iShowBMP2(manpos_x,manpos_y,"image\\boxer1.bmp",0);
		if(y2)iShowBMP2(manpos_x,manpos_y,"image\\boxer2.bmp",0);

	
		for(i = 0 ; i < 400 ;i++)
		{
			if(b[i].mark == 1)
			{
				iShowBMP(b[i].b_x,b[i].b_y,"image\\brick1.bmp");
				if((manpos_x >= b[i].b_x-40 && manpos_x <= b[i].b_x+64) && b[i].mark == 1 && (b[i].b_y <= manpos_y +80 && b[i].b_y >= 0))
				{
					if(s_f == 1)
					{
						if((manpos_y >= 0 && manpos_y < 40) && (b[i].b_y >= 10 && b[i].b_y < 80))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP2(manpos_x,manpos_y+70,"image\\opps.bmp",16777215);
							l--;
							sprintf_s(lifes,"%d",l);
							if(l == 0)screen = 8;
						}
					
						else if((manpos_y >= 40 && manpos_y <= 200) && (b[i].b_y >= 80 && b[i].b_y <= 200))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP(manpos_x, manpos_y+70,"image\\broke.bmp");
							s += 10;
							sprintf_s(score,"%d",s);
						}
						
					}
					else if(s_f == 0)
					{
						if(b[i].b_y <= 0)
						{
							if(flag == 0)
							{
								flag = 1;
								s += 20;
								sprintf_s(score,"%d",s);
								b[i].mark =0;	
							}
						}
					}
				}
				else if(b[i].b_y <= 0)
				{
					if(flag == 0)
					{
						if(create <= 399)
						{
							flag = 1;
							s++;
							sprintf_s(score,"%d",s);
							b[i].mark =0;
						}
					}
				}
			}
			op= 0;
			flag = 0;
		}			
		for(i = 0 ; i < 400 ;i++)
		{
			if(c[i].mark == 1)
				{
				iShowBMP2(c[i].b_x,c[i].b_y,"image\\coin.bmp",0);
				if((manpos_x >= c[i].b_x-40 && manpos_x <= c[i].b_x+40) && c[i].mark == 1 && (c[i].b_y <= manpos_y +80 && c[i].b_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (c[i].b_y >= 0 && c[i].b_y <= 200))
					{
						c[i].mark = 0;
						s += 100;
						sprintf_s(score,"%d",s);
					}	
				
				}
				if(c[i].b_y < 0)c[i].mark = 0;
			
			}
		}
		for(i = 0 ; i < 400 ;i++)
		{
			if(c1[i].mark == 1)
				{
				iShowBMP2(c1[i].b_x,c1[i].b_y,"image\\coin1.bmp",0);
				if((manpos_x >= c1[i].b_x-40 && manpos_x <= c1[i].b_x+40) && c1[i].mark == 1 && (c1[i].b_y <= manpos_y +80 && c1[i].b_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (c1[i].b_y >= 0 && c1[i].b_y <= 200))
					{
						c1[i].mark = 0;
						s -= 50;
						sprintf_s(score,"%d",s);
					}	
				
				}
				if(c1[i].b_y < 0)c[i].mark = 0;
			
			}
		}
		for(i = 0 ; i < 3 ; i++)
		{
			if(life[i].mark1 == 1)
			{
				iShowBMP2(life[i].li_x,life[i].li_y,"image\\heart.bmp",0);
				if((manpos_x >= life[i].li_x-30 && manpos_x <= life[i].li_x+70) && life[i].mark1 == 1 && (life[i].li_y <= manpos_y +80 && life[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (life[i].li_y >= 0 && life[i].li_y <= 200))
					{
						life[i].mark1 = 0;
						l++;
						sprintf_s(lifes,"%d",l);
					}
				}
				 if(life[i].li_y <= 0)
					life[i].mark1 = 0;

			}
			if(sheild[i].mark1 == 1)
			{
				iShowBMP2(sheild[i].li_x,sheild[i].li_y,"image\\sheild.bmp",0);
				if((manpos_x >= sheild[i].li_x-30 && manpos_x <= sheild[i].li_x+80) && sheild[i].mark1 == 1 && (sheild[i].li_y <= manpos_y +80 && sheild[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (sheild[i].li_y >= 0 && sheild[i].li_y <= 200))
					{
						sheild[i].mark1 = 0;
						s_v = 1;
						s_f = 0;
					}
				}
				 if(sheild[i].li_y <= 0)
					sheild[i].mark1 = 0;
			}

		}
}
void level3()
{
		iShowBMP(0,30,"image\\level3.bmp");
		iShowBMP(0,0,"image\\road.bmp");
		iShowBMP(0,500,"image\\board.bmp");
		iShowBMP(screen_x,screen_y,"image\\level31.bmp");
		iShowBMP2(768,512,"image\\pause.bmp",16777215);
		if(p_s)iShowBMP(768,512,"image\\pause1.bmp");
		iResumeTimer(t1);
		iResumeTimer(t2);
		iResumeTimer(t4);
		iResumeTimer(t5);
		iSetColor(0,0,0);
		iText(10,560,"Name : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,560,str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,560,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(650,560,score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(375,560,"Lifes :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450,560,lifes,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10,510,"Times : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,510,times,GLUT_BITMAP_TIMES_ROMAN_24);
		if(s_v)
		{
			iShowBMP2(375,510,"image\\sheild.bmp",0);
			iText(435,515,sheilds,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(580,510,"Levels : ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(levels,"%d",level);
		iText(680,510,levels,GLUT_BITMAP_TIMES_ROMAN_24);
		if(x)iShowBMP2(manpos_x,manpos_y,"image\\shake1.bmp",16777215);
		if(y)iShowBMP2(manpos_x,manpos_y,"image\\shake2.bmp",16777215);
		if(x2)iShowBMP2(manpos_x,manpos_y,"image\\boxer1.bmp",0);
		if(y2)iShowBMP2(manpos_x,manpos_y,"image\\boxer2.bmp",0);

	
		for(i = 0 ; i < 600 ;i++)
		{
			if(b[i].mark == 1)
			{
				iShowBMP(b[i].b_x,b[i].b_y,"image\\brick4.bmp");
				if((manpos_x >= b[i].b_x-40 && manpos_x <= b[i].b_x+64) && b[i].mark == 1 && (b[i].b_y <= manpos_y +80 && b[i].b_y >= 0))
				{
					if(s_f == 1)
					{
						if((manpos_y >= 0 && manpos_y < 40) && (b[i].b_y >= 10 && b[i].b_y < 80))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP2(manpos_x,manpos_y+70,"image\\opps.bmp",16777215);
							l--;
							sprintf_s(lifes,"%d",l);
							if(l == 0)screen = 8;
						}
					
						else if((manpos_y >= 40 && manpos_y <= 200) && (b[i].b_y >= 80 && b[i].b_y <= 200))
						{
							b[i].mark = 0;
							op = 1;
							if(op)iShowBMP(manpos_x, manpos_y+70,"image\\broke.bmp");
							s += 10;
							sprintf_s(score,"%d",s);
						}
						
					}
					else if(s_f == 0)
					{
						if(b[i].b_y <= 0)
						{
							if(flag == 0)
							{
								flag = 1;
								s += 20;
								sprintf_s(score,"%d",s);
								b[i].mark =0;	
							}

						}
					}
				}
				else if(b[i].b_y <= 0)
				{
					if(flag == 0)
					{
						if(create <= 599)
						{
							flag = 1;
							s++;
							sprintf_s(score,"%d",s);
							b[i].mark =0;
						}
						else screen = 9;
					}
				}
			}
			op= 0;
			flag = 0;
		}			
		for(i = 0 ; i < 600 ;i++)
		{
			if(c[i].mark == 1)
				{
				iShowBMP2(c[i].b_x,c[i].b_y,"image\\coin.bmp",0);
				if((manpos_x >= c[i].b_x-40 && manpos_x <= c[i].b_x+40) && c[i].mark == 1 && (c[i].b_y <= manpos_y +80 && c[i].b_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (c[i].b_y >= 0 && c[i].b_y <= 200))
					{
						c[i].mark = 0;
						s += 100;
						sprintf_s(score,"%d",s);
					}	
				
				}
				if(c[i].b_y < 0)c[i].mark = 0;
			
			}
		}
		for(i = 0 ; i < 600 ;i++)
		{
			if(c1[i].mark == 1)
				{
				iShowBMP2(c1[i].b_x,c1[i].b_y,"image\\coin1.bmp",0);
				if((manpos_x >= c1[i].b_x-40 && manpos_x <= c1[i].b_x+40) && c1[i].mark == 1 && (c1[i].b_y <= manpos_y +80 && c1[i].b_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (c1[i].b_y >= 0 && c1[i].b_y <= 200))
					{
						c1[i].mark = 0;
						s -= 50;
						sprintf_s(score,"%d",s);
					}	
				
				}
				if(c1[i].b_y < 0)c[i].mark = 0;
			
			}
		}
		for(i = 0 ; i < 2 ; i++)
		{
			if(life[i].mark1 == 1)
			{
				iShowBMP2(life[i].li_x,life[i].li_y,"image\\heart.bmp",0);
				if((manpos_x >= life[i].li_x-30 && manpos_x <= life[i].li_x+70) && life[i].mark1 == 1 && (life[i].li_y <= manpos_y +80 && life[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (life[i].li_y >= 0 && life[i].li_y <= 200))
					{
						life[i].mark1 = 0;
						l++;
						sprintf_s(lifes,"%d",l);
					}
				}
				 if(life[i].li_y <= 0)
					life[i].mark1 = 0;

			}
			if(sheild[i].mark1 == 1)
			{
				iShowBMP2(sheild[i].li_x,sheild[i].li_y,"image\\sheild.bmp",0);
				if((manpos_x >= sheild[i].li_x-30 && manpos_x <= sheild[i].li_x+80) && sheild[i].mark1 == 1 && (sheild[i].li_y <= manpos_y +80 && sheild[i].li_y >= 0))
				{
					if((manpos_y >= 0 && manpos_y <= 200) && (sheild[i].li_y >= 0 && sheild[i].li_y <= 200))
					{
						sheild[i].mark1 = 0;
						s_v = 1;
						s_f = 0;
					}
				}
				 if(sheild[i].li_y <= 0)
					sheild[i].mark1 = 0;
			}

		}
}
void sort()
{
	int k;
	for(i = 0 ; i < 4 ; i++)
	{
		for(k = 0 ; k < 4 ; k++)
		{
			if(h[k].scores < h[k+1].scores)
			{
				temp = h[k+1];
				h[k+1] = h[k];
				h[k] = temp;
			}
		}
	}
	SaveToFile();

}
void CopyFromFile()
{
	namefile = fopen("hscore.txt","r");
	for(i = 0 ; i < 4 ; i++)
	{
		fscanf(namefile,"%s %d\n",h[i].name, &h[i].scores);
	}
	fclose(namefile);
}
void SaveToFile()
{
	namefile = fopen("hscore.txt","w");
	for(i = 0 ; i < 4 ; i++)
	{
		fprintf(namefile,"%s %d\n",h[i].name, h[i].scores);
	}
	fclose(namefile);
}
void showHighscore()
{
	int dy = 330;
	for(i = 0 ; i < 4 ; i++,dy -= 330/5)
	{
		iSetColor(128,128,128);
		iFilledRectangle(50,dy-5,680,30);
		iSetColor(72,0,0);
		iText(80,dy,h[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
		char text[80];
		sprintf_s(text,"%d",h[i].scores);
		iText(530,dy,text,GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
}
void brickpreprocesslvl1()
{
		for(i = 0 ; i< 300 ; i++)
		{
			b[i].speed= (rand()%10)+10;
			b[i].b_x = rand()%800;
			b[i].b_y = 500;
			b[i].mark = 0;
			c[i].speed= (rand()%5)+10;
			c[i].b_x = rand()%790;
			c[i].b_y = 500;
			c[i].mark = 0;
		}
		b[0].mark = 1;
		create =1;
		c[0].mark = 1;
		create1 =1;
		CopyFromFile();

}
void brickpreprocesslvl2()
{
		for(i = 0 ; i< 400 ; i++)
		{
			b[i].speed= (rand()%20)+15;
			b[i].b_x = rand()%800;
			b[i].b_y = 500;
			b[i].mark = 0;
			c[i].speed= (rand()%10)+10;
			c[i].b_x = rand()%790;
			c[i].b_y = 500;
			c[i].mark = 0;
			c1[i].speed= (rand()%10)+10;
			c1[i].b_x = rand()%790;
			c1[i].b_y = 500;
			c1[i].mark = 0;
		}
		b[0].mark = 1;
		create =1;
		c[0].mark = 1;
		create1 =1;
		c1[0].mark = 1;
		create1 =1;

}
void brickpreprocesslvl3()
{
		for(i = 0 ; i< 600 ; i++)
		{
			b[i].speed= (rand()%20)+20;
			b[i].b_x = rand()%800;
			b[i].b_y = 500;
			b[i].mark = 0;
			c[i].speed= (rand()%15)+10;
			c[i].b_x = rand()%790;
			c[i].b_y = 500;
			c[i].mark = 0;
			c1[i].speed= (rand()%15)+10;
			c1[i].b_x = rand()%790;
			c1[i].b_y = 500;
			c1[i].mark = 0;
		}
		b[0].mark = 1;
		create =1;
		c[0].mark = 1;
		create1 =1;
		c1[0].mark = 1;
		create1 =1;

}
void screenmove()
{
	if(screen_d == 1)
	{
		screen_x -= 10;
		screen_y  -= 5;
		if(screen_x <= 0)
			screen_d = 2;
	}
	else if(screen_d == 2)
	{
		screen_x += 10;
		screen_y += 5;
		if(screen_x >= 20)
			screen_d = 1;
	}
}
void loading()
{
	iClear();
	iShowBMP(0,0,"image\\load.bmp");
	iShowBMP2(50,200,"image\\loading.bmp",0);
	iSetColor(143,11,3);
	iFilledRectangle(50,150,750,40);
	if(l_x >= 750)
	{
		if(lo == 1)
		{
		iPauseTimer(t2);
		l_x = 20;
		screen = 1;	
		play_s = false;
		play_s1 = false;
		play_s2 = true;
		play_s3 = false;
		play_s4 = false;
		play_s5 = false;
		lo = 2;
		}
		else
		{
			iPauseTimer(t2);
			l_x = 20;
			screen = 2;
			level = 1;
			play_s = false;
		play_s1 = false;
		play_s2 = false;
		play_s3 = true;
		play_s4 = false;
		play_s5 = false;
			screen = 2;
		}
		
	}
	iSetColor(56,128,4);
	iFilledRectangle(52,153,l_x,34);
}
void timer()
{
	if(screen == 2)
	{
		brick_create();
	}
	else if(screen == 12)
	{
		l_x += 90;
	}
}
void brick_create()
{
	if(level == 1)
	{
		if(create < 300)
		{
			b[create].mark =1;
			create++;
		}
		if(create1 < 300)
		{
			c[create1].mark =1;
			create1++;
		}
	}
	else if(level == 2)
	{
		if(create < 400)
		{
			b[create].mark =1;
			create++;
		}
		if(create1 < 400)
		{
			c[create1].mark =1;
			c1[create1].mark =1;
			create1++;
		}
	}
	else if(level == 3)
	{
		if(create < 600)
		{
			b[create].mark =1;
			create++;
		}
		if(create1 < 600)
		{
			c[create1].mark =1;
			c1[create1].mark =1;
			create1++;
		}
	}
}
void manmove()
{
	if(x_1 == 1)
	{
		y2 = 0;
		x2 = 1;
	}
	else if(y_1 == 1)
	{
		x2 = 0;
		y2 = 1;
	}
	if(man_d == 1)
	{
		manpos_y += 5;
		if(manpos_y >= (rand()%100 + 100))
		{
			man_d = 2;
		}
	}
	if(man_d == 2)
	{
		manpos_y -= 5;
		if(manpos_y <= 10)
		{
			iPauseTimer(t3);
			x2 = 0 ;
			y2 = 0;
			man_d =1;
		}
	}
}
void brick_move()
{
	if(level == 1)
	{
	for(i = 0 ; i < 300 ; i++)
	{
		if(b[i].mark == 1)
		{
			b[i].b_y -= b[i].speed;
		}
		if(c[i].mark == 1)
		{
			c[i].b_y -= c[i].speed;
		}
	}
	for(i = 0 ; i < 5 ; i++)
	{
		if(life[i].mark1 == 1)
		{
			life[i].li_y -= life[i].speed1;
		}
		if(sheild[i].mark1 == 1)
		{
			sheild[i].li_y -= sheild[i].speed1;
		}
	}
	}
	if(level == 2)
	{
	for(i = 0 ; i < 400 ; i++)
	{
		if(b[i].mark == 1)
		{
			b[i].b_y -= b[i].speed;
		}
		if(c[i].mark == 1)
		{
			c[i].b_y -= c[i].speed;
		}
		if(c1[i].mark == 1)
		{
			c1[i].b_y -=c1[i].speed;
		}
	}
	for(i = 0 ; i < 3 ; i++)
	{
		if(life[i].mark1 == 1)
		{
			life[i].li_y -= life[i].speed1;
		}
		if(sheild[i].mark1 == 1)
		{
			sheild[i].li_y -= sheild[i].speed1;
		}
	}
	}
	if(level == 3)
	{
	for(i = 0 ; i < 600 ; i++)
	{
		if(b[i].mark == 1)
		{
			b[i].b_y -= b[i].speed;
		}
		if(c[i].mark == 1)
		{
			c[i].b_y -= c[i].speed;
		}
		if(c1[i].mark == 1)
		{
			c1[i].b_y -= c1[i].speed;
		}
	}
	for(i = 0 ; i < 2 ; i++)
	{
		if(life[i].mark1 == 1)
		{
			life[i].li_y -= life[i].speed1;
		}
		if(sheild[i].mark1 == 1)
		{
			sheild[i].li_y -= sheild[i].speed1;
		}
	}
	}
}

void a_time()
{
	if(screen == 13)
	{
			if(image_d == 1)image_d = 0;
			else if(image_d == 0)image_d = 1;
	}
	else if(screen == 7)
	{
		if(node == 0)
		{
			if(image_d == 1)image_d = 0;
			else if(image_d == 0)image_d = 1;
		}
	}
	else if(screen == 11)
	{
		a_count++;
		if(a_count > 110)
		{
			iPauseTimer(t6);
			screen = 12;
			iResumeTimer(t2);
		}
	}
	else if(screen == 14)
	{
			if(image_d == 1)image_d = 0;
			else if(image_d == 0)image_d = 1;
	}
}
void animation()
{
	if(a_count == 1)
	{
		iClear();
		iShowBMP(0,0,"image\\1.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 2)
	{
		iClear();
		iShowBMP(0,0,"image\\2.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count ==3)
	{
		iClear();
		iShowBMP(0,0,"image\\3.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 4)
	{
		iClear();
		iShowBMP(0,0,"image\\4.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 5)
	{
		iClear();
		iShowBMP(0,0,"image\\5.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 6)
	{
		iClear();
		iShowBMP(0,0,"image\\6.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count ==7)
	{
		iClear();
		iShowBMP(0,0,"image\\7.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 8)
	{
		iClear();
		iShowBMP(0,0,"image\\8.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 9)
	{
		iClear();
		iShowBMP(0,0,"image\\9.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 10)
	{
		iClear();
		iShowBMP(0,0,"image\\10.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 11)
	{
		iClear();
		iShowBMP(0,0,"image\\11.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 12)
	{
		iClear();
		iShowBMP(0,0,"image\\12.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 13)
	{
		iClear();
		iShowBMP(0,0,"image\\13.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 14)
	{
		iClear();
		iShowBMP(0,0,"image\\14.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 15)
	{
		iClear();
		iShowBMP(0,0,"image\\15.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 16)
	{
		iClear();
		iShowBMP(0,0,"image\\16.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 17)
	{
		iClear();
		iShowBMP(0,0,"image\\17.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 18)
	{
		iClear();
		iShowBMP(0,0,"image\\18.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 19)
	{
		iClear();
		iShowBMP(0,0,"image\\19.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 20)
	{
		iClear();
		iShowBMP(0,0,"image\\20.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 21)
	{
		iClear();
		iShowBMP(0,0,"image\\21.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 22)
	{
		iClear();
		iShowBMP(0,0,"image\\22.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 23)
	{
		iClear();
		iShowBMP(0,0,"image\\23.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 24)
	{
		iClear();
		iShowBMP(0,0,"image\\24.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 25)
	{
		iClear();
		iShowBMP(0,0,"image\\25.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 26)
	{
		iClear();
		iShowBMP(0,0,"image\\26.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 27)
	{
		iClear();
		iShowBMP(0,0,"image\\27.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 28)
	{
		iClear();
		iShowBMP(0,0,"image\\28.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 29)
	{
		iClear();
		iShowBMP(0,0,"image\\29.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 30)
	{
		iClear();
		iShowBMP(0,0,"image\\30.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 31)
	{
		iClear();
		iShowBMP(0,0,"image\\31.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 32)
	{
		iClear();
		iShowBMP(0,0,"image\\32.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 33)
	{
		iClear();
		iShowBMP(0,0,"image\\33.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 34)
	{
		iClear();
		iShowBMP(0,0,"image\\34.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 35)
	{
		iClear();
		iShowBMP(0,0,"image\\35.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count ==36)
	{
		iClear();
		iShowBMP(0,0,"image\\36.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 37)
	{
		iClear();
		iShowBMP(0,0,"image\\37.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 38)
	{
		iClear();
		iShowBMP(0,0,"image\\38.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 39)
	{
		iClear();
		iShowBMP(0,0,"image\\39.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 40)
	{
		iClear();
		iShowBMP(0,0,"image\\40.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 41)
	{
		iClear();
		iShowBMP(0,0,"image\\41.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 42)
	{
		iClear();
		iShowBMP(0,0,"image\\42.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 43)
	{
		iClear();
		iShowBMP(0,0,"image\\43.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 44)
	{
		iClear();
		iShowBMP(0,0,"image\\44.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 45)
	{
		iClear();
		iShowBMP(0,0,"image\\45.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 46)
	{
		iClear();
		iShowBMP(0,0,"image\\46.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 47)
	{
		iClear();
		iShowBMP(0,0,"image\\47.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 48)
	{
		iClear();
		iShowBMP(0,0,"image\\48.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 49)
	{
		iClear();
		iShowBMP(0,0,"image\\49.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 50)
	{
		iClear();
		iShowBMP(0,0,"image\\50.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 51)
	{
		iClear();
		iShowBMP(0,0,"image\\51.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 52)
	{
		iClear();
		iShowBMP(0,0,"image\\52.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 53)
	{
		iClear();
		iShowBMP(0,0,"image\\53.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 54)
	{
		iClear();
		iShowBMP(0,0,"image\\54.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 55)
	{
		iClear();
		iShowBMP(0,0,"image\\55.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 56)
	{
		iClear();
		iShowBMP(0,0,"image\\56.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 57)
	{
		iClear();
		iShowBMP(0,0,"image\\57.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 58)
	{
		iClear();
		iShowBMP(0,0,"image\\58.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 59)
	{
		iClear();
		iShowBMP(0,0,"image\\59.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 60)
	{
		iClear();
		iShowBMP(0,0,"image\\60.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 61)
	{
		iClear();
		iShowBMP(0,0,"image\\61.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 62)
	{
		iClear();
		iShowBMP(0,0,"image\\62.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 63)
	{
		iClear();
		iShowBMP(0,0,"image\\63.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 64)
	{
		iClear();
		iShowBMP(0,0,"image\\64.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 65)
	{
		iClear();
		iShowBMP(0,0,"image\\65.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 66)
	{
		iClear();
		iShowBMP(0,0,"image\\66.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 67)
	{
		iClear();
		iShowBMP(0,0,"image\\67.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 68)
	{
		iClear();
		iShowBMP(0,0,"image\\68.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 69)
	{
		iClear();
		iShowBMP(0,0,"image\\69.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 70)
	{
		iClear();
		iShowBMP(0,0,"image\\70.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 71)
	{
		iClear();
		iShowBMP(0,0,"image\\71.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 72)
	{
		iClear();
		iShowBMP(0,0,"image\\72.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 73)
	{
		iClear();
		iShowBMP(0,0,"image\\73.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 74)
	{
		iClear();
		iShowBMP(0,0,"image\\74.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 75)
	{
		iClear();
		iShowBMP(0,0,"image\\75.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 76)
	{
		iClear();
		iShowBMP(0,0,"image\\76.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 77)
	{
		iClear();
		iShowBMP(0,0,"image\\77.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 78)
	{
		iClear();
		iShowBMP(0,0,"image\\78.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 79)
	{
		iClear();
		iShowBMP(0,0,"image\\79.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 80)
	{
		iClear();
		iShowBMP(0,0,"image\\80.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 81)
	{
		iClear();
		iShowBMP(0,0,"image\\81.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 82)
	{
		iClear();
		iShowBMP(0,0,"image\\82.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 83)
	{
		iClear();
		iShowBMP(0,0,"image\\83.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 84)
	{
		iClear();
		iShowBMP(0,0,"image\\84.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 85)
	{
		iClear();
		iShowBMP(0,0,"image\\85.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 86)
	{
		iClear();
		iShowBMP(0,0,"image\\86.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 87)
	{
		iClear();
		iShowBMP(0,0,"image\\87.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 88)
	{
		iClear();
		iShowBMP(0,0,"image\\88.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 89)
	{
		iClear();
		iShowBMP(0,0,"image\\89.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 90)
	{
		iClear();
		iShowBMP(0,0,"image\\90.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 91)
	{
		iClear();
		iShowBMP(0,0,"image\\91.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 92)
	{
		iClear();
		iShowBMP(0,0,"image\\92.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 93)
	{
		iClear();
		iShowBMP(0,0,"image\\93.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 94)
	{
		iClear();
		iShowBMP(0,0,"image\\94.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 95)
	{
		iClear();
		iShowBMP(0,0,"image\\95.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 96)
	{
		iClear();
		iShowBMP(0,0,"image\\96.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 97)
	{
		iClear();
		iShowBMP(0,0,"image\\97.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 98)
	{
		iClear();
		iShowBMP(0,0,"image\\98.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 99)
	{
		iClear();
		iShowBMP(0,0,"image\\99.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 100)
	{
		iClear();
		iShowBMP(0,0,"image\\100.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 101)
	{
		iClear();
		iShowBMP(0,0,"image\\101.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 102)
	{
		iClear();
		iShowBMP(0,0,"image\\102.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 103)
	{
		iClear();
		iShowBMP(0,0,"image\\103.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 104)
	{
		iClear();
		iShowBMP(0,0,"image\\104.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 105)
	{
		iClear();
		iShowBMP(0,0,"image\\105.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 106)
	{
		iClear();
		iShowBMP(0,0,"image\\106.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 107)
	{
		iClear();
		iShowBMP(0,0,"image\\107.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 108)
	{
		iClear();
		iShowBMP(0,0,"image\\108.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 109)
	{
		iClear();
		iShowBMP(0,0,"image\\109.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(a_count == 110)
	{
		iClear();
		iShowBMP(0,0,"image\\110.bmp");
		iSetColor(0,0,0);
		iText(340,550,"Press Enter to Skip All",GLUT_BITMAP_TIMES_ROMAN_24);
	}


}
void menu()
{
	PlaySound("music\\menu",NULL,SND_LOOP | SND_ASYNC);
	iClear();
	iShowBMP(0,0,"image\\Menu1.bmp");
	g_d = 0;
	ti = 0;
	s = 0;
	l = 5;
	c_s = 0;
	hl_s = 0;
	h_s = 0;
	s_s = 0;
	w_s = 0;
	sprintf_s(score,"%d",s);
	sprintf_s(times,"%d",ti);
	sprintf_s(lifes,"%d",l);
	brickpreprocesslvl1();
	laslvl1();
	if(count == 1)iShowBMP(270,410,"image\\newgame.bmp");
	else if(count == 2)iShowBMP(270,330,"image\\control1.bmp");
	else if(count ==3)iShowBMP(270,260,"image\\sound1.bmp");
	else if(count == 4)iShowBMP(270,185,"image\\help1.bmp");
	else if(count == 5)iShowBMP(270,105,"image\\score.bmp");
	else if(count == 6)iShowBMP(270,25,"image\\exit.bmp");
}
void time()
{
	ti++;
	sprintf_s(times,"%d",ti);
	if(level == 1)
	{
		s_count++;
		if(lc < 5)
		{
			if(s_count == 35)
			{
				life[lc].mark1 = 1;
				lc++;
			}
		}
		if(sc < 5)
		{
			if(s_count == 40)
			{
				sheild[sc].mark1 = 1;
				sc++;
				s_count = 0;
			}
			if(s_v == 1)
			{
				s_count1--;
				sprintf_s(sheilds,"%d",s_count1);
			}
			if(s_count1 == 0)
			{
				s_v = 0;
				s_f = 1;
				s_count1 = 30;
				sprintf_s(sheilds,"%d",s_count1);
			}
		}
	}
	else if(level == 2)
	{
		s_count++;
		if(lc < 3)
		{
			if(s_count == 60)
			{
				life[lc].mark1 = 1;
				lc++;
			}
		}
		if(sc < 3)
		{
			if(s_count == 70)
			{
				sheild[sc].mark1 = 1;
				sc++;
				s_count = 0;
			}
			if(s_v == 1)
			{
				s_count1--;
				sprintf_s(sheilds,"%d",s_count1);
			}
			if(s_count1 == 0)
			{
				s_v = 0;
				s_f = 1;
				s_count1 = 50;
				sprintf_s(sheilds,"%d",s_count1);
			}
		}
	}
	else if(level == 3)
	{
		s_count++;
		if(lc < 2)
		{
			if(s_count == 90)
			{
				life[lc].mark1 = 1;
				lc++;
			}
		}
		if(sc < 2)
		{
			if(s_count == 120)
			{
				sheild[sc].mark1 = 1;
				sc++;
				s_count = 0;
			}
			if(s_v == 1)
			{
				s_count1--;
				sprintf_s(sheilds,"%d",s_count1);
			}
			if(s_count1 == 0)
			{
				s_v = 0;
				s_f = 1;
				s_count1 = 70;
				sprintf_s(sheilds,"%d",s_count1);
			}
		}
	}
}
void namemove()
{
	d_dy += 11;
	n_dy -=10;
	p_dx -= 20;
	if(d_dy >= 300)
	{
		d_dy = 300;
	}
	if(n_dy <= 180)
	{
		n_dy = 180;
	}
	if(p_dx <= 140)
	{
		p_dx = 140;
	}
}
void name()
{

	iClear();
	iShowBMP(0,0,"image\\game1.bmp");
	iShowBMP2(180,450,"image\\present.bmp",16777215);
	iShowBMP2(120,d_dy,"image\\debashis.bmp",16777215);
	iShowBMP2(p_dx,250,"image\\prottasa.bmp",16777215);
	iShowBMP2(140,n_dy,"image\\neaz.bmp",16777215);
	iResumeTimer(t6);
	if(image_d)iShowBMP2(120,20,"image\\continue1.bmp",16777215);
}
void extra()
{
	iClear();
	if(level == 1)
	{
	iPauseTimer(t1);
	iPauseTimer(t2);
	iPauseTimer(t4);
	iPauseTimer(t5);
	iShowBMP(0,0,"image\\extra.bmp");
	if(image_d)iShowBMP2(150,50,"image\\continue.bmp",16777215);
	lc = 0;
	sc = 0;
	brickpreprocesslvl2();
	laslvl2();
	s_count1 = 50;
	sprintf_s(sheilds,"%d",s_count1);
	s_count = 0;
	play_s = false;
		play_s1 = false;
		play_s2 = false;
		play_s3 = false;
		play_s4 = false;
		play_s5 = false;
	}
	else if(level == 2)
	{
		iPauseTimer(t1);
		iPauseTimer(t2);
		iPauseTimer(t4);
		iPauseTimer(t5);
		iShowBMP(0,0,"image\\extra1.bmp");
		if(image_d)iShowBMP2(150,50,"image\\continue.bmp",16777215);
		lc = 0;
		sc = 0;
		brickpreprocesslvl3();
		laslvl3();
		s_count1 = 70;
		sprintf_s(sheilds,"%d",s_count1);
		s_count = 0;
		play_s = false;
		play_s1 = false;
		play_s2 = false;
		play_s3 = false;
		play_s4 = false;
		play_s5 = false;
	}

}
void game()
{
	iClear();
	if(level == 1)
	{
		if(create > 299)
		{
			screen = 13;
			iResumeTimer(t6);
		}
		else level1();
	}
	else if(level == 2)
	{
		if(create > 399)
		{
			screen = 13;
			iResumeTimer(t6);
		}
		else level2();
	}
	else if(level == 3)
	{
		level3();
	}
}
void control()
{
	iClear();
	iShowBMP(0,0,"image\\control.bmp");
	if(c_s)iShowBMP(590,9,"image\\back.bmp");
}
void help()
{
	iClear();
	iShowBMP(0,0,"image\\help.bmp");
	if(hl_s)iShowBMP(587,20,"image\\back1.bmp");
}
void sound()
{
	iClear();
	iShowBMP(0,0,"image\\sound.bmp");
	if(s_s == 1)iShowBMP(35,125,"image\\yes.bmp");
	if(s_s == 2)iShowBMP(590,125,"image\\no.bmp");
}
void highscore()
{
	iClear();
	iShowBMP(0,0,"image\\highscore.bmp");
	if(h_s)iShowBMP(590,25,"image\\back2.bmp");
	iShowBMP2(10,350,"image\\name.bmp",16777215);
	iShowBMP2(450,350,"image\\score1.bmp",16777215);
	CopyFromFile();
	showHighscore();
	
}
void username()
{
	if(node == 0)
	{
		iClear();
		iShowBMP(0,0,"image\\user.bmp");
		iShowBMP2(50,500,"image\\player.bmp",16777215);
		iSetColor(r,g,bl);
		if(text_d_r == 1)r+=10;
		if(r > 255)text_d_r = 2;
		if(text_d_r == 2)r-=10;
		if(r <=0)text_d_r =1;
		if(text_d_g == 1)g+=10;
		if(g > 255)text_d_g = 2;
		if(text_d_g == 2)g-=10;
		if(g <=0)text_d_g =1;
		if(text_d_b == 1)bl+=10;
		if(bl > 255)text_d_b = 2;
		if(text_d_b == 2)bl-=10;
		if(bl <=0)text_d_b =1;
		fp = fopen("name.txt","r");
		fscanf(fp,"%s",str1);
		fclose(fp);
		iText(100,470,str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(470,500,"image\\player1.bmp",16777215);
		iSetColor(255,255,255);
		iFilledRectangle(460,440,370,40);
		iSetColor(0,0,0);
		iText(600,455, "Click Here",GLUT_BITMAP_HELVETICA_18);
		if(image_d)iShowBMP2(150,120,"image\\continue.bmp",16777215);
	}
	else if(node == 1)
	{
		iClear();
		iShowBMP(0,0,"image\\user1.bmp");
		if(enter)iShowBMP(605,115,"image\\enter.bmp");
		iSetColor(r,g,bl);
		if(text_d_r == 1)r+=10;
		if(r > 255)text_d_r = 2;
		if(text_d_r == 2)r-=10;
		if(r <=0)text_d_r =1;
		if(text_d_g == 1)g+=10;
		if(g > 255)text_d_g = 2;
		if(text_d_g == 2)g-=10;
		if(g <=0)text_d_g =1;
		if(text_d_b == 1)bl+=10;
		if(bl > 255)text_d_b = 2;
		if(text_d_b == 2)bl-=10;
		if(bl <=0)text_d_b =1;
		iText(425,290,"INSERT NEW PLAYER NAME",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(115,118,121);
		iFilledRectangle(370,205,400,45);
		iSetColor(0,0,0);
		iText(375,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
		
}
void gameover()
{
	iClear();
	iShowBMP(0,0,"image\\gameover.bmp");
	iSetColor(re,ge,blu);
	if(text_d == 1)
	{
		re += 122;
		ge += 100;
		blu += 122;
		if(re > 255 || ge > 255 || blu > 255)
			text_d = 2;
	}
	else if(text_d == 2)
	{
		re -= 122;
		ge -= 100;
		blu -= 122;
		if(re < 0 || ge < 0 || blu < 0)
			text_d = 1;
	}
	iText(350,180,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);
	iFilledRectangle(320,115,200,50);
	iSetColor(0,0,0);
	iText(400,130,score,GLUT_BITMAP_TIMES_ROMAN_24);
	if(g_d == 1)iShowBMP(18,19,"image\\restartt.bmp");
	if(g_d == 2)iShowBMP(605,19,"image\\menu.bmp");
	strcpy(h[j].name,str1);
	h[j].scores = s;
	if(h[j].scores > h[3].scores)
	{
		sort();
		lo = 2;
		h_s = 0;
		screen = 6;
	}
	
}
void win()
{
	iClear();
	iShowBMP(0,0,"image\\you win.bmp");
	iSetColor(re,ge,blu);
	if(text_d == 1)
	{
		re += 122;
		ge += 100;
		blu += 122;
		if(re > 255 || ge > 255 || blu > 255)
			text_d = 2;
	}
	else if(text_d == 2)
	{
		re -= 122;
		ge -= 100;
		blu -= 122;
		if(re < 0 || ge < 0 || blu < 0)
			text_d = 1;
	}
	iText(350,180,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);
	iFilledRectangle(320,115,200,50);
	iSetColor(0,0,0);
	iText(400,130,score,GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(550,30,"image\\menu2.bmp");
	if(w_s)iShowBMP(540,20,"image\\menu.bmp");
	strcpy(h[j].name,str1);
	h[j].scores = s;
	if(h[j].scores > h[3].scores)
	{
		sort();
		lo = 2;
		h_s = 0;
		screen = 6;
	}
}
void pausemenu()
{
	iPauseTimer(t1);
	iPauseTimer(t2);
	iPauseTimer(t4);
	iPauseTimer(t5);
	if(p == 1)
	{
		iClear();
		iShowBMP(0,0,"image\\pausemenu2.bmp");
		if(count1 == 1)iShowBMP(190,380,"image\\Resume.bmp");
		else if(count1 == 2)iShowBMP(190,270,"image\\restart.bmp");
		else if(count1 == 3)iShowBMP(190,140,"image\\soundon.bmp");
		else if(count1 == 4)iShowBMP(190,10,"image\\quittomenu.bmp");

	}
	else if(p == 2)
	{
		iClear();
		iShowBMP(0,0,"image\\pausemenu1.bmp");
		if(count1 == 1)iShowBMP(190,380,"image\\Resume.bmp");
		else if(count1 == 2)iShowBMP(190,270,"image\\restart.bmp");
		else if(count1 == 3)iShowBMP(190,140,"image\\soundof.bmp");
		else if(count1 == 4)iShowBMP(190,10,"image\\quittomenu.bmp");

	}
}

void restart()
{
	ti = 0;
	s = 0;
	l = 5;
	p_s = 0;
	g_d = 0;
	level1;
	brickpreprocesslvl1();
	laslvl1();
	create = 0;
	sprintf_s(score,"%d",s);
	sprintf_s(times,"%d",ti);
	sprintf_s(lifes,"%d",l);
	screen = 2;
}
void iDraw()
{
	
	iClear();
	if(screen == 0)
	{
		iClear();
		iShowBMP(0,0,"image\\game.bmp");
		iSetColor(r,g,bl);
		if(text_d_r == 1)r+=5;
		if(r > 255)text_d_r = 2;
		if(text_d_r == 2)r-=2;
		if(r <=0)text_d_r =1;
		if(text_d_g == 1)g+=5;
		if(g > 255)text_d_g = 2;
		if(text_d_g == 2)g-=5;
		if(g <=0)text_d_g =1;
		if(text_d_b == 1)bl+=2;
		if(bl > 255)text_d_b = 2;
		if(text_d_b == 2)bl-=5;
		if(bl <=0)text_d_b =1;
		iText(300,38,"Press Enter For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	else if(screen == 1) menu();
	else if(screen == 2)game();
	else if(screen == 3)control();
	else if(screen == 4)sound();
	else if(screen == 5)help();
	else if(screen == 6)highscore();
	else if(screen == 7)username();
	else if(screen == 8)gameover();
	else if(screen == 9)win();
	else if(screen == 10)pausemenu();
	else if(screen == 11)animation();
	else if(screen == 12)loading();
	else if(screen == 13)extra();
	else if(screen == 14)name();
	
	
}
void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(screen ==1)//menu
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 410 && my <= 475))
		{
			screen = 7;
			enter = 0;
			iResumeTimer(t6);
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 330 && my <= 395))
		{
				screen = 3;//control
				c_s = 0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 260 && my <= 325))
		{
				screen = 4;//sound
				s_s = 0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 185 && my <= 250))
		{
				screen = 5;//help
				hl_s = 0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 105 && my <= 170))
		{
				screen = 6;//highscore
				h_s = 0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 25 && my <= 90))
		{
				exit(0);
		}
		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here	
		}
	}
	else if(screen == 2)//game
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >= 768 && mx <= 828) && (my >= 512 && my <= 572))
		{
				screen = 10;//pausemenu
				p_s = 0;
				f1 = 0 ;
				count1 = -1;
		}
	}
	else if(screen == 3)//control
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >= 590 && mx <= 830) && (my >= 9 && my <= 101))
		{
				screen = 1;//menu
				count = -1;
		}
	}
	else if(screen == 4)//sound
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=35 && mx <= 255) && (my >= 125 && my <= 195))
		{
			play_s = true;
			play_s1 = true;
			play_s2 = true;
			play_s3 = true;
			play_s4 = true;
			play_s5 = true;
				screen = 1;//menu
				count = -1;
				p = 1;
		}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=590 && mx <= 810) && (my >= 125 && my <= 195))
		{
			play_s = false;
				play_s1 = false;
			play_s2 = false;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
				screen = 1;//menu
				count = -1;
				p = 2;
		}
	}
	else if(screen ==  5)//help
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=587 && mx <= 827) && (my >= 20 && my <= 116))
		{
				screen = 1;//menu
				count = -1;
		}
	}
	
	else if(screen == 6)//highscore
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=590 && mx <= 830) && (my >= 25 && my <= 105))
		{
				screen = 1;//menu
				count = -1;
		}
	}
	else if(screen == 7)//username
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=460 && mx <= 830) && (my >= 440 && my <= 480) && node == 0)
			{
				node = 1;
			}
		if(node == 1)
		{

			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=605 && mx <= 815) && (my >= 115 && my <= 195))
			{
					
					strcpy(str1,str);
					fp = fopen("name.txt","w");
					fprintf(fp,"%s",str1);
					fclose(fp);
					for(i = 0 ; i < len ;i++)
						str[i] = 0;
					len = 0;
					node = 0;
					iResumeTimer(t2);
					screen = 12;
				
			}
		}
	}
	else if(screen == 8)//gameover
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=18 && mx <= 258) && (my >= 19 && my <= 89))
		{
				restart();
				f1 = 0;
				count1 = -1;
				p_s = 0;
				g_d = 0;
		}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=605 && mx <= 845) && (my >= 19 && my <= 89))
		{
				screen = 1;
				count1 = -1;
				f = 0;
				f1 = 0;
				count = -1;
				g_d = 0;
		}
	}
	else if(screen == 9)//win
	{
		
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=540 && mx <= 780) && (my >= 20 && my <= 90))
			{
					screen = 1;
			}

	}
	else if(screen == 10)//pausemenu
	{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=190 && mx <= 640) && (my >= 380 && my <= 470))
			{
					screen = 2;
					f1 = 0;
					count1 = -1;
					p_s = 0;
			}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=190 && mx <= 640) && (my >= 270 && my <= 360))
			{
					restart();
					f1 = 0;
					count1 = -1;
					p_s = 0;
			}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=190 && mx <= 640) && (my >= 140 && my <= 230))
			{
					if(p == 1)
						{
							play_s = false;
				play_s1 = false;
				play_s2 = false;
				play_s3 = false;
				play_s4 = false;
				play_s5 = false;
							p = 2;
					}
					else if(p == 2)
						{
							play_s = true;
				play_s1 = true;
				play_s2 = true;
				play_s3 = true;
				play_s4 = true;
				play_s5 = true;
							p = 1;
					}
			}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >=270 && mx <= 580) && (my >= 25 && my <= 90))
			{
					
					count1 = -1;
					f = 0;
					f1 = 0;
					count = -1;
					lo = 2;
					screen = 1;
					
					
			}
	}
}
void iPassiveMouseMove(int mx,int my)
{
	if(screen == 1)
	{
		if((mx >=270 && mx <= 580) && (my >= 410 && my <= 475))
		{
			count = 1;
		}
		else if((mx >=270 && mx <= 580) && (my >= 330 && my <= 395))
		{
				count = 2;
		}
		else if((mx >=270 && mx <= 580) && (my >= 260 && my <= 325))
		{
				count = 3;
		}
		else if((mx >=270 && mx <= 580) && (my >= 185 && my <= 250))
		{
				count = 4;
		}
		else if((mx >=270 && mx <= 580) && (my >= 105 && my <= 170))
		{
				count = 5;
		}
		else if((mx >=270 && mx <= 580) && (my >= 25 && my <= 90))
		{
				count = 6;
		}
		else
		{
			count = -1;
			f =0;
		}
	}
	else if(screen == 2)//game
	{
		if((mx >= 768 && mx <= 828) && (my >= 512 && my <= 572))
		{
			p_s = 1;
		}
		else  p_s = 0;
	}
	else if(screen == 3)//control
	{
		if((mx >= 590 && mx <= 830) && (my >= 9 && my <= 101))
		{
			c_s = 1;
		}
		else c_s = 0;
		
	}
	else if(screen == 4)//sound
	{
		if((mx >=35 && mx <= 255) && (my >= 125 && my <= 195))
		{
				s_s = 1;
		}
		else if((mx >=590 && mx <= 810) && (my >= 125 && my <= 195))
		{
				s_s = 2;
		}
		else s_s = 0;
	}
	else if(screen == 5)//help
	{
		if((mx >=587 && mx <= 827) && (my >= 20 && my <= 116))
		{
			hl_s = 1;
		}
		else hl_s = 0;
	}
	else if(screen == 6)//highscore
	{
		if((mx >=590 && mx <= 830) && (my >= 25 && my <= 105))
		{
			h_s = 1;
		}
		else h_s = 0;
	}
	else if(screen == 7)//username
	{
		if((mx >=605 && mx <= 815) && (my >= 115 && my <= 195))
		{
				enter = 1;
		}
		else enter = 0;
	}
	else if(screen == 8)//gameover
	{
		if((mx >=18 && mx <= 258) && (my >= 19 && my <= 89))
		{
			g_d = 1;
		}
		else if((mx >=605 && mx <= 845) && (my >= 19 && my <= 89))
		{
			g_d = 2;
		}
		else 
		{
			g_d = 0;
		}
	}
	else if(screen == 9)//win
	{
		if((mx >=540 && mx <= 780) && (my >= 20 && my <= 90))
		{
			w_s = 1;
		}
		else w_s = 0;

	}
	else if(screen == 10)//pause menu
	{
		if((mx >=190 && mx <= 640) && (my >= 380 && my <= 470))
		{
				count1 = 1;
		}
		else if((mx >=190 && mx <= 640) && (my >= 270 && my <= 360))
		{
				count1 = 2;
		}
		else if((mx >=190 && mx <= 640) && (my >= 140 && my <= 230))
		{
				count1 = 3;
		}
		else if((mx >=190 && mx <= 640) && (my >= 10 && my <= 100))
		{
				count1 = 4;
		}
		else
			{
				count1 = -1;
				f1  = 0;
		}
	}
}

void iKeyboard(unsigned char key)
{
	if(screen == 0)
	{
	  if(key == 13)
     	{
			screen = 14;
			iResumeTimer(t6);
			iResumeTimer(t7);
		}
	  play_s = true;
	  play_s1 = false;
	  play_s2 = false;
	  play_s3 = false;
	  play_s4 = false;
	  play_s5 = false;
	}
	else if(screen == 1)//menu
	{
		if(count == 1)
		{
			if(key == 13)
			{
				screen = 7;
				iResumeTimer(t6);
			}
		}
		else if(count == 2)
		{
			if(key == 13)
			{
				screen = 3;
				c_s = 0;
			}
		}
		if(count == 3)
		{
			if(key == 13)
			{
				screen = 4;
				s_s = 0;
			}
		}
		if(count == 4)
		{
			if(key == 13)
			{
				
				screen = 5;
				hl_s = 0;
			}
		}
		if(count == 5)
		{
			if(key == 13)
			{
				screen = 6;
				h_s = 0;
			}
		}
		if(count == 6)
		{
			if(key == 13)
			{
				exit(0);
			}
		}
	}
	else if(screen == 2)//game
	{
		if(key == ' ')
		{
			iResumeTimer(t3);
		}
		else if(key == 27)
		{
			screen = 10;
			f1 = 0;
		}
	}
	else if(screen == 3)//control
	{
		if(key == 8 || key == 13 || key == 27)
		{
			screen =1;
			count = -1;
			f = 0;
			c_s = 0;
		}
	}
	else if(screen == 4)//sound
	{
		if(key == 8  || key == 27)
		{
			play_s = true;
			play_s1 = true;
			play_s2 = true;
			play_s3 = true;
			play_s4 = true;
			play_s5 = true;
			screen =1;
			count = -1;
			f = 0;
			s_s = 0;
		}
		if(s_s == 1)
		{
			if(key == 13)
			{
				play_s = true;
				play_s1 = true;
			play_s2 = true;
			play_s3 = true;
			play_s4 = true;
			play_s5 = true;
				screen =1;
				count = -1;
				f = 0;
			}
			
		}
		else if(s_s == 2)
		{
			if(key == 13)
			{
				play_s = false;
				play_s1 = false;
			play_s2 = false;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
				screen =1;
				count = -1;
				f = 0;
			}
			
		}
		
	}
	else if(screen == 5)//help
	{
		if(key == 8 || key == 13 || key == 27)
		{
			screen =1;
			count = -1;
			f = 0;
			hl_s = 0;
		}
	}
	else if(screen == 6)//highscore
	{
		if(key == 8 || key == 13 || key == 27)
		{
			screen =1;
			count = -1;
			f = 0;
			h_s = 0;
		}
	}
	else if(screen == 7)//username
	{
		if(node == 1)
		{
			if(key == 13)
			{
					strcpy(str1, str);
					fp = fopen("name.txt","w");
					fprintf(fp,"%s",str1);
					fclose(fp);
				for(i = 0; i < len; i++)
				{
					str[i] = 0;
				}
				len = 0;
				node = 0;
				iResumeTimer(t2);
				screen = 12;
			}
			else if(key == 8)
			{
				len--;
				str[len] = key;
			}	
			else
			{
				str[len] = key;
				len++;
			}
		}
		else if(node == 0)
		{
			if(key == 13)
			{
				screen = 2;
				iPauseTimer(t6);
			}
		}
	}
	else if(screen == 8)//gameover
	{
		if(g_d == 1)
		{
			if(key == 13)
			{
				g_d = 0;
				restart();
			}
		}
		else if(g_d == 2)
		{
			if(key == 13)
			{
				play_s = false;
				play_s1 = false;
				play_s2 = true;
				play_s3 = false;
				play_s4 = false;
				play_s5 = false;
				g_d = 0;
				screen = 1;
				count = -1;
				f = 0;
			}
		}
	}
	else if(screen == 9)//win
	{
		if(w_s == 1)
		{
			if(key == 13)
			{
				play_s = false;
			play_s1 = false;
			play_s2 = true;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
				screen = 1;
			}

		}

	}
	else if(screen == 10)//pausemenu
	{
		if(count1 == 1)
		{
			if(key == 13)
			{
				screen = 2;
				count1 = -1;
				f1 = 0;
			}
		}
		else if(count1 == 2)
		{
			if(key == 13)
			{
				restart();
				count1 = -1;
				f1 = 0;
			}
		}
		else if(count1 == 3)
		{
			if(key == 13)
			{
				if(p == 1)
					{
						play_s = false;
			play_s1 = false;
			play_s2 = false;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
						p = 2;
				}
				else if(p == 2)
					{
						play_s = true;
			play_s1 = true;
			play_s2 = true;
			play_s3 = true;
			play_s4 = true;
			play_s5 = true;
						p = 1;
				}
			}
		}
		else if(count1 == 4)
		{
			if(key == 13)
			{
				count1 = -1;
				f1 = 0;
				f = 0;
				count = -1;
				screen = 1;
				lo = 2;
			}
		}
	}
	else if(screen == 11)//animation
	{
		if(key == 13)
		{
			play_s = false;
			play_s1 = false;
			play_s2 = false;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
			iPauseTimer(t6);
			screen = 12;
			iResumeTimer(t2);
			
		}
	}
	else if(screen == 13)//extra
	{
		if(level == 1)
		{
			if(key == 13)
			{
				play_s = false;
				play_s1 = false;
				play_s2 = false;
				play_s3 = false;
				play_s4 = true;
				play_s5 = false;
				iPauseTimer(t6);
				level = 2;
				screen = 2;
			}

		}
		else if(level == 2)
		{
			if(key == 13)
			{
				play_s = false;
				play_s1 = false;
				play_s2 = false;
				play_s3 = false;
				play_s4 = false;
				play_s5 = true;
				iPauseTimer(t6);
				level = 3;
				screen = 2;

			}

		}
	}
	else if(screen == 14)//name
	{
		if(key == 13)
		{
			play_s = false;
			play_s1 = true;
			play_s2 = false;
			play_s3 = false;
			play_s4 = false;
			play_s5 = false;
			iPauseTimer(t7);
			screen = 11;
			iResumeTimer(t6);
			
		}
	}

}
void iSpecialKeyboard(unsigned char key)
{

	if(screen == 1)//menu
	{
		if(key == GLUT_KEY_UP)
		{
			if(f == 0)
			{
				f = 1 ;
				count = 1;
			}
			else
			{
				count--;
				if(count == 0)
					count = 6;
			}
		}
		else if(key == GLUT_KEY_DOWN)
		{
			if(f == 0)
			{
				f = 1;
				count = 1;
			}
			else
			{
				count++;
				if(count == 7)
					count = 1;
			}
		}
	}
	else if(screen == 2)//game
	{
		if(manpos_y <= 10)
		{
		if(key == GLUT_KEY_LEFT && manpos_x >= 6)
		{
			y = 0;
			y_1 = 0;
			manpos_x -= 15;
			x = 1;
			x_1 = 1;
		}
		else if(key == GLUT_KEY_RIGHT && manpos_x <= 786)
		{
			x = 0;
			x_1 = 0;
			manpos_x += 15;
			y = 1;
			y_1 = 1;
		}
		}
	}
	else if(screen == 3)//control
	{
		if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT || key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		{
			c_s = 1;
		}
	}
	else if(screen == 4)//sound
	{
		if(key == GLUT_KEY_LEFT)
		{
			s_s = 1;
		}
		if(key == GLUT_KEY_RIGHT)
		{
			s_s = 2;
		}
	}
	else if(screen == 5)//help
	{
		if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT || key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		{
			hl_s = 1;
		}
	}
	else if(screen == 6)//highscore
	{
		if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT || key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		{
			h_s = 1;
		}
	}
	else if(screen == 7)//username
	{
		if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT || key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		{
			enter = 1;
		}
	}
	else if(screen == 8)
	{
		if(key == GLUT_KEY_LEFT)
		{
			g_d = 1;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			g_d = 2;
		}
	}
	else if(screen == 9)//win
	{
		if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT || key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		{
			w_s = 1;
		}
	}
	else if(screen == 10)//pausemenu
	{
		if(key == GLUT_KEY_UP)
		{
			if(f1 == 0)
			{
				f1 = 1 ;
				count1 = 1;
			}
			else
			{
				count1--;
				if(count1 == 0)
					count1 = 4;
			}
		}
		else if(key == GLUT_KEY_DOWN)
		{
			if(f1 == 0)
			{
				f1 = 1;
				count1 = 1;
			}
			else
			{
				count1++;
				if(count1 == 5)
					count1 = 1;
			}
		}
	}
}
int main()
{
	t1 = iSetTimer(100,brick_move);
	iPauseTimer(t1);
	t2 = iSetTimer(700,timer);
	iPauseTimer(t2);
	t3 = iSetTimer(30,manmove);
	iPauseTimer(t3);
	t4 = iSetTimer(1000,time);
	iPauseTimer(t4);
	t5 = iSetTimer(75,screenmove);
	iPauseTimer(t5);
	t6 = iSetTimer(170,a_time);
	iPauseTimer(t6);
	t7= iSetTimer(80,namemove);
	iPauseTimer(t7);
	len = 0;
	str[0]= 0;
	if(screen == 0 || screen == 14) 
	{
		if(play_s)PlaySound("music\\front",NULL,SND_LOOP | SND_ASYNC);
		else PlaySound(0,0,0);
	}
	else if(screen == 11)
	{
		if(play_s1)PlaySound("music\\animation",NULL,SND_LOOP | SND_ASYNC);
		else PlaySound(0,0,0);

	}
	else if(screen == 1 || screen == 3 || screen == 4 || screen == 5 ||  screen == 6 || screen == 8 || screen == 9 )
	{
		if(play_s2)PlaySound("music\\menu",NULL,SND_LOOP | SND_ASYNC);
		else PlaySound(0,0,0);
	}
	else if(screen == 2)
	{
		if(level == 1)
		{
			if(play_s3)PlaySound("music\\level",NULL,SND_LOOP | SND_ASYNC);
			else PlaySound(0,0,0);
		}
		if(level == 2)
		{
			if(play_s4)PlaySound("music\\level1",NULL,SND_LOOP | SND_ASYNC);
			else PlaySound(0,0,0);
		}
		if(level == 3)
		{
			if(play_s5)PlaySound("music\\level2",NULL,SND_LOOP | SND_ASYNC);
			else PlaySound(0,0,0);
		}
		if(level > 3)
		PlaySound(0,0,0);
	}
	else if(screen == 13 || screen == 7 || screen == 10 || screen == 12)
	{
		PlaySound(0,0,0);
	}
	iInitialize(850,580,"survival for the fittest");
	return 0;
}