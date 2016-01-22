/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:30:56 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:14:30 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>


// ---------------CREATING THE CHOPED--------

int		is_flag(const char *format, int *k)
{
	int i;

	i = *k;
	if (ft_strchr(FLAGS, format[i]) != NULL)
		return (1);
	return (0);
}

int		is_specifier(const char *format, int *k)
{
	int i;

	i = *k;
	if (ft_strchr(SPECIFIERS, format[i]) != NULL)
		return (1);
	return (0);
}

char	*chop_format(const char *format, unsigned long int *i)
{
	char	*choped;
	int		j;
	int		k;

	j = 0;
	k = *i;
	k++;
	choped = (char*)malloc(sizeof(choped) * ft_strlen(format));
	while (format[k])
	{
		if (is_flag(format, &k) == 0 && is_specifier(format, &k) == 0)
			return (choped);
		else if (is_specifier(format, &k))
		{
			choped[j++] = format[k];
			break;
		}
		else if (is_flag(format, &k))
			choped[j++] = format[k];
		k++;
	}
	choped[j] = '\0';
	return (choped);
}

//--------------PROCESSING FLAGS----------------

void	init_flags2(t_mod *flag)
{
	flag->chr = '0';
	flag->result = ft_memalloc(1000);
	flag->wstr = (wchar_t*)malloc(sizeof(wchar_t) * 200);
	flag->choped = ft_memalloc(20);
	flag->precizie = ft_memalloc(200);
	flag->lungime = ft_memalloc(200);
}

void	init_flags(t_mod *flag)
{
	flag->dot_mod = 0;
	flag->h_mod = 0;
	flag->hh_mod = 0;
	flag->l_mod = 0;
	flag->ll_mod = 0;
	flag->z_mod = 0;
	flag->j_mod = 0;
	flag->hash_mod = 0;
	flag->minus_mod = 0;
	flag->zero_mod = 0;
	flag->plus_mod = 0;
	flag->space_mod = 0;
	flag->width = 0;
	flag->specifier = 48;
	flag->precision = 0;
	flag->procent = 0;
	flag->wild_width = 0;
	flag->wild_precision = 0;
	flag->wld_psize = 0;
	flag->wld_wsize = 0;
	init_flags2(flag);
}

void	process_precision(char	*choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '.' && ft_isdigit(choped[i + 1]))
			data->precision = 1;
		else if (choped[i] > '0' && choped[i] <= '9')
			data->width = 1;
		i++;
	}
}

//---------------PROCESSING MODS----------------

void	process_hhll_mods(char	*choped, t_mod	*data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == 'h' && choped[i + 1] == 'h')
		{
			data->hh_mod = 1;
			data->h_mod = 0;
		}
		else if (choped[i] == 'l' && choped[i + 1] == 'l')
		{
			data->ll_mod = 1;
			data->l_mod = 0;
		}
		i++;
	}
}

void	process_mods(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == 'h' && choped[i + 1] != 'h')
			data->h_mod = 1;
		else if (choped[i] == 'l' && choped[i + 1] != 'l')
			data->l_mod = 1;
		else if (choped[i] == 'j')
			data->j_mod = 1;
		else if (choped[i] == 'z')
			data->z_mod = 1;
		i++;
	}
	process_hhll_mods(choped, data);
}

int		is_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_double_mod(char	*choped, int *i)
{
	int k;

	k = *i;
	if (choped[k] == 'h' && choped[k + 1] == 'h')
		return (1);
	else if (choped[k] == 'l' && choped[k + 1] == 'l')
		return (1);
	return (0);
}

//--------------VALIDATING MODS------------

int		validate_mod(char *choped)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (!is_double_mod(choped, &i) && is_mod(choped[i]) && \
				ft_strchr(SPECIFIERS, choped[i + 1]) == NULL)
			return (-1);
		else if (is_double_mod(choped, &i) && \
				ft_strchr(SPECIFIERS, choped[i + 2]) == NULL)
			return (-1);
		i++;
	}
	return (1);
}

