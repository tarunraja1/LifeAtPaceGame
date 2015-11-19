//-------------------------------------------------------------------------
//HEADER FILES
//-------------------------------------------------------------------------

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//-------------------------------------------------------------------------
//SOME VARIABLE DECLARATIONS
//-------------------------------------------------------------------------

void mainmenu();int tomatoes=0,loadpadd=0, filend,filend1,county=0,gamerace=0;
const int repairfactor[20]={2,3,5,7,8,11,12,14,16,20,26,31,37,43,49,55,62,70,81,93};

int col,NEW=0,OLD=1,t,NO=0,YES=1,l,turn=0,empty=NO, currrank,count1=0,saved=NO,training=NO,loaded=NO,noofinplayers=0,wins[4]={0,0,0,0},counter=0;
char playername[11],prevch;
float prizefloat, rankfloat, totlevelfloat;
int prize;


//-------------------------------------------------------------------------
//CLASS DECLARATION
//-------------------------------------------------------------------------

class player
 { public:
   char password[11];
   int exists;
   char name[11];
   int totlevel;
   int rank;
   int maxhealth;
   int health;
   int fin;
   int carno;
   int maxhandling;
   int handling;
   int tyres;
   int maxspeed;
   int speed;
   int engine;
   int chassi;
   int maxweaponstrength;
   int weaponstrength;
   int ammo;
   int weapon;
   int nitro;
   double money;
   int team;
   int type;
   int pos;
   int prg;
   int prevpos;
   int healthpack;
   int bonushealth;
   int bonusspeed;
   int bonushandling;
   int bonusweaponstrength;

   int ihealth;
   int ihandling;
   int ispeed;
   int iweaponstrength;

   int chassirepaircost;
   int tyresrepaircost;
   int enginerepaircost;
   int weaponrepaircost;
   int enginecount;
   int weaponcount;
   int tyrescount;
   int chassicount;

   player()
   {
   exists=NO;
   ihealth=70;
   ihandling=70;
   ispeed=70;
   rank=1;
   iweaponstrength=70;
   totlevel=0;
   maxhealth=70;
   health=70;
   carno=0;
   maxhandling=70;
   handling=70;
   tyres=0;
   fin=NO;
   maxspeed=70;
   speed=70;
   engine=0;
   chassi=0;
   maxweaponstrength=70;
   weaponstrength=70;
   ammo=0;
   weapon=0;
   nitro=0;
   money=0;
   team=1;
   type=0;
   pos=0;
   prg=0;
   prevpos=0;
   healthpack=0;
   bonushealth=0;
   bonusspeed=0;
   bonushandling=0;
   bonusweaponstrength=0;

   chassirepaircost=0;
   tyresrepaircost=0;
   enginerepaircost=0;
   weaponrepaircost=0;
   chassicount=0;
   enginecount=0;
   tyrescount=0;
   weaponcount=0;}

   void defaultify()
   {exists=NO;
    chassicount=0;
   enginecount=0;
   tyrescount=0;
   weaponcount=0;
   ihealth=70;
   ihandling=70;
   ispeed=70;
   iweaponstrength=70;
   totlevel=0;
   maxhealth=70;
   health=70;
   carno=0;
   maxhandling=70;
   handling=70;
   tyres=0;
   fin=NO;
   rank=1;
   maxspeed=70;
   speed=70;
   engine=0;
   chassi=0;
   maxweaponstrength=70;
   weaponstrength=70;
   ammo=0;
   weapon=0;
   nitro=0;
   money=0;
   team=1;
   type=1;
   pos=0;
   prg=0;
   prevpos=0;
   healthpack=0;
   bonushealth=0;
   bonusspeed=0;
   bonushandling=0;
   bonusweaponstrength=0;

   chassirepaircost=0;
   tyresrepaircost=0;
   enginerepaircost=0;
   weaponrepaircost=0;
 }


   void getchassirepaircost()
   {chassirepaircost=(maxhealth-health)*repairfactor[carno];}

   void getenginerepaircost()
   {enginerepaircost=(maxspeed-speed)*repairfactor[carno];}

   void gettyresrepaircost()
   {tyresrepaircost=(maxhandling-handling)*repairfactor[carno];}

   void getweaponrepaircost()
   {weaponrepaircost=(maxweaponstrength-weaponstrength)*repairfactor[carno];}

   void totallevel()
   {totlevel=maxhealth+maxhandling+maxweaponstrength+maxspeed;
     }};

   player p[5];
   player sp[50],p1;


//-------------------------------------------------------------------------
//VARIABLE AND CONSTANT DECLARATIONS
//-------------------------------------------------------------------------
char currname[11];
 float currbarfrac,floatcurrbar;
 enum specials{up=72,down=80,next=77,previous=75,esc=27,enter=13,back=8,space=32};
 char HEALTH=3,HANDLING=247,SPEED=175,WEAPON=15,HEALTHPACK=206,NITRO=235,yes=0,no=1;

 const double bribecost[6][3]={200,300,500,400,800,5000,1000,2000,8000,6000,8000,12000,9000,13000,20000,16000,25000,50000};
 const double rewardarray[6][3]={300,400,650,550,950,4500,1000,2100,7000,2000,3300,10500,4200,6800,13000,6000,8900,25000};
 const char trackname[6][15]={"USA","Japan","India","Mozambique","Afghanistan","Antarctica"};
 const char trackdescription[6][200]={"Race through the highways of California, and chase your American dream!","Race in the moonlight on the streets of Tokyo. Gambatte kudasai!","Can you dare to drive on the railway tracks of rural India? Bas ki hai?","The jungle awaits you.","May God save you from this place. Va-L-Hamd-o-Le-L-Allah!","Currently there is no information available about this place."};
 const float tracklength[6]={2.0,2.3,2.5,2.7,3.0,5.0};
 const char tracksymbol[6]={'a','≤','ÿ','∞','∞','€'};
 const int trackcolor[6]={7,BLUE,BROWN,GREEN,YELLOW,7};
 const char chassiname[8][25]={"Iron","Steel","Titanium","Karbium","Gerrdium","Obzite","Nitronium","Gold-Nitronium"};
 const float speeddegrade[6]={1,2,3,6,8,10};
 const float handlingdegrade[6]={2,4,6,12,16,20};
 const int chassicolor[8]={7,15,11,13,10,9,12,14};
 const int chassibonus[8]={0,30,80,140,250,360,450,500};
 const double chassicost[8]={0,600,3000,12000,21000,40000,70000,100000};

 const int enginebonus[8]={0,30,80,140,210,290,380,500};
 const double enginecost[8]={0,500,2000,10000,19000,28000,40000,70000};

 const int tyresbonus[8]={0,30,80,140,210,290,380,500};
 const double tyrescost[8]={0,500,2000,10000,19000,28000,40000,70000};

 const int weaponstrengthbonus[8]={0,30,80,140,210,290,380,500};
 const double weaponcost[8]={0,500,2000,10000,19000,28000,40000,70000};
 int sumofrank[4]={0,0,0,0};

 const double carcost[20]={0,500,1500,3500,4000,10000,11000,14000,16000,21000,34000,40000,43000,38000,53000,102000,123000,180000,250000,320000};
 const int carhealth[20]={70,75,85,100,110,150,160,170,185,200,280,290,300,305,310,470,410,450,460,480};
 const int carspeed[20]={70,80,90,75,85,100,120,130,150,160,200,250,270,285,300,370,470,390,500,450};
 const int carhandling[20]={70,60,75,65,60,150,130,140,140,170,250,220,230,200,270,460,410,450,460,400};
 const int carweaponstrength[20]={70,75,70,100,75,150,140,190,150,200,190,290,310,280,340,440,400,470,485,500};
 const char carname[20][19]={"Rickshaw","Bajaj Scooter","Smile Mobile","Homie","Broadwagon","The Bus","Bubble Racer","Curve 444","Wriggler","Widewing","Triple Decker","Scramcut","Jetset","Khaya Bhusa","Roadster","The Cube","Orb 9000","Tank","Crusher","Mysterious Vehicle"};
 const char weaponname[20][30]={"Throwing Knife","Pistol","Smile Gun","Rooftop Turret","Shotgun","Machine Gun","Bubble Bombs","RDX Boomerangs","Parasite Bombs","Air Wave","Triple Gun","Cutter Missiles","Guided Missiles","Electrobeam","Heat Mines","Gravity Bomb","Laser Cannon","Plasma Cannon","Shockwave","Mysterious Weapon"};
 const char carsymbol[21]={"ÌÏÃÕÍ}˜)>Ø˛ÈÂ‰®"};
 const int healthpackcost=1000;

 int sold=yes,damage=NO;
 double reward;
 float chance;




 float eventprob[3]={15,9,5};
 const int eventdamage[6][3]={3,7,10,
			      10,15,20,
			      20,25,30,
			      30,35,40,
			      40,45,50,
			      50,60,70};
 const char eventstatement[6][3][79]={"You are being chased by the cops.",
				      "A huge truck is trying to overtake you.",
				      "A helicopter is going to crash onto you.",

				      "An old lady is crossing the road.",
				      "A crazy out-of-control robot just escaped, and is coming to attack you.",
				      "A samurai Godzilla just came in front of you.",

				      "A train is coming in front of you.",
				      "A beggar came and slept on the railway track.",
				      "Veerappan is chasing you on a horse, and wants to eat you.",

				      "A group of tribals appeared and are interested in making a soup of you.",
				      "You just got stuck in a swamp.",
				      "A herd of elephants is coming towards you.",

				      "A group of terrorists is coming to attack you.",
				      "A sandstorm is coming towards you.",
				      "Osama Bin Laden is coming in his heavy armoured tank to kill you.",

				      "A snowstorm is coming towards you.",
				      "The icy ground in front of you is cracking and melting away.",
				      "A meteorite is coming crashing towards you."
				      };

 const char eventattempt[6][3][79]={"Kill them.",
				    "Overtake the truck.",
				    "Destroy it in mid air.",

				    "Crush her.",
				    "Turn the robot off.",
				    "Blast him.",

				    "Destroy the train.",
				    "Crush him.",
				    "Fire on his moustache.",

				    "Slice and dice them.",
				    "Try to get out of it.",
				    "Blast them.",

				    "Kill 'em all.",
				    "Try to pass through it.",
				    "KILL HIM!",

				    "Try to pass through it.",
				    "Try to pass through it.",
				    "Destroy it."};

 const char eventbribe[6][3][79]={"Bribe them.",
				  "Throw some money at him.",
				  "Call the rescue team.",

				  "Throw some money at her.",
				  "Throw some money at it.",
				  "Bribe Godzilla.",

				  "Throw some money on the tracks.",
				  "Throw him... on some money.",
				  "Throw some money at him.",

				  "Throw some clothes on them.",
				  "Call Tarzan for rescue.",
				  "Bribe them.",

				  "Call the US Forces for rescue.",
				  "Call the rescue team.",
				  "Bribe him.",

				  "Call the rescue team from Russia.",
				  "Throw some money in the cracks.",
				  "Call Optimus Prime for rescue."
				  };


const char eventevade[6][3][79]={"Evade them.",
				 "Just stay there, and let the truck overtake you.",
				 "Run!",

				 "Let her peacefully cross the road.",
				 "Let it do what it wants.",
				 "Wait for him to destroy the city and leave.",

				 "Move aside to let the train go.",
				 "Wait for him to wake up and leave.",
				 "Evade him.",

				 "Run away.",
				 "Wait for the swamp to dry up.",
				 "Stay still.",

				 "Evade them.",
				 "Evade the storm.",
				 "Pray for your life.",

				 "Evade the storm.",
				 "Take a longer, safer route.",
				 "Run for your life!!!!"};

const char eventfail[6][3][79]={"The cops fire at you, and you take some damage.",
				"You collide with the truck.",
				"The helicopter crashed onto you! You missed it!",

				"The old lady happens to be a Samurai. She takes out her sword and slices you!",
				"The robot damaged your vehicle, and started moonwalking. (AAAooo!)",
				"Godzilla steps onto you... that's all what is needed for some serious damage.",

				"You failed. The train just crushed you.",
				"The beggar threw a grenade at you. God knows where he got that from.",
				"You miss your target! Veerappan just ate you!",

				"You failed. But you do make a tasty soup.",
				"Your vehicle is damaged in the swamp.",
				"You missed. But now those elephants won't miss stepping on you.",

				"Those guys are too strong this time! Boom! Boom!",
				"You are blown away in the storm.",
				"Osama: You missed me haha! Die, fool! For Allah!",

				"You are blown away out of sight.",
				"You fell into the crack.",
				"You missed hitting the meteorite. OUCH!"};

const char eventbribed[6][3][79]={"The cops happily go away.",
				  "The driver stays behind you, while collecting your money.",
				  "The team arrives just in time.",

				  "She crosses the road faster as she picks up the money.",
				  "Robot: Yes! Now i can finally buy my new nailcutters with this money!",
				  "Godzilla leaves the city and buys clothes for himself with the money.",

				  "Looking at the money on the tracks... the train driver stops, to take it.",
				  "The beggar runs away with the money.",
				  "Veerappan eats the money instead.",

				  "The tribals retreat. And make a soup of the money.",
				  "Tarzan: I'll save you my friend! Convenience charges apply.",
				  "You successfully bribe the elephants. How you did that, is still a mystery.",

				  "The US Forces turn those terrorists to dust.",
				  "You are successfully rescued.",
				  "Osama leaves happily with your generous gift.",

				  "You are successfully rescued.",
				  "With the touch of the money you throw on the ground, the cracks rejoin.",
				  "Optimus: You will be rescued, for you are responsible for saving my pockets!"};


const char eventevaded[6][3][79]={"You successfully evade the cops.",
				  "The truck overtook you, slowing you down.",
				  "You drive away from the road and are saved.",

				  "Crossing.... Crossing.... Crossed.",
				  "The robot kisses you and leaves.",
				  "Damn! Tokyo is doomed.",

				  "You come out of the railway track, as the train passes by.",
				  "Beggar: Good Morning stranger! See ya.",
				  "Veerappan: Damn! My horse is slower than his vehicle. My food ran away!",

				  "You move away from the track to evade the tribals.",
				  "The swamp has become a desert by now.",
				  "The elephants.... just leave.",

				  "You successfully escape the terrorists.",
				  "You successfully evade the storm.",
				  "Osama finds you too boring, and leaves.",

				  "You escape the snowstorm unharmed.",
				  "You take a longer, safer route.",
				  "Your running was, after all, not in vain. You did manage to save your life."};

//-------------------------------------------------------------------------
//SOME MORE VARIABLES
//-------------------------------------------------------------------------

 int track[50],currrace=0,currammo=0,currtrack=0,totaltracks=5,decider=1,count=0,y=0,flash=1;
 int currcar=0,currengine=0,currtyres=0,currchassi=0,currweapon=0,currnitro=0,currhealthpack=0;
 int noofplayers=1,spadd,tempnoof,hit;
 int noofraces=0,noofsaved=0,prob1,prob2;
 char nameoftournament[60],currtour[60],passo[11],defname[10]="Noname",passo2[11],defpass[11]="race";
 char fh;
 int currplayer=0,flash2=no,currbar=0,currbarperc=0,available=NO,currprg=0;
 float speedmod=0.75,handlingmod=0.25,currprgfloat,prgfloat,posfloat;
 float dmg,degrade,weaponstrength,healthfloat,handlingfloat;
 int prevpos,d=0,move=NO,prgfactor,noofteams=0,tempteam[4]={0,0,0,0};

//-------------------------------------------------------------------------
//MAIN MENU CAR
//-------------------------------------------------------------------------

 void startmenucar()
  {
   cprintf("                                   _..-------++._                 ");cout<<endl;
   cprintf("                               _.-'/ |      _||  \"--._           ");cout<<endl;
   cprintf("                         __.--'`._/_\j_____/_||___\    `----.     ");cout<<endl;
   cprintf("                    _.--'_____    |          \     _____    /     ");cout<<endl;
   cprintf("                  _j    /,---.\   |        =o |   /,---.\   |_    ");cout<<endl;
   cprintf("                 [__]==// .-. \\==`===========/==// .-. \\=[__]   ");cout<<endl;
   cprintf("                   `-._|\\ `-' /|___\_________/___|\\ `-' /|_.'     ");cout<<endl;
   cprintf("                         '---'                    `---'          ");cout<<endl;
  }


