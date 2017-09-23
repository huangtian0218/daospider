#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
// ��������JSON���ݰ�
char text[] = "{\"timestamp\":\"2013-11-19T08:50:11\",\"value\":1}";
int main (int argc, const char * argv[]) {
    cJSON *json , *json_value , *json_timestamp;
    // �������ݰ�
    json = cJSON_Parse(text);
    if (!json) {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
    } else {
        // ��������ֵ
        json_value = cJSON_GetObjectItem( json , "value");
        if( json_value->type == cJSON_Number ) {
            // ��valueint�л�ý��
            printf("value:%d\r\n",json_value->valueint);
        }
        // ����ʱ���
        json_timestamp = cJSON_GetObjectItem( json , "timestamp");
        if( json_timestamp->type == cJSON_String ) {
            // valuestring�л�ý��
            printf("%s\r\n",json_timestamp->valuestring);
        }
        // �ͷ��ڴ�ռ�
        cJSON_Delete(json);
    }
    return 0;
}