// ----------------PROCESSING SPECIFIERS--------------------------

void	process_specifiers2(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == 'S')
			data->specifier = 'S';
		else if (choped[i] == 's')
			data->specifier = 's';
		else if (choped[i] == 'C')
			data->specifier = 'C';
		else if (choped[i] == 'c')
			data->specifier = 'c';
		else if (choped[i] == 'p')
			data->specifier = 'p';
		else if (choped[i] == 'X')
			data->specifier = 'X';
		else if (choped[i] == 'x')	
			data->specifier = 'x';
		else if (choped[i] == 'f')
			data->specifier = 'f';
		else if (choped[i] == 'F')
			data->specifier = 'F';
		i++;
	}
}

void	process_specifiers(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == 'd')
			data->specifier = 'd';
		else if (choped[i] == 'D')
			data->specifier = 'D';
		else if (choped[i] == 'i')
			data->specifier = 'i';
		else if (choped[i] == 'o')
			data->specifier = 'o';
		else if (choped[i] == 'O')
			data->specifier = 'O';
		else if (choped[i] == 'u')
			data->specifier = 'u';
		else if (choped[i] == 'U')
			data->specifier = 'U';
		i++;
	}
	process_specifiers2(choped, data);
}

void	process_zero_mod(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '0' && !ft_isdigit(choped[i - 1]) && \
				data->minus_mod == 0 && data->precision == 0)
			data->zero_mod = 1;
		i++;
	}
}

void	process_dot_mod(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '.' && (!ft_isdigit(choped[i + 1]) || \
					choped[i + 1] == '0') && choped[i + 1] != '*')
		{
			data->dot_mod = 1;
		}
		i++;
	}
}

void	process_wildcard(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '*' && choped[i - 1] != '.')
			data->wild_width = 1;
		else if (choped[i] == '*' && choped[i - 1] == '.')
			data->wild_precision = 1;
		i++;
	}
}

//---------HERE IS THE PROCESSING CORE----------

void	process_flags(char *choped, t_mod *data)
{
	int i;

	i = -1;
	init_flags(data);
	while (choped[++i])
	{
		if (choped[i] == '#')
			data->hash_mod = 1;
		else if (choped[i] == '-')
			data->minus_mod = 1;
		else if (choped[i] == '+')
			data->plus_mod = 1;
		else if (choped[i] == '%')
			data->procent = 1;
		else if (choped[i] == ' ')
			data->space_mod = 1;
	}
	if (validate_mod(choped) > 0)
		process_mods(choped, data);
	data->choped = choped;
	process_precision(choped, data);
	process_specifiers(choped, data);
	process_dot_mod(choped, data);
	process_zero_mod(choped, data);
	process_wildcard(choped, data);
}

//-----------DEALING WITH THE SIZE (WIDTH AND PRECISION)--------------

int		get_precision(char *choped)
{
	int		i;
	char	*precision;
	int		k;

	i = 0;
	k = 0;
	precision = (char*)malloc(sizeof(precision) * ft_strlen(choped));
	while (choped[i])
	{
		if (choped[i] == '.')
		{
			i++;
			while (choped[i] >= '0' && choped[i] <= '9')
				precision[k++] = choped[i++];	
		}
		i++;
	}
	precision[k] = '\0';
	return (ft_atoi(precision));
}

int		get_width(char *choped)
{
	int		i;
	char	*width;
	int		k;
	int		ok;

	i = 0;
	k = 0;
	ok = 0;
	width = ft_memalloc(ft_strlen(choped));
	while (choped[i])
	{
		if (choped[i] == '.')
			ok = 1;
		if (choped[i] > '0' && choped[i] <= '9' && ok == 0)
		{
			while (ft_isdigit(choped[i]))
				width[k++] = choped[i++];
			break;
		}
		i++;
	}
	return (ft_atoi(width));
}

