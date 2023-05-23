#include <sys/types.h>
//#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
#include <shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//#include <sys/mman.h>

#include "motion.h"
#include "plc.h"
#include "error.h"

#include "decode.h"
#include "para.h"

#define test 1

#if test==0
#include <sys/mman.h>
#include <sys/ipc.h>
#endif

//struct motion_internal_struct *motion_internal=NULL;
struct motion_internal_struct  motion_internal123;
struct motion_internal_struct *motion_internal = &motion_internal123;

//struct motion_status_struct *motion_status=NULL;
struct motion_status_struct  motion_status123;
struct motion_status_struct *motion_status = &motion_status123;

//struct plc_shm_s *plc_shm=NULL;
struct plc_shm_s  plc_shm123;
struct plc_shm_s *plc_shm = &plc_shm123;

//struct decode_status_s * decode_status=NULL;
struct decode_status_s  decode_status123;
struct decode_status_s *decode_status = &decode_status123;

//struct command_queue_s * command_q=NULL;
struct command_queue_s  command_q123;
struct command_queue_s *command_q = &command_q123;

//struct motion_err_struct *motion_err=NULL;
struct motion_err_struct  motion_err123;
struct motion_err_struct *motion_err = &motion_err123;

//struct motion_err_struct *motion_warn=NULL;
struct motion_err_struct  motion_warn123;
struct motion_err_struct *motion_warn = &motion_warn123;

//struct para_s * para = NULL;
struct para_s  para123;
struct para_s *para = &para123;

#if 0
char * shm_mbuff_alloc(char * name,int size,int flag)
{
    char pname[40] ="/shm/";
    char * tmp_p;
    int shm_id;
    key_t key;

    strcat(pname,name);

    int ex = access(pname, 0);
    if (ex == -1)
    {
        int fd_open = open(pname, O_RDWR|O_CREAT, 0666);
        close(fd_open);
    }
    key = ftok(pname,0x03);
    if(key==-1)
    {
        perror("ftok error");
        return NULL;
    }
    if(flag)
        shm_id = shmget(key,size,IPC_CREAT|IPC_EXCL|0600);
    else
        shm_id = shmget(key,size,IPC_CREAT|0600);

    if(shm_id ==-1)
    {
        perror("shmget error");
        return NULL;
    }

    tmp_p = (char *)shmat(shm_id ,NULL,0);
    return tmp_p;
}

void shm_mbuff_free(char * name, void * shm_p,  int flag)
{
    char pname[40] ="/shm/";
    char * tmp_p;
    int shm_id;
    key_t key;

    shmdt(shm_p);
    if(flag)
    {
        strcat(pname,name) ;

        key = ftok(pname,0x03);

        if(key==-1)
        {
            perror("ftok error");
            return  ;
        }
        shm_id = shmget(key,0,0);
        shmctl(shm_id, IPC_RMID, NULL) ;
    }
}

#endif


#define share_printf //printf


