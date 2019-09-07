//Hand Cricket 2017 Version 1.0
//Siddharth G.C

#include <iostream>
#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>
#include<cstdlib>
#include "func.h"

using namespace std;

int mxpos,mypos;            //Mouse x and y position
int music_playing = 0;      //Global variable used to tell if music is playing

class match
{
public:
    int overs;
    char winner[4];
    char loser[4];
    void set_match(int type)
    {
        if(type==1)
            overs = 5;
        else if(type==2)
            overs = 0;
        else
            overs = 2;
    }
};

class player:public match           //Player class inherited from match
{
public:
    int score;
    int curr_batsman;
    int curr_ball;
    int curr_over;
    int curr_innings;
    int wickets;
    int ptype;
    char name[8];
    char over[6];
    int pover[6];
    player()
    {
        curr_over = 0;
        curr_ball = 0;
        curr_batsman = 0;
        score = 0;
        wickets = 10;
        sprintf(over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        for(int i=0;i<6;i++)
        {
           pover[i] = 0;
        }
    }
    void updatescores(char x)       //Updating the player's current score
    {
        switch(x)
        {
        case '1':
            score+=1;
            curr_batsman+=1;
            break;
        case '2':
            score+=2;
            curr_batsman+=2;
            break;
        case '3':
            score+=3;
            curr_batsman+=3;
            break;
        case '4':
            score+=4;
            curr_batsman+=4;
            break;
        case '5':
            score+=5;
            curr_batsman+=5;
            break;
        case '6':
            score+=6;
            curr_batsman+=6;
            break;
        }
    }
};

int page = 0;

void getwinner(player p1,player p2)     //Gets the winner of the current match
{
    int maxx = getmaxx();
    int maxy = getmaxy();
    char score1[15],score2[15];
    sprintf(score1,"%s : %d / %d",p1.name,p1.score,10-p1.wickets);
    sprintf(score2,"%s : %d / %d",p2.name,p2.score,10-p2.wickets);
    setcolor(COLOR(181,158,32));
    setbkcolor(BLACK);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,16);
    if(p2.ptype==2)
    {
        if(p1.score>p2.score)
        {
            PlaySound(TEXT("data_files/music/Cool_Rock.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide1.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide2.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
        else if((p1.score==p2.score)&&(p1.overs<=0))
        {
            PlaySound(TEXT("data_files/music/Cool_Rock.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide3.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide4.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
        else
        {
            PlaySound(TEXT("data_files/music/Death_of_Kings.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide5.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide6.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
    }
    else
    {
        if(p1.score>p2.score)
        {
            PlaySound(TEXT("data_files/music/Cool_Rock.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide7.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide8.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
        else if((p1.score==p2.score)&&(p1.overs<=0))
        {
            PlaySound(TEXT("data_files/music/Cool_Rock.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide3.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide4.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
        else
        {
            PlaySound(TEXT("data_files/music/Cool_Rock.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            readimagefile("data_files/screens/winlose/Slide9.jpg",0,0,maxx,maxy);
            delay(4000);
            readimagefile("data_files/screens/winlose/Slide10.jpg",0,0,maxx,maxy);
            outtextxy(maxx*37/100,maxy*40/100,score1);
            outtextxy(maxx*37/100,maxy*50/100,score2);
            getch();
        }
    }
    readimagefile("data_files/screens/loading/Slide1.jpg",0,0,maxx,maxy);
    delay(4000);
}

char toss_begin(int maxx,int maxy)      //Toss intro screen
{
        readimagefile("data_files/screens/toss/Slide2.jpg",0,0,maxx,maxy);
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
        if((mxpos>=maxx*22/100)&&(mxpos<=maxx*38/100)&&(mypos>=maxy*38/100)&&(mypos<=maxy*53/100))
        {
            readimagefile("data_files/screens/toss/Slide3.jpg",0,0,maxx,maxy);
            delay(300);
            return 'h';
        }
        if((mxpos>=maxx*63/100)&&(mxpos<=maxx*79/100)&&(mypos>=maxy*38/100)&&(mypos<=maxy*53/100))
        {
            readimagefile("data_files/screens/toss/Slide4.jpg",0,0,maxx,maxy);
            delay(300);
            return 't';
        }
        toss_begin(maxx,maxy);
}

char toss_input(int maxx,int maxy,int result)       //Post toss decision
{
    char screen1[100],screen2[100],screen3[100];
    if(result == 1)
    {
        sprintf(screen1,"data_files/screens/toss/Slide6.jpg");
        sprintf(screen2,"data_files/screens/toss/Slide7.jpg");
        sprintf(screen3,"data_files/screens/toss/Slide8.jpg");
    }
    else
    {
        sprintf(screen1,"data_files/screens/toss/Slide9.jpg");
        sprintf(screen2,"data_files/screens/toss/Slide10.jpg");
        sprintf(screen3,"data_files/screens/toss/Slide11.jpg");
    }
    readimagefile(screen1,0,0,maxx,maxy);
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
        if((mxpos>=maxx*16/100)&&(mxpos<=maxx*40/100)&&(mypos>=maxy*25/100)&&(mypos<=maxy*82/100))
        {
            readimagefile(screen2,0,0,maxx,maxy);
            delay(300);
            return 'b';
        }
        if((mxpos>=maxx*60/100)&&(mxpos<=maxx*84/100)&&(mypos>=maxy*25/100)&&(mypos<=maxy*82/100))
        {
            readimagefile(screen3,0,0,maxx,maxy);
            delay(300);
            return 'f';
        }
        toss_input(maxx,maxy,result);
}

void team_select(int maxx,int maxy,player* p,int player)        //Screen where the player selects his/her team
{
    char screen[40];
    if(player==1)
        sprintf(screen,"data_files/screens/teamsel/Slide1.jpg");
    else
        sprintf(screen,"data_files/screens/teamsel/Slide2.jpg");
    readimagefile(screen,0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*7/100)&&(mxpos<=maxx*22/100)&&(mypos>=maxy*19/100)&&(mypos<=maxy*47/100))
    {
        strcpy(p->name,"AUS");
        return;
    }
    if((mxpos>=maxx*30/100)&&(mxpos<=maxx*46/100)&&(mypos>=maxy*19/100)&&(mypos<=maxy*47/100))
    {
        strcpy(p->name,"ENG");
        return;
    }
    if((mxpos>=maxx*54/100)&&(mxpos<=maxx*70/100)&&(mypos>=maxy*19/100)&&(mypos<=maxy*47/100))
    {
        strcpy(p->name,"IND");
        return;
    }
    if((mxpos>=maxx*78/100)&&(mxpos<=maxx*93/100)&&(mypos>=maxy*19/100)&&(mypos<=maxy*47/100))
    {
        strcpy(p->name,"NZ");
        return;
    }
    if((mxpos>=maxx*7/100)&&(mxpos<=maxx*22/100)&&(mypos>=maxy*61/100)&&(mypos<=maxy*89/100))
    {
        strcpy(p->name,"PAK");
        return;
    }
    if((mxpos>=maxx*30/100)&&(mxpos<=maxx*46/100)&&(mypos>=maxy*61/100)&&(mypos<=maxy*89/100))
    {
        strcpy(p->name,"SA");
        return;
    }
    if((mxpos>=maxx*54/100)&&(mxpos<=maxx*70/100)&&(mypos>=maxy*61/100)&&(mypos<=maxy*89/100))
    {
        strcpy(p->name,"SR");
        return;
    }
    if((mxpos>=maxx*78/100)&&(mxpos<=maxx*93/100)&&(mypos>=maxy*61/100)&&(mypos<=maxy*89/100))
    {
        strcpy(p->name,"WI");
        return;
    }
    team_select(maxx,maxy,p,player);
}

int toss(player p1,player p2,int maxx,int maxy)     //Main toss function
    {
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        readimagefile("data_files/screens/toss/Slide1.jpg",0,0,maxx,maxy);
        delay(2000);
        char coin,choice;
        coin = toss_begin(maxx,maxy);
        srand(time(0));
        int val = (rand()%2);
        readimagefile("data_files/screens/toss/Slide5.jpg",0,0,maxx,maxy);
        delay(1500);
        if(((val==1)&&(coin=='h'))||((val==0)&&(coin=='t')))
            {
                choice = toss_input(maxx,maxy,1);
                if(choice=='b')
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        else if(((val==0)&&(coin=='h'))||((val==1)&&(coin=='t')))
            {
                choice = toss_input(maxx,maxy,2);
                if(choice=='b')
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
    }

void setup_field(int rt1,int rt2,int rb1,int rb2,int ht1,int ht2,int hb1,int hb2,int st1,int st2,int sb1,int sb2)       //sets up all the items on the playing field. Parameters - field dimensions
{
    int maxx = getmaxx();
    int maxy = getmaxy();
    readimagefile("data_files/images/ground.jpg",0,0,maxx,maxy);
    setcolor(BLACK);
    setfillstyle(1,COLOR(255,203,151));
    bar(rt1,rt2,rb1,rb2);
    setfillstyle(3,COLOR(150,94,63));
    bar(ht1,ht2,hb1,hb2);
    readimagefile("data_files/images/stumps.jpg",st1,st2,sb1,sb2);
}

void ball_hit_out(int runs,player p,player q)       //Animation for ball hitting stumps
{
    char output[40],board1[20],board2[20],target[30];
    sprintf(board1,"%s : %d / %d",p.name,p.score,10-p.wickets);
    sprintf(board2,"%d.%d overs",p.curr_over,p.curr_ball);
    if(runs!=0)
       strcpy(output,"HOWZAT!!! What a wicket!");
    else
       strcpy(output,"Duck out!!! What a shame!");
    int maxx = getmaxx();
    int maxy = getmaxy();
    int st1 = (maxx*5)/100 ,st2 = (maxy/2) + 165;
    int sb1 = st1+50 ,sb2 = st2 + 140;
    int rt1 = (maxx*13)/100 , rb1, rt2 = (maxy/2) + 170 , rb2;
    rb1 = rt1+30; rb2 = rt2 + 130;
    int ht1 = ((rb1+rt1)/2) - 5, ht2 = rt2 - 50, hb1 = ((rb1+rt1)/2) + 5, hb2 = rt2+3;
    setactivepage((page-1)%2);
    setbkcolor(BLACK);
    cleardevice();
    int collide = 0,bounce=0,bounced = 0;
    float d = -((maxy*40)/100),x = 0,i=maxx;
    while(1)
        {
                if(page==3000)
                    {
                        page=0;
                    }
                setactivepage((page-1)%2);
                setvisualpage(page%2);
                cleardevice();
                setup_field(rt1,rt2,rb1,rb2,ht1,ht2,hb1,hb2,st1,st2,sb1,sb2);
                setcolor(WHITE);
                settextstyle(SANS_SERIF_FONT,HORIZ_DIR,13);
                outtextxy(((maxx*38)/100),((maxy*10)/100),board1);
                outtextxy(((maxx*38)/100),((maxy*13)/100),board2);
                if(p.curr_innings==2)
                {
                    sprintf(target,"Target score : %d",q.score+1);
                    outtextxy(((maxx*38)/100),((maxy*16)/100),target);
                }
                setcolor(BLACK);
                setfillstyle(1,RED);
                if((i-20 <= st1+30) && (((maxy*86)/100)+x>= st2)&&(((maxy*86)/100)+x<= sb2))
                    {
                        PlaySound(TEXT("data_files/sounds/stump.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        delay(100);
                        if(runs==0)
                            PlaySound(TEXT("data_files/sounds/duck.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        collide = 1;
                    }
                if(maxy+d+15 >= maxy*87/100)
                    {
                        d=-maxy;
                        bounce = 1;
                        PlaySound(TEXT("data_files/sounds/bounce.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        bounced = 1;
                    }
                if(bounced==1)
                    {
                        circle(i,((maxy*86)/100) +x,12);
                        floodfill(i,((maxy*86)/100)+x,BLACK);
                        x = x-4;
                    }
                else
                    {
                        circle(i,maxy+d,12);
                        floodfill(i,maxy+d,BLACK);
                        d = d+7;
                    }
                page++;
                if(collide==0)
                  {
                     i-=25;
                  }
                else
                 {
                    page++;
                    setactivepage(page%2);
                    setvisualpage(page%2);
                    setup_field(rt1,rt2,rb1,rb2,ht1,ht2,hb1,hb2,st1,st2,sb1,sb2);
                    setcolor(WHITE);
                    if(runs==0)
                    {
                      readimagefile("data_files/images/duck.jpg",rb1+100,rt2,rb1+200,sb2);
                      setcolor(YELLOW);
                    }
                    outtextxy(((maxx*38)/100),((maxy*12)/100),output);
                    delay(4000);
                    page++;
                    break;
                 }
        }
    return;
}

void ball_hit_runs(char* runs,player p,player q)        //Animation for ball hitting bat and scoring runs
{
    float force = 0;
    if((runs[0]=='6')||(runs[0]=='5'))
        force = 8;
    else if((runs[0]=='4')||(runs[0]=='3'))
        force = 3;
    else
        force = 0.33;
    char output[30] = {" run(s)!!! What a shot!"},board1[20],board2[20],target[30];
    sprintf(board1,"%s : %d / %d",p.name,p.score,10-p.wickets);
    sprintf(board2,"%d.%d overs",p.curr_over,p.curr_ball);
    int maxx = getmaxx();
    int maxy = getmaxy();
    int st1 = (maxx*5)/100 ,st2 = (maxy/2) + 165;
    int sb1 = st1+50 ,sb2 = st2 + 140;
    int rt1 = (maxx*13)/100 , rb1, rt2 = (maxy/2) + 170 , rb2;
    rb1 = rt1+30; rb2 = rt2 + 130;
    int ht1 = ((rb1+rt1)/2) - 5, ht2 = rt2 - 50, hb1 = ((rb1+rt1)/2) + 5, hb2 = rt2+3;
    setactivepage((page-1)%2);
    setbkcolor(BLACK);
    cleardevice();
    int collide = 0,bounce=0,bounced = 0;
    float d = -((maxy*40)/100),x = 0,i=maxx;
    while(1)
        {
                if(page==3000)
                    {
                        page=0;
                    }
                if(i==0||i>maxx+30)
                    {
                        page++;
                        setactivepage(page%2);
                        setvisualpage(page%2);
                        setup_field(rt1,rt2,rb1,rb2,ht1,ht2,hb1,hb2,st1,st2,sb1,sb2);
                        setcolor(WHITE);
                        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,13);
                        outtextxy(((maxx*40)/100),((maxy*12)/100),runs);
                        outtextxy(((maxx*40)/100) + 18,((maxy*12)/100),output);
                        delay(4000);
                        page++;
                        break;
                    }
                setactivepage((page-1)%2);
                setvisualpage(page%2);
                cleardevice();
                setup_field(rt1,rt2,rb1,rb2,ht1,ht2,hb1,hb2,st1,st2,sb1,sb2);
                setcolor(WHITE);
                settextstyle(SANS_SERIF_FONT,HORIZ_DIR,13);
                outtextxy(((maxx*38)/100),((maxy*10)/100),board1);
                outtextxy(((maxx*38)/100),((maxy*13)/100),board2);
                if(p.curr_innings==2)
                {
                    sprintf(target,"Target score : %d",q.score+1);
                    outtextxy(((maxx*38)/100),((maxy*16)/100),target);
                }
                setcolor(BLACK);
                setfillstyle(1,RED);
                if((i-20 <= rt1+30) && (((maxy*86)/100)+x>= st2)&&(((maxy*86)/100)+x<= sb2))
                    {
                        PlaySound(TEXT("data_files/sounds/batball.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        collide = 1;
                    }
                if(maxy+d+15 >= maxy*87/100)
                    {
                        d=-maxy;
                        bounce = 1;
                        PlaySound(TEXT("data_files/sounds/bounce.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        bounced = 1;
                    }
                if(bounced==1)
                    {
                        circle(i,((maxy*86)/100) +x,12);
                        floodfill(i,((maxy*86)/100)+x,BLACK);
                        x = x-4;
                    }
                else
                    {
                        circle(i,maxy+d,12);
                        floodfill(i,maxy+d,BLACK);
                        d = d+7;
                    }
                page++;
                if(collide==0)
                  {
                     i-=25;
                  }
                else
                 {
                     i+=25;
                     x= x - force;
                 }
        }
    return;
}

int get_user_input(int maxx,int maxy)
{
    getit:
    outtextxy(maxx*13/100,maxy*15/100,"Enter a number between 1 and 6");
    char inp;
    inp = getch();
    if(inp=='1'||inp=='2'||inp=='3'||inp=='4'||inp=='5'||inp=='6')
        return inp;
    else
        goto getit;
}

int confirmation(int maxx,int maxy)
{
    readimagefile("data_files/screens/selectmenu/Slide8.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*26/100)&&(mxpos<=maxx*44/100)&&(mypos>=maxy*53/100)&&(mypos<=maxy*65/100))
    {
        readimagefile("data_files/screens/selectmenu/Slide9.jpg",0,0,maxx,maxy);
        delay(300);
        return 0;
    }
    if((mxpos>=maxx*56/100)&&(mxpos<=maxx*74/100)&&(mypos>=maxy*53/100)&&(mypos<=maxy*65/100))
    {
        readimagefile("data_files/screens/selectmenu/Slide10.jpg",0,0,maxx,maxy);
        delay(300);
        return 1;
    }
    confirmation(maxx,maxy);
}

void prevscreen(player* o1,player* o2,int maxx,int maxy)
{
    char batprev[20],bowlprev[20];
    sprintf(batprev,"%d %d %d %d %d %d",o1->pover[0],o1->pover[1],o1->pover[2],o1->pover[3],o1->pover[4],o1->pover[5]);
    sprintf(bowlprev,"%d %d %d %d %d %d",o2->pover[0],o2->pover[1],o2->pover[2],o2->pover[3],o2->pover[4],o2->pover[5]);
    setbkcolor(BLACK);
    readimagefile("data_files/screens/selectmenu/Slide2.jpg",0,0,maxx,maxy);
    setcolor(COLOR(181,158,32));
    outtextxy(maxx*35/100,maxy*40/100,"Batting :");
    setcolor(WHITE);
    outtextxy(maxx*35/100,maxy*50/100,batprev);
    setcolor(COLOR(181,158,32));
    outtextxy(maxx*35/100,maxy*60/100,"Bowling :");
    setcolor(WHITE);
     outtextxy(maxx*35/100,maxy*70/100,bowlprev);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*28/100)&&(mxpos<=maxx*72/100)&&(mypos>=maxy*4/100)&&(mypos<=maxy*11/100))
    {
        readimagefile("data_files/screens/selectmenu/Slide3.jpg",0,0,maxx,maxy);
        delay(300);
        return;
    }
    else
        prevscreen(o1,o2,maxx,maxy);
}

void run_input(player* o1,player* o2)       //Screen where the player inputs his runs for the over
{
    int choice = 0,c;
    int maxx = getmaxx();
    int maxy = getmaxy();
    int p1,p2,p3,p4,ret;
    char ball1[2],ball2[2],ball3[2],ball4[2],ball5[2],ball6[2];
    sprintf(ball1,"%c",o1->over[0]);
    sprintf(ball2,"%c",o1->over[1]);
    sprintf(ball3,"%c",o1->over[2]);
    sprintf(ball4,"%c",o1->over[3]);
    sprintf(ball5,"%c",o1->over[4]);
    sprintf(ball6,"%c",o1->over[5]);
    readimagefile("data_files/screens/selectmenu/Slide1.jpg",0,0,maxx,maxy);
    setbkcolor(WHITE);
    setcolor(COLOR(181,158,32));
    settextstyle(GOTHIC_FONT,HORIZ_DIR,17);
    outtextxy(maxx*11/100,maxy*47/100,ball1);
    outtextxy(maxx*26/100,maxy*47/100,ball2);
    outtextxy(maxx*41/100,maxy*47/100,ball3);
    outtextxy(maxx*56/100,maxy*47/100,ball4);
    outtextxy(maxx*71/100,maxy*47/100,ball5);
    outtextxy(maxx*86/100,maxy*47/100,ball6);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    p1 = maxx*2/100; p2 = maxx*26/100; p3 = maxy*4/100; p4 = maxy*11/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           readimagefile("data_files/screens/selectmenu/Slide4.jpg",0,0,maxx,maxy);
           delay(300);
           sprintf(o1->over,"%d%d%d%d%d%d",o1->pover[0],o1->pover[1],o1->pover[2],o1->pover[3],o1->pover[4],o1->pover[5]);
           choice = 1;
        }

    p1 = maxx*28/100; p2 = maxx*72/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           readimagefile("data_files/screens/selectmenu/Slide5.jpg",0,0,maxx,maxy);
           delay(300);
           prevscreen(o1,o2,maxx,maxy);
        }
    p1 = maxx*74/100; p2 = maxx*98/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           readimagefile("data_files/screens/selectmenu/Slide6.jpg",0,0,maxx,maxy);
           delay(300);
           choice = 2;
        }
    p1 = maxx*72/100; p2 = maxx*94/100; p3 = maxy*84/100; p4 = maxy*96/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           readimagefile("data_files/screens/selectmenu/Slide7.jpg",0,0,maxx,maxy);
           delay(300);
           choice = 3;
        }
    p1 = maxx*8/100; p2 = maxx*16/100; p3 = maxy*44/100; p4 = maxy*56/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[0] = ret;
        }
    p1 = maxx*23/100; p2 = maxx*31/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[1] = ret;
        }
    p1 = maxx*38/100; p2 = maxx*46/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[2] = ret;
        }
    p1 = maxx*53/100; p2 = maxx*61/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[3] = ret;
        }
    p1 = maxx*68/100; p2 = maxx*76/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[4] = ret;
        }
    p1 = maxx*83/100; p2 = maxx*91/100;
    if((mxpos>=p1)&&(mxpos<=p2)&&(mypos>=p3)&&(mypos<=p4))
        {
           ret = get_user_input(maxx,maxy);
           o1->over[5] = ret;
        }
    if(choice==1||choice==2||choice==3)
    {
        c = confirmation(maxx,maxy);
        if(c==0)
        {
            choice=0;
            run_input(o1,o2);
        }
        else
        {
            if(choice==2)
            {
                readimagefile("data_files/screens/loading/Slide1.jpg",0,0,maxx,maxy);
                delay(4000);
                main_menu();
            }
            else
                return;
        }
    }
    else
        run_input(o1,o2);
}

void gameloop_mp_odi(int type)
{
    int maxx = getmaxx();
    int maxy = getmaxy();
    player p1,p2;
    player *b,*f;
    team_select(maxx,maxy,&p1,1);
    team_select(maxx,maxy,&p2,2);
    p1.set_match(type);
    p2.set_match(type);
    p1.ptype = 1;
    p2.ptype = 1;
    int toss_result = toss(p1,p2,maxx,maxy);
    switch(toss_result)
    {
    case 1:
        b= &p1;
        f = &p2;
        break;
    case 2:
        f = &p1;
        b = &p2;
        break;
    }
    p1.curr_innings = 1;
    p2.curr_innings  = 1;
    while(b->overs>0)
    {
        sprintf(b->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        sprintf(f->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        readimagefile("data_files/images/batsman.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(b,f);
        readimagefile("data_files/images/bowler.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(f,b);
        for(int j=0;j<6;j++)
        {
            b->curr_ball = j;
            PlaySound(TEXT("data_files/sounds/crowd.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            if(b->over[j]!=f->over[j]) {
            ball_hit_runs(&b->over[j],*b,*f);
            b->updatescores(b->over[j]);
            delay(500);
            }
            else  {
            ball_hit_out(b->curr_batsman,*b,*f);
            delay(500);
            b->wickets--;
            b->curr_batsman = 0;
            if(b->wickets==0)
                break;
              }
            }
            if(b->wickets==0)
                break;
            b->overs--;
            b->curr_over++;
            for(int k=0;k<6;k++)
            {
                b->pover[k] = b->over[k] - '0';
                f->pover[k] = f->over[k] - '0';
            }
        }
        readimagefile("data_files/images/eofi.jpg",0,0,maxx,maxy);
        delay(2000);
        p1.curr_innings = 2;
        p2.curr_innings = 2;
        if(b==&p1)
        {
            b = &p2;
            f = &p1;
        }
        else
        {
            b = &p1;
            f = &p2;
        }
    while(b->overs>0)
    {
        sprintf(b->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        sprintf(f->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        readimagefile("data_files/images/batsman.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(b,f);
        readimagefile("data_files/images/bowler.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(f,b);
        for(int j=0;j<6;j++)
        {
            b->curr_ball = j;
            PlaySound(TEXT("data_files/sounds/crowd.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            if(b->over[j]!=f->over[j]) {
            ball_hit_runs(&b->over[j],*b,*f);
            b->updatescores(b->over[j]);
            delay(500);
            if(b->score>f->score)
            {
                break;
            }
            }
            else  {
            ball_hit_out(b->curr_batsman,*b,*f);
            delay(500);
            b->wickets--;
            b->curr_batsman = 0;
            if(b->wickets==0)
                break;
              }
            }
            if(b->score>=f->score)
            {
                break;
            }
            if(b->wickets==0)
                break;
            b->overs--;
            b->curr_over++;
            for(int k=0;k<6;k++)
            {
                b->pover[k] = b->over[k] - '0';
                f->pover[k] = f->over[k] - '0';
            }
        }
    readimagefile("data_files/images/eofi.jpg",0,0,maxx,maxy);
    delay(2000);
    getwinner(p1,p2);
}

void gameloop_mp_test(int type)
{
    int innings_count=0,set_score=0;
    int maxx = getmaxx();
    int maxy = getmaxy();
    player p1,p2;
    player *b,*f;
    team_select(maxx,maxy,&p1,1);
    team_select(maxx,maxy,&p2,2);
    char y;
    char x[1];
    p1.set_match(type);
    p2.set_match(type);
    p1.ptype = 1;
    p2.ptype = 1;
    int toss_result = toss(p1,p2,maxx,maxy);
    switch(toss_result)
    {
    case 1:
        b= &p1;
        f = &p2;
        break;
    case 2:
        f = &p1;
        b = &p2;
        break;
    }
    for(innings_count=0;innings_count<2;innings_count++)
    {
    p1.curr_innings = innings_count+1;
    p2.curr_innings = innings_count+1;
    if(innings_count==1)
    {
        if(b==&p1)
        {
            b = &p2;
            f = &p1;
        }
        else
        {
            b = &p1;
            f = &p2;
        }
    }
    while(1)
    {
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        sprintf(b->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        sprintf(f->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        readimagefile("data_files/images/batsman.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(b,f);
        readimagefile("data_files/images/bowler.jpg",0,0,maxx,maxy);
        delay(3000);
        run_input(f,b);
        for(int j=0;j<6;j++)
        {
            b->curr_ball = j;
            PlaySound(TEXT("data_files/sounds/crowd.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            if(b->over[j]!=f->over[j]) {
            ball_hit_runs(&b->over[j],*b,*f);
            b->updatescores(b->over[j]);
            delay(500);
            if((set_score!=0)&&(b->score >= set_score))
                break;
            }
            else  {
            ball_hit_out(b->curr_batsman,*b,*f);
            delay(500);
            b->wickets--;
            b->curr_batsman = 0;
            if(b->wickets==0)
                break;
              }
            }
            if((set_score!=0)&&(b->score>=set_score))
            {
                break;
            }
            if(b->wickets==0)
                break;
            b->curr_over++;
            for(int k=0;k<6;k++)
            {
                b->pover[k] = b->over[k] - '0';
                f->pover[k] = f->over[k] - '0';
            }
        }
        set_score = b->score+1;
        readimagefile("data_files/images/eofi.jpg",0,0,maxx,maxy);
        delay(2000);
    }
    getwinner(p1,p2);
}

void gameloop_sp(int type)
{
    int innings_count,k;
    int maxx = getmaxx();
    int maxy = getmaxy();
    player p,o;
    player *b,*f;
    team_select(maxx,maxy,&p,1);
    team_select(maxx,maxy,&o,2);
    char y;
    char x[1];
    p.set_match(type);
    o.set_match(type);
    p.ptype = 1;
    o.ptype = 2;
    if(p.overs==0)
    {
    int toss_result = toss(p,o,maxx,maxy);
    switch(toss_result)
    {
    case 1:
        b= &p;
        f = &o;
        break;
    case 2:
        f = &p;
        b = &o;
        break;
    }
    for(innings_count=0;innings_count<2;innings_count++)
    {
    p.curr_innings = innings_count+1;
    o.curr_innings = innings_count+1;
    if(innings_count==1)
    {
        if(b==&p)
        {
            b = &o;
            f = &p;
        }
        else
        {
            b = &p;
            f = &o;
        }
    }
    while(1)
    {
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        sprintf(b->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        sprintf(f->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        readimagefile("data_files/images/batsman.jpg",0,0,maxx,maxy);
        delay(3000);
        if(b==&p)
        {
            run_input(b,f);
        }
        else
        {
            readimagefile("data_files/images/simulating.jpg",0,0,maxx,maxy);
            delay(2000);
            cout<<"Random batting : ";
            srand(time(0));
            for(int i=0;i<6;i++)
                {
                    b->over[i]= (1+(rand()%6))+'0';
                    cout<<b->over[i];
                }
        }
        readimagefile("data_files/images/bowler.jpg",0,0,maxx,maxy);
        delay(3000);
        if(f==&p)
            {
                run_input(f,b);
            }
        else
            {
                readimagefile("data_files/images/simulating.jpg",0,0,maxx,maxy);
                delay(2000);
                cout<<"Random bowling : ";
                srand(time(0));
                for(int i=0;i<6;i++)
                    {
                        f->over[i]= (1+(rand()%6))+'0';
                        cout<<f->over[i];
                    }
            }
        for(int j=0;j<6;j++)
        {
            b->curr_ball = j;
            PlaySound(TEXT("data_files/sounds/crowd.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            if(b->over[j]!=f->over[j]) {
            ball_hit_runs(&b->over[j],*b,*f);
            b->updatescores(b->over[j]);
            delay(500);
            if((innings_count==1)&&(b->score >= f->score))
                break;
            }
            else  {
            ball_hit_out(b->curr_batsman,*b,*f);
            delay(500);
            b->wickets--;
            b->curr_batsman = 0;
            if(b->wickets==0)
                break;
              }
            }
            if((innings_count==1)&&(b->score >= f->score))
                break;
            if(b->wickets==0)
                break;
            b->curr_over++;
            for(k=0;k<6;k++)
            {
                b->pover[k] = b->over[k] - '0';
                f->pover[k] = f->over[k] - '0';
            }
        }
        readimagefile("data_files/images/eofi.jpg",0,0,maxx,maxy);
        delay(2000);
    }
    }
    else
    {
    int toss_result = toss(p,o,maxx,maxy);
    switch(toss_result)
    {
    case 1:
        b= &p;
        f = &o;
        break;
    case 2:
        f = &p;
        b = &o;
        break;
    }
    for(innings_count=0;innings_count<2;innings_count++)
    {
    p.curr_innings = innings_count+1;
    o.curr_innings = innings_count+1;
    if(innings_count==1)
    {
        if(b==&p)
        {
            b = &o;
            f = &p;
        }
        else
        {
            b = &p;
            f = &o;
        }
    }
    while(b->overs>0)
    {
        PlaySound(TEXT("data_files/music/raw.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        sprintf(b->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        sprintf(f->over,"%d%d%d%d%d%d",0,0,0,0,0,0);
        readimagefile("data_files/images/batsman.jpg",0,0,maxx,maxy);
        delay(3000);
        if(b==&p)
        {
            run_input(b,f);
        }
        else
        {
            readimagefile("data_files/images/simulating.jpg",0,0,maxx,maxy);
            delay(2000);
            cout<<"Random batting : ";
            srand(time(0));
            for(int i=0;i<6;i++)
                {
                    b->over[i]= (1+(rand()%6))+'0';
                    cout<<b->over[i];
                }
        }
        readimagefile("data_files/images/bowler.jpg",0,0,maxx,maxy);
        delay(3000);
        if(f==&p)
            {
                run_input(f,b);
            }
        else
            {
                readimagefile("data_files/images/simulating.jpg",0,0,maxx,maxy);
                delay(2000);
                cout<<"Random bowling : ";
                srand(time(0));
                for(int i=0;i<6;i++)
                    {
                        f->over[i]= (1+(rand()%6))+'0';
                        cout<<f->over[i];
                    }
            }
        for(int j=0;j<6;j++)
        {
            b->curr_ball = j;
            PlaySound(TEXT("data_files/sounds/crowd.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            if(b->over[j]!=f->over[j]) {
            ball_hit_runs(&b->over[j],*b,*f);
            b->updatescores(b->over[j]);
            delay(500);
            if((innings_count==1)&&(b->score >= f->score))
                break;
            }
            else  {
            ball_hit_out(b->curr_batsman,*b,*f);
            delay(500);
            b->wickets--;
            b->curr_batsman = 0;
            if(b->wickets==0)
                break;
              }
            }
            if((innings_count==1)&&(b->score >= f->score))
                break;
            if(b->wickets==0)
                break;
            b->overs--;
            b->curr_over++;
            for(int k=0;k<6;k++)
            {
                b->pover[k] = b->over[k] - '0';
                f->pover[k] = f->over[k] - '0';
            }
        }
        readimagefile("data_files/images/eofi.jpg",0,0,maxx,maxy);
        delay(2000);
      }
    }
    getwinner(p,o);
}

void intro()
{
    int i;
        int maxx = getmaxx();
        int maxy = getmaxy();
        for(i=0;i<15;i++)
        {
            setfillstyle(SOLID_FILL,i);
            bar(0+i*12,0+i*12,maxx-i*12,maxy-i*12);
            delay(200);
        }
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,0);
            bar(0+i*12,0+i*12,maxx-i*12,maxy-i*12);
        delay(1500);
        setcolor(WHITE);
        settextstyle(3,HORIZ_DIR,8);
        int width2 = textwidth("Neo-Retro Games");
        int height2 = textheight("Neo-Retro Games");
        outtextxy(maxx/2 - width2/2,maxy/2 - height2/2 +15,"Neo-Retro Games");
        delay(2300);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(600);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(300);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(200);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(100);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(100);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(70);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(70);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(50);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(50);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(50);
        readimagefile("data_files/screens/intro/Slide3.jpg",0,0,maxx,maxy);
        delay(40);
        readimagefile("data_files/screens/intro/Slide2.jpg",0,0,maxx,maxy);
        delay(770);
        readimagefile("data_files/screens/intro/Slide4.jpg",0,0,maxx,maxy);
        delay(2000);
        readimagefile("data_files/screens/intro/Slide5.jpg",0,0,maxx,maxy);
        getch();
        readimagefile("data_files/screens/loading/Slide2.jpg",0,0,maxx,maxy);
        delay(2000);
}

void credits(int maxx,int maxy)
{
    readimagefile("data_files/screens/credits/Slide1.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*2/100)&&(mxpos<=maxx*10/100)&&(mypos>=maxy*4/100)&&(mypos<=maxy*9/100))
    {
        readimagefile("data_files/screens/credits/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        return;
    }
    credits(maxx,maxy);
}

void how_to_play(int maxx,int maxy)
{
    readimagefile("data_files/screens/htp/Slide1.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*2/100)&&(mxpos<=maxx*10/100)&&(mypos>=maxy*4/100)&&(mypos<=maxy*9/100))
    {
        readimagefile("data_files/screens/htp/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        return;
    }
    how_to_play(maxx,maxy);
}

void spmenu(int maxx,int maxy)      //single player menu
{
    music_playing = 0;
    readimagefile("data_files/screens/modemenu/Slide1.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*56/100)&&(mxpos<=maxx*92/100)&&(mypos>=maxy*5/100)&&(mypos<=maxy*19/100))
    {
        readimagefile("data_files/screens/modemenu/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        gameloop_sp(1);
        return;
    }
    if((mxpos>=maxx*56/100)&&(mxpos<=maxx*92/100)&&(mypos>=maxy*23/100)&&(mypos<=maxy*37/100))
    {
        readimagefile("data_files/screens/modemenu/Slide3.jpg",0,0,maxx,maxy);
        delay(300);
        gameloop_sp(2);
        return;
    }
    if((mxpos>=maxx*3/100)&&(mxpos<=maxx*11/100)&&(mypos>=maxy*5/100)&&(mypos<=maxy*11/100))
    {
        readimagefile("data_files/screens/modemenu/Slide4.jpg",0,0,maxx,maxy);
        delay(300);
        music_playing=1;
        return;
    }
    spmenu(maxx,maxy);
}

void mpmenu(int maxx,int maxy)      //Multiplayer menu
{
    music_playing = 0;
    readimagefile("data_files/screens/multimenu/Slide1.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*69/100)&&(mxpos<=maxx*91/100)&&(mypos>=maxy*25/100)&&(mypos<=maxy*35/100))
    {
        readimagefile("data_files/screens/multimenu/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        gameloop_mp_odi(1);
        return;
    }
    if((mxpos>=maxx*69/100)&&(mxpos<=maxx*91/100)&&(mypos>=maxy*45/100)&&(mypos<=maxy*56/100))
    {
        readimagefile("data_files/screens/multimenu/Slide3.jpg",0,0,maxx,maxy);
        delay(300);
        gameloop_mp_test(2);
        return;
    }
    if((mxpos>=maxx*3/100)&&(mxpos<=maxx*11/100)&&(mypos>=maxy*5/100)&&(mypos<=maxy*11/100))
    {
        readimagefile("data_files/screens/multimenu/Slide4.jpg",0,0,maxx,maxy);
        delay(300);
        music_playing=1;
        return;
    }
    mpmenu(maxx,maxy);
}

int exitconf(int maxx,int maxy)     //Exit game confirmation prompt - yes or no
{
    readimagefile("data_files/screens/mainmenu/Slide7.jpg",0,0,maxx,maxy);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*27/100)&&(mxpos<=maxx*45/100)&&(mypos>=maxy*58/100)&&(mypos<=maxy*70/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide8.jpg",0,0,maxx,maxy);
        delay(300);
        return 1;
    }
    if((mxpos>=maxx*54/100)&&(mxpos<=maxx*72/100)&&(mypos>=maxy*58/100)&&(mypos<=maxy*70/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide9.jpg",0,0,maxx,maxy);
        delay(300);
        return 0;
    }
    exitconf(maxx,maxy);
}

void main_menu()
{
    int maxx = getmaxx();
    int maxy = getmaxy();
    readimagefile("data_files/screens/mainmenu/Slide1.jpg",0,0,maxx,maxy);
    int choice,run=0;
    if(music_playing==0)
    {
        PlaySound(TEXT("data_files/music/RFC.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        music_playing = 1;
    }
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,mxpos,mypos);
    if((mxpos>=maxx*39/100)&&(mxpos<=maxx*61/100)&&(mypos>=maxy*34/100)&&(mypos<=maxy*45/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide2.jpg",0,0,maxx,maxy);
        delay(300);
        choice = 1;
    }
    if((mxpos>=maxx*39/100)&&(mxpos<=maxx*61/100)&&(mypos>=maxy*47/100)&&(mypos<=maxy*58/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide3.jpg",0,0,maxx,maxy);
        delay(300);
        choice = 2;
    }
    if((mxpos>=maxx*39/100)&&(mxpos<=maxx*61/100)&&(mypos>=maxy*61/100)&&(mypos<=maxy*72/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide4.jpg",0,0,maxx,maxy);
        delay(300);
        choice = 3;
    }
    if((mxpos>=maxx*39/100)&&(mxpos<=maxx*61/100)&&(mypos>=maxy*74/100)&&(mypos<=maxy*85/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide5.jpg",0,0,maxx,maxy);
        delay(300);
        choice = 4;
    }
    if((mxpos>=maxx*39/100)&&(mxpos<=maxx*61/100)&&(mypos>=maxy*88/100)&&(mypos<=maxy*99/100))
    {
        readimagefile("data_files/screens/mainmenu/Slide6.jpg",0,0,maxx,maxy);
        delay(300);
        choice = 5;
    }
    switch(choice)
        {
        case 1:
            spmenu(maxx,maxy);
            break;
        case 2:
            mpmenu(maxx,maxy);
            break;
        case 3:
            how_to_play(maxx,maxy);
            break;
        case 4:
            credits(maxx,maxy);
            break;
        case 5:
            run = exitconf(maxx,maxy);
            if(run==0)
            break;
            else
            throw(1);
        default:
            break;
        }
    main_menu();
}

int main()          //Main function
{
    try
    {
    PlaySound(TEXT("data_files/music/RFC.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
    music_playing = 1;
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    initwindow(int(screenWidth),int(screenHeight),"",-3,-3,false,false);
    intro();
    main_menu();
    }
    catch(...) {        //Not really error handling. Just a quick way to exit the game :-P
    int maxx = getmaxx();
    int maxy = getmaxy();
    readimagefile("data_files/screens/intro/Slide1.jpg",0,0,maxx,maxy);
    delay(3000);
    closegraph();
    }
    return 0;
}