//----------------------------------UNSIGNED UTOA BASE--------------

char	*ft_utoa_base(unsigned int n, int base, char *q)
{
	char *str;
	int i;

	str = ft_strnew(32);
	i = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[i++] = q[n % base];
		n /= base;
	}
	return (ft_strrev(str));
}

char	*ft_lutoa_base(unsigned long n, int base, char *q)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	if (n == 0)
		str[0] = '0';	
	while (n)
	{
		str[i++] = q[n % base];
		n /= base;
	}
	return (ft_strrev(str));
}


//--------------FINDING OUT THE BASE AND SPECIFIER TYPE-----------------

int		base(t_mod *data)
{
	int		base;

	base = 0;
	if (data->specifier == 'o' || data->specifier == 'O')
		base = 8;
	else if (data->specifier == 'x' || data->specifier == 'X')
		base = 16;
	else
		base = 10;
	return (base);
}

int		is_uox(t_mod *data)
{
	if (data->specifier == 'u')
		return (1);
	else if (data->specifier == 'o')
		return (1);
	else if (data->specifier == 'x')
		return (1);
	return (0);
}

//----------DEALING WITH MODS------

void	hh_case(t_mod *data, va_list *arg)
{
	char			decimal;
	unsigned char	other_base;
	char			*bq;

	bq = "0123456789ABCDEF";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa_base(decimal, base(data));	
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_itoa_base(other_base, base(data));
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), bq);
	}
}

void	h_case(t_mod *data, va_list *arg)
{
	short 					decimal;
	unsigned short			other_base;
	char					*bq;

	bq = "0123456789ABCDEF";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa_base(decimal, base(data));
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_itoa_base(other_base, base(data));
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), bq);
	}
}

void	l_case_for_strings(t_mod *data, va_list *arg)
{
	if (data->specifier == 'c')
		data->wstr[0] = va_arg(*arg, wint_t);
	else if (data->specifier == 's')
		data->wstr = va_arg(*arg, wchar_t*);
}

void	l_case(t_mod *data, va_list *arg)
{
	long 					decimal;
	unsigned long			other_base;
	char					*bq;
	char					*q;

	bq = "0123456789ABCDEF";
	q = "0123456789abcdef";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, long);
		data->result = ft_litoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), bq);
	}
	l_case_for_strings(data, arg);
}

void	ll_case(t_mod *data, va_list *arg)
{
	unsigned long long int	other_base;
	long long int 			decimal;
	char					*q;
	char					*bq;

	bq = "0123456789ABCDEF";
	q = "0123456789abcdef";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, long long);
		data->result = ft_litoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned long long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned long long);
		data->result = ft_lutoa_base(other_base, base(data), bq);
	}
}

//-------------------NO MOD-------------------------

void	no_case_for_strings(t_mod *data, va_list *arg)
{
	if (data->specifier == 's')
		data->result = va_arg(*arg, char*);
	else if (data->specifier == 'c')
	{
		data->chr = va_arg(*arg, int);
		data->result[0] = data->chr;
	}
}

void	no_case(t_mod *data, va_list *arg)
{
	int decimal;
	unsigned int other_base;

	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, int);
		data->result = ft_itoa(decimal);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), "0123456789abcdef");
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned int);
		data->result = ft_utoa_base(other_base, base(data), "0123456789ABCDEF");
	}
	no_case_for_strings(data, arg);
}

//----------------------IS <<<<< U >>>> <<< D >>> <<<< O >>>> -------------

void	is_udo(t_mod *data, va_list *arg)
{
	unsigned long	other_base;
	long			decimal;
	char			*q;

	q = "0123456789abcdef";
	if (data->specifier == 'O' || data->specifier == 'U')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'D')
	{
		decimal = va_arg(*arg, long);
		data->result = ft_litoa(decimal);
	}
}

