#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
int main (int argc, const char * argv[])
{
    // ����JSON Object
    cJSON *root = cJSON_CreateObject();
    // ����ڵ㣨��ֵ�ԣ����ڵ�����Ϊvalue���ڵ�ֵΪ123.4
    cJSON_AddNumberToObject(root,"value",123.4);
    // ��ӡJSON���ݰ�
    char *out = cJSON_Print(root);
    printf("%s\n",out);
    // �ͷ��ڴ�
    cJSON_Delete(root);
    free(out);
    return 0;
}