/*
********************************************************运动共享内存
*/
int share_motion_status(int need_init)
{
    int fd;
    int ret = 1;
    my_print("share_motion_status 0\n");
    //fd = open("./shm/share_motion_status",O_RDWR|O_CREAT ,0777);
    fd = open("/home/root/shm/share_motion_status",O_RDWR|O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_motion_status,open error,%s:%d\n",__FILE__,__LINE__);
        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct motion_status_struct)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test ==0
    motion_status = mmap(NULL,sizeof(struct motion_status_struct),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(motion_status == MAP_FAILED)
    {
        error_printf("share_motion_status,mmap error,%s:%d\n",__FILE__,__LINE__);
        ret = -1;
        return ret;
    }

    if(need_init == 1)
    {
        memset(motion_status,0,sizeof(struct motion_status_struct));
    }
#endif
    close(fd);
    return ret;
}




int share_motion_internal(int need_init)
{
    int fd;
    int ret = 1;
    fd = open("/home/root/shm/share_motion_internal",O_RDWR|O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_motion_internal,open error,%s:%d\n",__FILE__,__LINE__);

        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct motion_internal_struct)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    motion_internal = mmap(NULL,sizeof(struct motion_internal_struct),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(motion_internal == MAP_FAILED)
    if(-1 == fd)
    {
        error_printf("share_motion_internal,mmap error,%s:%d\n",__FILE__,__LINE__);

        ret = -1;
        return ret;
    }
    if(need_init == 1)
    {
        memset(motion_internal,0,sizeof(struct motion_internal_struct));
    }
#endif
    close(fd);
    return ret;
}

/*
********************************************************PLC共享内存
*/

int share_plc_shm(int need_init)
{
    int fd;
    int ret = 1;
    fd = open("/home/root/shm/share_plc_shm",O_RDWR|O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_plc_shm,open error,%s:%d\n",__FILE__,__LINE__);

        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct plc_shm_s)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    plc_shm = mmap(NULL,sizeof(struct plc_shm_s),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(plc_shm == MAP_FAILED)
    {
        error_printf("share_plc_shm,mmap error,%s:%d\n",__FILE__,__LINE__);

        ret = -1;
        return ret;
    }
    if(need_init == 1)
    {
        memset(plc_shm,0,sizeof(struct plc_shm_s));
    }
#endif
    close(fd);
    return ret;
}


/*
********************************************************解释器共享内存
*/
int share_decode_status(int need_init)
{
    int fd;


    fd = open("/home/root/shm/share_decode_status",O_RDWR|O_CREAT,0777);
    if(-1 == fd)
    {
        error_printf("share_decode_status,open error,%s:%d\n",__FILE__,__LINE__);
        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct decode_status_s)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    decode_status = mmap(NULL,sizeof(struct decode_status_s),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(decode_status == MAP_FAILED)
    {
        error_printf("share_decode_status error\n");
        return -1;
    }

    if(need_init == 1)
    {
        memset(decode_status,0,sizeof(struct decode_status_s));
    }
#endif
    close(fd);
    return 1;
}


/*
********************************************************公用共享内存
*/
int share_command(int need_init)
{
    int fd;


    fd = open("/home/root/shm/share_command",O_RDWR|O_CREAT,0777);

    if(-1 == fd)
    {
        error_printf("share_command,open error,%s:%d\n",__FILE__,__LINE__);
        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct command_queue_s)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    command_q = mmap(NULL,sizeof(struct command_queue_s),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(command_q == MAP_FAILED)
    {
        error_printf("share_command error\n");
        return -1;
    }

    if(need_init == 1)
    {
        memset(command_q,0,sizeof(struct command_queue_s));
    }
#endif
    close(fd);
    return 1;
}

int share_motion_err(int need_init)
{
    int fd;
    int ret = 1;
    fd = open("/home/root/shm/share_error",O_RDWR|O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_motion_err,open error,%s:%d\n",__FILE__,__LINE__);
        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct motion_err_struct)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    motion_err = mmap(NULL,sizeof(struct motion_err_struct),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(motion_err == MAP_FAILED)
    {
       error_printf("share_motion_err,mmap error,%s:%d\n",__FILE__,__LINE__);
       ret = -1;
       return ret;
    }
    if(need_init == 1)
    {
        memset(motion_err,0,sizeof(struct motion_err_struct));
    }
#endif
    close(fd);
    return ret;
}

int share_warn(int need_init)
{
    int fd;
    int ret = 1;
    fd = open("/home/root/shm/share_warn",O_RDWR |O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_warn,open error,%s:%d\n",__FILE__,__LINE__);

        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct motion_err_struct)+50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_motion_status ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    motion_warn = mmap(NULL,sizeof(struct motion_err_struct),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(motion_warn == MAP_FAILED)
    {
        error_printf("share_warn,mmap error,%s:%d\n",__FILE__,__LINE__);

        ret = -1;
        return ret;
    }
    if(need_init == 1)
    {
        memset(motion_warn,0,sizeof(struct motion_err_struct));
    }
#endif
    close(fd);
    return ret;
}

int share_para(int need_init)
{
    int fd;
    int ret = 1;
    fd = open("/home/root/shm/share_para",O_RDWR |O_CREAT ,0777);
    if(-1 == fd)
    {
        error_printf("share_para,open error,%s:%d\n",__FILE__,__LINE__);

        return -1;
    }
    int f_ret = ftruncate(fd, sizeof(struct para_s) * PARA_NUM + 50);
    if (-1 == f_ret)//成功返回0
    {
        error_printf("share_para ftruncate error,%s:%d\n",__FILE__,__LINE__);
    }
#if test==0
    para = mmap(NULL,sizeof(struct para_s) * PARA_NUM,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    if(para == MAP_FAILED)
    {
        error_printf("share_para,mmap error,%s:%d\n",__FILE__,__LINE__);

        ret = -1;
        return ret;
    }
    if(need_init == 1)
    {
        memset(para,-1,sizeof(struct para_s) * PARA_NUM);
    }
#endif
    close(fd);
    return ret;
}




int shm_init(void)
{
    int ret;

    /*
    ********************************************************运动共享内存
    运动状态
    运动设置(就是参数配置)
    运动内部数据
    */
    ret = share_motion_status(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_motion_status ok\n");

    ret = share_motion_internal(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_motion_internal ok\n");

    /*
    ********************************************************PLC共享内存
    */
    ret = share_plc_shm(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_plc_shm ok\n");


    /*
    ********************************************************解释器共享内存
    解释器状态
    */
    ret = share_decode_status(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_decode_status ok\n");

    /*
    ********************************************************公用共享内存
    任务->运动命令队列
    报警队列
    警告队列

    */
    ret = share_command(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_command ok\n");

    ret = share_motion_err(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_motion_err ok\n");

    ret= share_warn(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_warn ok\n");

    ret= share_para(0);
    if(-1 == ret)
    {
        return -1;
    }
    usleep(1000);
    my_print("share_para ok\n");

    return 1;

}



