# if 0

typedef union msg_arg
{
    INT8U u8Arg; /*成员：8 位无符号*/
    INT8U s8Arg; /*成员：8 位有符号*/
    #if CFG_MSG_ARG_INT16_EN>0
    INT16U u16Arg; /*可选成员：16 位无符号*/
    INT16S s16Arg; /*可选成员：16 位有符号*/
    #endif
    #if CFG_MSG_ARG_INT32_EN>0
    INT32U u32Arg; /*可选成员：32 位无符号*/
    INT32S s32Arg; /*可选成员：32 位有符号*/
    #endif
    #if CFG_MSG_ARG_FP32_EN>0
    FP32 f32Arg; /*可选成员：32 位单精度浮点*/
    #endif
    #if CFG_MSG_ARG_PTR_EN>0
    void* pArg; /*可选成员：void 指针*/
    #endif
}MSG_ARG;

/*消息结构体*/
typedef struct _msg
{
    INT8U u8MsgID; /*消息 ID*/
    #if CFG_MSG_USR_SUM > 1
    INT8U u8UsrID; /*消费者 ID*/
    #endif
    MSG_ARG uMsgArg; /*应用消息参数*/
} MSG;

/*消息缓冲区结构体*/
typedef struct msg_box
{
    INT8U u8MBLock; /*队列上锁标识*/
    INT8U u8MsgSum; /*队列长度*/
    INT8U u8MQHead; /*队列头结点位置*/
    INT8U u8MQTail; /*队列尾节点位置*/
    MSG arMsgBox[CFG_MSG_SUM_MAX]; /*存放队列的数组*/
} MB;
static MB g_stMsgUnit; /*消息管理单元全局变量*/

void mq_init(void) //消息队列初始化，负责初始化 g_stMsgUnit ；
void mq_clear(void) //清空消息队列，效果同 mq_init()，可有可无；
void mq_lock(void) //消息队列锁定，锁定的消息队列不可读不可写；
void mq_unlock(void) //消息队列解锁，解锁后消息队列恢复正常功能；
BOOL mq_is_empty(void) //消息队列判空，返回 TRUE 表示消息队列当前为空，返回 FALSE 表示有消息存储；
INT8U mq_get_msg_cur_sum(void) //查询消息队列中当前存储的消息总数，函数返回值为查询结果；
INT8U mq_get_msg_sum_max(void) //查询消息队列的最大容量，函数返回值为查询结果；
INT8U mq_msg_post_fifo(MSG* pMsg) //向消息队列中寄送消息，方式为先入先出，形参 pMsg 指向消息的备份内存，函数返回操作结果。该函数多被 ISR 调用，所以必须为可重入函数；
INT8U mq_msg_req_fifo(MSG* pMsg) //从消息队列中读取消息， 方式为先入先出， 函数将读出的消息存入形参 pMsg 指向的内存，函数返回操作结果。该函数被主程序调用， 可以不是可重入函数， 但要对共享数据进行临界保护 。

#endif
