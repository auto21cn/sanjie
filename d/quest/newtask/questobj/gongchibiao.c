#include <weapon.h>
inherit THROWING; 

void create()
{
        set_name("工尺镖", ({ "gongchi biao" }) );
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                 set("material", "iron");
                set("long", "江湖暗器。为一枚枚大小厚薄不同的银钱。\n");}
                init_throwing(15);
                setup();
}