//-------------------------------------------------------------------------
//SMALL FUNCTIONS
//-------------------------------------------------------------------------
 void symbol(int ascii,int col)
  {char symbol[2];
   symbol[0]=ascii;
   textcolor(col);
   cprintf(symbol);
   textcolor(7);
  }

 void displaycar(int sym,int col)
 {textcolor(chassicolor[col]);
   char symb[2];
   symb[0]=carsymbol[sym];
   cprintf(symb); }

 void displaytrack(int trackno)
 {char arr[2];

 textcolor(trackcolor[trackno]);
  arr[0]=tracksymbol[trackno];
  arr[1]='\0';
  cprintf(arr);
  }

  void reverse(char arr[11])
  { char temp[11];
   int character=NO;
   int c=-1;
   for(int y=10;y>=0;y--)
   { if(arr[y]=='\0')
     {
     character=YES;
     continue; }
     if(character==YES)
     {c++;
      temp[c]=arr[y];}

   }
   c++;
   temp[c]='\0';
   c--;
   if(isupper(temp[c]))
   temp[c]=tolower(temp[c]);

   if(islower(temp[0]))
   temp[0]=toupper(temp[0]);

   strcpy(arr,temp);
   }



 char ch=0;
 int x=0,tf;

 void line(int col,int length=80)
  {
   textcolor(col);
   for(int i=0;i<length;i++)
    cprintf("ƒ");
   textcolor(7);}

 void printinmiddle(char arr[80],int textcol,int backcolor)
  {textcolor(textcol);
   textbackground(backcolor);
   for(int l=0;arr[l]!='\0';l++);
   int noofspaces=(80-l)/2;

   for(int i=0;i<noofspaces;i++)
    cprintf(" ");
   cprintf(arr);
   if((80-l)%2==0)
    {for(int i=0;i<noofspaces;i++)
     cprintf(" "); }
   else
    {for(int i=0;i<(noofspaces+1);i++)
     cprintf(" ");}
   textcolor(7);
   textbackground(0);
		}


 void centerprint(char arr[80],int textcol,int tf)
  {
   for(int l=0;arr[l]!='\0';l++);
   int noofspaces=(80-l)/2;
   textbackground(0);
   if((80-l)%2==0)
    {for(int i=0;i<noofspaces;i++)
     cprintf(" "); }
   else
    {for(int i=0;i<(noofspaces-1);i++)
     cprintf(" ");}

   textcolor(textcol);
   if(tf==0)
    textbackground(BLUE);
   else
    textbackground(0);
   cprintf(arr);

   textcolor(7);
   textbackground(0);
 }


 int &i=currplayer;

//-------------------------------------------------------------------------
//FUNCTION PROTOTYPES
//-------------------------------------------------------------------------

  void error(char arr[100]);
  void getstring(char arr[],int len);
  void getstringpass(char arr[],int len);
  void bar(int curr,int max,int ulti);
  void healthbar(int curr,int max,float size);
  void new1();
  void intro();
  void boot();
  void mainmenu();
  void multiplayer();
  void choosemode();
  void trainingmode();

  char ai(int);
  void loadtournament();
  void tournament();
  void savetournament();
  void choosetype();
  void enterplayers();
  void garage();
  void buyupgrade();
  void buyammo();
  void entername();
  void warning();
  void loadplayer();
  void deletewarning();
  void deleteplayer();
  void deletingplayer();
  void loadtournament1();
  void loadplayer1();
  void enterpassload();
  void loadingplayer();
  void saveplayer();
  void setpassword();
  void enterpassword();
  void changepassword();
  void savingplayer();
  void encrypt(char p[]);
  void decrypt(char p[]);
  void game();
  void showrank();

  void controls();


//-------------------------------------------------------------------------
//FUNCTIONS FOR THE INTRO
//-------------------------------------------------------------------------
 void box(int l,int y,int o=0)
   {
   textcolor(RED);
   if(o==1)
   textcolor(7);
   textbackground(RED);
   int b=y;
    for(int u=0;u<l;u++)
    {

     if(b==0)
     {cprintf(" ");
     b=1;

     continue;}

     if(b==1)
     {cprintf("€");
     b=0;

     continue;}
     }}

 void intro()
 {

 sleep(1);
 randomize();

  clrscr();

  float r=0;
  int w=0;
  char arr[21]={"ÌÏÃÕÍ}˜)>Ø˛ÈÂ‰®"};
  char e[2];
  while(r<250000)
  {r++;
   w++;
   if(w>20)
   w=0;


   e[0]=arr[w];
   e[1]='\0';

   int y=rand()%7+1;
    textcolor(y);
    cprintf(e);

    }
    clrscr();
    cout<<endl<<endl<<endl<<endl;
   textbackground(0);
   textcolor(RED); cprintf("                         €€€€€  €      €€€€€"); textcolor(7);cprintf("  €€€  €€€");   cout<<endl;
   textcolor(RED); cprintf("                         €      €      €    "); textcolor(7);cprintf("  €      €");   cout<<endl;
   textcolor(RED); cprintf("                         €      €      €€€€€"); textcolor(7);cprintf("  €      €");   cout<<endl;
   textcolor(RED); cprintf("                         €      €          €"); textcolor(7);cprintf("  €      €");   cout<<endl;
   textcolor(RED); cprintf("                         €€€€€  €€€€€  €€€€€"); textcolor(7);cprintf("  €€€  €€€");   cout<<endl;
   sleep(1);
   cout<<endl<<endl;
   textcolor(RED);
   cprintf("                          ClearScreen");
   textcolor(7);
   cprintf("()");
   textcolor(RED);
   cprintf(" Entertainment");
   sleep(1);
   cout<<endl<<endl<<endl;
   printinmiddle("A Pulkitvision(c) Entertainment | Kar-Tar(c) Entertainment alliance.",7,0);
   cout<<endl;
   textcolor(RED);
   printinmiddle("(Pulkit Soni)                    (Tarun Raja)",RED,0);
   sleep(2);
   cout<<endl<<endl<<endl;
   printinmiddle("Presents:",7,0);
   sleep(3);

   clrscr();

   textbackground(RED);

    box(80,1,1);
    box(80,0);



box(10,1);  textcolor(7);   cprintf("ƒƒƒ€    ƒƒƒ€ ƒƒƒ€€€€€ ƒƒƒ€€€€€");box(40,1);
box(10,0);  textcolor(7);   cprintf(" ƒƒ€     ƒƒ€  ƒƒ€      ƒƒ€    ");box(40,0);
box(10,1);  textcolor(7);   cprintf("  ƒ€      ƒ€   ƒ€€€€    ƒ€€€€€");box(40,1);
box(10,0);  textcolor(7);   cprintf("   €       €    €        €    ");box(40,0);
box(10,1);  textcolor(7);   cprintf("   €€€€€   €    €        €€€€€");box(40,1);
box(80,0);
box(80,1);
box(32,0);  textcolor(7);   cprintf("ƒƒƒ€€€€€ ƒ€€€€€ ");box(32,0);
box(32,1);  textcolor(7);   cprintf(" ƒƒ€   €  ƒƒ€   ");box(32,1);
box(32,0);  textcolor(7);   cprintf("  ƒ€€€€€   ƒ€   ");box(32,0);
box(32,1);  textcolor(7);   cprintf("   €   €    €   ");box(32,1);
box(32,0);  textcolor(7);   cprintf("   €   €    €   ");box(32,0);
box(80,1);
box(80,0);
box(40,1);  textcolor(7);   cprintf("ƒƒƒ€€€€€ ƒƒƒ€€€€€ ƒƒƒ€€€€€ ƒƒƒ€€€€€");box(5,1);
box(40,0);  textcolor(7);   cprintf(" ƒƒ€   €  ƒƒ€   €  ƒƒ€      ƒƒ€    ");box(5,0);
box(40,1);  textcolor(7);   cprintf("  ƒ€€€€€   ƒ€€€€€   ƒ€       ƒ€€€€€");box(5,1);
box(40,0);  textcolor(7);   cprintf("   €        €   €    €        €    ");box(5,0);
box(40,1);  textcolor(7);   cprintf("   €        €   €    €€€€€    €€€€€");box(5,1);
box(80,0);

box(37,0);  textcolor(7);   cprintf("RACING");box(37,0);


box(80,1,1);
textcolor(7);
textbackground(0);
cprintf("                           Press any key to continue.");


getch();
}

//-------------------------------------------------------------------------
//FUNCTION TO SHOW ERROR
//-------------------------------------------------------------------------

 void error(char arr[100])
  {int sec=11;
   while(tomatoes==0)
    {clrscr();
     sec--;
     printinmiddle("LIFE AT PACE RACING: ERROR",7,RED);
     textcolor(RED);
     cout<<endl;
     cprintf("ERROR! ");
     cprintf(arr);
     cout<<endl<<endl;
     textcolor(GREEN);
     cprintf("Returning to main menu in %d seconds.",sec);
     sleep(1);
     if(sec==1)
     mainmenu();
    }
  }


//-------------------------------------------------------------------------
//FUNCTION TO INPUT STRING
//-------------------------------------------------------------------------
 void getstring(char arr[],int len)
  {char smallarr[2];
   for(int u=0;;u++)
    {
     arr[u]=getch();

     if(arr[u]==esc)
      mainmenu();
     if(arr[0]==space||arr[0]==enter)
      {u=-1;
       continue;}
	  if(!((arr[u]>=65&&arr[u]<=90)||(arr[u]>=97&&arr[u]<=122)||(arr[u]>=48&&arr[u]<=57)||(arr[u]==enter)||(arr[u]==space)||(arr[u]==back)||(arr[u]==esc)))
     {u--;
     continue;}

     textcolor(7);
     smallarr[0]=arr[u];
     smallarr[1]='\0';
     cprintf(smallarr);
     if(arr[u]==back)
      {delline();
       int y=wherey();
       gotoxy(1,y);
       u=-1;}
     if(arr[u]==enter)
      {arr[u]='\0';
       break;}
     if(u==(len-1))
      {arr[len]='\0';
       break;}
    }
  }

//-------------------------------------------------------------------------
//FUNCTION TO INPUT PASSWORD
//-------------------------------------------------------------------------

 void getstringpass(char arr[],int len)
  {char smallarr[2];
   for(int u=0;;u++)
    {arr[u]=getch();
     if(arr[u]==esc)
     mainmenu();
     if(arr[0]==space||arr[0]==enter)
      {u=-1;
       continue;}
       if(!((arr[u]>=65&&arr[u]<=90)||(arr[u]>=97&&arr[u]<=122)||(arr[u]>=48&&arr[u]<=57)||(arr[u]==enter)||(arr[u]==space)||(arr[u]==back)||(arr[u]==esc)))
     {u--;
     continue;}


     textcolor(7);
     if(arr[u]!=enter)
      cprintf("*");
     if(arr[u]==back)
      {delline();
       int y=wherey();
       gotoxy(1,y);
       u=-1;}
     if(arr[u]==enter)
      {arr[u]='\0';
       break;}
     if(u==(len-1))
      {arr[len]='\0';
       break;}
    }
   }

//-------------------------------------------------------------------------
//FUNCTION FOR DISPLAYING BARS
//-------------------------------------------------------------------------

 void bar(int curr,int max,int ulti)
  {int currfrac=curr*0.075;
   int maxfrac=max*0.075;
   int ultifrac=ulti*0.075;
   int pinkbar=ultifrac-maxfrac;
   if(currfrac<0.25*maxfrac)
    textcolor(GREEN+BLINK);
   else
    textcolor(GREEN);
   for(int i=0;i<currfrac;i++)
    cprintf("ﬂ");
   textcolor(RED);
   for(i=0;i<(maxfrac-currfrac);i++)
    cprintf("ﬂ");
   textcolor(5);
   if(pinkbar<0)
    pinkbar=0;
   for(i=0;i<pinkbar;i++)
    cprintf("ﬂ");
   textcolor(7);
  }

//-------------------------------------------------------------------------
//FUNCTION FOR DISPLAYING HEALTH BAR
//-------------------------------------------------------------------------

 void healthbar(int curr,int max,float size)
  { float currf=curr;
   float maxf=max;
   float frac=(currf/maxf)*size;
   float currfrac=frac;
   //int currfrac=(curr/max)*size;
   //int maxfrac=max*frac;
   if(currfrac<0.25*size)
    textcolor(GREEN);
   else
    textcolor(GREEN);
   for(int i=0;i<currfrac;i++)
    cprintf("ﬂ");
   textcolor(RED);
    float blah=size-currfrac;
   for(i=0;i<(blah);i++)
    cprintf("ﬂ");
   textcolor(5);
  }

//-------------------------------------------------------------------------
//TITLE BAR
//-------------------------------------------------------------------------

 void new1()
  {char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   clrscr();
   textbackground(RED);
   textcolor(7);
   cprintf("            ÆÆLIFE AT PACE RACINGØØ  ƒ  ClearScreen Entertainment(c)            ");
   textbackground(7);
   textcolor(0);
   textcolor(BLUE);
   cprintf("  [ESC]");textcolor(0);cprintf("Main Menu ");textcolor(BLUE); cprintf("[ENTER]");textcolor(0);cprintf("Select - Arrow Keys: ");textcolor(BLUE);cprintf("[]");textcolor(0);cprintf("Up ");textcolor(BLUE);cprintf("[]");textcolor(0);cprintf("Down ");textcolor(BLUE); cprintf("[");cprintf(leftarrow);cprintf("]");textcolor(0);cprintf("Previous ");textcolor(BLUE);cprintf("[]");textcolor(0);cprintf("Next  ");
   textbackground(0);
   textcolor(7);
   }

//-------------------------------------------------------------------------
//STARTING PROCESSES
//-------------------------------------------------------------------------

 void boot()
  {

   gotoxy(1,10);
   printinmiddle("Press ALT+ENTER for full screen mode if not using Windows Vista.",7,0);
cout<<endl;
   printinmiddle("Press any key to continue.",RED,0);
   textbackground(0);
   getch();
  intro();
  for(int k=0;k<4;k++)
    {strcpy(p[k].name,defname);}
   for( k=0;k<4;k++)
    {strcpy(p[k].password,defpass);}
   for( k=0;k<50;k++)
    {strcpy(sp[k].password,defpass);}

    p[0].team=1;
    p[1].team=2;
    p[2].team=3;
    p[3].team=4;
   mainmenu();
  }


//-------------------------------------------------------------------------
//LOADING AND SAVING ANIMATION
//-------------------------------------------------------------------------
 void anime(char arr1[15],char arr2[20])
{
l=0;
      currbar=0;
      while(ch!='›')
    {clrscr();l++;

     textcolor(7);

     printinmiddle("LIFE AT PACE",7,RED);
     cout<<endl;
     floatcurrbar=currbar;
     currbarfrac=floatcurrbar/80;
     currbarperc=currbarfrac*100;
     textcolor(CYAN);
     cprintf(arr1);
     cprintf(" (");
     textcolor(GREEN);
     cprintf("%d%",currbarperc);
     textcolor(CYAN);
     cprintf(") ...");
     cout<<endl<<endl;
     int unitsize= rand()%5;
     currbar=unitsize+currbar;
     for(int r=0;r<currbar;r++)
      {textcolor(GREEN);
       cprintf("€");
      }
     for(int s=0;s<80-currbar;s++)
      {textcolor(RED);
       cprintf("€");
      }
     cout<<endl;
     line(RED,80);
     if(currbar>80)
      {clrscr();

       printinmiddle("LIFE AT PACE",7,RED);
       textcolor(GREEN);
       cout<<endl;
       cprintf(arr2);cout<<endl;
       line(RED,80);
       sleep(1);
       break;
      }
     delay(30);
     if(l==1)
     sleep(1);
    }
 }

//-------------------------------------------------------------------------
//THE MAIN MENU
//-------------------------------------------------------------------------


 void mainmenu()
  {x=0; clrscr();
   cout<<endl<<endl;
   textcolor(7);

   while(ch!='›')
   {
    new1();
    textbackground(RED);
    textcolor(7);
    printinmiddle("MAIN MENU",7,RED);
    cout<<endl;
    textcolor(10);
    startmenucar();
    line(RED);
    textcolor(7);
    textbackground(0);

    if(x<0)
     x=2;
    if(x>2)
     x=0;
    if(x==0)
     tf=0;
    else
     tf=1;

    centerprint("START GAME",7,tf);
    cout<<endl;
    textbackground(0);

    if(x==1)
     tf=0;
    else
     tf=1;
    centerprint("CONTROLS",7,tf);
    cout<<endl;
    textbackground(0);

    if(x==2)
     tf=0;
    else
     tf=1;
    centerprint("QUIT",7,tf);
    cout<<endl;
    textbackground(0);
    line(RED);
    cout<<endl;
    line(7,77);
    cprintf("±");
    line(7,2);

    for(int i=0;i<77;i++)
     {cout<<("-");}
    cprintf("±"); cout<<"--";
    textbackground(0);

    line(7,77);cprintf("±");line(7,2);
    ch=getch();
    if(ch==up)
     x--;
    if(ch==down)
     x++;
    if(ch==enter)
     break;
    ch='b';
   }

  if(x==0)
   choosemode();
  if(x==1)
   controls();
  if(x==2)
   exit(0);

  cout<<endl;
  textbackground(0);
 }

