
inherit ROOM;

int block_cmd(string);
int things(object me);
void create () 
{
set ("short", "发呆室"); 
set ("long", @LONG 

这是巫师为广大的发呆爱好者设计的发呆室，练习发呆神功的最好场
所，您可以在这里想尽任何办法，任何花样，各种姿势，尽情的发呆
而不会影响别人，不要再为影响市容而担心了，让我们发呆吧......

LONG); 

    set("exits", ([ /* sizeof() == 4 */ 
     "south" : "/d/city/kezhan",

     ]));
     set("objects", ([ /* sizeof() == 2 */ 

    ])); 
set("no_time", 1); 
set("freeze", 1); 
set("no_fight", 1); 
set("chat_room",1); 
set("no_magic", 1); 
set("no_upgrade_age",1); 

setup(); 
 call_other("/obj/board/idle_b", "???"); 
}
void init() 
{
add_action("block_cmd", "", 1);
}
int things(object me) 
{
int i;
object* inv; 
me = this_player(); 
  inv = all_inventory(me); 
    for(i=0; i<sizeof(inv); i++)  { 
    if( inv[i]->query_unique() ) { 
    message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]); 
    destruct(inv[i]); 
   }
}
//   add_action("block_cmd", "", 1); 
return 0; 
}
int block_cmd(string args) 
{
string verb; 
  verb = query_verb(); 

    // if (verb == "bian") return 1; // by mon 7/15 
    if (verb == "xiudao") return 1; 
    if (verb == "exert") return 1; 
    if (verb == "who") return 1; 
    if (verb == "top") return 1; 

    return 0; 
}