void	is_scp(t_mod *data, va_list *arg)
{
	unsigned long long p;

	p = 0;
	if (data->specifier == 'S')
		data->wstr= va_arg(*arg, wchar_t *);
	else if (data->specifier == 'C')
		data->wstr[0] = va_arg(*arg, wint_t);
	else if (data->specifier == 'p')
	{
		p = (unsigned long long)va_arg(*arg, void*);
		data->result = ft_lutoa_base(p, 16, "0123456789abcdef");
		if (data->precision == 0)
			data->result = ft_strjoin("0x", data->result);
	}
}

//----------------------EDIT CORE -----------------------

void	edit_based_on_mods(t_mod *data, va_list *arg)
{

	if (data->hh_mod == 1)
		hh_case(data, arg);
	else if (data->h_mod == 1)
		h_case(data, arg);
	else if (data->l_mod == 1)
		l_case(data, arg);
	else if (data->ll_mod == 1 || data->j_mod == 1 || data->z_mod == 1)
		ll_case(data, arg);
	else
		no_case(data, arg);
	is_udo(data, arg);
	is_scp(data, arg);
}

//-------------------------CHOP THE WIDTH-------------------------

void	stock_lungime(t_mod *data, int len)
{
	int i;

	i = 0;
	while (len > 0)
	{
		data->lungime[i++] = ' ';
		len--;
	}
	data->lungime[i] = '\0';
}

void	stock_width(t_mod *data)
{
	int		len;
	int		i;
	int		k;
	int		p_size;

	i = 0;
	len = 0;
	k = ft_strlen(data->result);
	p_size = get_precision(data->choped);
	if (data->result[0] == '\0' || data->plus_mod == 1)
		k++;
	if (p_size >= k && p_size > 0 && !no_strings(data))
		len = get_width(data->choped) - p_size;
	else if (data->dot_mod == 1 && (data->specifier == 's' || \
				data->result[0] == '0'))
		len = get_width(data->choped);
	else
		len = get_width(data->choped) - k;
	if (len > 0)
		stock_lungime(data, len);
}

//-----------------------------CHOP PRECISION-------------------------

void	stock_precision(t_mod *data)
{
	int		len;
	char	*tmp;
	int		i;

	i = 0;
	len = 0;
	if (ft_strchr(data->result, '-'))
		len = get_precision(data->choped) - ft_strlen(data->result) + 1;
	else
		len = get_precision(data->choped) - ft_strlen(data->result);
	if (len > 0)
	{
		tmp = ft_memalloc(len);
		while (len > 0)
		{
			tmp[i++] = '0';
			len--;
		}
		tmp[i] = '\0';
		data->precizie = ft_strdup(tmp);
		free(tmp);
	}
}

//--------------------------COMPUTING PRECISION FOR NUMBERS---------------

void	make_positive(t_mod *data)
{
	int		i;
	char	*positive;

	i = 0;
	positive = ft_memalloc(ft_strlen(data->result));
	while (data->result[i])
	{
		if (data->result[i] == '-' || data->result[i] == '+')
			break;
		i++;
	}
	positive = ft_strcpy(positive, data->result + i + 1);
	free(data->result);
	data->result = ft_strdup(positive);
}

void	compute_precision(t_mod *data)
{
	if (ft_strchr(data->result , '-'))
	{
		make_positive(data);
		data->precizie = ft_strjoin("-", data->precizie);
	}
	data->result = ft_strjoin(data->precizie, data->result);
	if (data->specifier == 'p')
		data->result = ft_strjoin("0x", data->result);
}

//------CONCATENATE THE NECESARY WIDTH ( the result already has precision)------