//-------------------------------------------------------------------------
//CONTROLS PAGE
//-------------------------------------------------------------------------

 void controls()
 {  while(ch!='a')
  { new1();
    char leftarrow[2]="";
    leftarrow[0]=(leftarrow[0]+1);
    printinmiddle("CONTROLS",7,RED);

     textcolor(GREEN);
     gotoxy(15,5);
     cprintf("(Arrow Keys)");
     gotoxy(15,6);
     cprintf("[] - Up ");
     gotoxy(15,7);
     cprintf("[] - Down ");
     gotoxy(15,8);
     cprintf("[");cprintf(leftarrow);cprintf("] - Previous (Left)");
     gotoxy(15,9);
     cprintf("[] - Next (Right)");
     gotoxy(50,5);
     cprintf("(General Keys)");
     gotoxy(50,6);
     cprintf("Select - [ENTER]");
     gotoxy(50,7);
     cprintf("Main Menu - [ESC]");
     gotoxy(50,8);
     cprintf("Move - D");
     gotoxy(50,9);
     cprintf("Fire - F (followed by");
     gotoxy(50,10);
     cprintf("    player number.)");
     gotoxy(50,11);
     cprintf("Nitro - N");
     gotoxy(50,12);
     cprintf("Healthpack - H");
     gotoxy(50,13);
     cprintf("Event option 1 - W");
     gotoxy(50,14);
     cprintf("Event option 2 - S");
     gotoxy(50,15);
     cprintf("Event option 3 - X");
     cout<<endl<<endl;
     cprintf("For more detailed information, open Howtoplay.exe from your Life at Pace");
     cout<<endl;
     cprintf("directory.");
     cout<<endl;
     line(RED);
     textbackground(BLUE);
     textcolor(7);
     cprintf("BACK");
     textbackground(0);
     cout<<endl;

     ch=getch();

     if(ch==enter)
     mainmenu();

     if(ch==esc)
     mainmenu();
     ch='b';
     }}

//-------------------------------------------------------------------------
//SELECT GAME MODE
//-------------------------------------------------------------------------

 void choosemode()
 { x=0;
 gamerace=0;
 wins[0]=0;
 wins[1]=0;
 wins[2]=0;
 wins[3]=0;
 for(int l=0;l<=3;l++)
 p[l].defaultify();



   while(ch!='›')
   {
    new1();
    textbackground(RED);
    textcolor(7);
    printinmiddle("CHOOSE MODE",7,RED);
    cout<<endl;

    textcolor(7);


    if(x==0)
    textbackground(BLUE);
    cprintf("NEW TOURNAMENT");
    textbackground(0);
    cout<<endl;

    if(x==1)
    textbackground(BLUE);
    cprintf("LOAD TOURNAMENT");
    textbackground(0);
    cout<<endl;
    line(RED);


    if(x==2)
    textbackground(BLUE);
    cprintf("BACK");
    textbackground(0);

    ch=getch();

    if(ch==up)
    x--;
    if(ch==down)
    x++;

    if(x<0)
    x=2;
    if(x>2)
    x=0;

    if(x==0&&ch==enter)
    multiplayer();
    if(x==1&&ch==enter)
    loadtournament1();

    if(x==2&&ch==enter)
    mainmenu();

    if(ch==esc)
    mainmenu();
     ch='b';
 }
  }

//-------------------------------------------------------------------------
//TOURNAMENT DETAILS
//-------------------------------------------------------------------------
 void multiplayer()
  {x=0;
   while(ch!='›')
    {new1();
     char leftarrow[2]="";
     leftarrow[0]=(leftarrow[0]+1);
     textbackground(RED);
     printinmiddle("TOURNAMENT",7,RED);
     textcolor(CYAN);
     textbackground(0);
     cout<<endl;
     if(county==0)
      cprintf("Enter the name of the tournament:");
     else
      cprintf("Tournament:");
     cout<<endl;
     textcolor(GREEN);

     if(county==0)
      {getstring(nameoftournament,60);
       county++;
       continue;}
     else
      cprintf(nameoftournament);
     cout<<endl<<endl;

     textcolor(7);

     if(x==0)
      textbackground(BLUE);
     cprintf("ENTER AGAIN");
     textbackground(0);
     cout<<endl<<endl;
     textcolor(CYAN);
     cprintf("Select number of races in the tournament:");cout<<endl;
     textcolor(7);
     if(x==1)
      textbackground(BLUE);
     textcolor(RED);
     cprintf(leftarrow);
     textcolor(7);
     cprintf("%d",(noofraces+1));
     textcolor(RED);
     cprintf("");
     textcolor(7);
     cout<<endl;

     textbackground(0);
     cout<<endl;

     if(x==2)
      textbackground(BLUE);
     cprintf("CONTINUE");
     textbackground(0);
     cout<<endl;
     line(RED);
     if(x==3)
      textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);
     cout<<endl;
     ch=getch();

     if(ch==up)
      x--;
     if(ch==down)
      x++;
     if(x<0)
      x=3;
     if(x>3)
      x=0;

     if(x==1)
     {
      if(ch==previous)
       noofraces--;
      if(ch==next)
       noofraces++;
      if(noofraces<0)
       noofraces=49;
      if(noofraces>49)
       noofraces=0;}
      if(ch==enter&&x==0)
       {county=0;
	continue;}
      if(ch==enter&&((x==2)||(x==3)))
       break;
      if(ch==esc)
       mainmenu();

      ch='b';
     }

     if(x==2)
      tournament();
     if(x==3)
      choosemode();
     textbackground(0);
  }

//-------------------------------------------------------------------------
//TOURNAMENT SETUP
//-------------------------------------------------------------------------

 void tournament()
  {x=0;
   char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   while(ch!='›')
    {new1();
     printinmiddle("TOURNAMENT SETUP",7,RED);
     cout<<endl;
     textcolor(CYAN);
     cprintf("Tournament: ");
     textcolor(GREEN);
     cprintf(nameoftournament);
     cout<<endl<<endl;

     textcolor(CYAN);
     cprintf("Select the race:");
     cout<<endl;

     if(x<0)
      x=4;
     if(x>4)
      x=0;
     line(RED,35);

     if(x==0)
      textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);
     if(currrace<9)
      cprintf("RACE  %d",currrace+1);
     if(currrace<99&&currrace>=9)
      cprintf("RACE %d",currrace+1);
     textcolor(RED);cprintf("");
     textbackground(0);
     line(RED,36);
     textcolor(CYAN);
     cout<<endl;
     cprintf("Select the track for this race:");
     cout<<endl;

     if(x==1)
      textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf(trackname[track[currrace]]);textcolor(RED);cprintf("");
     textbackground(0);
     textcolor(7);
     cout<<endl<<endl;
     textcolor(GREEN);
     cprintf(trackdescription[track[currrace]]);
     textcolor(7);
     cout<<endl<<endl;


     if(x==2)
     textbackground(BLUE);
     cprintf("SAVE TOURNAMENT");
     cout<<endl;
     textbackground(0);


     if(x==3)
      textbackground(BLUE);
     cprintf("CONTINUE");
     cout<<endl;
     textbackground(0);
     line(RED);

     if(x==4)
      textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);

     ch=getch();

     if(ch==esc)
      mainmenu();
     if(ch==up)
      x--;
     if(ch==down)
      x++;
     if(x==0)
      {
       if(ch==next)
	currrace++;
       if(ch==previous)
	currrace--;
       if(currrace<0)
	currrace=noofraces;
       if(currrace>noofraces)
	currrace=0;
      }
     if(x==1)
      {
       if(ch==next)
	currtrack++;
       if(ch==previous)
	currtrack--;
       if(currtrack<0)
	currtrack=totaltracks;
       if(currtrack>totaltracks)
	currtrack=0;
       if(ch==next)
	track[currrace]=currtrack;
       if(ch==previous)
	track[currrace]=currtrack;
      }

     if(x==2&&ch==enter)
      savetournament();
     if(ch==enter&&(x==4) )
      {decider=0;
       multiplayer();
      }
     if(x==3&&ch==enter)
     {choosetype();}

     ch='b';
     }
   }

//-------------------------------------------------------------------------
//CHOOSE GAME TYPE
//-------------------------------------------------------------------------
 void choosetype()
 {x=0;
  training=NO;

  while(ch!='›')
    {new1();
     printinmiddle("CHOOSE MODE",7,RED);
     cout<<endl;
     textcolor(7);
     if(x==0)
     textbackground(BLUE);
     cprintf("TRAINING MODE");
     textbackground(0);
     cout<<endl<<endl;

     if(x==1)
     textbackground(BLUE);
     cprintf("MULTIPLAYER TOURNAMENT");
     textbackground(0);
     cout<<endl<<endl;


     line(RED);

     if(x==2)
     textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);


     ch=getch();

     if(ch==up)
     x--;
     if(ch==down)
     x++;

     if(x<0)
     x=2;
     if(x>2)
     x=0;

     if(x==0&&ch==enter)
     {training=YES;
      noofplayers=0;
      garage();}

     if(x==1&&ch==enter)
     enterplayers();

     if(x==2&&ch==enter&&loaded==YES)
     loadtournament1();
     else if(x==2&&ch==enter)
     tournament();

     if(ch==esc)
     mainmenu();

     ch='b';
     }
    }


//-------------------------------------------------------------------------
//LOAD TOURNAMENT FROM FILE
//-------------------------------------------------------------------------
 void loadtournament1()
 { loaded=NO;
   struct tournament1
  { char name[60];
    int  no;
    int  fastrack[50];
    };

  tournament1 t;
  ofstream touts("toursave.lap",ios::app|ios::out);
  if(!touts)
  error("Cannot create file.");
  touts.close();

  ifstream tin("toursave.lap",ios::in|ios::binary);

  if(!tin)
  error("Cannot open file.");
  tin.seekg(0);



   x=0;

    tin.read((char*)&t,sizeof(tournament1));
	strcpy(currtour,t.name);


	if(tin.eof()==1)
    {clrscr();
     new1();
     printinmiddle("LOAD TOURNAMENT",7,RED);
     cout<<endl;
     textcolor(CYAN);
     cprintf("There are no tournaments currently saved.");
     sleep(2);
     choosemode();

    }
    else
    { tin.seekg(0);
    while(tomatoes!='c')
  {
  tin.read((char*)&t,sizeof(tournament1));
   if(tin.eof()==1)
   {filend=tin.tellg();
    tin.seekg(0);
    break;}
   }  tin.close();
    loadtournament();}}

 void loadtournament()
 {  struct tournament
  { char name[60];
    int  no;
    int  fastrack[50];
    };

  tournament t;

  ifstream tin("toursave.lap",ios::in|ios::binary);

  if(!tin)
  error("Cannot open file.");
  tin.seekg(0);

  char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   x=0;

    tin.read((char*)&t,sizeof(tournament));
    currrace=0;
	strcpy(currtour,t.name);
	tin.seekg(0);


  while(ch!='›')
  {
      clrscr();
      textcolor(7);
      new1();
      printinmiddle("LOAD TOURNAMENT",7,RED);
      cout<<endl;

	    if(tin.eof()==1)
   {

   tin.close();
   loadtournament();

      }

     textcolor(CYAN);
     cprintf("Choose the saved tournament you wish to load:");
     cout<<endl<<endl;
      textcolor(7);
     if(x==0)
     textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);
     cprintf(t.name);
     textcolor(RED);cprintf("");
     textcolor(7);
     textbackground(0);
     cout<<endl;

     line(RED,80);
     textcolor(CYAN);
     cprintf("Tournament: ");
     textcolor(GREEN);
     cprintf(t.name);
     cout<<endl<<endl;



     if(x==1)
      textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);
     if(currrace<9)
      cprintf("RACE  %d",currrace+1);
     if(currrace<99&&currrace>=9)
      cprintf("RACE %d",currrace+1);
     textcolor(RED);cprintf("");
     textbackground(0);

     textcolor(CYAN);
     cout<<endl;
     cprintf("Track for race %d: ",currrace+1);


     textcolor(7);cprintf(trackname[t.fastrack[currrace]]);
     textbackground(0);
     textcolor(7);
     cout<<endl;




     line(RED,80);


     if(x==2)
     textbackground(BLUE);
     cprintf("LOAD TOURNAMENT");
     textbackground(0);
     cout<<endl;

     if(x==3)
     textbackground(BLUE);
     cprintf("MODIFY AND LOAD");
     textbackground(0);
     cout<<endl;

     if(x==4)
     textbackground(BLUE);
     cprintf("DELETE TOURNAMENT");
     textbackground(0);
     cout<<endl;

     line(RED);

     if(x==5)
     textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);


     ch=getch();

     if(ch==up)
     x--;
     if(ch==down)
     x++;
     if(x>5)
     x=0;
     if(x<0)
     x=5;



	  if(x==1)
      {
       if(ch==next)
	currrace++;
       if(ch==previous)
	currrace--;
       if(currrace<0)
	currrace=t.no;
       if(currrace>t.no)
	currrace=0;
      }


     if(x==0&&ch==next)
      { int nono=tin.tellg();

	tin.read((char*)&t,sizeof(tournament));
	if(nono==0)
	tin.read((char*)&t,sizeof(tournament));
	strcpy(currtour,t.name);
	currrace=0;}

    if(x==0&&ch==previous)
     {int bolo=tin.tellg();
      if(bolo<=sizeof(tournament))
      tin.seekg(filend+sizeof(tournament));
      bolo=tin.tellg();
      tin.seekg(bolo-(2*(sizeof(tournament))));


      tin.read((char*)&t,sizeof(tournament));
      strcpy(currtour,t.name);
      currrace=0;
      }

       if(x==2&&ch==enter)
     {strcpy(nameoftournament,t.name);
      noofraces=t.no;
      for(int cat=0;cat<50;cat++)
      track[cat]=t.fastrack[cat];

      loaded=YES;


      anime("Loading Tournament","Loaded!");
      choosetype();

      }


     if(x==3&&ch==enter)
     { strcpy(nameoftournament,t.name);
      noofraces=t.no;
      for(int cat=0;cat<50;cat++)
      track[cat]=t.fastrack[cat];
       county=1;
      anime("Loading Tournament","Loaded!");
      multiplayer();

      }




     if(x==4&&ch==enter)
     {


      ifstream tin("toursave.lap",ios::in|ios::binary);
      ofstream tout("TEMP.lap",ios::out|ios::binary);
      if(!tin)
      error("Cannot open file.");
      if(!tout)
      error("Cannot create file.");

      tout.seekp(0);

      tin.seekg(0);
      while(tin.read((char*)&t,sizeof(tournament)))
      {
	if(strcmp(t.name,currtour))
	tout.write((char*)&t,sizeof(tournament));
	}
       tout.close();
       tin.close();
       remove("toursave.lap");
       rename("temp.lap","toursave.lap");

	   l=0;
	   currbar=0;
       while(ch!='›')
    {clrscr();
     l++;
     textcolor(7);
     new1();
     printinmiddle("LOAD TOURNAMENT",7,RED);
     cout<<endl;
     floatcurrbar=currbar;
     currbarfrac=floatcurrbar/80;
     currbarperc=currbarfrac*100;
     textcolor(CYAN);
     cprintf("Deleting Tournament (");
     textcolor(GREEN);
     cprintf("%d%",currbarperc);
     textcolor(CYAN);
     cprintf(") ...");
     cout<<endl<<endl;
     int unitsize= rand()%5;
     currbar=unitsize+currbar;
     for(int r=0;r<currbar;r++)
      {textcolor(GREEN);
       cprintf("€");
      }
     for(int s=0;s<80-currbar;s++)
      {textcolor(RED);
       cprintf("€");
      }
     cout<<endl;

     line(RED,80);
     if(currbar>80)
      {clrscr();
       new1();
       printinmiddle("LOAD TOURNAMENT",7,RED);
       textcolor(GREEN);
       cout<<endl;
       cprintf("Deleted!");cout<<endl;
       line(RED,80);
       sleep(1);
       choosemode();
      }
     delay(30);
     if(l==1)
      sleep(1);
    }

      }

     if(x==5&&ch==enter)
     choosemode();

     if(ch==esc)
     mainmenu();
     ch='b';
     }
  }

