// Room: /u/cigar/home.c

inherit ROOM;

void create()
{
        set("short", "星期天小店");
        set("long", @LONG
                _..._
                  .~     `.
          ,_     /          }
         ,_\'--, \   _.'`~/
          \'--,_`{_,}    -(
           '.`-.`\;--,___.'_
             '._`/    |_ _{@}
                /     ` |-';/            _
               /   \    /  |        _   {@}_
              /     '--;_        _ {@}  _Y{@}
             _\          `\     {@}\Y/_{@} Y/
            / |`-.___.    /     \Y/\|{@}Y/\|//
  ^^^^^^^^^`--`------'`--`^^^^^^^^^^^^^^^^^^^^^^^^


      在这里聊天吧，你现在高高在上，望眼欲穿，远离脚下的硝烟尘世！



LONG
        );
        set("valid_startroom", "1");
                set("exits", 
        ([ //sizeof() == 8

  "down" : "/d/wiz/entrance",
]));
        set("objects", ([ /* sizeof() == 1 */
//                "/obj/board/xlqy_ss" : 1,
//
                       ]));
set("no_magic", 1);
        set("no_time",1);
        set("no_fight", "1");

        setup();
          call_other( "/obj/board/sjsh_ss", "???" );
}
