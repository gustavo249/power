/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:30:56 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/13 20:01:58 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
			return (NULL);
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
	flag->result = ft_memalloc(1000);
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

//---------HERE IS THE PROCESSING CORE----------

void	process_flags(char *choped, t_mod *data)
{
	int i;

	i = 0;
	init_flags(data);
	while (choped[i])
	{
		if (choped[i] == '#')
			data->hash_mod = 1;
		else if (choped[i] == '0')
			data->zero_mod = 1;
		else if (choped[i] == '-')
			data->minus_mod = 1;
		else if (choped[i] == '+')
			data->plus_mod = 1;
		else if (choped[i] == ' ')
			data->space_mod = 1;
		i++;
	}
	if (validate_mod(choped) > 0)
		process_mods(choped, data);
	process_precision(choped, data);
	process_specifiers(choped, data);
}

//-----------DEALING WITH THE SIZE (WIDTH AND PRECISION)--------------

int		get_precision(char *choped)
{
	int		i;
	char	*precision;
	int		k;

	i = 0;
	k = 0;
	precision = (char*)malloc(sizeof(precision) * strlen(choped));
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

	i = ft_strlen(choped) - 1;
	k = 0;
	width = (char*)malloc(sizeof(width) * strlen(choped));
	while (i >= 0)
	{
		if (choped[i] == '0' && !ft_isdigit(choped[i - 1]))
			i--;
		else if (!ft_isdigit(choped[i]))
			i--;
		else
			break;
	}
	while (ft_isdigit(choped[i]) && i >= 0)
		width[k++] = choped[i--];
	width[k] = '\0';
	ft_strrev(width);
	return (ft_atoi(width));
}

//---------ADDING THE WIDTH OR PRECISION TO A SUM---------

int		get_size(char *choped, t_mod *data)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	if (data->width == 0 && data->precision == 0)
		return (0);	
	else if (data->precision == 1)
		sum = get_precision(choped);
	else if (data->width == 1 && data->precision == 0)
		sum = get_width(choped);
	return (sum);
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

//------------------------------SIGNED ITOA BASE-----------------

char	*ft_litoa_base(long n, int base, char *q)
{
	char    sgn;
	char    *str;
	int     i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	str = ft_strnew(32);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i++] = q[ft_neg(n % base)];
		n /= base;
	}
	if (sgn && base == 10)
		str[i] = '-';
	str = ft_strrev(str);
	return (str);
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
	char			*Q;

	Q = "0123456789ABCDEF";
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
		data->result = ft_utoa_base(other_base, base(data), Q);
	}
}

void	h_case(t_mod *data, va_list *arg)
{
	short 					decimal;
	unsigned short			other_base;
	char					*Q;

	Q = "0123456789ABCDEF";
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
		data->result = ft_utoa_base(other_base, base(data), Q);
	}
}

void	l_case(t_mod *data, va_list *arg)
{
	long 					decimal;
	unsigned long			other_base;
	char					*Q;
	char					*q;

	Q = "0123456789ABCDEF";
	q = "0123456789abcdef";
	if (data->specifier == 'd' || data->specifier == 'i')
	{
		decimal = va_arg(*arg, long);
		data->result = ft_litoa_base(decimal, base(data), q);
	}
	else if (is_uox(data))
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
	}
	else if (data->specifier == 'X')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), Q);
	}
}

//-------------------NO MOD-------------------------

void	no_case_for_strings(t_mod *data, va_list *arg)
{
	char *result;

	result = ft_strnew(5000);
	if (data->specifier == 's' || data->specifier == 'S')
	{
		result = va_arg(*arg, char*);
		if (result)
			data->result = ft_strdup(result);
	}
	else if (data->specifier == 'c' || data->specifier == 'C')
		data->chr = va_arg(*arg, int);
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

void	is_UDO(t_mod *data, va_list *arg)
{
	unsigned long	other_base;
	char			*q;

	q = "0123456789abcdef";
	if (data->specifier == 'O' || data->specifier == 'U' || data->specifier == 'D')
	{
		other_base = va_arg(*arg, unsigned long);
		data->result = ft_lutoa_base(other_base, base(data), q);
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
	/*else if (data->ll_mod = 1)
	  ll_case(data, arg);
	  else if (data->j_mod = 1)
	  j_case(data, arg);
	  else if (data->z_mod = 1)
	  z_case(data, arg);*/
	else
		no_case(data, arg);
	is_UDO(data, arg);
}

//----------HERE WE START THE CONVERTING PHASE (THE MAGIC BEGINS)-------------

char	*convert_based_on_flags(t_mod *data, va_list *arg)
{
	char		*text = NULL;

	text = ft_memalloc(10000);
	edit_based_on_mods(data, arg);
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

int		how_much_to_print(char *choped, char *text, t_mod *data)
{
	int length;
	int size;

	size = 0;
	length = get_size(choped, data);
	if (length != 0)
		ft_putnstr(text, length);
	else if (data->specifier == 'c' || data->specifier == 'C')
	{
		ft_putchar(data->chr);
		size++;
	}
	else
		ft_putstr(text);
	size = size + ft_strlen(text);
	return (size);
}

//----------------THE HEART OF THE PROGRAM-------------

void	start_engine(char *text, char *choped, \
		t_mod *data, unsigned long int *i, int *size, va_list *arg)
{
	process_flags(choped, data);
	text = ft_strdup(convert_based_on_flags(data, arg));
	*i = ft_strlen(choped) + *i;
	*size = *size + how_much_to_print(choped, text, data);
}

int		what_to_print(const char *format, va_list *arg)
{
	char	*text = NULL;
	int		size;
	char	*choped;
	t_mod	data;
	unsigned long int	i;

	i = -1;
	size = 0;
	while (++i < ft_strlen(format))
	{
		if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '\0')
		{
			choped = ft_strdup(chop_format(format, &i));
			if (choped != NULL)
				start_engine(text, choped, &data, &i, &size, arg);
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
		return (ft_strlen(format) - 1);
	done = what_to_print(format, &arg);
	va_end(arg);
	return (done);
}
/*
int main (int argc, char **argv)
{
	int n;

	argc = argc + 1 - 1;	
	printf(argv[1], ft_atoi(argv[2]));
	printf("\n");
	n =	ft_printf(argv[1], ft_atoi(argv[2]));

	char	*choped;

	  printf("WIDTH = %d\t PRECISION = %d\n", get_width(choped), get_precision(choped));
	  process_flags(choped, &flag);

	  printf("dot = %d\n", flag.dot_mod);
	  printf("h mod = %d\n", flag.h_mod);
	  printf("hh mod = %d\n", flag.hh_mod);
	  printf("l mod = %d\n", flag.l_mod);
	  printf("ll mod = %d\n", flag.ll_mod);
	  printf("z mod = %d\n", flag.z_mod);
	  printf("j mod = %d\n", flag.j_mod);
	  printf("# mod = %d\n", flag.hash_mod);
	  printf("minus mod = %d\n", flag.minus_mod);
	  printf("0 mod = %d\n", flag.zero_mod);
	  printf("+ mod = %d\n", flag.plus_mod);
	  printf("space mod = %d\n", flag.space_mod);
	  printf("specifier = %c\n", flag.specifier);
	  printf("width mod = %d\n", flag.width);
	  printf("precision mod = %d\n", flag.precision);
	  printf("procent mod = %d\n", flag.procent);
	  return (0);
}*/
