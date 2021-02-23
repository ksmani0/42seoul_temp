#include "libft.h"

typedef struct  s_flt
{
    char        d_bit[129];//1+128
    int         d_len;
    char        m_bit[179];//52+127
    int         m_len;
    char        m_num[11];//integer length + 1
    int         i_mod;
    char        sign;
}               t_sflt;

typedef union   u_flt
{
    float       value;
    struct
    {
        t_uint  m : 23;
        t_uint  e : 8;
        t_uint  s : 1;
    }           s_uint;
}               t_uflt;

char            multiply_two(char *s)
{
    int i;
    int up;
    int tmp;

    i = 0;
    up = 0;
    while (s[i] != 0 && i < 179)//문자열로 곱하기 계산
    {
        if ((tmp = (s[i] - '0') * 2 + up) > 9)
            up = 1;
        else
            up = 0;
        s[i++] = (tmp % 10) + '0';
    }
    if (s[0] == '0')
    {//곱하기 결과값의 마지막 자릿수가 0이면 없애줘야 함
        i = -1;
        while (s[++i] != 0)
            s[i] = s[i + 1];
    }
    return up == 1 ? '1' : '0';
}

float          bit_to_float(t_sflt *f, int i, int j)
{
    t_uflt  uf;
    int     exp;

    ft_bzero(&uf, sizeof(t_uflt));
    if (f->d_len == 1 && f->d_bit[0] == '0')
    {//정수 비트가 0이면 2^?의 ?는 소수 비트에서 찾기
        while (f->m_bit[i] != '1' && f->m_bit[i] != 0)
            i++;
        exp = (i + 1) * -1;
    }
    else
        exp = f->d_len - 1;
    uf.s_uint.s = f->sign == '-' ? 1 : 0;
    uf.s_uint.e = exp + 127;
    i = exp;
    while (i > 0 && j-- >= 0)//정수 비트에서 가져올 게 있을 때
        uf.s_uint.m += (f->d_bit[--i] & 1) << j;
    i = i < 0 ? i * -1 : i;
    while (f->m_bit[i] != 0 && j-- >= 0)
        uf.s_uint.m += (f->m_bit[i++] & 1) << j;
    return (uf.value);
}

float           make_f_bit(long div, t_sflt *f)
{
    f->d_bit[0] = '0';
    if (div < 0 && (f->sign = '-'))
        div *= -1;
    while (div != 0 && f->d_len < 129)
    {//정수 부분 비트 저장
        f->d_bit[f->d_len++] = div % 2 + '0';//0번째 색인이 제일 큰 값
        div /= 2;
    }
    f->d_len = f->d_len == 0 ? 1 : f->d_len;
    f->m_bit[0] = '0';
    while (f->m_num[0] != 0 && f->m_len < 179)//소수에 2씩 곱하며 비트 패턴 뽑기
        f->m_bit[f->m_len++] = multiply_two(f->m_num);
    f->m_len = f->m_len == 0 ? 1 : f->m_len;
    return (bit_to_float(f, 0, 23));
}

float			ft_atof(char *s, char *p)
{
    float   f;
	long    div;
	t_sflt	flt;

	div = ft_atoi(s);//?.? vs ? or ?. or .?
	while (*p != '.' && *p != 0)
		p++;
	if (*p == 0 || s == p || *(p + 1) < '0' || *(p + 1) > '9')
		return *p == 0 ? (float)div : -0.0;//? or . or .nf
	ft_bzero(&flt, sizeof(t_sflt));
	p++;
	while (*p >= '0' && *p <= '9')//소수 부분 10진수를 아스키 문자로 바꿔 저장
		flt.m_num[flt.i_mod++] = *p++;
	ft_strrev(flt.m_num);
    if (flt.i_mod == 1 && flt.m_num[0] == '0')//-0.0 or 0.0 or ?.0
        return (*s == '-' && div == 0 ? -0.0 : (float)div);
    f = make_f_bit(div, &flt);
	return (f);
}
