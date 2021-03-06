//transter.c
//by xiaofeng

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
#define RECEIVE_DIR "/p/receive/"
#define TRANSFER_A "/adm/daemons/network/services/transfer_a.c"
void create() { seteuid(ROOT_UID); }

void send_msg(object me,string mud,string file,string msg)
{
        mapping minfo;
        if (!file || !msg) return;
        mud = htonn( mud );
        if(mud == mud_nname() || !geteuid(me)) return;

        minfo = (mapping)DNS_MASTER->query_mud_info(mud);
        if (!minfo)
        {
                tell_object(me, "无此MUD或未和此MUD联网!请使用mudlist查看!\n");
                return ;
        }
        DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                        "@@@" + "transfer_q" +
                        "||NAME:" + Mud_name() +
                        "||PORTUDP:" + udp_port() +
                        "||ID:" + geteuid(me) +
                        "||CNAME:" + me->query("name") +
                        "||FILE:" + file +
                        "||MSG:"+msg+"@@@\n");
        tell_object(me, "本地验证通过,请等待远程计算机回应。\n");
}
void incoming_request(mapping info)
{
        mapping minfo;
        string id, name, msg, file, backmsg, localmsg;
        set("channel_id", HIW"[文件精灵]");
        if (info["NAME"] && info["PORTUDP"]) 
        {
                if (info["NAME"] == Mud_name())   return;

                minfo = DNS_MASTER->query_mud_info(info["NAME"]);
                if (!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
                        PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        
                if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) 
                        return ;
                id = info["ID"];
                name = info["CNAME"];
                file = RECEIVE_DIR + info["FILE"];
                msg = info["MSG"];
                if (file_size(RECEIVE_DIR) != -2)
                {
                        localmsg = "试图发送文件,但我方未建立相应的RECEIVE目录!" +
                                "请查看/adm/daemons/network/services/transfer.c文件!";
                        backmsg = "失败,对方没有建立RECEIVE目录!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
        
                        return;
                }
                if( stringp(file) && file!="")
                if (file_size(file) != -1 || file_size(file) == -2 )
                {
                        localmsg = "试图发送文件"+file+",但该文件已经存在!";
                        backmsg = "失败,对方系统中已存在同名文件!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                        return;
                }
                msg = info["MSG"];
                if (!msg) return;
                write_file(file, msg);
                if (file_size(file) < 0)
                {
                        localmsg = "试图发送文件"+file+"失败,可能是权限不允许!";
                        backmsg = "失败,可能是无权利写入对方RECEIVE目录!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                }
                else
                {
                        localmsg = "发送文件"+file+"成功!";
                        backmsg = "成功!";
                        TRANSFER_A->send_msg(info["NAME"], name, file, backmsg);                        
                        CHANNEL_D->do_channel(this_object(), "wiz",name+"("+id+"@"+info["NAME"]+")"+localmsg + NOR + "\n");
                }
                
                return;    
        }
}

