/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:30:56 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/19 15:51:02 by rcrisan          ###   ########.fr       */
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
	if (ft_strchr(SPECIFIERS, choped[j - 1]) == NULL)
		return (NULL);
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
	flag->chr = '0';
	flag->result = ft_memalloc(1000);
	flag->wstr = ft_memalloc(200);
	flag->choped = ft_memalloc(20);
	flag->precizie = ft_memalloc(200);
	flag->lungime = ft_memalloc(200);
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
		else if (choped[i] == '-')
			data->minus_mod = 1;
		else if (choped[i] == '+')
			data->plus_mod = 1;
		else if (choped[i] == ' ')
			data->space_mod = 1;
		else if (choped[i] == '.' && (!ft_isdigit(choped[i + 1]) || \
					choped[i + 1] == '0'))
			data->dot_mod = 1;
		i++;
	}
	if (validate_mod(choped) > 0)
		process_mods(choped, data);
	process_precision(choped, data);
	process_specifiers(choped, data);
	process_zero_mod(choped, data);
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
	char					*Q;
	char					*q;

	Q = "0123456789ABCDEF";
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
		data->result = ft_lutoa_base(other_base, base(data), Q);
	}
	l_case_for_strings(data, arg);
}

void	ll_case(t_mod *data, va_list *arg)
{
	unsigned long long int	other_base;
	long long int 			decimal;
	char					*q;
	char					*Q;

	Q = "0123456789ABCDEF";
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
		data->result = ft_lutoa_base(other_base, base(data), Q);
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

void	is_UDOSC(t_mod *data, va_list *arg)
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
	else if (data->specifier == 'S')
		data->wstr = va_arg(*arg, wchar_t*);
	else if (data->specifier == 'C')
		data->wstr[0] = va_arg(*arg, wint_t);
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
	is_UDOSC(data, arg);
}

//--------prototype------------
int		no_strings(t_mod *data);

//-------------------------CHOP THE WIDTH-------------------------

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
	else if (data->dot_mod == 1 && data->specifier == 's')
		len = get_width(data->choped);
	else
		len = get_width(data->choped) - k;
	if (len > 0)
	{
		while (len > 0)
		{
			data->lungime[i++] = ' ';
			len--;
		}
	}
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
}

//------CONCATENATE THE NECESARY WIDTH ( the result already has precision)------

void	compute_width(t_mod *data)
{
	if (ft_strchr(data->result, '+') && data->zero_mod == 1)
	{
		make_positive(data);
		data->lungime = ft_strjoin("+", data->lungime);
	}
	if (data->minus_mod == 1)
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
	if (data->specifier == 'x' && data->result[0] != '0')
		data->result = ft_strjoin("0x", data->result);
	else if (data->specifier == 'X' && data->result[0] != '0')
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
	else if (ft_strchr(data->result, '-') == NULL && (data->specifier == 'D' || \
				data->specifier == 'd' || data->specifier == 'i') && \
			data->width == 1 && data->zero_mod == 1)
		data->result[0] = ' ';

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
	if (data->result[0] == '0' && !(data->hash_mod == 1 && \
				(data->specifier == 'o' || data->specifier == 'O')))
		data->result = ft_strdup("");
	else if (data->specifier == 's' || data->specifier == 'c')
		data->result = ft_strdup("");
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

//----------------------EDIT FLAGS------------------------------------

void	edit_based_on_flags(t_mod *data)
{
	if (data->precision == 1)
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
	if (data->zero_mod == 1 && data->dot_mod == 0)
		case_zero(data);
	if (data->plus_mod == 1)
		case_plus(data);
	if (data->dot_mod == 1)
		case_dot(data);	
	compute_width(data);
	if (data->space_mod == 1 && data->plus_mod == 0)
		case_space(data);
}

//---------------------------CONVERTING CORE--------------------

char	*convert_based_on_flags(t_mod *data, va_list *arg, int *size)
{
	char		*text = NULL;

	text = ft_memalloc(1000);
	edit_based_on_mods(data, arg);
	if (data->result == NULL)
		return (NULL);
	if (data->result[0] == '\0' && data->specifier != 's')
		*size = *size + 1;
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

int		how_much_to_print(char *text, t_mod *data)
{
	int len;

	if (text == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(data->result);
	ft_putstr(text);
	if (data->chr == '\0')
		ft_putchar('\0');
	return (len);
}

//----------------THE HEART OF THE PROGRAM-------------

void	start_engine(char *text, char *choped, \
		t_mod *data, unsigned long int *i, int *size, va_list *arg)
{
	process_flags(choped, data);
	data->choped = ft_strdup(choped);
	text = ft_strdup(convert_based_on_flags(data, arg, size));
	*i = ft_strlen(choped) + *i;
	*size = *size + how_much_to_print(text, data);
}

int		what_to_print(const char *format, va_list *arg)
{
	char				*text = NULL;
	int					size;
	char				*choped;
	t_mod				data;
	unsigned long int	i;

	i = -1;
	size = 0;
	while (++i < ft_strlen(format))
	{
		if (format[i] == '%' && format[i - 1] != '%')
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
		return (ft_strlen(format));
	done = what_to_print(format, &arg);
	va_end(arg);
	return (done);
}

/*
int main (int argc, char **argv)
{
	int n;
	int a;

	argc = argc + 1 - 1;	
	a = printf(argv[1], ft_atoi(argv[2]));
	printf("<<<<");
	printf("\n");
	n =	ft_printf(argv[1], ft_atoi(argv[2]));
	printf("\tOriginal size = %d\tMy size = %d\n", a, n);


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
