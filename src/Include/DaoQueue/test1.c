#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <pcre.h>

/*struct pregAllStr{
        int num;
        struct pregStr ovector[256];
};*/
struct pregStr {
    int num;
    int ovector[16];
};

int preg_match(char *pattern, char *srcStr, struct pregStr *ret, int getWhich) {
    //�����ֱ���������ʽ�� Ҫƥ����ַ����� Ҫ���ص�������ƫ���㷨
    pcre  *re;
    int matchNum=512;
    int i;
    struct pregStr matchs[matchNum];
    //��ʼ��num=0
    for(i=0; i<matchNum; i++) {
        matchs[i].num=0;
    }

    const char *error;
    int oveccount=30;
    int  erroffset;
    int  ovector[oveccount];
    int p, q;
    int  rc;
    int exec_offset=0;
    //char  src [] = "111 <title>Hello World</title> 222<title>PCRE</title>";   // Ҫ������ƥ����ַ���
    //char  pattern [] = "<title>(.*)</(tit)le>";    // ��Ҫ��������ַ�����ʽ��������ʽ
    //printf("String : %s\n", srcStr);
    //printf("Pattern: \"%s\"\n", pattern);
    re = pcre_compile(pattern,     // pattern, �����������Ҫ��������ַ�����ʽ��������ʽ
                      0,             // options, �������������ָ������ʱ��һЩѡ��
                      &error,         // errptr, ����������������������Ϣ
                      &erroffset,     // erroffset, ���������pattern�г���λ�õ�ƫ����
                      NULL);         // tableptr, �������������ָ���ַ���һ�������NULL
    // ����ֵ��������õ�������ʽ��pcre�ڲ���ʾ�ṹ
    if (re == NULL) {
        //�������ʧ�ܣ����ش�����Ϣ
        //printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
        pcre_free(re);
        return 0;
    }
    //��ʼ����ά����
    p=0;
    do {
        rc = pcre_exec(re,    // code, �����������pcre_compile����õ�������ṹ��ָ��
                       NULL,  // extra, ���������������pcre_exec��һЩ�����������Ϣ�Ľṹ��ָ��
                       srcStr,   // subject, ���������Ҫ������ƥ����ַ���
                       strlen(srcStr),  // length, ���������Ҫ������ƥ����ַ�����ָ��
                       exec_offset,     // startoffset, �������������ָ��subject��ʲôλ�ÿ�ʼ��ƥ���ƫ����
                       0,     // options, �������������ָ��ƥ������е�һЩѡ��
                       ovector,        // ovector, �����������������ƥ��λ��ƫ����������
                       oveccount);    // ovecsize, ��������� ��������ƥ��λ��ƫ���������������С
        // ����ֵ��ƥ��ɹ����طǸ�����û��ƥ�䷵�ظ���
        if (rc < 0) {
            //���û��ƥ�䣬���ش�����Ϣ
            //if (rc == PCRE_ERROR_NOMATCH) printf("Sorry, no match ...\n");
            //else printf("Matching error %d\n", rc);
            //pcre_free(re);
            //printf("HelloWorld\n");
            break;
            //return 0;
        }
        //printf("\nOK, has matched ...\n\n");   //û�г����Ѿ�ƥ��
        matchs[p].num=rc;
        printf("%d:%d\n", p, matchs[p].num);
        for (i = 0, q=0; i < rc; i++) {
            //�ֱ�ȡ��������� $0��������ʽ $1��һ��()
            matchs[p].ovector[q]=ovector[2*i];
            q++;
            matchs[p].ovector[q]=ovector[2*i+1];
            q++;
        }
        exec_offset=ovector[i];
        //printf("%d\n", matchs[p].num);
        p++;
    } while(rc>0);

    pcre_free(re);   // ����������ʽre �ͷ��ڴ�
    //���ؽ������
    //�ó�������������һ�������и�ֵ
    *ret=matchs[getWhich];

    return 0;
}

int main() {
    struct pregStr ovector;
    //��������malloc��malloc�Ͼ�Ч�ʵȲ���
    //ovector=(char *)malloc(sizeof(char)*100);
    int i, j;
    char  srcStr[] = "111 <title>Hello World</title> 222<title>PCRE</title>";   // Ҫ������ƥ����ַ���
    char  pattern[] = "<title>(.*?)</(tit)le>";    // ��Ҫ��������ַ�����ʽ��������ʽ
    int getWhich=0;

    preg_match(pattern, srcStr, &ovector, getWhich);

    //printf("%d\n", ovector.num);
    for(i=0; i<ovector.num; i++) {
        char *substring_start = srcStr + ovector.ovector[2*i];
        int substring_length =ovector.ovector[2*i+1] - ovector.ovector[2*i];
        printf("$%2d: %.*s\n", j, substring_length, substring_start);
    }


    //free(ovector);
    return 0;
}