//-------------------------------------------------------------------------
//SAVE TOURNAMENT TO FILE
//-------------------------------------------------------------------------
 void savetournament()
 { empty=NO;
  struct tournament
  { char name[60];
    int  no;
    int  fastrack[50];
    };

  tournament t,t1;
  strcpy(t.name,nameoftournament);
  t.no=noofraces;
  for(int dog=0;dog<50;dog++)
  t.fastrack[dog]=track[dog];


  fstream tout("toursave.lap",ios::ate|ios::out|ios::binary|ios::in);
  if(!tout)
  error("Cannot open file.");
  tout.seekp(0);
  tout.seekg(0);
  while(tout.read((char*)&t1,sizeof(tournament)))
  {
   if(!strcmp(t1.name,t.name))
   {clrscr();
    empty=YES;
    new1();
    printinmiddle("TOURNAMENT",7,RED);
    int bolo=tout.tellg();
    cout<<endl;

   textcolor(CYAN);
    cprintf("Tournament with this name already exists. Overwriting...");
    sleep(3);


    tout.seekp(bolo-sizeof(tournament));
    tout.write((char*)&t,sizeof(tournament));

   anime("Saving Tournament","Saved!");
   ::tournament();

    }
  tout.close();   }

  if(empty==NO)
  {
  ofstream tout2("toursave.lap",ios::app|ios::binary|ios::out);
  if(!tout2)
  error("Cannot open file.");
  tout2.seekp(0);
  tout2.write((char*)&t,sizeof(tournament));
  tout2.close();

  anime("Saving Tournament","Saved!");
  ::tournament();


  }
      }

//-------------------------------------------------------------------------
//ENTER NUMBER OF PLAYERS
//-------------------------------------------------------------------------
 void enterplayers()
  {x=0;
   char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   while(ch!='›')
    {new1();
     textbackground(RED);
     textcolor(7);
     printinmiddle("PLAYER SETUP",7,RED);
     textbackground(0);
     cout<<endl;
     textcolor(CYAN);
     cprintf("Select the number of players:");
     cout<<endl;

     if(x==0)
      textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf("%d",noofplayers+1);textcolor(RED);cprintf("");
     textbackground(0);
     textcolor(7);
     cout<<endl<<endl;

     if(x==1)
      textbackground(BLUE);
     cprintf("CONTINUE");
     textbackground(0);
     cout<<endl;
     line(RED);

     if(x==2)
      textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);

     ch=getch();
     if(ch==up)
      x--;
     if(ch==down)
      x++;
     if(x<0)
      x=2;
     if(x>2)
      x=0;

     if(x==0)
      {if(ch==next)
	noofplayers++;
       if(ch==previous)
	noofplayers--;
       if(noofplayers<1)
	noofplayers=3;
       if(noofplayers>3)
	noofplayers=1;
      }

     if(x==1&&ch==enter)
     {
       garage();}
     if(x==2&&ch==enter)
      choosemode();
     if(ch==esc)
      mainmenu();
     ch='b';
     }
  }


//-------------------------------------------------------------------------
//GETS THE PLAYER DETAILS
//-------------------------------------------------------------------------
void garage()
{x=0;
y=0;

if(training==YES)
noofplayers=0;

char leftarrow[2]="";
leftarrow[0]=(leftarrow[0]+1);
currchassi=currengine=currweapon=currtyres=1;
currammo=currhealthpack=currnitro=1;
currcar=0;
while(ch!='›')
{clrscr();
 textbackground(RED);
textcolor(7);
printinmiddle("GARAGE - PRESS [S] TO START RACE - [ESC]MAIN MENU",7,RED);



line(RED,35);
if(x==0)
textbackground(BLUE);

textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf("PLAYER %d",currplayer+1);textcolor(RED);cprintf("");
textbackground(0);
line(RED,35);

textbackground(0);
cprintf("     ");

textcolor(7);



if(x==1&&y==0)
textbackground(BLUE);
cprintf("LOAD PLAYER");
textbackground(0);

cprintf("      ");

if(x==1&&y==1)
textbackground(BLUE);
cprintf("SAVE PLAYER");
textbackground(0);

cprintf("                         ");




if(x==1&&y==2)
textbackground(BLUE);
cprintf("BACK");
textbackground(0);

cout<<endl;
line(RED);
cout<<"                          ";
textcolor(CYAN);
if(training==YES)
textcolor(RED);
cprintf("Choose player team: ");

if(x==2)
textbackground(BLUE);
textcolor(RED);cprintf(leftarrow);textcolor(7);
if(training==YES)
textcolor(RED);
cprintf("TEAM %d",p[i].team);textcolor(RED);cprintf("");
textbackground(0);
cout<<endl<<endl;



cprintf("         ");
if(x==3&&y==0)
textbackground(BLUE);
textcolor(7);
cprintf("ENTER PLAYER %d'S NAME",currplayer+1);
textbackground(0);
cprintf("    ");
cprintf("                      ");
if(x==3&&y==1)
textbackground(BLUE);
textcolor(7);

cprintf("SIGN OUT");
textbackground(0);
cout<<endl;
line(RED);

textcolor(CYAN);
cprintf("Name: ");
textcolor(GREEN);
cprintf(p[currplayer].name);



textcolor(CYAN);

cprintf("        Total Level: ");
textcolor(GREEN);
p[currplayer].totallevel();
cprintf("%d",p[currplayer].totlevel);

textcolor(CYAN);


cprintf("        Cash: ");
if(flash==no)
{textcolor(YELLOW);


cprintf("$%.0f",p[currplayer].money); }
else
{if(flash==yes)
textcolor(RED);
cprintf("$%.0f",p[currplayer].money);
}
cout<<endl<<endl;


textcolor(CYAN);
cprintf("Current Vehicle: ");
textcolor(7);

   cprintf("[");
   displaycar(p[i].carno,p[i].chassi);
   textcolor(7);
   cprintf("] ");


textcolor(GREEN);
cprintf(carname[p[i].carno]);
cout<<endl;

cout<<endl;
  textcolor(7);
cprintf("Health-(");
textcolor(GREEN);
cprintf("%d/",p[i].health);
cprintf("%d",p[currplayer].maxhealth);
textcolor(7);
cprintf(")");
textcolor(CYAN);
cprintf(" Chassi(");
textcolor(chassicolor[p[i].chassi]);cprintf("€");
textcolor(CYAN);
cprintf("): ");
textcolor(GREEN);
cprintf(chassiname[p[i].chassi]);

cout<<endl;

bar(p[currplayer].health,p[currplayer].maxhealth,carhealth[currcar]+chassibonus[p[i].chassi]);
cout<<endl;




 textcolor(7);
cprintf("Speed-(");
textcolor(GREEN);
cprintf("%d/",p[i].speed);
cprintf("%d",p[currplayer].maxspeed);
textcolor(7);
cprintf(")");
textcolor(CYAN);
cprintf(" Engine Level: ");
textcolor(GREEN);
cprintf("%d",p[i].engine);

cout<<endl;

bar(p[currplayer].speed,p[currplayer].maxspeed,carspeed[currcar]+enginebonus[p[i].engine]);
cout<<endl;



textcolor(7);
cprintf("Handling-(");
textcolor(GREEN);
cprintf("%d/",p[i].handling);
cprintf("%d",p[currplayer].maxhandling);
textcolor(7);
cprintf(")");
textcolor(CYAN);
cprintf(" Tyres Level: ");
textcolor(GREEN);
cprintf("%d",p[i].tyres);

cout<<endl;
bar(p[currplayer].handling,p[currplayer].maxhandling,carhandling[currcar]+tyresbonus[p[i].tyres]);
cout<<endl;



textcolor(7);
cprintf("Weapon Strength-(");
textcolor(GREEN);
cprintf("%d/",p[i].weaponstrength);
cprintf("%d",carweaponstrength[p[currplayer].carno]);
textcolor(7);
cprintf(") ");
textcolor(CYAN);
cprintf(weaponname[p[currplayer].carno]);
cprintf(" Level: ");
textcolor(GREEN);
cprintf("%d",p[i].weapon);

cout<<endl;

bar(p[currplayer].weaponstrength,p[currplayer].maxweaponstrength,carweaponstrength[currcar]+weaponstrengthbonus[p[i].weapon]);
cout<<endl;

cout<<" " ;
textbackground(RED);
textcolor(7);
cprintf("©");

textbackground(0);
textcolor(7);
cprintf("(");

textcolor(GREEN);
cprintf("%d/9", p[currplayer].ammo);
textcolor(7);
cprintf("),  ");


textcolor(RED);
cprintf("Î");

textbackground(0);
textcolor(7);
cprintf("(");
textcolor(GREEN);
if(p[currplayer].carno==0)
{cprintf("Not Available");
currnitro=1;}
else
cprintf("%d/4", p[currplayer].nitro);
textcolor(7);
cprintf("),  ");



textbackground(7);
textcolor(RED);
cprintf("+");

textbackground(0);
textcolor(7);
cprintf("(");
textcolor(GREEN);
cprintf("%d/6",p[currplayer].healthpack);
textcolor(7);
cprintf(")");
cout<<endl;


line(RED);

if(x==4&&y==0)
textbackground(BLUE);
cout<<"         ";
cprintf("BUY CAR AND UPGRADES");
textbackground(0);
cout<<"                         ";
if(x==4&&y==1)
textbackground(BLUE);
cprintf("BUY ACCESORIES");
textbackground(0);
cout<<endl;


line(RED);

textbackground(0);



if(flash==yes)
{delay(500);
flash=no;
ch='c';
continue;}

if(flash2==yes)
{delay(500);
flash2=no;
ch='c';
continue;}

ch=getch();


if(x==3&&training==YES&&ch==up)
x=1;
else if(ch==up)
x--;
if(x==1&&training==YES&&ch==down)
x=3;
else if(ch==down)
x++;
if(x<0)
x=4;
if(x>4)
x=0;



if(x==0&&ch==next)
currplayer++;
if(x==0&&ch==previous)
currplayer--;
if(currplayer<0)
currplayer=noofplayers;
if(currplayer>noofplayers)
currplayer=0;

if((x==1)&&ch==next)
y++;
if((x==1)&&ch==previous)
y--;

if((x==4)&&ch==next)
y++;
if((x==4)&&ch==previous)
y--;


if(x==1&&y<0)
y=2;
if(x==1&&y>2)
y=0;

if(x==4&&y<0)
y=1;
if(x==4&&y>1)
y=0;

if(x==4&&y==0&&ch==enter)
buyupgrade();
if(x==4&&y==1&&ch==enter)
buyammo();

if(x==1&&y==0&&ch==enter)
loadplayer1();
if(x==1&&y==1&&ch==enter)
saveplayer();

if(x==1&&y==2&&ch==enter&&training==YES)
choosetype();
else if(x==1&&y==2&&ch==enter)
enterplayers();




if(x==2&&ch==next)
p[currplayer].team++;
if(x==2&&ch==previous)
p[currplayer].team--;

if(x==2&&p[currplayer].team<1)
p[currplayer].team=4;
if(x==2&&p[currplayer].team>4)
p[currplayer].team=1;


if(x==3&&ch==next)
y++;
if(x==3&&ch==previous)
y--;
if(x==3&&y<0)
y=1;
if(x==3&&y>1)
y=0;
if(x==3&&y==0&&ch==enter)
entername();
if(x==3&&y==1&&ch==enter)
warning();


  if(ch=='s'||ch=='S')
  game();

  if(ch==esc)
  mainmenu();
  ch='b';

       } }


