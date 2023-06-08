#include <MachineTrace.h>


MachineTrace::MachineTrace()
{
    // 定义10000个值为int类型最小值的坐标节点
    trace.start = 0;
    trace.end = 0;
    int i = 0;
    while(i<200){
        coordinate tmp ;
        tmp.x = i;
        tmp.y = i;
        this->addPoint(tmp);
        i++;
    }
}

void MachineTrace::getSharedMemory()
{
    // 定义一个共享内存对象
    QSharedMemory sharedMemory;
    // 设置一个key标识共享内存
    sharedMemory.setKey("my_shared_memory");
    // 将共享内存与主进程绑定
    if (!sharedMemory.attach()) {
        qDebug() << "Unable to attach to shared memory segment.";
        return;
    }
    // 将共享内存上锁，并进行成功检测
    if (!sharedMemory.lock()) {
        qDebug() << "Unable to lock to shared memory segment.";
        return;
    }
    // 获取一个指向共享内存段中数据的指针
    void *data = sharedMemory.data();
    if (data) {
        // 转换共享内存内数据的指针类型
        QPair<int, int> *coordinate = static_cast<QPair<int, int> *>(data);
        // 从pair中读取坐标值
        int x = coordinate->first;
        int y = coordinate->second;
        // *********************待完成**************************
    }
    // 读完后对共享内存进行解锁
    sharedMemory.unlock();
}

const Trace&  MachineTrace::getTrace()
{
    return trace;
}

bool MachineTrace::addPoint(const coordinate &p)
{
    //先将末尾指针加1（循环数组满了的话覆盖）
    trace.end = (trace.end+1) % 10000;
    // 在末尾增加新节点
    trace.cord[trace.end].x = p.x;
    trace.cord[trace.end].y = p.y;
    //循环数组已经满了
    if(trace.end == trace.start){
        trace.start = (trace.start+1) % 10000;
    }
    // start = end+1为数组满了的标志
    return true;
}












