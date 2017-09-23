#ifndef DaoLibs_h
#define DaoLibs_h

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

//�Զ������

//�����(��Ķ����������˶��ڳ�����Ķ��Լ���⣬�ڱ���ʱ������Զ��滻)
#define DAOTRUE 1
#define DAOFALSE 0
#define DAOSUCCESS 0
#define DAOFAILURE -1

//������ֽṹ�塢�����塢ö�ٵ�
//�ڴ����ṹ
struct MemLink {
    int num;//�ڴ�������
    int index;//�ڴ�������
    struct MemLinkNode *memLinkNodes;//�ڴ����ڵ�
};

//�ڴ����ڵ�
struct MemLinkNode {
    void *p;//����ı���ָ��
};

/*
���ã��ڴ�����ʼ��
memLinkFlag:�ڴ���
num:�ڴ����ڵ�����
*/
int dao_memory_link_init(struct MemLink *memLinkFlag, int num);

/*
���ã��ڴ������ӽڵ�
memLinkFlag:�ڴ���
p:�������ڴ�ָ��
*/
void dao_memory_link_add(struct MemLink *memLinkFlag, void *p);

/*
���ã��ڴ����˳�
memLinkFlag:�ڴ���
*/
void dao_memory_link_exit(struct MemLink *memLinkFlag);

#endif