//-------------------------------------------------------------------------
//BUY UPGRADES AND VEHICLE
//-------------------------------------------------------------------------
 void buyupgrade()
  { x=0;
y=0;
char leftarrow[2]="";
leftarrow[0]=(leftarrow[0]+1);
if(p[i].chassi!=0)
currchassi=p[i].chassi;
if(p[i].engine!=0)
currengine=p[i].engine;
if(p[i].weapon!=0)
currweapon=p[i].weapon;
if(p[i].tyres!=0)
currtyres=p[i].tyres;
currcar=p[i].carno;

   while(ch!='›')
    {clrscr();
     textbackground(RED);
     textcolor(7);
     printinmiddle("GARAGE - UPGRADES - [ESC]MAIN MENU",7,RED);
     textbackground(0);
     textcolor(CYAN);


     textcolor(CYAN);
     cprintf("Name: ");
     textcolor(GREEN);
     cprintf(p[i].name);
     textcolor(CYAN);

cprintf("        Total Level: ");
textcolor(GREEN);
p[currplayer].totallevel();
cprintf("%d",p[currplayer].totlevel);

textcolor(CYAN);


cprintf("        Cash: ");
if(flash==no)
{textcolor(YELLOW);


cprintf("$%.0f",p[currplayer].money); }
else
{if(flash==yes)
textcolor(RED);
cprintf("$%.0f",p[currplayer].money);
}
cout<<endl;



line(RED);


   textcolor(CYAN);
   cprintf("Select Vehicle: ");
   textcolor(7);

   cprintf("[");
   displaycar(p[i].carno,p[i].chassi);
   textcolor(7);
   cprintf("] ");
   textcolor(GREEN);
   cprintf(carname[p[i].carno]);
   cprintf(" ");

   if(x==0)
    textbackground(BLUE);
   if(p[currplayer].carno==currcar)
    col=GREEN;
   else
    col=7;
   textcolor(RED);
   cprintf(leftarrow);
   textcolor(7);
   cprintf("[");
   displaycar(currcar,0);
   textcolor(7);
   cprintf("] ");
   textcolor(col);
   cprintf(carname[currcar]);textcolor(RED);cprintf("");
   textbackground(0);
   textcolor(CYAN);
   textcolor(7);

   cout<<endl;
   line(RED);

   textcolor(7);
   cprintf("Health-(");
   textcolor(GREEN);
   cprintf("%d/",p[i].health);
   cprintf("%d",p[currplayer].maxhealth);
   textcolor(7);
   cprintf(")");
   textcolor(CYAN);
   cprintf(" Chassi(");
   textcolor(chassicolor[currchassi]);cprintf("€");
   textcolor(CYAN);
   cprintf("): ");

   if(x==1)
    textbackground(BLUE);
   if(p[currplayer].chassi==currchassi)
    col=GREEN;
   else
    col=7;
   textcolor(RED);cprintf(leftarrow);textcolor(col);cprintf(chassiname[currchassi]);textcolor(RED);cprintf("");
   textbackground(0);
   textcolor(CYAN);
   cprintf(" Health Bonus:");
   textcolor(GREEN);
   cprintf("+%d",chassibonus[currchassi]);
   textcolor(7);
   cout<<endl;
   bar(p[currplayer].health,p[currplayer].maxhealth,carhealth[currcar]+chassibonus[p[i].chassi]);
   cout<<endl<<endl;
   textcolor(7);
   cprintf("Speed-(");
   textcolor(GREEN);
   cprintf("%d/",p[i].speed);
   cprintf("%d",p[currplayer].maxspeed);
   textcolor(7);
   cprintf(")");
   textcolor(CYAN);
   cprintf(" Engine: ");

   if(x==2)
    textbackground(BLUE);
   if(p[currplayer].engine==currengine)
    col=GREEN;
   if(p[i].engine>currengine)
    col=RED;
   if(p[i].engine<currengine)
    col=7;
   textcolor(RED);cprintf(leftarrow);textcolor(col);cprintf("Engine Level %d",currengine);textcolor(RED);cprintf("");

   textbackground(0);
   textcolor(CYAN);
   cprintf(" Speed Bonus:");
   textcolor(GREEN);
   cprintf("+%d",enginebonus[currengine]);
    cout<<endl;
   bar(p[currplayer].speed,p[currplayer].maxspeed,carspeed[currcar]+enginebonus[p[i].engine]);
   cout<<endl<<endl;
   textcolor(7);
   cprintf("Handling-(");
   textcolor(GREEN);
   cprintf("%d/",p[i].handling);
   cprintf("%d",p[currplayer].maxhandling);
   textcolor(7);
   cprintf(")");
   textcolor(CYAN);
   cprintf(" Tyres: ");

   if(x==3)
    textbackground(BLUE);
   if(p[currplayer].tyres==currtyres)
    col=GREEN;
   if(p[i].tyres>currtyres)
    col=RED;
   if(p[i].tyres<currtyres)
    col=7;
   textcolor(RED);cprintf(leftarrow);textcolor(col);cprintf("Tyres Level %d",currtyres);textcolor(RED);cprintf("");

   textbackground(0);
   textcolor(CYAN);
   cprintf(" Handling Bonus:");
   textcolor(GREEN);
   cprintf("+%d",tyresbonus[currtyres]);
   cout<<endl;
   bar(p[currplayer].handling,p[currplayer].maxhandling,carhandling[currcar]+tyresbonus[p[i].tyres]);
   cout<<endl<<endl;
   textcolor(7);
   cprintf("Weapon Strength-(");
   textcolor(GREEN);
   cprintf("%d/",p[i].weaponstrength);
   cprintf("%d",carweaponstrength[p[currplayer].carno]);
   textcolor(7);
   cprintf(") ");
   textcolor(CYAN);
   cprintf(weaponname[p[currplayer].carno]);
   cprintf(": ");

   if(x==4)
    textbackground(BLUE);
   if(p[currplayer].weapon==currweapon)
    col=GREEN;
   if(p[i].weapon>currweapon)
    col=RED;
   if(p[i].weapon<currweapon)
    col=7;
   textcolor(RED);cprintf(leftarrow);textcolor(col);cprintf("Weapon Level %d",currweapon);textcolor(RED);cprintf("");

   textbackground(0);
   textcolor(CYAN);
   cprintf(" WS Bonus:");
   textcolor(GREEN);
   cprintf("+%d",weaponstrengthbonus[currweapon]);
   cout<<endl;
   bar(p[currplayer].weaponstrength,p[currplayer].maxweaponstrength,carweaponstrength[currcar]+weaponstrengthbonus[p[i].weapon]);
   cout<<endl<<endl;


   textcolor(CYAN);
if(x==0||x==1||x==2||x==3||x==4)
{ textcolor(CYAN);
cprintf("[ENTER] Buy for ");
		  }
else
{cout<<" ";}

if(x==0)
{textcolor(YELLOW);
cprintf("$%.0f",carcost[currcar]);
textcolor(CYAN);
cprintf(", ");

 if(flash2==yes)
    textcolor(RED);
   if(flash2==no)
    textcolor(CYAN);
   cprintf("[SPACE] Sell for ");
   if(flash2==yes)
    textcolor(RED);
   if(flash2==no)
    textcolor(YELLOW);

   cprintf("$%.0f",(carcost[p[i].carno])/2);

   if(flash2==yes)
    textcolor(RED);
   if(flash2==no)
    textcolor(7);
}


if(x==1)
{
   textcolor(YELLOW);
   cprintf("$%.0f",chassicost[currchassi]);

   }

if(x==2)
{
   textcolor(YELLOW);
   cprintf("$%.0f",enginecost[currengine]);
   }

if(x==3)
{
   textcolor(YELLOW);
   cprintf("$%.0f",tyrescost[currtyres]);

   }

if(x==4)
{
   textcolor(YELLOW);
   cprintf("$%.0f",weaponcost[currweapon]);
   }


   cout<<endl;

   line(RED);

textbackground(0);
cprintf("       ");

if(x==5&&y==0)
textbackground(BLUE);
textcolor(7);
cprintf("REPAIR CHASSI(");
textcolor(YELLOW);
cprintf("$");
p[currplayer].getchassirepaircost();
cprintf("%d",p[currplayer].chassirepaircost);

textcolor(7);
cprintf(")");

textbackground(0);
cprintf("                    ");
if(x==5&&y==1)
textbackground(BLUE);
textcolor(7);
cprintf("REPAIR ENGINE(");
textcolor(YELLOW);
cprintf("$");
p[currplayer].getenginerepaircost();
cprintf("%d",p[currplayer].enginerepaircost);

textcolor(7);
cprintf(")");



cout<<endl;

textbackground(0);
cout<<endl;
cprintf("       ");

if(x==6&&y==0)
textbackground(BLUE);
textcolor(7);
cprintf("REPAIR TYRES(");
textcolor(YELLOW);
cprintf("$");
p[currplayer].gettyresrepaircost();
cprintf("%d",p[currplayer].tyresrepaircost);

textcolor(7);
cprintf(")");
textbackground(0);
cprintf("                     ");

if(x==6&&y==1)
textbackground(BLUE);
textcolor(7);
cprintf("REPAIR WEAPON(");
textcolor(YELLOW);
cprintf("$");
p[currplayer].getweaponrepaircost();
cprintf("%d",p[currplayer].weaponrepaircost);

textcolor(7);
cprintf(")");
textbackground(0);
cout<<endl;
line(RED);
if(x==7)
textbackground(BLUE);
textcolor(7);
cprintf("BACK");
textbackground(0);



if(x==5&&ch==next)
currcar++;
if(x==5&&ch==previous)
currcar--;

if(x==5&&currcar<0)
currcar=19;
if(x==5&&currcar>19)
currcar=0;



if(x==5&&ch==enter)
{if(p[currplayer].money>=carcost[currcar])
 {
  if(sold==yes||(p[i].carno==0))

 {p[currplayer].money-=carcost[currcar];
 p[currplayer].carno=currcar;
 p[currplayer].ihealth=carhealth[p[currplayer].carno];
 p[currplayer].ispeed=carspeed[p[currplayer].carno];
 p[currplayer].ihandling=carhandling[p[currplayer].carno];
 p[currplayer].iweaponstrength=carweaponstrength[p[currplayer].carno];

 p[i].health=p[i].maxhealth=p[i].bonushealth+p[i].ihealth;
 p[i].speed=p[i].maxspeed=p[i].bonusspeed+p[i].ispeed;
 p[i].handling=p[i].maxhandling=p[i].bonushandling+p[i].ihandling;
 p[i].weaponstrength=p[i].maxweaponstrength=p[i].bonusweaponstrength+p[i].iweaponstrength;



 sold=no;
 flash=no;}
 if(sold==no&&(p[i].carno!=currcar))
 flash2=yes;}
 else

 flash=yes; }



if(x==5&&ch==space)
{sold=yes;
p[currplayer].money+=(carcost[p[currplayer].carno])/2;
p[currplayer].carno=0;
 p[currplayer].ihealth=carhealth[p[currplayer].carno];
 p[currplayer].ispeed=carspeed[p[currplayer].carno];
 p[currplayer].ihandling=carhandling[p[currplayer].carno];
 p[currplayer].iweaponstrength=carweaponstrength[p[currplayer].carno];

 p[i].health=p[i].maxhealth=p[i].bonushealth+p[i].ihealth;
 p[i].speed=p[i].maxspeed=p[i].bonusspeed+p[i].ispeed;
 p[i].handling=p[i].maxhandling=p[i].bonushandling+p[i].ihandling;
 p[i].weaponstrength=p[i].maxweaponstrength=p[i].bonusweaponstrength+p[i].iweaponstrength;

}


if(flash==yes)
{delay(500);
flash=no;
ch='c';
continue;}

if(flash2==yes)
{delay(500);
flash2=no;
ch='c';
continue;}

ch=getch();
if(ch==up)
x--;
if(ch==down)
x++;
if(x<0)
x=7;
if(x>7)
x=0;
if((x==5||x==6)&&ch==next)
y++;
if((x==5||x==6)&&ch==previous)
y--;




if(x==0&&ch==next)
currcar++;
if(x==0&&ch==previous)
currcar--;

if(x==0&&currcar<0)
currcar=19;
if(x==0&&currcar>19)
currcar=0;

if(x==0&&ch==enter)
{if(p[currplayer].money>=carcost[currcar])
 {
  if(sold==yes||(p[i].carno==0))

 {p[currplayer].money-=carcost[currcar];
 p[currplayer].carno=currcar;
 p[currplayer].ihealth=carhealth[p[currplayer].carno];
 p[currplayer].ispeed=carspeed[p[currplayer].carno];
 p[currplayer].ihandling=carhandling[p[currplayer].carno];
 p[currplayer].iweaponstrength=carweaponstrength[p[currplayer].carno];

 p[i].health=p[i].maxhealth=p[i].bonushealth+p[i].ihealth;
 p[i].speed=p[i].maxspeed=p[i].bonusspeed+p[i].ispeed;
 p[i].handling=p[i].maxhandling=p[i].bonushandling+p[i].ihandling;
 p[i].weaponstrength=p[i].maxweaponstrength=p[i].bonusweaponstrength+p[i].iweaponstrength;



 sold=no;
 flash=no;}
 if(sold==no&&(p[i].carno!=currcar))
 flash2=yes;}
 else

 flash=yes; }



if(x==0&&ch==space)
{sold=yes;
p[currplayer].money+=(carcost[p[currplayer].carno])/2;
p[currplayer].carno=0;
 p[currplayer].ihealth=carhealth[p[currplayer].carno];
 p[currplayer].ispeed=carspeed[p[currplayer].carno];
 p[currplayer].ihandling=carhandling[p[currplayer].carno];
 p[currplayer].iweaponstrength=carweaponstrength[p[currplayer].carno];

 p[i].health=p[i].maxhealth=p[i].bonushealth+p[i].ihealth;
 p[i].speed=p[i].maxspeed=p[i].bonusspeed+p[i].ispeed;
 p[i].handling=p[i].maxhandling=p[i].bonushandling+p[i].ihandling;
 p[i].weaponstrength=p[i].maxweaponstrength=p[i].bonusweaponstrength+p[i].iweaponstrength;

}


if(x==1&&ch==next)
currchassi++;
if(x==1&&ch==previous)
currchassi--;
if(x==1&&currchassi<1)
currchassi=7;
if(x==1&&currchassi>7)
currchassi=1;
if(x==1&&ch==enter)
{if(p[i].chassi!=currchassi)
{if((p[currplayer].money>=chassicost[currchassi]))
 {p[currplayer].money-=chassicost[currchassi];
 p[currplayer].chassi=currchassi;
 p[currplayer].bonushealth=chassibonus[p[currplayer].chassi];
 p[currplayer].maxhealth=p[currplayer].bonushealth+p[currplayer].ihealth;
 p[currplayer].health=p[currplayer].maxhealth;
 flash=no;}
 else
 flash=yes; } }

if(x==2&&ch==next)
currengine++;
if(x==2&&ch==previous)
currengine--;
if(x==2&&currengine<1)
currengine=7;
if(x==2&&currengine>7)
currengine=1;
if((x==2&&ch==enter)&&(currengine>p[currplayer].engine))
{if(p[currplayer].money>=enginecost[currengine])
 {p[currplayer].money-=enginecost[currengine];
 p[currplayer].engine=currengine;
 p[currplayer].bonusspeed=enginebonus[p[currplayer].engine];
 p[currplayer].maxspeed=p[currplayer].bonusspeed+p[currplayer].ispeed;
 p[currplayer].speed=p[currplayer].maxspeed;
 flash=no;}
 else
 flash=yes; }

if(x==3&&ch==next)
currtyres++;
if(x==3&&ch==previous)
currtyres--;

if(x==3&&currtyres<1)
currtyres=7;
if(x==3&&currtyres>7)
currtyres=1;
if(x==3&&ch==enter&&(currtyres>p[currplayer].tyres))
{if((p[currplayer].money>=tyrescost[currtyres]))
 {p[currplayer].money-=tyrescost[currtyres];
 p[currplayer].tyres=currtyres;
 p[currplayer].bonushandling=tyresbonus[p[currplayer].tyres];
 p[currplayer].maxhandling=p[currplayer].bonushandling+p[currplayer].ihandling;
 p[currplayer].handling=p[currplayer].maxhandling;
 flash=no;}
 else
 flash=yes;}

 if(x==4&&ch==next)
currweapon++;
if(x==4&&ch==previous)
currweapon--;

 if(x==4&&currweapon<1)
currweapon=7;
if(x==4&&currweapon>7)
currweapon=1;
if((x==4&&ch==enter)&&(currweapon>p[currplayer].weapon))
{if(p[currplayer].money>=weaponcost[currweapon])
 {p[currplayer].money-=weaponcost[currweapon];
 p[currplayer].weapon=currweapon;
 p[currplayer].bonusweaponstrength=weaponstrengthbonus[p[currplayer].weapon];

 p[currplayer].maxweaponstrength=p[currplayer].bonusweaponstrength+p[currplayer].iweaponstrength;
 p[currplayer].weaponstrength=p[currplayer].maxweaponstrength;
 flash=no;}
 else
 flash=yes;}

if(x==5&&y>1)
y=0;
if(x==5&&y<0)
y=1;
 if(x==5&&y==0&&ch==enter)
{
 if(p[currplayer].money>=p[currplayer].chassirepaircost)
 {p[currplayer].money-=p[currplayer].chassirepaircost;
  p[currplayer].health=p[currplayer].maxhealth;
  flash=no;}
  else
  flash=yes;}

  if(x==5&&y==1&&ch==enter)
{
 if(p[currplayer].money>=p[currplayer].enginerepaircost)
 {p[currplayer].money-=p[currplayer].enginerepaircost;
  p[currplayer].speed=p[currplayer].maxspeed;
  flash=no;}
  else
  flash=yes;}

if(x==6&&y>1)
y=0;
if(x==6&&y<0)
y=1;

 if(x==6&&y==0&&ch==enter)
{
 if(p[currplayer].money>=p[currplayer].tyresrepaircost)
 {p[currplayer].money-=p[currplayer].tyresrepaircost;
  p[currplayer].handling=p[currplayer].maxhandling;
  flash=no;}
  else
  flash=yes;}


   if(x==6&&y==1&&ch==enter)
{
 if(p[currplayer].money>=p[currplayer].weaponrepaircost)
 {p[currplayer].money-=p[currplayer].weaponrepaircost;
  p[currplayer].weaponstrength=p[currplayer].maxweaponstrength;
  flash=no;}
  else
  flash=yes;}

 if(x==7&&ch==enter)
 garage();
  if(ch==esc)
  mainmenu();
  ch='b';
       }}


//-------------------------------------------------------------------------
//BUY ACCESSORIES
//-------------------------------------------------------------------------
void buyammo()
{ x=0;
y=0;
char leftarrow[2]="";
leftarrow[0]=(leftarrow[0]+1);


while(ch!='›')
{clrscr();
 textbackground(RED);
textcolor(7);
printinmiddle("GARAGE - ACCESORIES - [ESC]MAIN MENU",7,RED);
  cout<<endl;
  textcolor(CYAN);
cprintf("Name: ");
textcolor(GREEN);
cprintf(p[currplayer].name);



textcolor(CYAN);

cprintf("        Total Level: ");
textcolor(GREEN);
p[currplayer].totallevel();
cprintf("%d",p[currplayer].totlevel);

textcolor(CYAN);


cprintf("        Cash: ");
if(flash==no)
{textcolor(YELLOW);


cprintf("$%.0f",p[currplayer].money); }
else
{if(flash==yes)
textcolor(RED);
cprintf("$%.0f",p[currplayer].money);
}
cout<<endl;
line(RED);

textcolor(CYAN);
cprintf("[");
textbackground(RED);
textcolor(7);
cprintf("©");
textcolor(CYAN);
textbackground(0);
cprintf("]");

cprintf(" Ammunition: ");
textcolor(GREEN);

cprintf("%d/9        ", p[currplayer].ammo);


if(x==0)
textbackground(BLUE);
textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf("%d",currammo);textcolor(RED);cprintf("");
textbackground(0);

textcolor(7);
cprintf("   [ENTER]Buy(");
textcolor(YELLOW);
cprintf("$%0.f",(float)(p[currplayer].weaponstrength)*5*currammo);
textcolor(7);
cprintf(")");
cout<<endl<<endl;


textcolor(CYAN);
cprintf("[");

textcolor(RED);
cprintf("Î");
textcolor(CYAN);
textbackground(0);
cprintf("]");


cprintf(" Nitro: ");
textcolor(GREEN);
if(p[currplayer].carno==0)
{cprintf("Not Available   ");
currnitro=1;}
else
cprintf("     %d/4        ", p[currplayer].nitro);
if(x==1)
textbackground(BLUE);
if(p[currplayer].carno==0)
{textcolor(RED);cprintf(leftarrow);textcolor(RED);cprintf("%d",currnitro);textcolor(RED);cprintf("");}
else
{textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf("%d",currnitro);textcolor(RED);cprintf("");}
textbackground(0);
textcolor(7);
cprintf("   [ENTER]Buy(");
textcolor(YELLOW);
cprintf("$%d",(p[currplayer].speed)*5*currnitro);
textcolor(7);
cprintf(")");
cout<<endl<<endl;
textcolor(CYAN);
cprintf("[");
textbackground(7);
textcolor(RED);
cprintf("+");
textcolor(CYAN);
textbackground(0);
cprintf("]");
cprintf(" Healthpack: ");
textcolor(GREEN);
cprintf("%d/6        ",p[currplayer].healthpack);

if(x==2)
textbackground(BLUE);
textcolor(RED);cprintf(leftarrow);textcolor(7);cprintf("%d",currhealthpack);textcolor(RED);cprintf("");
textbackground(0);
textcolor(7);
cprintf("   [ENTER]Buy(");
textcolor(YELLOW);
cprintf("$%d",(healthpackcost*currhealthpack));
textcolor(7);
cprintf(")");
cout<<endl;
line(RED);

if(x==3)
textbackground(BLUE);
textcolor(7);
cprintf("BACK");
textbackground(0);

ch=getch();
if(ch==up)
x--;
if(ch==down)
x++;
if(x<0)
x=3;
if(x>3)
x=0;

if(x==0&&ch==next)
currammo++;
if(x==0&&ch==previous)
currammo--;
if(x==0&&currammo<1)
currammo=9;
if(x==0&&currammo>9)
currammo=1;
if(x==0&&ch==enter)
{if(p[currplayer].money>=(((p[currplayer].weaponstrength)*5)*currammo))
 {p[currplayer].ammo+=currammo;
 if(p[i].ammo<=10)
 p[currplayer].money-=(((p[currplayer].weaponstrength)*5)*currammo);
 else
 p[i].ammo=9;
 flash=no;}
 else
 flash=yes;    }

if(x==1&&ch==next)
currnitro++;
if(x==1&&ch==previous)
currnitro--;
if(x==1&&currnitro<1)
currnitro=4;
if(x==1&&currnitro>4)
currnitro=1;
if(x==1&&ch==enter)
{ if(p[currplayer].money>=((p[currplayer].speed)*5*currnitro))
  {p[currplayer].nitro+=currnitro;
  if(p[i].nitro<=4)
  p[currplayer].money-=((p[currplayer].speed)*5*currnitro);
  else
  p[i].nitro=4;

   flash=no;}
   else
   flash=yes;}


if(x==2&&ch==next)
currhealthpack++;
if(x==2&&ch==previous)
currhealthpack--;
if(x==2&&currhealthpack<1)
currhealthpack=6;
if(x==2&&currhealthpack>6)
currhealthpack=1;
if(x==2&&ch==enter)
{ if(p[currplayer].money>=(healthpackcost*currhealthpack))
  { p[currplayer].healthpack+=currhealthpack;
  if(p[currplayer].healthpack<=6)
 p[currplayer].money-=(healthpackcost*currhealthpack);
 else
 p[i].healthpack=6;

   flash=no;}
  else
   flash=yes;}

if(x==3&&ch==enter)
garage();

if(ch==esc)
  mainmenu();
  ch='b'; }   }

