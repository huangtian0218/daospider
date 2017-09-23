#include "DaoLibs.h"

/*
���ã��ڴ�����ʼ��
memLinkFlag:�ڴ���
num:�ڴ����ڵ�����
*/
int dao_memory_link_init(struct MemLink *memLinkFlag, int num){
    if(num<1){
        return DAOFAILURE;
    }
    //�ڴ�������
    struct MemLinkNode *memLinkNodes=(struct MemLinkNode *)malloc(sizeof(struct MemLinkNode)*num);
    if(memLinkNodes==NULL){
        return DAOFAILURE;
    }
    memset(memLinkNodes, 0, sizeof(struct MemLinkNode)*num);
    //�ڴ�����ֵ
    memLinkFlag->memLinkNodes=memLinkNodes;
    memLinkFlag->num=num;
    memLinkFlag->index=0;

    return DAOSUCCESS;
}

/*
���ã��ڴ������ӽڵ�
memLinkFlag:�ڴ���
p:�������ڴ�ָ��
*/
void dao_memory_link_add(struct MemLink *memLinkFlag, void *p){
    struct MemLinkNode *nowMemLinkNode;//��ʱ���ڴ����ڵ�

    //�洢�Ŀռ�
    nowMemLinkNode=memLinkFlag->memLinkNodes+memLinkFlag->index;
    //��ֵ
    nowMemLinkNode->p=p;

    //�����ڴ�������
    memLinkFlag->index=memLinkFlag->index+1;
}

/*
���ã��ڴ����˳�
memLinkFlag:�ڴ���
*/
void dao_memory_link_exit(struct MemLink *memLinkFlag){
    int i;
    struct MemLinkNode *nowMemLinkNode;//��ʱ���ڴ����ڵ�
    for(i=0; i<memLinkFlag->index; i++){
        nowMemLinkNode=memLinkFlag->memLinkNodes+i;
        free(nowMemLinkNode->p);
    }
    free(memLinkFlag->memLinkNodes);
}
