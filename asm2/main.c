/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoukim </var/mail/kyoukim>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:53:48 by kyoukim           #+#    #+#             */
/*   Updated: 2020/12/09 18:21:54 by kyoukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

#define BUFFER_SIZE 10

void	test_strlen(void)
{
	printf("\n***************TEST ft_strlen****************\n\n");
		
	char *s1 = "";
	char *s2 = "tonykim";
	char *s3 = "abc123~!@&*()_+";
	char *s4 = "     ";

	printf("//argument:  \n");
	printf("strlen   :%zu\n", strlen(s1));
	printf("ft_strlen:%zu\n", ft_strlen(s1));
	printf("\n//argument: tonykim\n");
	printf("strlen   :%zu\n", strlen(s2));
	printf("ft_strlen:%zu\n", ft_strlen(s2));
	printf("\n//argument: abc123~!@&*()_+\n");
	printf("strlen   :%zu\n", strlen(s3));
	printf("ft_strlen:%zu\n", ft_strlen(s3));
	printf("\n//argument:      \n");
	printf("strlen   :%zu\n", strlen(s4));
	printf("ft_strlen:%zu\n", ft_strlen(s4));
}

void	test_strcpy(void)
{
	printf("\n****************TEST ft_strcpy*****************\n\n");
	
	char s1[1] = "";
	char s2[8] = "tonykim";
	char s3[14] = "sdf234903tjsd";
	char s4[6] = "     ";
	char dest[20];
	
	printf("//string to copy: \n");
	printf("strcpy   :%s\n", strcpy(dest, s1));
	printf("ft_strcpy:%s\n", ft_strcpy(dest, s1));
	printf("\n//string to copy: tonykim\n");
	printf("strcpy   :%s\n", strcpy(dest, s2));
	printf("ft_strcpy:%s\n", ft_strcpy(dest, s2));
	printf("\n//string to copy: sdf234903tjsd\n");
	printf("strcpy   :%s\n", strcpy(dest, s3));
	printf("ft_strcpy:%s\n", ft_strcpy(dest, s3));
	printf("\n//string to copy:      \n");
	printf("strcpy   :%s\n", strcpy(dest, s4));
	printf("ft_strcpy:%s\n", ft_strcpy(dest, s4));
}

void	test_strdup(void)
{
	printf("\n****************TEST ft_strdup******************\n\n");

	char s1[1] = "";
	char s2[8] = "tonykim";
	char s3[14] = "sdf234903tjsd";
	char s4[6] = "     ";

	printf("//string to duplicate: \n");
	printf("strdup   :%s\n", strdup(s1));	
	printf("ft_strdup:%s\n", ft_strdup(s1));	
	printf("\n//string to duplicate: tonykim\n");
	printf("strdup   :%s\n", strdup(s2));	
	printf("ft_strdup:%s\n", ft_strdup(s2));	
	printf("\n//string to duplicate: sdf234903tjsd\n");
	printf("strdup   :%s\n", strdup(s3));	
	printf("ft_strdup:%s\n", ft_strdup(s3));	
	printf("\n//string to duplicate:      \n");
	printf("strdup   :%s\n", strdup(s4));	
	printf("ft_strdup:%s\n", ft_strdup(s4));	
}

void	test_strcmp(void)
{
	printf("\n***************TEST ft_strcmp*****************\n\n");
	
	char s1[6] = "hello";
	char s2[4] = "hel";
	char s3[10] = "@(1))~!3s";
	char s4[1] = "";
	
	printf("//compare [hello], [hello]\n");
	printf("strcmp   :%d\n", strcmp(s1, s1));
	printf("ft_strcmp:%d\n", ft_strcmp(s1, s1));
	printf("\n//compare [hello], [hel]\n");
	printf("strcmp   :%d\n", strcmp(s1, s2));
	printf("ft_strcmp:%d\n", ft_strcmp(s1, s2));
	printf("\n//compare [hel], [hello]\n");
	printf("strcmp   :%d\n", strcmp(s2, s1));
	printf("ft_strcmp:%d\n", ft_strcmp(s2, s1));
	printf("\n//compare [hello], [@(1))~!3s]\n");
	printf("strcmp   :%d\n", strcmp(s1, s3));
	printf("ft_strcmp:%d\n", ft_strcmp(s1, s3));
	printf("\n//compare [], [@(1))~!3s]\n");
	printf("strcmp   :%d\n", strcmp(s4, s3));
	printf("ft_strcmp:%d\n", ft_strcmp(s4, s3));
	printf("\n//compare [], []\n");
	printf("strcmp   :%d\n", strcmp(s4, s4));
	printf("ft_strcmp:%d\n", ft_strcmp(s4, s4));
}

void	test_write(void)
{
	printf("\n****************TEST ft_write*****************\n\n");
	
	char s1[8] = "tonykim";

	int	len = strlen(s1);

	errno = 0;
	printf("//write(1, \"tonykim\", 7)\n");
	printf("write   :%zd    errno:%d\n", write(1, s1, 7), errno);
	errno = 0;
	printf("ft_write:%zd    errno:%d\n", ft_write(1, s1, 7), errno);
	errno = 0;
	printf("\n//write(-1, \"tonykim\", strlen(\"tonykim\"))\n");
	printf("write   :%zd    errno:%d\n", write(-1, s1, len), errno);
	errno = 0;
	printf("ft_write:%zd    errno:%d\n", ft_write(-1, s1, len), errno);
	errno = 0;
	printf("\n//write(2, \"tonykim\", strlen(\"tonykim\"))\n");
	printf("write   :%zd    errno:%d\n", write(2, s1, len), errno);
	errno = 0;
	printf("ft_write:%zd    errno:%d\n", ft_write(2, s1, len), errno);
	errno = 0;
}

void	test_read(void)
{
	printf("\n****************TEST ft_read*****************\n\n");
	
	int fd1;
	int	fd2;

	char *d1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	char *d2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	
	printf("//read(fd, buf, size) : NORMAL CASE\n");
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	printf("read   :%zd\n", read(fd1, d1, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd1, errno);
	printf("ft_read:%zd\n", ft_read(fd2, d2, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);

	printf("\n//read(-1, buf, size) : ERROR CASE(open fail)\n");
	fd1 = open("sdflh", O_RDONLY);
	fd2 = open("sdflh", O_RDONLY);
	printf("read   :%zd\n", read(fd1, d1, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd1, errno);
	errno = 0;
	printf("ft_read:%zd\n", ft_read(fd2, d2, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd2, errno);
	errno = 0;
	printf("\n");
	close(fd1);
	close(fd2);

	printf("\n//read(fd, NULL, size) : ERROR CASE(buffer is NULL)\n");
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	printf("read   :%zd\n", read(fd1, NULL, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd1, errno);
	printf("ft_read:%zd\n", ft_read(fd2, NULL, BUFFER_SIZE));
	printf("fd: %d    errno  :%d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);
	printf("\n//read(fd, buf, -100) : ERROR CASE(size is negative)\n");
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	printf("read   :%zd\n", read(fd1, d1, -3));
	printf("fd: %d    errno  :%d\n", fd1, errno);
	printf("ft_read:%zd\n", ft_read(fd2, d2, -3));
	printf("fd: %d    errno  :%d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);
}

int main(void)
{
	test_strlen();
	test_strcpy();
	test_strdup();
	test_strcmp();
	test_read();
	test_write();
}
