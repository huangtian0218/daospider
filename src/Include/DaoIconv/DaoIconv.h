#ifndef DaoIconv_h
#define DaoIconv_h

//ϵͳ�������
//���ϵͳ�Ƿ��볣�����
#ifndef HAS_LIBS

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
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
//#include <pcre.h>
//#include <sqlite3.h>
//#include <iconv.h>
//#include <mysql.h>
#include <math.h>
#include <fcntl.h>

#define HAS_LIBS
#endif

#ifndef HAS_DAOLIBS
/*����DaoLibs��*/
#include "../DaoLibs/DaoLibs.h"
#define HAS_DAOLIBS
#endif // HAS_DAOLIBS

#ifndef HAS_ICONV
/*����iconv��*/
#include <iconv.h>
#define HAS_ICONV
#endif // HAS_ICONV
//�Զ������


//�����(��Ķ����������˶��ڳ�����Ķ��Լ���⣬�ڱ���ʱ������Զ��滻)


//����Ҫ���ǵ����������ʹ�ã����Բ����ú�򻯽ṹ
//#define MBlock struct DaoMPLMBlock
//#define Flag struct struct DaoMPLFlag

//������ֽṹ�塢�����塢ö�ٵ�


/*
���ã�����ת����Ҫ����
from_charset:���ڵı���
to_charset��ת��Ϊ�ı���
inbuf�������ַ���
inlen:inbuf�л���Ҫ����ת�����ֽ���
outbuf������ַ���
outlen:outbuf�л����Դ��ת����ֽ�����Ҳ����outbuf�е�ʣ��ռ�
*/
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/*
���ã�����ת��utf8��gbk
inbuf�������ַ���
inlen:inbuf�л���Ҫ����ת�����ֽ���
outbuf������ַ���
outlen:outbuf�л����Դ��ת����ֽ�����Ҳ����outbuf�е�ʣ��ռ�
*/
int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/*
���ã�����ת��gbk��utf8
inbuf�������ַ���
inlen:inbuf�л���Ҫ����ת�����ֽ���
outbuf������ַ���
outlen:outbuf�л����Դ��ת����ֽ�����Ҳ����outbuf�е�ʣ��ռ�
*/
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
#endif
