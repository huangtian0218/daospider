#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char* server_groups[]= {"embedded","server","this_program_server",(char*)NULL};
int main() {

    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sqlcmd[200];
    int t,r;
    mysql_library_init(0,NULL,server_groups);//��ʼ��MYSQL���ݿ�
    mysql_init(&mysql);//��ʼ��MYSQL��ʶ������������
    if(!mysql_real_connect(&mysql,"localhost","root","159126","tjuhe",0,NULL,0)) {
        fprintf(stderr,"error:%s\n",mysql_error(&mysql));

    } else {
        puts("success");
//���������ݿ��в���һ����¼
        //sprintf(sqlcmd,"%s","insert into test (id, name, value) values (NULL, 'TEST', 'HAHA')");
        //mysql_query(&mysql,sqlcmd);
        sprintf(sqlcmd,"%s","select * from test");
        t=mysql_real_query(&mysql,sqlcmd,(unsigned int)strlen(sqlcmd));

        if(t) {
            printf("faliure%s\n",mysql_error(&mysql));
        } else {
            res=mysql_store_result(&mysql);//���ز�ѯ��ȫ�������
            while(row=mysql_fetch_row(res)) { //mysql_fetch_rowȡ���������һ��
                for(t=0; t<mysql_num_fields(res); t++) { //��������е�����
                    printf("%s\t",row[t]);
                }
                printf("\n");
            }

            mysql_free_result(res);//������ϣ���ѯ�����
        }
        mysql_close(&mysql);//�ر����ݿ�����

    }
    mysql_library_end();//�ر�MySQL��

    return EXIT_SUCCESS;
}
