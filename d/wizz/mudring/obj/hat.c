
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_AUTOLOAD; 

void create()
{
object ob = this_player();
        set_name(GRN+ob->query("couple/name")+"给的绿帽子"NOR, ({ ob->query("couple/id")+" hat", "maozi" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "顶");
                set("long","这是一顶人见人怕的帽子，可是有时你又只好带着它。\n");
                set("material", "hat");
                set("wear_msg","$N很不情愿地带上一顶$n。\n");
                set("remove_msg","$N很快乐地摘下一顶$n。\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
        object ob = this_player();
                if ( (!ob->query("couple/id") || !ob->query("couple/name")) && ob->query("id")!="newtest" ) {
                        call_out("lost", 1);
                        return;
                }
        add_action ("do_give", "give");
}

int do_give(string arg)
{
        object me, ob, who;
        string wiz, obs, whos;

        me = this_player();
        if (sscanf(arg, "%s to %s", obs, whos) != 2) return 0;
        if (obs != "hat" && obs != "maozi") return 0;
  
        ob = present ("hat", me);
        if (!ob) write ("好可怜啊，你没有送别人"GRN"绿帽子"NOR"的能力！\n");
        who = find_player(whos);
        if (!who) write ("没有这个人。\n");
        if (ob && who) {
                ob->move (who);
                message_vision ("$N送给$n一顶"GRN"绿帽子"NOR"戴。\n", me, who);
        }
        return 1;
}

int query_autoload() {return 1;}

void lost()
{
        object ob = environment();

        if (userp(ob))
                tell_object(ob, HIB "\n你隐约觉得身上的束缚消失了！\n\n" NOR);
        destruct(this_object());
}