//-------------------------------------------------------------------------
//ENTER THE PLAYER NAME
//-------------------------------------------------------------------------
 void entername()
  {clrscr();
   printinmiddle("GARAGE - PRESS [ENTER] TO SET THE ENTERED NAME - [ESC]MAIN MENU",7,RED);
   textcolor(CYAN);
   cout<<endl;
   if(p[i].exists==NO)
    {
     cprintf("Enter player %d's name: ",i+1);
     textcolor(7);
     cout<<endl;
     getstring(p[i].name,10);
     garage();
    }
   if(p[i].exists==YES)
    {
     textcolor(CYAN);
     cprintf("Name: ");
     textcolor(GREEN);
     cprintf(p[i].name);
     cout<<endl<<endl;
     textcolor(CYAN);

       cprintf("A player with this name already exists.");cout<<endl<<endl;
     cprintf("You need to enter your password before you can change your name:");
     cout<<endl;
     getstringpass(passo,10);
     cout<<endl;
     //reading password from file
     fstream inoutplayer;
     inoutplayer.open("save.lap",ios::out|ios::binary|ios::in);
     if(!inoutplayer)
      error("Cannot open file.");
      inoutplayer.seekp(0);
      inoutplayer.seekg(0);
     while(inoutplayer.read((char*)&p1,sizeof(player)))
     { encrypt(p[i].name);
     if(!strcmp(p1.name,p[i].name))
      {  decrypt(p1.password);
	decrypt(p1.name);
	spadd=inoutplayer.tellg();
	spadd-=sizeof(player);
	break;
      }
	    }

     if(!strcmp(p1.password,passo))
      {
       textcolor(CYAN);
       cout<<endl;
       cprintf("Enter your new name:");
       cout<<endl;
       getstring(p[i].name,10);
       inoutplayer.seekp(spadd+14);
       encrypt(p[i].name);
       inoutplayer.write((char*)&p[i].name,sizeof(p[i].name));
       decrypt(p[i].name);
       textcolor(GREEN);
       cout<<endl<<endl;
       cprintf("New name set!");
       sleep(1);
       inoutplayer.close();
       garage();
      }
     else
      {textcolor(RED);
       cprintf("Incorrect match!");
       cout<<endl;
       cprintf("Enter again!");
       sleep(1);
       garage();
      }
    }
  }


//-------------------------------------------------------------------------
//SIGN OUT CONFIRMATION
//-------------------------------------------------------------------------
 void warning()
  {x=0;
   y=0;
   char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   while(ch!='›')
    {clrscr();
     textbackground(RED);
     textcolor(7);
     printinmiddle("GARAGE - SIGN OUT",7,RED);
     textcolor(CYAN);
     cprintf("\nAre you sure you want to sign out?");
     cout<<endl;
     cprintf(p[i].name);
     cprintf(" will lose any unsaved progress on doing so.");
     textcolor(7);

     if(x==0)
      textbackground(BLUE);
     cout<<endl<<endl;
     cprintf("YES");
     textbackground(0);
     if(x==1)
      textbackground(BLUE);
     cout<<endl;
     cprintf("NO");
     textbackground(0);
     cout<<endl;
     line(RED,80);

     ch=getch();
     if(ch==up)
      x++;
     if(ch==down)
      x--;

     if(x<0)
      x=1;
     if(x>1)
      x=0;

     if(x==0&&ch==enter)
      {strcpy(p[i].name,defname);
      p[i].defaultify();
       garage();}
     if(x==1&&ch==enter)
      {garage();}
     if(ch==esc)
      mainmenu();
     ch='b';
    }
  }

//-------------------------------------------------------------------------
//DELETE WARNING
//-------------------------------------------------------------------------
 void deletewarning()
  {x=0;
   y=0;
   char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   while(ch!='›')
    {clrscr();
     textbackground(RED);
     textcolor(7);
     printinmiddle("GARAGE - WARNING!",7,RED);
     textcolor(CYAN);
     cprintf("\nAre you sure you want to delete your player?");
     cout<<endl;
     decrypt(currname);
     cprintf(currname);
     encrypt(currname);
     cprintf(", you will lose all your progress on deleting.");
     textcolor(7);

     if(x==0)
      textbackground(BLUE);
     cout<<endl<<endl;
     cprintf("YES, DELETE ME!");
     textbackground(0);
     if(x==1)
      textbackground(BLUE);
     cout<<endl;
     cprintf("NO, DO NOT DELETE ME");
     textbackground(0);
     cout<<endl;
     line(RED,80);

     ch=getch();
     if(ch==up)
      x++;
     if(ch==down)
      x--;
     if(x<0)
      x=1;
     if(x>1)
      x=0;

     if(x==0&&ch==enter)
      deleteplayer();
     if(x==1&&ch==enter)
      loadplayer();
     if(ch==esc)
      mainmenu();
     ch='b';
    }
  }

//-------------------------------------------------------------------------
//DELETE PLAYER
//-------------------------------------------------------------------------

 void deleteplayer()
  {x=0;

   while(ch!='›')
    {clrscr();
     printinmiddle("GARAGE - DELETE PLAYER - [ESC]MAIN MENU",7,RED);
     textcolor(CYAN);
     cout<<endl;
     cprintf("Welcome ");
     decrypt(currname);
     cprintf(currname);
     encrypt(currname);
     cprintf(".");
     cout<<endl<<endl;
     cprintf("Please enter your password (case-sensitive): ");
     cout<<endl;
     getstringpass(passo,10);
     decrypt(p1.password);
     if(!strcmp(passo,p1.password))
      {textcolor(GREEN);
       cout<<endl<<endl;
       cprintf("Correct Match!");
       sleep(2);
       deletingplayer();}
     else
      {textcolor(RED);
       cout<<endl<<endl;
       cprintf("Incorrect Match!");
       cout<<endl;
       cprintf("Enter password again.");
       sleep(2);
       ch='b';
       loadplayer();
      }
    }
  }


//-------------------------------------------------------------------------
//DELETE PLAYER ANIMATION AND DELETION FROM FILE
//-------------------------------------------------------------------------
 void deletingplayer()
  {x=0;
   l=0;




    ifstream tin("save.lap",ios::in|ios::binary);
      ofstream tout("TEMP.lap",ios::out|ios::binary);
      if(!tin)
      error("Cannot open file.");
      if(!tout)
      error("Cannot create file.");

      tout.seekp(0);

      tin.seekg(0);
      while(tin.read((char*)&p1,sizeof(player)))
      {
	if(strcmp(p1.name,currname))
	tout.write((char*)&p1,sizeof(player));
	}
       tout.close();
       tin.close();
       remove("save.lap");
       rename("temp.lap","save.lap");

   randomize();
   currbar=0;
   l=0;
   while(ch!='›')
    {clrscr();l++;
     textbackground(RED);
     textcolor(7);
     printinmiddle("GARAGE - DELETE PLAYER - [ESC]MAIN MENU",7,RED);
     cout<<endl;
     floatcurrbar=currbar;
     currbarfrac=floatcurrbar/80;
     currbarperc=currbarfrac*100;
     textcolor(CYAN);
     cprintf("Deleting Player (");
     textcolor(GREEN);
     cprintf("%d%",currbarperc);
     textcolor(CYAN);
     cprintf(") ...");
     cout<<endl<<endl;
     int unitsize= rand()%5;
     currbar=unitsize+currbar;
     for(int r=0;r<currbar;r++)
      {textcolor(GREEN);
       cprintf("€");
      }
     for(int s=0;s<80-currbar;s++)
      {textcolor(RED);
       cprintf("€");
      }
     cout<<endl;
     line(RED,80);
     if(currbar>80)
      {clrscr();
       printinmiddle("GARAGE - DELETE PLAYER - [ESC]MAIN MENU",7,RED);
       textcolor(GREEN);
       cout<<endl;
       cprintf("You've been FLUSH'd! Don't show your face again, coward!");cout<<endl;
       line(RED,80);
       sleep(3);
       garage();
      }
     delay(30);
     if(l==1)
      sleep(1);
    }
  }

//-------------------------------------------------------------------------
//LOAD PLAYER
//-------------------------------------------------------------------------
  void loadplayer1()
 {


  ofstream touts("save.lap",ios::app|ios::out);
  if(!touts)
  error("Cannot create file.");
  touts.close();

  ifstream tin("save.lap",ios::in|ios::binary);

  if(!tin)
  error("Cannot open file.");
  tin.seekg(0);



   x=0;

    tin.read((char*)&p1,sizeof(player));
	strcpy(currname,p1.name);

	if(tin.eof()==1)
    {clrscr();

     printinmiddle("GARAGE - LOAD PLAYER - [ESC]MAIN MENU",7,RED);
     cout<<endl;
     textcolor(CYAN);
     cprintf("There are no players currently saved.");
     sleep(2);
     garage();

    }
    else
    { tin.seekg(0);
    while(tomatoes!='c')
  {
  tin.read((char*)&p1,sizeof(player));
   if(tin.eof()==1)
   {filend1=tin.tellg();
    tin.seekg(0);
    break;}
   }  tin.close();
    loadplayer();}}

 void loadplayer()
 {

  ifstream tin("save.lap",ios::in|ios::binary);

  if(!tin)
  error("Cannot open file.");
  tin.seekg(0);

  char leftarrow[2]="";
   leftarrow[0]=(leftarrow[0]+1);

   x=0;

    tin.read((char*)&p1,sizeof(player));
	strcpy(currname,p1.name);
	tin.seekg(0);


  while(ch!='›')
  {
      clrscr();
      textcolor(7);

      printinmiddle("GARAGE - LOAD PLAYER - [ESC]MAIN MENU",7,RED);
      cout<<endl;

	    if(tin.eof()==1)
   {

   tin.close();
   loadplayer();

      }



     textcolor(CYAN);
     cprintf("Choose the saved player you wish to load:");
     cout<<endl<<endl;
      textcolor(7);
     if(x==0)
     textbackground(BLUE);
     textcolor(RED);cprintf(leftarrow);textcolor(7);
     decrypt(p1.name);
     cprintf(p1.name);
     encrypt(p1.name);
     textcolor(RED);cprintf("");
     textcolor(7);
     textbackground(0);
     cout<<endl<<endl;

     if(x==1)
     textbackground(BLUE);
     cprintf("LOAD PLAYER");
     textbackground(0);
     cout<<endl;

     if(x==2)
     textbackground(BLUE);
     cprintf("DELETE PLAYER");
     textbackground(0);
     cout<<endl;

     line(RED);

     if(x==3)
     textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);


     ch=getch();

     if(ch==up)
     x--;
     if(ch==down)
     x++;
     if(x>3)
     x=0;
     if(x<0)
     x=3;


     if(x==0&&ch==next)
      { int nono=tin.tellg();

	tin.read((char*)&p1,sizeof(player));
	if(nono==0)
	tin.read((char*)&p1,sizeof(player));
	strcpy(currname,p1.name);}

    if(x==0&&ch==previous)
     {int bolo=tin.tellg();
      if(bolo<=sizeof(player))
      tin.seekg(filend1+sizeof(player));
      bolo=tin.tellg();
      tin.seekg(bolo-(2*(sizeof(player))));


      tin.read((char*)&p1,sizeof(player));
      strcpy(currname,p1.name);
      }

       if(x==1&&ch==enter)
     {enterpassload();


      }




     if(x==2&&ch==enter)
     {
       deletewarning();
		    }


     if(x==3&&ch==enter)
     garage();

     if(ch==esc)
     mainmenu();
     ch='b';
     }
  }

//-------------------------------------------------------------------------
//ENTER PASSWORD FOR LOADING PLAYER
//-------------------------------------------------------------------------
 void enterpassload()
  {x=0;

   while(ch!='›')
    {clrscr();
     printinmiddle("GARAGE - LOAD PLAYER - [ESC]MAIN MENU",7,RED);
     textcolor(CYAN);
     cout<<endl;
     cprintf("Welcome ");
     decrypt(currname);
     cprintf(currname);
     encrypt(currname);cprintf(".");
     cout<<endl<<endl;
     cprintf("Please enter your password (case-sensitive): ");
     cout<<endl;
     getstringpass(passo,10);
     decrypt(p1.password);
     if(!strcmp(passo,p1.password))
      {textcolor(GREEN);
       cout<<endl<<endl;
       cprintf("Correct Match!");
       sleep(2);
       loadingplayer();
      }
     else
      {textcolor(RED);
       cout<<endl<<endl;
       cprintf("Incorrect Match!");
       cout<<endl;
       cprintf("Enter password again.");
       sleep(2);
       ch='b';
       loadplayer();
      }
    }
  }

//-------------------------------------------------------------------------
//PLAYER LOADING ANIMATION
//-------------------------------------------------------------------------

 void loadingplayer()
  {x=0;currbar=0;l=0;
   decrypt(p1.name);
   p[i]=p1;
   randomize();
anime("Loading Player","Loaded!");
garage();
  }


//-------------------------------------------------------------------------
//SAVE PLAYER TO FILE
//-------------------------------------------------------------------------
 void saveplayer()
  {
   if(!strcmp(p[i].name,defname))
   {clrscr();
    printinmiddle("ERROR",7,RED);
    cout<<endl;
    textcolor(CYAN);
    cprintf("You need to enter your player's name before you can save.");
    cout<<endl<<endl;
    textcolor(RED);
    cprintf("You cannot save with the default name of \"Noname\".");
    cout<<endl<<endl<<endl;
    textcolor(CYAN);
    cprintf("Press any key to go back.");
    getch();
    garage();
    }

   x=0;
   fstream inoutplayer;
   inoutplayer.open("save.lap",ios::app|ios::binary|ios::in);//file created here
   if(!inoutplayer)
    error("Cannot open file.");
   saved=NO;
   inoutplayer.seekg(0);
   inoutplayer.seekp(0);
   while(inoutplayer.read((char*)&p1,sizeof(player)) )
   {decrypt(p1.name);
   if(!strcmp(p1.name,p[i].name))
     {saved=YES;
    spadd=inoutplayer.tellg();
    spadd-=sizeof(player);

    break;}}


   while(ch!='›')
    {clrscr();
     printinmiddle("GARAGE - SAVE PLAYER - [ESC]MAIN MENU",7,RED);
     cout<<endl;
     textcolor(CYAN);
     cprintf("Name: ");
     textcolor(GREEN);
     cprintf(p[i].name);
     cout<<endl<<endl;
     if(saved==YES)
      {textcolor(CYAN);
       cprintf("A player with this name already exists.");cout<<endl<<endl;
       cprintf("Please enter your password for saving and updating your player:");
       cout<<endl<<endl;
       textcolor(7);
     if(x==0)
      textbackground(BLUE);
     cprintf("ENTER PASSWORD");
     textbackground(0);
     cout<<endl;
     if(x==1)
      textbackground(BLUE);
     cprintf("CHANGE MY PASSWORD");
     textbackground(0);
     cout<<endl<<endl;

     line(RED,80);
     textcolor(7);
     if(x==2)
      textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);

     ch=getch();
     if(ch==up)
      x--;
     if(ch==down)
      x++;

     if(x<0)

      x=2;
     if(x>2)
      x=0;

     if(ch==enter&&x==0)
      enterpassword();
     if(ch==enter&&x==1)
      changepassword();
     if(ch==enter&&x==2)
      garage();
     if(ch==esc)
      mainmenu();
     ch='b';
    }
   if(saved==NO)
    {
    textcolor(CYAN);
     cprintf("You need to set a password for your player to be able to save.");
     cout<<endl<<endl;
     textcolor(7);
     if(x==0)
      textbackground(BLUE);
     cprintf("SET PASSWORD");
     textbackground(0);
     cout<<endl;
     line(RED,80);
     if(x==1)
      textbackground(BLUE);
     cprintf("BACK");
     textbackground(0);

     ch=getch();
     if(ch==up)
      x--;
     if(ch==down)
      x++;
     if(x<0)
      x=1;
     if(x>1)
      x=0;

     if(ch==enter&&x==0)
      setpassword();
     if(ch==enter&&x==1)
      garage();
     if(ch==esc)
      mainmenu();
     ch='b';
    }
 }inoutplayer.close();
  }