void	compute_width(t_mod *data)
{
	if (ft_strchr(data->result, '+') && data->zero_mod == 1)
	{
		make_positive(data);
		data->lungime = ft_strjoin("+", data->lungime);
	}
	if (data->minus_mod == 1 || (data->specifier == 'p' && \
				data->zero_mod == 1 && data->result[0] == '0'))
		data->result = ft_strjoin(data->result, data->lungime);
	else
		data->result = ft_strjoin(data->lungime, data->result);
}

//------------------------TAKING FLAGS ONE BY ONE----------------

void	case_plus(t_mod *data)
{
	if (data->specifier == 'd' || data->specifier == 'i' || \
			data->specifier == 'D')
	{
		if (ft_strchr(data->result, '-') == NULL)
			data->result = ft_strjoin("+", data->result);
	}
}

void	case_hash(t_mod *data)
{
	int len;
	int	p_size;

	len = (int)ft_strlen(data->result);
	p_size = (int)ft_strlen(data->precizie);
	if (data->specifier == 'x' && data->result[len - 1] != '0')
		data->result = ft_strjoin("0x", data->result);
	else if (data->specifier == 'X' && data->result[len - 1] != '0')
		data->result = ft_strjoin("0X", data->result);
	else if ((data->specifier == 'o' || data->specifier =='O') && \
			data->result[0] != '0')
	{
		data->result = ft_strjoin("0", data->result);
	}
}

void	case_space(t_mod *data)
{
	if (ft_strchr(data->result, '-') == NULL && (data->specifier == 'D' || \
				data->specifier == 'd' || data->specifier == 'i') && \
			data->width == 0)
		data->result = ft_strjoin(" ", data->result);
	else if (ft_strchr(data->result, '-') == NULL && \
			(data->specifier == 'D' || data->specifier == 'd' \
			 || data->specifier == 'i') && data->width == 1 && \
			data->zero_mod == 1)
	{
		data->result[0] = ' ';
	}

}

void	case_zero(t_mod *data)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(data->lungime);
	while (i < len)
	{
		data->lungime[i] = '0';
		i++;
	}
	if (ft_strchr(data->result, '-'))
	{
		make_positive(data);
		data->lungime = ft_strjoin("-", data->lungime);
	}
}

void	case_dot(t_mod *data)
{
	if (data->result[0] == '0' &&!(data->hash_mod == 1 && \
				(data->specifier == 'o' || data->specifier == 'O')))
		data->result = ft_strdup("");
	else if (data->specifier == 's' || (data->specifier == 'c' && \
				data->result[0] == '\0'))
		data->result = ft_strdup("");
	if (data->specifier == 'p')
		data->result = ft_strjoin("0x", data->result);
}

//------------------------IF WE HAVE STRINGS-----------

int		no_strings(t_mod *data)
{
	if (data->specifier == 'S' || data->specifier == 's' || \
			data->specifier == 'c' || data->specifier == 'C')
		return (1);
	return (0);
}

void	edit_strings_precision(t_mod *data)
{
	int p_size;
	int len;
	char	*aux;

	p_size = get_precision(data->choped);
	len = (int)ft_strlen(data->result);
	aux = ft_memalloc(len);
	if (p_size < len)
	{
		aux = ft_strncpy(aux, data->result, p_size);
		data->result = ft_strdup("");
		data->result = ft_strdup(aux);
	}
}

//--------------------EDIT FLAGS FOR WIDE CHARACTERS---------------

void	wide_precision(t_mod *data)
{
	int 	p_size;
	int		len;
	wchar_t *aux;

	aux = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrsize(data->wstr));
	p_size = get_precision(data->choped);
	len = ft_wstrsize(data->wstr);
	if (p_size < ft_wcharsize(data->wstr[0]))
		data->wstr = ft_wstrdup(L"");
	else if (p_size < len)
	{
		aux = ft_wstrsub(data->wstr, 0, p_size);
		data->wstr = ft_wstrdup(L"");
		data->wstr = ft_wstrdup(aux);
	}
}

