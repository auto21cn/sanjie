// ring.c
// for marry
// written by mudring

#include <ansi.h>
#include <armor.h>

inherit F_AUTOLOAD;
inherit FINGER;

int CoupleTalk(string msg);

void create()
{
    string color;
    object ob = this_player();

    color = ob->query("color")?ob->query("color"):MAG;

    set_name( color + "水晶钻戒"NOR, ({"wedding ring", "ring"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("gift_modify/per", 4);
        set("unit", "只");
        set("value", 100000);
        set("material", "gold");
        set("armor_prop/armor", 1);
        set("no_sell", "这你也要卖？不如把你自己卖了！\n"); 
        set("no_give","这个也给人？\n");
        set("no_copy",1);
        set("no_drop",1);
        set("no_get",1);
    }

    setup();
}

void init()
{
    object ob = environment(); 

    if ((!ob->query("couple/id") || !ob->query("couple/name"))
        && !wizardp(ob))
    {
        ob->delete("married");
        call_out("LostRing", 1);
        return;
    }

    set("long", MAG"\n这是你"
        + (ob->query("gender") == "女性"?"丈夫":"妻子")
        + "在婚礼的时候给你戴上的结婚戒指\n上面"
        + "刻着"
        + (ob->query("gender") == "女性"?"他":"她")
        + "的名字：「"
        + ob->query("couple/name") + "」\n"NOR);

    wear();

    add_action("CoupleTalk", "me");
}

// can use me verb talk
int CoupleTalk(string msg)
{
    object me;
    object obj;

    me = this_player();

    if (!me->query("married"))
        return notify_fail("你结婚了吗？\n");

    if (me->query("sen") < 200)
        return notify_fail("温存重要，但身体更要紧！\n");

    obj = find_player(me->query("couple/id"));

    if (!obj || (!wizardp(me) && !me->visible(obj)))
        return notify_fail("你的伴侣现在不在....\n");

    if (!msg)
    {
        tell_object(me,sprintf(HIM"你总得说点什么吧？\n" NOR));
    }
    else
    {
        me->receive_damage("sen", 20);
        write(HIM "你悄悄告诉你的" + me->query("couple/name") + "：" + msg + "\n" NOR);
        tell_object(obj, sprintf(HIM "你的%s悄悄告诉你：%s\n" NOR,
            obj->query("couple/name"), msg)); 
    }

    return 1;
}

void LostRing()
{
    object ob = environment();

    if (userp(ob))
        tell_object(ob, HIB "\n你隐约觉得有一样很重要的东西丢失了！\n\n" NOR);

    destruct(this_object());
}

int unequip()
{
    object ob = environment();

    if (userp(ob) && ob->query("couple/id") && ob->query("couple/name"))
        return notify_fail("你不能卸下你的定情信物。\n");

    return ::unequip();
}

int query_autoload() { return 1; }

