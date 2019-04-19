#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

//Functions in the program :

void setup_field(int rt1,int rt2,int rb1,int rb2,int ht1,int ht2,int hb1,int hb2,int st1,int st2,int sb1,int sb2);      //Sets up the game screen with the stumps,bat,pitch,etc.
int get_user_input(int maxx,int maxy);      //Get's users input for each ball.
int confirmation(int maxx,int maxy);    //Prompts the user for a 'yes' or 'no' confirmation
void gameloop_mp_odi(int type);     //Multiplayer ODI match Game loop
void gameloop_mp_test(int type);    //Multiplayer Test match Game loop
void gameloop_sp(int type);     //Single player game loop (common for all match types)
void intro();                           //Intro animation
void credits();                 //credits screen display
void main_menu();           //Main menu in the game

#endif // FUNC_H_INCLUDED
