inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼第七层——星空无限");
  set ("long", HIW@LONG







             *       ★     *   ☆.        ★ *     .    *        *     *☆
         ★ *     .     *              .     * ★            ★ *     . 
                   *     .    *        *     *☆

   *☆   纵观脚下世界， 缕缕烟丝，吹不散心头凝重的忧伤。★ *
         试看微笑，灵魂却冻结般难受，再也经受不住挫折的
  ☆★ * 心空。守望，霓虹灯绵延的夜。静坐一隅，任凭目光  *☆
         寻觅，已成虚幻的身影。苍远的流星，划破曾经相恋
 ☆      的地方。怀中的玫瑰，终于悠悠而泣。 *        ☆   ★
       *☆

              *       ★     *   ☆.        ★ *     .    *        *     *☆
   ★ *             .     *          ☆★ *     .     * ★            ★ *     . 
            ★ *     .    *        *     *☆
      ★         *     .     *          ☆★ *     .     * ★            ★ *    





LONG NOR);

  set("exits",([
  "down" : __DIR__"qingfenglou6",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