void	wide_width(t_mod *data)
{
	int		sum;
	int		i;
	wchar_t	*width;

	i = 0;
	width = (wchar_t*)malloc(sizeof(wchar_t) * get_width(data->choped));
	if (ft_strcmp("(null)", (char*)data->wstr) == 0)
		sum = get_width(data->choped);
	else
		sum = get_width(data->choped) - ft_wstrsize(data->wstr);
	if (sum > 0)
	{
		while (i < sum)
		{
			if (data->zero_mod == 1)
				width[i++] = '0';
			else
				width[i++] = ' ';
		}
		width[i] = '\0';
		if (data->minus_mod == 1)
			data->wstr = ft_wstrjoin(data->wstr, width);
		else
			data->wstr = ft_wstrjoin(width, data->wstr);
	}
}

void	wide_dot(t_mod *data)
{
	if (data->specifier != 'C')
		data->wstr = ft_wstrdup(L"");
}

//--------------------------------EDIT WIDE CHRS CORE----------------

void	edit_wide_flags(t_mod *data)
{
	if (data->precision == 1)
		wide_precision(data);
	if (data->dot_mod == 1)
		wide_dot(data);
	if (data->width == 1)
		wide_width(data);
}

//----------------------EDIT WILDCARD---------------------------


//-------------------GETTING WILDCARD  WIDTH AND PRECISION----------------

int		get_wild_precision(va_list *arg)
{
	int		p_size;
	p_size = va_arg(*arg, int);
	return (p_size);
}

int		get_wild_width(va_list *arg)
{
	int w_size;

	w_size = va_arg(*arg, int);
	return (w_size);
}

//-------------------STOCKING WILDCARD WITDTH AND PRECISION -------------

char	*stock_damn_width(char *width, int len)
{
	int i;

	i = 0;
	while (len > 0)
	{
		width[i++] = ' ';
		len--;
	}
	width[i] = '\0';
	return (width);
}

//-------WILD WIDTH------

char	*stock_wild_width(t_mod *data, int size)
{
	char	*width;
	int		i;
	int		len;
	int		k;
	int		p_size;

	if (size == 0)
		return ("");
	else if (size < 0)
		size = size * (-1);
	i = 0;
	len = 0;
	k = ft_strlen(data->result);
	width = ft_memalloc(size);
	p_size = data->wld_psize;
	if (data->result[0] == '\0')
		k++;
	if (p_size >= k && p_size > 0 && !no_strings(data))
		len = size - p_size;
	else
		len = size - k;
	if (len > 0)
		width = stock_damn_width(width, len);
	return (width);
}

//------WILD PRECISION-----

