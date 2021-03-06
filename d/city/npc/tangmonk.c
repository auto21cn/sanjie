// Update by waiwai@2003/04/25

#include <localtime.h>
#include <ansi.h>
inherit NPC;

string *msg=({
	"多欲为苦，生死疲劳，从贪欲起；少欲无为，身心自在。",
	"懈怠坠落，常行精进，破烦恼恶，摧伏四魔，出阴界狱。",
	"愚痴生死，菩萨常念，广学多闻，增长智慧，成就辩才，教化一切，悉以大乐。",
	"贫苦多怨，横结恶缘，菩萨布施，等念怨亲，不念旧恶，不憎恶人。",
	"生死炽燃，苦恼无量，发大乘心，普济一切。",
	"愿代众生，受无量苦，令诸众生，毕竟大乐。",
	"愿以此功德，庄严佛净土，上报四重恩，下济三途苦。",
	"若有见闻者，悉发菩提心，常行菩萨道，广度诸有情。",
	"求经者，万缘都罢。",
 	"了性者，诸法皆空。",
	"大智闲闲，澹泊在不生之内。",
	"真机默默，消遥于寂灭之中。",
	"三界空而百端治，六根净而千种穷。",
	"若乃坚诚知觉，须当识心。",
	"心净则孤明独照，心存则万境皆清。",
	"真容无欠亦无余，生前可见。",
	"幻相有形终有坏，分外何求。",
	"行功打坐，乃为入定之原。",
	"布惠施恩，诚是修行之本。",
	"大巧若拙，还知事事无为。",
	"善计非筹，必须头头放下。",
	"但使一心不动，万行自全。",
	"若云采阴补阳，诚为谬语，服饵长寿，实乃虚词。",
	"只要尘尘缘总弃，物物色皆空。",
	"素素纯纯寡爱欲，自然享寿永无穷。",
});

void create()
{
	set_name("唐僧", ({"tang monk", "monk", "tang"}) );
	set("title","我不入地狱谁入地狱");
	set("gender", "男性");
	set("age", 50);
	set("per", 99);
	set("str", 200);
	set("int", 40);
	set("spi", 40);
	set("kar", 40);
	set("cor", 40);
	set("con", 40);
	set("cps", 40);

	set("combat_exp",1000000);
	set("wuxue_exp",10000);
	set("sav_mana",2000);
	set("mana",2000);
	set("max_mana",2000);
	set("class","bonze");
	set_skill("chanting",300);
	
	set("long","唐僧在取经回来以后就在长安城开始讲经，普渡众生。\n");
	set("attitude", "friendly");
        
	setup();
    carry_object("/d/obj/cloth/jia_sha")->wear();
    if(clonep()){
    	call_out("start_chanting", 10);
    }
}

void start_chanting()
{
	set("chanting_times", 50+random(10));

	message_vision(HIY "$N席地而坐，双目微闭，口中轻声诵起了经文。\n"NOR, this_object());
	call_out("chanting", random(4)+4);
	call_out("start_chanting", 200+random(100));
}

void chanting()
{
	object * obs;
	mixed * local;
	string mark;
	int gain, val;
	
	add("chanting_times", -1);
	if(!query("chanting_times")){
		message_vision(HIY"$N缓缓睁开眼睛，长舒一口气站了起来。\n" NOR, this_object());
		return;
	}

	local = localtime(time());
	mark=sprintf("chanting_learn/%d%d%d", local[LT_YEAR], local[LT_MON],
		local[LT_MDAY]);

	obs=all_inventory(environment(this_object()));
	obs=filter_array(obs, (: userp($1) && $1->query("sen")>50 && living($1) :));

	message_vision(sprintf(HIY"$N缓缓念道：%s\n"NOR, msg[random(sizeof(msg))]), this_object());
	
	foreach(object ob in obs){
		gain=ob->query_skill("chanting", 1)/10;
		gain=1+random(gain)+gain;
		if(gain>10)
			gain=7+random(4);

		val=25+random(10);;
		if(ob->query("bonze/class")=="bonze"){
			val/=2;
			gain*=2;
		}
			
		ob->start_busy(1);
		ob->receive_damage("sen", 20+random(20));
		
		if(ob->query(mark)>500){
			tell_object(ob, "你怎么也无法理解唐僧讲的内容。\n");
			continue;
		}
		ob->add(mark, 1);
		if(random(ob->query_int()+ob->query_spi())>val){
			tell_object(ob, "你听了唐僧的话，似乎有所了解。\n");
			ob->add("potential", gain/2);
			tell_object(ob, sprintf("你的潜能增加了%s点。\n", chinese_number(gain/2)));
			gain=gain+random(gain*2);
			ob->improve_skill("chanting", gain);
			tell_object(ob, sprintf("你的诵经修为增加了%s点。\n", chinese_number(gain)));
		}
	}
	call_out("chanting", random(5)+5);
}