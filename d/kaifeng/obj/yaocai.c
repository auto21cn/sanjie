inherit ITEM;
string *b_names = ({
        "三七",
        "枸杞子",
        "牛黄",
        "人参",
});
mapping names = ([
  "三七":       "san qi",
  "枸杞子":       "gouji zi",
  "牛黄":       "niu huang",
  "人参":       "ren shen",
]);
void setname() 
{
int i;
string name,*kn,*id;
i=random(4); 
name=b_names[i];
set("yaocai",b_names[i]); 
id=({names[b_names[i]],"yaocai"});
 set_name(name,id);  
}
void create(int i) 
{
setname();
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("long", "制药的材料。\n");
                set("unit", "个");
                set("value", 11111);
        }
        setup();
}
