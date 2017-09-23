#ifndef DaoQueue_h
#define DaoQueue_h

//ϵͳ�������
//���ϵͳ�Ƿ��볣�����
#ifndef HAS_LIBS

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <math.h>
#include <fcntl.h>
#include <pthread.h>

#define HAS_LIBS
#endif

#ifndef HAS_DAOLIBS
/*����DaoLibs��*/
#include "../DaoLibs/DaoLibs.h"
#define HAS_DAOLIBS
#endif // HAS_DAOLIBS

//�Զ������


//�����(��Ķ����������˶��ڳ�����Ķ��Լ���⣬�ڱ���ʱ������Զ��滻)


//����Ҫ���ǵ����������ʹ�ã����Բ����ú�򻯽ṹ
//#define MBlock struct DaoMPLMBlock
//#define Flag struct struct DaoMPLFlag

//������ֽṹ�塢�����塢ö�ٵ�
//���нṹ
struct DaoQueueDate {
    char *data;//�����е�����ָ����ڴ��ַ
    int dataSize;//���ݴ�С
};

//���нṹ
struct DaoQueue {
    int index;//����
    struct DaoQueueDate *data;//�����е�����ָ���DaoQueueDate�ڴ��ַ
    int depth;//�����������ȣ��������е������ʶ�����п����Զ����ʶ��
    int updateStatus;//sqlite����queue�Ƿ�ɹ������״̬.ֵΪ1��-1
    int totalSize;//���д�С
    /*��Ϊ��������*/
    struct DaoQueueFlag *queueFlag;//���нṹ
};

//���нṹ
struct DaoQueueFlag {
    int num;//��������
    //��������λ��
    int nowSetIndex;
    int nowGetIndex;
    int maxIndex;
    struct DaoQueue **startQueue;//��ʼ����
};

/*
queueFlag:���й���ṹ
queueNum:��������
queues:��������
queueDates����������
*/
int dao_queue_init(struct DaoQueueFlag *queueFlag, int queueNum, struct DaoQueue **queues, struct DaoQueueDate **queueDates);

/*
�����ڴ�صĶ���ע��
queueFlag:���й���ṹ
*/
void dao_queue_exit(struct DaoQueueFlag *queueFlag);

/*
���ö���
queueFlag:���й���ṹ
*/
int dao_queue_reset(struct DaoQueueFlag *queueFlag);

/*
�̰߳�ȫѹ������
queueFlag:���б�ʶ��
depth:���
obj:�����õ����ݵ��������ַ���
*/
int dao_queue_set(struct DaoQueueFlag *queueFlag, int depth, char *obj);

/*
�̰߳�ȫȡ������
queueFlag:���б�ʶ��
queue:��ȡ���Ķ�������
*/
int dao_queue_get(struct DaoQueueFlag *queueFlag, struct DaoQueue **nowQueue);

/*
���±�ѹ������
queueFlag:���б�ʶ��
index:��������
depth:���
obj:�����õ����ݵ��������ַ���
*/
int dao_queue_set_index(struct DaoQueueFlag *queueFlag, int index, int depth, char *obj);

/*
���±�ȡ������
queueFlag:���б�ʶ��
index:��������
queue:��ȡ���Ķ�������
*/
int dao_queue_get_index(struct DaoQueueFlag *queueFlag, int index, struct DaoQueue **nowQueue);
#endif