//-------------------------------------------------------------------------
//SET THE PASSWORD FOR NEW PLAYER
//-------------------------------------------------------------------------
 void setpassword()
  {x=0;
   clrscr();
   printinmiddle("GARAGE - SET PASSWORD - [ESC]MAIN MENU",7,RED);
   cout<<endl;
   textcolor(RED);
   cprintf("Warning! You cannot recover a lost password.");
   cout<<endl<<endl;
   textcolor(CYAN);
   cprintf("Type the password you want to set for your player (max. 10 characters,");
   cout<<endl;
   cprintf("case-sensitive): "); cout<<endl;
   getstringpass(passo,10);
   cout<<endl;
   textcolor(CYAN);
   cprintf("Type the password once again for confirmation: ");
   cout<<endl;
   getstringpass(passo2,10);
   if(!strcmp(passo,passo2))
    {strcpy(p[i].password,passo);

     textcolor(GREEN);
     cout<<endl<<endl;
     cprintf("Password set!");
     sleep(2);
     savingplayer();
    }
   else
    {textcolor(RED);
     cout<<endl;
     cprintf("Passwords do not match! Enter again.");
     sleep(2);
     saveplayer();
    }
  }


//-------------------------------------------------------------------------
//ENTER PASSWORD FOR SAVING PLAYER
//-------------------------------------------------------------------------
 void enterpassword()
  {x=0;

   while(ch!='›')
    {clrscr();
     printinmiddle("GARAGE - SAVE PLAYER - [ESC]MAIN MENU",7,RED);
     textcolor(CYAN);
     cout<<endl;
     cprintf("Welcome ");
     cprintf(p[i].name);cprintf(".");
     cout<<endl<<endl;
     cprintf("Please enter your password (case-sensitive): ");
     cout<<endl;
     getstringpass(passo,10);
     decrypt(p1.password);
     if(!strcmp(passo,p1.password))
      {textcolor(GREEN);
       cout<<endl<<endl;
       cprintf("Correct Match!");
       sleep(2);
       savingplayer();
      }
     else
      {textcolor(RED);
       cout<<endl<<endl;
       cprintf("Incorrect Match!");
       cout<<endl;
       cprintf("Enter password again.");
       sleep(2);
       ch='b';
       saveplayer();
      }
    }
  }


//-------------------------------------------------------------------------
//CHANGE YOUR PASSWORD
//-------------------------------------------------------------------------
 void changepassword()
  {x=0;

   while(ch!='›')
    {clrscr();
     printinmiddle("GARAGE - CHANGE PASSWORD - [ESC]MAIN MENU",7,RED);
     textcolor(CYAN);
     cout<<endl;
     cprintf("Welcome ");
     cprintf(p[i].name);cprintf(".");
     cout<<endl<<endl;
     cprintf("Please enter your old password (case-sensitive): ");
     cout<<endl;
     getstringpass(passo,10);
     decrypt(p1.password);
     if(!strcmp(passo,p1.password))
      {textcolor(GREEN);
       cout<<endl;
       cprintf("Correct Match!");
       cout<<endl<<endl;
       textcolor(CYAN);
       cprintf("Now enter your new password (case-sensitive, max. 10 characters): ");
       cout<<endl;
       getstringpass(passo,10);
       textcolor(CYAN);
       cout<<endl;
       cprintf("Type the new password once again for confirmation: ");
       cout<<endl;
       getstringpass(passo2,10);
       if(!strcmp(passo,passo2))
	{strcpy(p[i].password,passo2);
	 strcpy(p1.password,passo2);
	 cout<<endl;
	 textcolor(GREEN);
	 cprintf("Password set!");
	 sleep(2);
	 savingplayer();
	}
       else
	{textcolor(RED);
	 cout<<endl<<endl;
	 cprintf("Incorrect Match!");
	 cout<<endl;
	 cprintf("Enter password again.");
	 sleep(2);
	 ch='b';
	 saveplayer();
	}
      }
     else
      {textcolor(RED);
       cout<<endl<<endl;
       cprintf("Incorrect Match!");
       cout<<endl;
       cprintf("Enter password again.");
       sleep(2);
       ch='b';
       saveplayer();
      }
    }
  }


//-------------------------------------------------------------------------
//PLAYER SAVING AND ANIMATION
//-------------------------------------------------------------------------
 void savingplayer()
  {x=0;
   currbar=0;
   l=0;
   ofstream outplayer;
   outplayer.open("save.lap",ios::out|ios::binary|ios::app);
   outplayer.seekp(0);
   if(!outplayer)
    error("Cannot create file.");
   outplayer.close();

   if(saved==YES)
  {
   fstream ioplayer;                             //actual saving of file
   ioplayer.open("save.lap",ios::out|ios::binary|ios::in|ios::ate);
   if(!ioplayer)
    error("Cannot open file.");
   ioplayer.seekp(0);
   p1=p[i];

     encrypt(p1.password);
     encrypt(p1.name);
     ioplayer.seekp(spadd);
     ioplayer.write((char*)&p1,sizeof(player));
      ioplayer.seekp(0);
   ioplayer.seekg(0);
   ioplayer.close();
    }
   if(saved==NO)
    { p[i].exists=YES;
    ofstream ioplayer2;                             //actual saving of file
   ioplayer2.open("save.lap",ios::out|ios::binary|ios::app);
   if(!ioplayer2)
    error("Cannot open file.");
   ioplayer2.seekp(0);
   p1=p[i];

     encrypt(p1.password);
     encrypt(p1.name);

     ioplayer2.write((char*)&p1,sizeof(player));

   ioplayer2.seekp(0);

   ioplayer2.close();
    }
   randomize();
anime("Saving Player","Saved!");
garage();
  }


//-------------------------------------------------------------------------
//ENCRYPTION DURING SAVING
//-------------------------------------------------------------------------
 void encrypt(char a[11])
  {char temp[11];
  int r;
   char c1[63]="(`@#$%^&*)_-=|}{[];:<>.Ö©ùëûü§¶°Ÿπ®£ö‰ÊÈÎËÂ›ºÁ–Äì‚∆…Ú¸ˆŒ„≈Í";
   char  u[63]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

   randomize();
   for(int f=0;a[f]!='\0';f++)
   {
    for(int q=0;u[q]!='\0';q++)
    { if(a[f]==u[q])
      {
       temp[f]=c1[q];
       }


       }}
       temp[f]='\0';
       strcpy(a,temp);
       }

//-------------------------------------------------------------------------
//DECRYPTION DURING LOADING
//-------------------------------------------------------------------------
 void decrypt(char a[11])
  {char c1[63]="(`@#$%^&*)_-=|}{[];:<>.Ö©ùëûü§¶°Ÿπ®£ö‰ÊÈÎËÂ›ºÁ–Äì‚∆…Ú¸ˆŒ„≈Í";
   char  u[63]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

   char temp[11];
   for(int f=0;a[f]!='\0';f++)
   {for(int q=0;u[q]!='\0';q++)
    {if(a[f]==c1[q])
     temp[f]=u[q];
     }}
     temp[f]='\0';
     strcpy(a,temp);}

