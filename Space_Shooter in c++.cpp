#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
using namespace std;
int main()
{	
	int x=500,y=800;
	initwindow(1526,864);

		circle(x,y,20);
		int a=8;
		int d=200;
		int enemyx[20];
		int flaglevel4=0;
		int reset=0;
		int flaglevel5=0;
		int enemyrad[20];
		for(int j=0;j<20;j++){
			enemyx[j]=d;
			d+=100;
			enemyrad[j]=10;
			if(j==10)
			{
				d=250;
			}
			cout<<enemyx[j]<<endl;
		}
		int y_inc_bullet=50;
		int y_inc_bullet1=50;
		int j=0;
		int no_of_enemies=3;
		int flaglevel3=0;
		int b=rand()%no_of_enemies;
		int flaglevel2=0;
		int l=rand()%no_of_enemies;
		int enemyy[20];
		for(int i=0;i<10;i++)
		{
			enemyy[i]=50;
		}
		for(int x=10;x<20;x++)
		{
			enemyy[x]=100;
		}
		int radius=20;
		int flag=0;
		int c=0;
		int f=50;
		int dedenemy=0;
		int flag1=0;
		int flaglevel1=0;
		char h[50];
	while(1)
	{
		setbkcolor(GREEN);
		//cleardevice();
		if(flaglevel1==0)
		{
		settextstyle(EUROPEAN_FONT,0,4);
			outtextxy(450,50,"INSTRUCTIONS");
			outtextxy(40,100,"use ( arrow keys/ A or D) to move around");
			outtextxy(40,200,"press space to fire bullets");
			outtextxy(40,300,"avoid hitting space debris");
			outtextxy(40,400,"different colored debris gives different score");
			outtextxy(40,500,"esc key during game restarts level");
			outtextxy(350,600,"Press Space key to Start Level 1");
			outtextxy(350,700,"Press Esc key to Exit 1");
		}
			if(GetAsyncKeyState(VK_SPACE)||flaglevel1==1)
			{
				cleardevice();
				if(flag==1)
		{
			//outtextxy(500,500,"Life Lost");
		}
	    for(int i=0;i<no_of_enemies;i++)
		{                          //print enemies
		if(enemyrad[i]!=0)
		{
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
	    circle(enemyx[i],enemyy[i],enemyrad[i]);
	    floodfill(enemyx[i],enemyy[i],RED);
	}
	    }
	    setcolor(YELLOW);
	    setfillstyle(SOLID_FILL,YELLOW);
	    circle(x,y,radius); 
	    floodfill(x,y,YELLOW);
	    setcolor(WHITE);
		circle(x,y,radius);                                       //spaceship
		if(y_inc_bullet<800&&enemyrad[b]!=0&&radius!=0&&l!=b)
		{
			setcolor(BLACK);
			circle(enemyx[b],y_inc_bullet,5);                                //enemy bullets
			if(y_inc_bullet>y-20&&y_inc_bullet<y+20&&enemyx[b]>x-20&&enemyx[b]<x+20)        //if hits spaceship destroyed
			{
				for(int g=0;g<1000;g++)
				{
		         outtextxy(600,500,"Live lost");
				setcolor(RED);
	            setfillstyle(SOLID_FILL,RED);
	            circle(x,y,radius); 
	           floodfill(x,y,RED);
	       }
				
			}
	    }
		else
		{
			b=rand()%no_of_enemies;                                                 //randomly generate enemy bullet
			y_inc_bullet=enemyy[b];
		}
		if(y_inc_bullet1<800&&enemyrad[l]!=0&&radius!=0&&l!=b)
		{
			setcolor(BLACK);
			circle(enemyx[l],y_inc_bullet1,5);                                //enemy bullets
			if(y_inc_bullet1>y-20&&y_inc_bullet1<y+20&&enemyx[l]>x-20&&enemyx[l]<x+20)        //if hits spaceship destroyed
			{
					for(int g=0;g<1000;g++)
				{
		         outtextxy(600,500,"Live lost");
				setcolor(RED);
	            setfillstyle(SOLID_FILL,RED);
	            circle(x,y,radius); 
	           floodfill(x,y,RED);
	       }
			}
	    }
		else
		{
			l=rand()%no_of_enemies;                                                 //randomly generate enemy bullet
			y_inc_bullet1=enemyy[l];
		}
		y_inc_bullet1+=5;
		y_inc_bullet+=5;
		if(GetAsyncKeyState(VK_RIGHT)&&x<1450)
		{
			x=x+5;
		}
		if(GetAsyncKeyState(VK_LEFT)&&x>50)
		{
			x=x-5;
		}
		if(GetAsyncKeyState(VK_SPACE)&&radius!=0)                          //spaceship shoot
		{
			int s=x;
			for(int i=770;i>20;i-=20)
			{
				cleardevice();
			if(y_inc_bullet<800&&enemyrad[b]!=0&&radius!=0&&b!=l)
			{                                           //enemy bullet and enemy alive
			setcolor(BLACK);
			circle(enemyx[b],y_inc_bullet,5);
			if(y_inc_bullet>y-10&&y_inc_bullet<y+10&&enemyx[b]>x-10&&enemyx[b]<x+10)
			{
					for(int g=0;g<1000;g++)
				{
		         outtextxy(600,500,"Live lost");
				setcolor(RED);
	            setfillstyle(SOLID_FILL,RED);
	            circle(x,y,radius); 
	           floodfill(x,y,RED);
	       }
			}
         	}
		else
		{
			b=rand()%no_of_enemies;
			y_inc_bullet=enemyy[b];
		}
		setcolor(WHITE);
		for(int j=0;j<no_of_enemies;j++)
			  {
			  	if(enemyrad[j]!=0)
	         	{
	        	setcolor(RED);
	        	setfillstyle(SOLID_FILL,RED);
	            circle(enemyx[j],enemyy[j],enemyrad[j]);
	            floodfill(enemyx[j],enemyy[j],RED);
            	}
      	      }
      	      setcolor(WHITE);
		if(y_inc_bullet1<800&&enemyrad[l]!=0&&radius!=0&&b!=l)
		{
			setcolor(BLACK);
			circle(enemyx[l],y_inc_bullet,5);                                //enemy bullets
			if(y_inc_bullet1>y-10&&y_inc_bullet1<y+10&&enemyx[l]>x-10&&enemyx[l]<x+10)        //if hits spaceship destroyed
			{
		    		for(int g=0;g<1000;g++)
				{
		         outtextxy(600,500,"Live lost");
				setcolor(RED);
	            setfillstyle(SOLID_FILL,RED);
	            circle(x,y,radius); 
	           floodfill(x,y,RED);
	       }
			}
	    }
		else
		{
			l=rand()%no_of_enemies;                                                 //randomly generate enemy bullet
			y_inc_bullet1=enemyy[l];
		}
		y_inc_bullet1+=5;
		y_inc_bullet+=5;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
				circle(x,y,radius);
				floodfill(x,y,YELLOW);
				setcolor(WHITE);
				circle(s,i,5);                                                               //spaceship bullet
				for(int k=0;k<no_of_enemies;k++)
				{
					
				if(s>(enemyx[k]-20)&&s<(enemyx[k]+20)&&(i>45&&i<55))                              //if touch enemy destroyed
				{
					enemyrad[k]=0;
					dedenemy++;
				}
				if(dedenemy==3)
				{
				enemyrad[k]=10;
		     	}
		     	if(dedenemy==10)
				{
				enemyrad[k]=10;
		     	}
		     	if(dedenemy==20)
		     	{
		     		enemyrad[k]=10;
				}
				if(dedenemy==33)
				{
					enemyrad[k]=10;
				}
		     }
		     for(int f=0;f<20;f++)
		     {
		     		if(dedenemy==3&&f<10)
		     	{
		     	  no_of_enemies=7;
		     	  if(flaglevel2==0)
		     	  {
				   enemyy[f]=50;
				   y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];	
				   c=0;
			}
			     
				}
				if(dedenemy==10&&f<10)
				{
					no_of_enemies=10;
					if(flaglevel3==0)
					{
					enemyy[f]=50;
				   y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];
				   c=0;
				}
			}
				if(dedenemy==20)
				{
					no_of_enemies=15;
					if(f>10)
					{
						if(flaglevel4==0)
						{
					enemyy[f]=100;
					 y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];
			}
				}
				else
				{
					if(flaglevel4==0)
					{
					enemyy[f]=50;
					 y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];
				}
			}
				}
				if(dedenemy==33)
				{
					no_of_enemies=20;
					if(f>10)
					{
						if(flaglevel5==0)
						{
					enemyy[f]=100;
					 y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];
				}
			}
				else
				{
					if(flaglevel5==0)
					{
					enemyy[f]=50;
					 y_inc_bullet=enemyy[f];
				   y_inc_bullet1=enemyy[f];
				}
			}
				
					
				}
			}
				if(GetAsyncKeyState(VK_RIGHT)&&x<1450)
		        {
			     x=x+5;
		        }
		        if(GetAsyncKeyState(VK_LEFT)&&x>50)
		        {
			     x=x-5;
		        }
				delay(10);
				flag1=1;
			} 
		}
		if(flag1==0)
		{
		delay(10);
	}
	flag1=0;
		c+=2;
		if(c%200==0)                                               //move enemies a step down
		{
			for(int v=0;v<no_of_enemies;v++)
			{
				if(flaglevel2==0)
				{
			enemyy[v]+=40;
		}
           if(flaglevel2==1)
				{
			enemyy[v]+=50;
	        	}  
	        	if(flaglevel3==1)
				{
			enemyy[v]+=55;
		}
		if(flaglevel4==1)
				{
			enemyy[v]+=20;
		}
		if(flaglevel5==1)
				{
			enemyy[v]+=20;
		}
				if(enemyy[v]>800)                                             //if enemy touches bottom game khtm
		{
				for(int g=0;g<1000;g++)
				{
		         outtextxy(600,500,"Live lost");
				setcolor(RED);
	            setfillstyle(SOLID_FILL,RED);
	            circle(x,y,radius); 
	           floodfill(x,y,RED);
	       }
	       	for(int i=0;i<=10;i++)
		{
			enemyy[i]=50;
		}
		for(int x=11;x<20;x++)
		{
			enemyy[x]=100;
			reset=1;
		}
	       if(reset==1)
	       {
	       	break;
		   }
		   reset=0;
			flag=1;
		}
		}
		//	y_inc_bullet+=80;
		//	y_inc_bullet1+=80;
			f+=100;
		}
		if(dedenemy==3)
		{
		flaglevel2=1;
	}
		if(dedenemy==10)
		{
			flaglevel3=1;
		}
		if(dedenemy==20)
		{
			flaglevel4=1;
		}
		if(dedenemy==33)
		{
			flaglevel5=1;
		}
				flaglevel1=1;
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
	}
}
  