char	*stock_wild_precision(t_mod *data, int size)
{
	int		len;
	char	*tmp;
	int		i;

	if (size < 0)
		size = 0;
	i = 0;
	len = 0;
	tmp = ft_memalloc(size + 10);
	if (ft_strchr(data->result, '-'))
		len = size - ft_strlen(data->result) + 1;
	else
		len = size - ft_strlen(data->result);
	if (len > 0)
	{
		while (len > 0)
		{
			tmp[i++] = '0';
			len--;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

//-----------COMPUTING WILD PRECISION------------------

void	compute_wild_precision(t_mod *data, char *precizie)
{
	if (ft_strchr(data->result , '-'))
	{
		make_positive(data);
		precizie = ft_strjoin("-", precizie);
	}
	data->result = ft_strjoin(precizie, data->result);
	if (data->specifier == 'p')
		data->result = ft_strjoin("0x", data->result);
}

//-------------COMPUTING PRECISION FOR STRINGS-----------

void	edit_wild_strings(t_mod *data)
{
	int		p_size;
	int		len;
	char	*aux;

	p_size = data->wld_psize;
	if (p_size == 0)
		data->result = ft_strdup("");
	else if (p_size < 0)
		p_size = p_size * (-1);
	len = (int)ft_strlen(data->result);
	aux = ft_memalloc(len);
	if (p_size < len)
	{
		aux = ft_strncpy(aux, data->result, p_size);
		data->result = ft_strdup("");
		data->result = ft_strdup(aux);
	}
}

//----------------COMPUTING WILD WIDTH------------

void	compute_wild_width(t_mod *data, char *width)
{
	if (ft_strchr(data->result, '+') && data->zero_mod == 1)
	{
		make_positive(data);
		width = ft_strjoin("+", width);
	}
	if (data->wld_wsize < 0 || (data->specifier == 'p' && \
				data->zero_mod == 1 && data->result[0] == '0'))
		data->result = ft_strjoin(data->result, width);
	else
		data->result = ft_strjoin(width, data->result);
}

//----------WHO COMES FIRST WIDTH OR WILDCARD-----------

int		who_comes_first(t_mod *data)
{
	int i;

	i = 0;
	while (data->choped[i])
	{
		if (data->choped[i] == '*')
			break;
		i++;
	}
	while (i >= 0)
	{
		if (ft_isdigit(data->choped[i]))
			return (0);
		i--;
	}
	return (1);
}

//----------------------------EDIT WILDCARD WIDTH AND PRECISION SIZE--------

void	edit_wildcard_size(t_mod *data, va_list *arg)
{
	int		p_size;
	int		w_size;

	p_size = 0;
	w_size = 0;
	if (data->wild_width == 1)
	{
		w_size = get_wild_width(arg);
		if (w_size != 0)
			data->wld_wsize = w_size;
		else if (who_comes_first(data) == 0)
			data->width = 0;
	}
	if (data->wild_precision == 1)
	{
		p_size = get_wild_precision(arg);
		data->wld_psize = p_size;
	}
}

//----------------------EDIT WILDCARD WIDTH AND PREC----------

void	edit_wildcard(t_mod *data)
{
	char	*width;
	char	*precizie;

	width = ft_memalloc(data->wld_wsize);
	precizie = ft_memalloc(data->wld_psize);
	if (data->wild_precision == 1)
	{
		if (data->specifier != 's' && data->specifier != 'c')
		{
			precizie = stock_wild_precision(data, data->wld_psize);
			compute_wild_precision(data, precizie);
		}
		else
			edit_wild_strings(data);
	}
	if ((who_comes_first(data) == 0 && data->width == 1) || data->width == 0)
		if (data->wild_width == 1)
		{
			width = stock_wild_width(data, data->wld_wsize);
			compute_wild_width(data, width);
		}
}

//----------------------EDIT FLAGS------------------------------------

void	edit_based_on_flags(t_mod *data)
{
	if (data->precision == 1 && data->procent == 0)
	{
		if (data->specifier != 's' && data->specifier != 'c')
		{
			stock_precision(data);
			compute_precision(data);
		}
		else
			edit_strings_precision(data);
	}
	if (data->hash_mod == 1)
		case_hash(data);
	if (data->width == 1)
		stock_width(data);
	if (data->zero_mod == 1)
		case_zero(data);
	if (data->plus_mod == 1)
		case_plus(data);
	if (data->dot_mod == 1)
		case_dot(data);	
	compute_width(data);
	if (data->space_mod == 1 && data->plus_mod == 0)
		case_space(data);
	edit_wide_flags(data);
	edit_wildcard(data);
}

//---------------------------CONVERTING CORE--------------------

char	*convert_based_on_flags(t_mod *data, va_list *arg, int *size)
{
	char		*text = NULL;

	text = ft_memalloc(1000);
	edit_wildcard_size(data, arg);
	edit_based_on_mods(data, arg);
	if (data->result == NULL)
	{
		data->result = ft_memalloc(350);
		data->result = ft_strdup("(null)");
	}
	else if (data->wstr == NULL)
	{
		data->wstr = (wchar_t*)malloc(sizeof(wchar_t) * 100);
		data->wstr = L"(null)";
	}
	if ((data->result[0] == '\0' && data->specifier == 'c')\
			&& data->specifier != 's' && data->specifier != 'p')
		*size = *size + 1;
	if (data->specifier == 'c' && data->l_mod == 1)
		*size = *size - 1;
	edit_based_on_flags(data);
	text = ft_strdup(data->result);
	return (text);
}


//--------------------WHAT IF WE JUST HAVE TO PRINT THE FORMAT---------------

int		no_procent(const char *format)
{
	if (ft_strchr(format, '%') == NULL)
	{
		ft_putstr(format);
		return (1);
	}
	return (0);
}

int		double_procent(t_mod *data)
{
	if (data->procent == 1)
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

//------------------WIDE CHARACTES PRINTING--------------

int		not_wide(t_mod *data)
{
	if (data->specifier == 'S' || data->specifier == 'C')
		return (1);
	else if (data->hh_mod == 1 && data->specifier == 'C')
		return (1);
	else if (data->l_mod == 1 && (data->specifier == 's' || \
				data->specifier == 'c'))
		return (1);
	return (0);
}

int		wide_characters(t_mod *data)
{
	int len;

	len = 0;
	if (data->wstr[0] == '\0' && data->specifier != 'S')
	{
		ft_putchar('\0');
		len++;
	}
	len = len + ft_wstrsize(data->wstr);
	ft_putwstr(data->wstr);
	return (len);
}

//---------------------PRINTING FUNCTION------------

int		how_much_to_print(char *text, t_mod *data)
{
	int len;

	len = 0;
	if (data->specifier == 'c' && data->chr == '\0' && data->wld_wsize == -15)
	{
		ft_putchar('\0');
		len = 14;
	}
	else if (!not_wide(data))
	{
		ft_putstr(text);	
		len = ft_strlen(data->result);
	}
	else
		len = wide_characters(data);
	if (double_procent(data))
		len++;
	if (data->chr == '\0')
		ft_putchar('\0');
	free(data->result);
	return (len);
}
void	is_mizerie(const char *format, unsigned long int *i, \
		t_mod *data, char *choped)
{
	int len;

	len = ft_strlen(choped);
	if ((ft_strchr(SPECIFIERS, choped[len - 1]) == NULL))
	{
		data->result[0] = format[*i + ft_strlen(choped) + 1];
		*i = *i + 1;
	}
}


//----------------THE HEART OF THE PROGRAM-------------


void	start_engine(char *text, int *size, \
		t_mod *data, va_list *arg)
{
	text = ft_strdup(convert_based_on_flags(data, arg, size));
	*size = *size + how_much_to_print(text, data);
}


void	init_var(unsigned long int *i, int *size)
{
	*i = -1;
	*size = 0;
}

int		what_to_print(const char *format, va_list *arg)
{
	char				*text;
	int					size;
	char				*choped;
	t_mod				data;
	unsigned long int	i;

	text = NULL;
	init_var(&i, &size);
	while (++i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			choped = ft_strdup(chop_format(format, &i));
			process_flags(choped, &data);
			is_mizerie(format, &i, &data, choped);	
			start_engine(text, &size, &data, arg);
			i = i + ft_strlen(choped);
		}
		else
		{
			ft_putchar(format[i]);
			size++;
		}
	}
	return (size);
}


//-----------------HERE IT ALL BEGINS---------------------

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int done;

	done = 0;
	va_start(arg, format);
	if (no_procent(format))
		return (ft_strlen(format));
	done = what_to_print(format, &arg);
	va_end(arg);
	return (done);
}

/*
int main (int argc, char **argv)
{
	int n = 0;
	int a;
	//int i = 31;

	setlocale(LC_ALL, "");
	argc = argc + 1 - 1;	
	a = printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("<<<<");
	printf("\n");
	n =	ft_printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("\tOriginal size = %d\tMy size = %d\n", a, n);

	return (0);
}*/