//-------------------------------------------------------------------------
//THE GAME
//-------------------------------------------------------------------------

 void game()                             // 1/11/2009  4:27
  { int tk;

    if(training==YES)
    {noofplayers=1;
    p[1]=p[0];  }

   l=0;
   currbar=0;
   while(ch!='›')
    {clrscr();l++;
	 textbackground(RED);
     textcolor(7);
     printinmiddle("GARAGE - LOAD RACE - [ESC]MAIN MENU",7,RED);
     cout<<endl;
     floatcurrbar=currbar;
     currbarfrac=floatcurrbar/80;
     currbarperc=currbarfrac*100;
     textcolor(CYAN);
     cprintf("Loading Race %d (",gamerace+1);
     textcolor(GREEN);
     cprintf("%d%",currbarperc);
     textcolor(CYAN);
     cprintf(") ...");
     cout<<endl<<endl;
     int unitsize= rand()%5;
     currbar=unitsize+currbar;
     for(int r=0;r<currbar;r++)
      {textcolor(GREEN);
       cprintf("€");
      }
     for(int s=0;s<80-currbar;s++)
      {textcolor(RED);
       cprintf("€");
      }
     cout<<endl;
     line(RED,80);
     if(currbar>80)
      {clrscr();
       printinmiddle("GARAGE - LOAD RACE - [ESC]MAIN MENU",7,RED);
       textcolor(GREEN);

       line(RED,80);

       break;
      }
     delay(30);
     if(l==1)
     sleep(1);
    }


  clrscr();

   char unitsdigit;
   char tensdigit;
   char singledigit;
   char singlarr[10]="123456789";
   char chararr[11]={"1234567890"};
   if(gamerace<9)
    singledigit=singlarr[gamerace];
   if(gamerace>=9)
    {tempnoof=gamerace;
     tempnoof++;
     unitsdigit=chararr[tempnoof%10];
     tensdigit=chararr[tempnoof/10];
    }
   char traname[50];
   int z=strlen(trackname[track[gamerace]]);
   strcpy(traname,trackname[track[gamerace]]);
   traname[z]=' ';
   traname[z+1]='-';
   traname[z+2]=' ';
   traname[z+3]='R';
   traname[z+4]='a';
   traname[z+5]='c';
   traname[z+6]='e';
   traname[z+7]=' ';
   if(noofraces<10)
    {traname[z+8]=singledigit;
     traname[z+9]='\0';
    }
   if(noofraces>=10)
    {traname[z+8]=tensdigit;
     traname[z+9]=unitsdigit;
     traname[z+10]='\0';
    }

    if(training==YES)
    {strcpy(playername,p[0].name);
     reverse(playername);
     strcpy(p[1].name,playername);
     p[0].team=1;
     p[1].team=2;
     }

   randomize();
   while(ch!='›')
    {clrscr();


     currrank=(noofplayers+1);
     printinmiddle(nameoftournament,0,7);
     textbackground(GREEN);
     textcolor(0);
     printinmiddle(traname,7,RED);
     cout<<endl;

     for(int q=0;q<=noofplayers;q++)
      {textcolor(7);
       cprintf("%d.",q+1);
       if(p[q].health<0)
       p[q].health=0;


       if(q==turn)
       {textbackground(BLUE);
       textcolor(7);  }
       else
       {textbackground(0);
       textcolor(GREEN);}

       cprintf(p[q].name);

       if(training!=YES)
      { textcolor(7);
       textbackground(0);
       cprintf("   Team: ");
       textcolor(GREEN);
       cprintf("%d",p[q].team); }
       textbackground(0);
       textcolor(7);

       cprintf("   Total Level: ");
       p[q].totallevel();
       textcolor(GREEN);
       cprintf("%d",p[q].totlevel);
       textcolor(7);
       cprintf("  ");
       cout<<"  ";

       textbackground(RED);
       textcolor(7);
       cprintf("©");

       textbackground(0);
       textcolor(7);
       cprintf("(");

       textcolor(GREEN);
       cprintf("%d/9", p[q].ammo);
       textcolor(7);
       cprintf(")  ");




textcolor(RED);
cprintf("Î");

textbackground(0);
textcolor(7);
cprintf("(");
textcolor(GREEN);
if(p[q].carno==0)
{cprintf("-");
currnitro=1;}
else
cprintf("%d/4", p[q].nitro);
textcolor(7);
cprintf(")  ");



textbackground(7);
textcolor(RED);
cprintf("+");

textbackground(0);
textcolor(7);
cprintf("(");
textcolor(GREEN);
cprintf("%d/6",p[q].healthpack);
textcolor(7);
cprintf(")  ");
textcolor(7);
textbackground(0);


textcolor(7);
cprintf("%d",p[q].rank);
if(p[q].rank==1)
cprintf("st");
if(p[q].rank==2)
cprintf("nd");
if(p[q].rank==3)
cprintf("rd");
if(p[q].rank==4)
cprintf("th");

char leftarrow[2]="";
leftarrow[0]=(leftarrow[0]+1);

       if(q==turn)
       {
	textcolor(RED);
       cout<<"   ";
       cprintf(leftarrow);
       textbackground(RED);
       textcolor(7);
       cprintf("<<<");
       textcolor(7);
       textbackground(0);}
       cout<<endl;
       textcolor(RED);
       char heart[2];
       heart[0]=HEALTH;
       heart[1]='\0';
       cprintf(heart);
       textcolor(GREEN);
       healthbar(p[q].health,p[q].maxhealth,70);
       cout<<endl;
       textcolor(7);



       line(7,78);
       cprintf("±");
       line(7,1);


      if(track[gamerace]==0)
      {
       if(q!=turn)
       {for(int k=0;k<80;k++)
	 {if(k!=p[q].pos&&k!=78)
	 {   textcolor(7);
	 if(k%2==0)
	 cprintf("-");
	 else
	 cout<<" ";
	 }
	 if(k==p[q].pos)
	 displaycar(p[q].carno,p[q].chassi);
	 if(k==78&&p[q].pos!=78)
	 {textcolor(7);
	    cprintf("±");
	    textcolor(trackcolor[track[gamerace]]);}
	  }
       }

       if(q==turn)
       { textcolor(7);


       for(int k=0;k<80;k++)
	{ if(k!=(d+p[q].prevpos)&&k!=78)
	 {textcolor(7);
	 if(k%2==0)
	 cprintf("-");
	 else
	 cout<<" ";
	 }
	 if(k==(d+p[q].prevpos))
	 displaycar(p[q].carno,p[q].chassi);
	 if(k==78&&k!=(d+p[q].prevpos))
	 {textcolor(7);
	 cprintf("±");
	 textcolor(trackcolor[track[gamerace]]);    }

}        }
	      }




if(track[gamerace]!=0)
      {
       if(q!=turn)
       {for(int k=0;k<80;k++)
	 {if(k!=p[q].pos&&k!=78)
	 {
	 displaytrack(track[gamerace]);
	 }
	 if(k==p[q].pos)
	 displaycar(p[q].carno,p[q].chassi);
	 if(k==78&&p[q].pos!=78)
	   {textcolor(7);
	    cprintf("±");
	     textcolor(trackcolor[track[gamerace]]);   }
	  }
       }

       if(q==turn)
       {


       for(int k=0;k<80;k++)
	{ if(k!=(d+p[q].prevpos)&&k!=78)
	 {
	 displaytrack(track[gamerace]);
	 }
	 if(k==(d+p[q].prevpos))
	 displaycar(p[q].carno,p[q].chassi);
	 if(k==78&&k!=(d+p[q].prevpos))
	 {textcolor(7);
	 cprintf("±");
	 textcolor(trackcolor[track[gamerace]]);}

	  if(p[turn].pos>79)
	  {p[turn].pos=79;
	  displaycar(p[q].carno,p[q].chassi);}
}        }
	      }

       line(7,78);
       cprintf("±");
       line(7,1);


       }




	if(move==YES)
       {delay(100);
	d++;
	if(d>=(p[turn].pos-p[turn].prevpos))
	{
	if(p[turn].prg>=1000)
	{
	 p[turn].fin=YES;
	 p[turn].pos=79;
	}
	turn++;

	  {if(turn>noofplayers)
	turn=0;
	if(turn<0)
	turn=noofplayers; }


	d=0;
	move=NO;
	p[turn].prevpos=p[turn].pos;
	}

	if(damage==YES)
	{

	sleep(1);
	p[tk].health-=eventdamage[track[gamerace]][prob1];
	if(p[tk].health<0)
	p[tk].health=0;
	damage=NO;}

	continue;
	}



       if(training==YES&&turn==0&&p[turn].fin!=YES)
       ch=getch();
       if(training==YES&&turn==1&&p[turn].fin!=YES)
       ch=ai(0);
       if(training!=YES&&p[turn].fin!=YES)
       ch=getch();



       if(ch=='d'||ch=='D')
       {
	prob1=rand()%3;
	prob2=rand()%100;

	if(prob2<=eventprob[prob1])
	{first:
	 clrscr();
	 printinmiddle("EVENT",7,RED);
	 cout<<endl;
	 textcolor(GREEN);
	 cprintf(p[turn].name);
	 cprintf(",");
	 cout<<endl;


	 cprintf(eventstatement[track[gamerace]][prob1]);
	 cout<<endl<<endl<<endl;
	 textcolor(CYAN);
	 cprintf("What do you want to do?");
	 cout<<endl<<endl<<endl;
	 textcolor(7);
	 cprintf("(W) ");
	 textcolor(CYAN);
	 cprintf(eventattempt[track[gamerace]][prob1]);
	 cout<<endl<<endl;
	 textcolor(7);
	 cprintf("(S) ");
	 textcolor(CYAN);
	 cprintf(eventbribe[track[gamerace]][prob1]);

	 textcolor(YELLOW);
	 cprintf(" (- $%.0f)",bribecost[track[gamerace]][prob1]);

	 cout<<endl<<endl;
	 textcolor(7);
	 cprintf("(X) ");
	 textcolor(CYAN);
	 cprintf(eventevade[track[gamerace]][prob1]);

		p[turn].handling-=handlingdegrade[track[gamerace]];





       if(training==YES&&turn==0)
       ch=getch();
       if(training==YES&&turn==1)
       {sleep(3);
       ch=ai(1);}
       if(training!=YES)
       ch=getch();


	 if(ch=='W'||ch=='w')
	 {handlingfloat=p[turn].handling;
	 chance=(((handlingfloat/(1000.0/0.55))*100)+25);
	  int r=rand()%100;
	  if(r<=chance)
	  {

	   clrscr();
	   printinmiddle("EVENT",7,RED);
	   cout<<endl;


	   textcolor(GREEN);

	   cprintf("You succeed!");
	   reward=rewardarray[track[gamerace]][prob1];
	   p[turn].money+=reward;
	   cout<<endl<<endl<<endl;
	    textcolor(YELLOW);
	   cprintf("You win $%.0f.",reward);
	   cout<<endl<<endl;
	   textcolor(CYAN);

	   if(training==YES&&turn==1)
	   sleep(1);
	   else
	   {cprintf("Press any key to continue.");
	   getch();}
	   textcolor(7);


	   }

	   else
	   { clrscr();
	   printinmiddle("EVENT",7,RED);
	   cout<<endl;
	   textcolor(RED);
	   cprintf("You failed!");
	     cout<<endl<<endl<<endl;
	     cprintf(eventfail[track[gamerace]][prob1]);
	     cout<<endl<<endl;
	     textcolor(CYAN);
	     damage=YES;
	     tk=turn;
	     if(training==YES&&turn==1)
	     sleep(1);
	     else
	    { cprintf("Press any key to continue.");
	     getch();}
	     textcolor(7);

	   } }



	  else if(ch=='S'||ch=='s')
	  {clrscr();
	   printinmiddle("EVENT",7,RED);
	   cout<<endl;
	   textcolor(GREEN);
	   cprintf(eventbribed[track[gamerace]][prob1]);
	   p[turn].money-=bribecost[track[gamerace]][prob1];

	   cout<<endl<<endl;
	   textcolor(CYAN);

	   if(training==YES&&turn==1)
	     sleep(1);
	     else
	  { cprintf("Press any key to continue.");
	  getch();}
	   textcolor(7);

	   }

	   else if(ch=='X'||ch=='x')
	   {clrscr();
	    printinmiddle("EVENT",7,RED);
	    cout<<endl;

	    textcolor(RED);
	    cprintf("You miss your turn!");
	    cout<<endl<<endl<<endl;
	    textcolor(GREEN);
	    cprintf(eventevaded[track[gamerace]][prob1]);
	    turn++;
	    textcolor(CYAN);
	    cout<<endl<<endl;


	    if(training==YES&&turn==1)
	     sleep(1);
	     else
	     {
	    cprintf("Press any key to continue.");
	    getch();}

	   textcolor(7);


	 {if(turn<0)
	    turn=noofplayers;
	    if(turn>noofplayers)
	    turn=0;}
	    p[turn].prevpos=p[turn].pos;
	    continue;
	    }
	    else if(ch==esc)
	    mainmenu();
	    else
	    {goto first;}
	     }


	p[turn].prevpos=p[turn].pos;
	currprgfloat=(((speedmod*p[turn].speed)+(handlingmod*p[turn].handling))/tracklength[track[gamerace]]);
	currprg=currprgfloat;
	prgfactor=rand()%(currprg/2);
	currprg=currprg-prgfactor;
	p[turn].prg+=currprg;
	prgfloat=p[turn].prg;
	posfloat=((prgfloat/1000)*78);
	p[turn].pos=posfloat;
	if(p[turn].pos>79)
	p[turn].pos=79;
	if(p[turn].speed>0)
	p[turn].speed-=speeddegrade[track[gamerace]];

	move=YES;
	ch='l';
	}


       if(p[turn].ammo>0)
       if(ch=='f'||ch=='F')
       {if((training!=YES)||((training==YES)&&(turn==0)))
       fh=getch();
	 if(fh=='1'||fh=='2'||fh=='3'||fh=='4')
	{ int f1;
	  if(fh=='1')
	  f1=0;
	  if(fh=='2')
	  f1=1;
	  if(fh=='3')
	  f1=2;
	  if(fh=='4')
	  f1=3;

	if(p[f1].team!=p[turn].team)
	{
	 p[turn].ammo--;

	 int kuchbhi=rand()%100;
	 if(kuchbhi<80)
	 hit=YES;
	 else
	 hit=NO;

	 if(hit==YES)

	 {
	 weaponstrength=p[turn].weaponstrength;
	 dmg=0.10*weaponstrength;

	  degrade=0.01*p[turn].weaponstrength;
	  weaponstrength=p[turn].weaponstrength;
	  if(p[turn].weaponstrength>0)
	  p[turn].weaponstrength=weaponstrength-degrade;


	  if(p[f1].health>0)
	  p[f1].health-=dmg;
	  }
	  turn++;
	  p[turn].prevpos=p[turn].pos;
		} }}


	if(p[turn].nitro>0)
	if(ch=='n'||ch=='N')
	{ p[turn].nitro--;
	  p[turn].prevpos=p[turn].pos;
	currprgfloat=(((speedmod*p[turn].speed)+(handlingmod*p[turn].handling))/tracklength[track[gamerace]]);
	currprgfloat=(currprgfloat/2);
	currprg=currprgfloat;

	prgfactor=rand()%(currprg);
	currprg=currprg+prgfactor;
	p[turn].prg+=currprg;
	prgfloat=p[turn].prg;
	posfloat=((prgfloat/1000)*78);
	p[turn].pos=posfloat;
	if(p[turn].pos>79)
	p[turn].pos=79;
	if(p[turn].speed>0)
	p[turn].speed-=speeddegrade[track[gamerace]];

	healthfloat=p[turn].health;
	healthfloat=0.066*healthfloat;
	p[turn].health-=healthfloat;

	move=YES;
	ch='l'; }


	if(p[turn].healthpack>0)
	if(ch=='h'||ch=='H')
	{ p[turn].health+=100;
		if(p[turn].health>p[turn].maxhealth)
	p[turn].health=p[turn].maxhealth;

	  p[turn].healthpack--;
	  turn++;
	   p[turn].prevpos=p[turn].pos; }


		if(p[turn].health<0)
	 p[turn].health=0;



	if(p[turn].weaponstrength<0)
	 p[turn].weaponstrength=0;

	if(p[turn].handling<0)
	p[turn].handling=0;


	if(p[turn].speed<0)
	p[turn].speed=0;

	if(turn>noofplayers)
	turn=0;
	if(turn<0)
	turn=noofplayers;
	count1=0;



       noofinplayers=0;
       if(turn==noofplayers)
       {for(int j=0;j<=noofplayers;j++)
	{currrank=1;
	 for(int k=0;k<=noofplayers;k++)
	 if(p[j].prg<p[k].prg)
	 currrank++;
	 p[j].rank=currrank;}
       for(int m=0;m<=noofplayers;m++)
       if(p[m].fin==YES)
       noofinplayers++;
       if((noofinplayers-1)==noofplayers)
       {for(int o=0;o<=noofplayers;o++)
	{ if(p[o].rank==1)
	 {wins[p[o].team-1]++;} }
       sleep(1);
       showrank();}}


	 if(p[turn].handling<=0||p[turn].speed<=0||p[turn].health<=0||p[turn].fin==YES)
       {p[turn].fin=YES;
	if(p[turn].tyrescount==0&&p[turn].enginecount==0&&p[turn].chassicount==0&&p[turn].prg<1000 )
	{clrscr();
	 printinmiddle("LIFE AT PACE",7,RED);
	 cout<<endl;
	 textcolor(RED);
	 cprintf(p[turn].name);
	 if(p[turn].handling<=0)
	 cprintf(", your tyres have failed!");
	 if(p[turn].speed<=0)
	 cprintf(", your engines have failed!");
	 if(p[turn].health<=0)
	 cprintf(", your vehicle has been destroyed!");
	 cout<<endl<<endl;
	 cprintf("Your race is over!");
	 textcolor(CYAN);
	 cout<<endl<<endl<<endl;
	 cprintf("Press any key to continue.");
	 getch();
	 if(p[turn].handling<=0)
	 p[turn].tyrescount++;
	  if(p[turn].speed<=0)
	 p[turn].enginecount++;
	  if(p[turn].health<=0)
	 p[turn].chassicount++;
	 }





	turn++;
	if(turn<0)
	turn=noofplayers;
	if(turn>noofplayers)
	turn=0;
       }
	if(ch==esc)
	mainmenu();
	ch='b';
  }
 }


//-------------------------------------------------------------------------
//AI (ARTIFICIAL INTELLIGENCE)
//-------------------------------------------------------------------------
char ai(int fox)
{
int nitrochance,bribechance,healthpackchance,ammochance,evadechance;
 if(fox==0)
 {
  if(p[1].nitro>0)
  nitrochance=10;
  if(p[1].healthpack>0)
  healthpackchance=10;
  if(p[1].ammo>0)
  ammochance=20;
  if((p[1].ammo>0)&&(p[0].health<(p[0].maxhealth/2)))
  ammochance=50;
  if((p[1].healthpack>0)&&(p[1].health<(p[1].maxhealth/4)))
  healthpackchance=50;

  int which=rand()%3;

  if(which==0)
  {
   int aichance=rand()%100+1;

   if(aichance<nitrochance)
   return 'N';
   else
   return 'D';
   }

  if(which==2)
  {int aichance=rand()%100+1;

   if(aichance<healthpackchance)
   return 'H';
   else
   return 'D';
   }

   if(which==1)
  {int aichance=rand()%100+1;

   if(aichance<ammochance)
   {fh=1;
   return 'F';}
   else
   return 'D';

   }

   else
   return 'D';
   }

 if(fox==1)
 {
  if(p[1].money>(2*bribecost[track[gamerace]][prob1]))
  bribechance=50;
  if(p[1].prg>p[0].prg)
  evadechance=50;

   int which=rand()%2;

  if(which==0)
  {
   int aichance=rand()%100+1;

   if(aichance<bribechance)
   return 'S';
   else
   return 'W';
   }

  if(which==1)
  {int aichance=rand()%100+1;

   if(aichance<evadechance)
   return 'X';
   else
   return 'W';
   }

   else
   return 'W';
   }}

//-------------------------------------------------------------------------
//RESULT AND RANK PAGE
//-------------------------------------------------------------------------
void showrank()
{ for(int f=0;f<=3;f++)
  {p[f].fin=NO;
  p[f].pos=p[f].prg=p[f].weaponcount=p[f].chassicount=p[f].tyrescount=p[f].enginecount=0;}
   count1=0;
 for(int g=0;g<20;g++)
 {clrscr();
  printinmiddle("CONGRATULATIONS !!!",7,RED);
  cout<<endl;
  textcolor(CYAN);
  gotoxy(45,3);
  cprintf(" Result:");
  int rihanna=5;
 for(int h=1;h<=(noofplayers+1);h++)
 {
  for(int u=0;u<=noofplayers;u++)
  {
   if(p[u].rank==h)
   {  textcolor(7);

    gotoxy(45,rihanna);
    cprintf(" %d ",p[u].rank);
    textcolor(GREEN);
    cprintf(p[u].name);
    textcolor(7);
    cprintf(", ");
    cprintf("Team:");

    textcolor(GREEN);
    cprintf("%d  ",p[u].team);
    textcolor(YELLOW);
    p[u].totallevel();
    totlevelfloat=p[u].totlevel;
    rankfloat=p[u].rank;
    prizefloat=((totlevelfloat*15.0)-(rankfloat*3*totlevelfloat));
	p[u].money+=prizefloat;
    cprintf("+ $%0.f",prizefloat);
    rihanna++;

     }
   }}



  if(gamerace==noofraces)
  {for(int d=0;d<4;d++)
   {counter=0;
    for(int e=0;e<4;e++)
    if(wins[d]>wins[e])
    counter++;

    if(counter==3)
    {gotoxy(45,rihanna+2);
    textcolor(GREEN);
    cprintf("Team %d won the tournament.",d+1);
     break;}
     else

     {gotoxy(45,rihanna+2);
      textcolor(GREEN);
     cprintf("No team won. It was a tie.");
      break;}
      }
     }
     else
     {textcolor(GREEN);
      gotoxy(45,rihanna+1);
      cprintf("Get ready for next race!");
      }

   gotoxy(1,3);
  if(g%2==0)
 {
       textcolor(13);
 cprintf("\\_,     _ _     \\.=   ");cout<<endl;
 cprintf("  \\\\   /,~,\"\\  //    ");cout<<endl;
 cprintf("   \\\\ /|o_o|( //      ");cout<<endl;
 cprintf("    :\\)\\'=/ /'/       ");cout<<endl;
 cprintf("     \\(-._.-\\'        ");cout<<endl;
 cprintf("     '\\  Y  /          ");cout<<endl;
 cprintf("       | :  |           ");cout<<endl;
 cprintf("      _/ :  (_          ");cout<<endl;
 cprintf("      \\'.__.'/         ");cout<<endl;
 cprintf("       |'-,-'|          ");cout<<endl;
 cprintf("       \\  | /          ");cout<<endl;
 cprintf("        | / )            ");cout<<endl;
 cprintf("        |/\\/            ");cout<<endl;
 cprintf("        /|/|             ");cout<<endl;
 cprintf("       [_[_/            ");cout<<endl;
  }
  else
  { cout<<endl;
  textcolor(13);
 cprintf("        _ __     ");cout<<endl;
 cprintf("       /.-. |    ");cout<<endl;
 cprintf("      ||o_o||    ");cout<<endl;
 cprintf("      |,\\= ||   ");cout<<endl;
 cprintf("     .--' '-.    ");cout<<endl;
 cprintf("    / .--Y-.\\\\ ");cout<<endl;
 cprintf("   ( /\\   -/ /  ");cout<<endl;
 cprintf("    \\\\|   \\8\" ");cout<<endl;
 cprintf("     9/    )     ");cout<<endl;
 cprintf("     /_____/     ");cout<<endl;
 cprintf("     ) / \\ (    ");cout<<endl;
 cprintf("     //   \\|    ");cout<<endl;
 cprintf("    |/    |\\    ");cout<<endl;
 cprintf("   /|     '='    ");cout<<endl;
 cprintf("   '=            ");cout<<endl;
 }
delay(400);   }
cout<<endl;
textcolor(CYAN);
cprintf("Press any key to continue.");
textcolor(GREEN);
cout<<endl<<endl;
if(gamerace<noofraces)
cprintf("Get ready for the next race!");

getch();


fstream pout("save.lap",ios::ate|ios::in|ios::out|ios::binary);

pout.seekp(0);
pout.seekg(0);

while(pout.read((char*)&p1,sizeof(player)))
{for(int frog=0;frog<=noofplayers;frog++)
 {
  if(!strcmp(p1.name,p[frog].name))
  {int bolo=pout.tellg();
   pout.seekp(bolo-sizeof(player));
   pout.write((char*)&p[frog],sizeof(player));}
  }
   }

 anime("Saving Players","Saved!");

 if(gamerace==noofraces)
 {pout.close();
 choosemode(); }

 gamerace++;

pout.close();
garage();

}



//-------------------------------------------------------------------------
//MAIN
//-------------------------------------------------------------------------
 void main()
  {clrscr();
   boot();
  }
//-------------------------------------------------------------------------
//END OF PROGRAM
//-------------------------------------------------------------------------








