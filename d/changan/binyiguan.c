inherit ROOM;
void create()
{
set("short", "殡仪馆");
set("long", "
    人们由生到死，这是人之常情，我国历史上和世界各民族中有各种安置死者的办法，其中\n
主要的办法是土葬和火葬，而土葬沿用最广。但是土葬占用耕地，浪费木材；加以我国历代封建\n
统治阶级把厚葬久丧定作礼法， 常使许多家庭因为安置死者而陷于破产的境地。实行火葬，不\n
占用耕地，不需要棺木，可以节省装殓和埋葬的费用，也无碍于对死者的纪念。\n
    为了让逝者尽早的升入天国，我们在这里把他的尸体火化（shao）吧！\n
");
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"broadway1",
]));
// mudring Dec/09/2002
set("no_fight",1);
set("no_move",1);
setup();
}
void init()
{
add_action("do_burn","shao");
}
int do_burn(string arg)
{
object me;
object tar;
int score, pot;
me = this_player();
score = (int) me->query("combat_exp");
pot = (int) me->query("potential");
// busy cant shao
// mudring Dec/09/2002
if (me->is_busy())
return notify_fail("别急，别急。\n");
if( !arg || arg == "") 
return notify_fail("你要火化什么．\n");
tar = present(arg, me);
if( !tar) 
return notify_fail("没有这具尸体．\n");
if( userp(tar))
return notify_fail("你干什么，还有救呀！\n");
if( tar->query("owner"))
return notify_fail("这东西这里不收．\n");
if( tar->is_corpse())           
{
me->add("combat_exp", 10);
me->add("potential", 10);
message_vision("$N将$n送入炉膛，$n慢慢的开始燃烧，最后变成一堆骨灰．\n", me, tar);
// 这个还不busy哪个busy??
// mudring Dec/09/2002
message_vision("$N怀念起以前的日子，心里不禁涌起阵阵酸来！\n", me);
me->start_busy(5);
}
message_vision("$n烧化了．\n", me, tar);
tar->move(environment(me));
destruct(tar);
return 1;
}

