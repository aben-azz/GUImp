/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:27:44 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/24 12:06:45 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			handle_char(int fd, va_list list, t_fmt *fmt)
{
	char	c;

	c = (fmt->type == 'c') ? (char)va_arg(list, int) : '%';
	if (fmt->opt & SUB)
	{
		ft_putchar_fd(c, fd);
		ft_nputchar_fd(' ', fmt->field - 1, fd);
	}
	else
	{
		ft_nputchar_fd(fmt->opt & ZERO ? '0' : ' ', fmt->field - 1, fd);
		ft_putchar_fd(c, fd);
	}
	return (fmt->field > 0 ? fmt->field : 1);
}

int			handle_array(int fd, va_list list, t_fmt *fmt)
{
	int		*array;
	char	**string;
	int		i;
	char	*separator;
	int		number;

	array = (fmt->type == 'v') ? va_arg(list, int *) : NULL;
	string = (fmt->type == 'r') ? va_arg(list, char **) : NULL;
	(void)string;
	(void)array;
	if ((fmt->type == 'r' && !string) || (fmt->type == 'v' && !array))
		return (0);
	number = va_arg(list, int);
	i = 0;
	separator = va_arg(list, char *);
	while (i < number)
	{
		fmt->type == 'v' ? ft_putnbr_fd(array[i++], fd) :
			ft_putstr_fd(string[i++], fd);
		i != number && ft_putstr_fd(separator, fd);
	}
	return (0);
}

int			handle_string(int fd, va_list list, t_fmt *fmt)
{
	char	*str;
	int		ret;

	str = va_arg(list, char*);
	str = !str ? "(null)" : str;
	if (fmt->prec >= 0 && ((size_t)fmt->prec < ft_strlen(str)))
	{
		str = ft_strsub(str, 0, (size_t)fmt->prec);
		fmt->prec = -5;
	}
	str == NULL ? exit(1) : NULL;
	ret = ft_strlen(str);
	if (fmt->opt & SUB)
	{
		ft_putstr_fd(str, fd);
		ft_nputchar_fd(' ', fmt->field - ret, fd);
	}
	else
	{
		ft_nputchar_fd(fmt->opt & ZERO ? '0' : ' ', fmt->field - ret, fd);
		ft_putstr_fd(str, fd);
	}
	(fmt->prec == -5) ? ft_strdel(&str) : 0;
	return (ret < fmt->field ? fmt->field : ret);
}

int			handle_number(int fd, va_list list, t_fmt *fmt)
{
	char		*str;
	int			len;

	(!~ft_indexof("fF", fmt->type) && ~fmt->prec) && (fmt->opt &= ~(ZERO));
	(~ft_indexof("fF", fmt->type)) && (fmt->prec = !~fmt->prec ? 6 : fmt->prec);
	str = get_s(fmt, list);
	if (!fmt->prec && str[0] == '0' && !~ft_indexof("fF", fmt->type))
	{
		(~ft_indexof("Xx", fmt->type)) && (fmt->prefixe = 0);
		str[0] = '\0';
	}
	if (!~ft_indexof("Pp", fmt->type))
		fmt->prefixe = *str == '0' ? 0 : fmt->prefixe;
	(*str == '-') && (fmt->signe = *(str++));
	fmt->prec -= ft_strlen(str);
	fmt->prec = fmt->prefixe == 1 ? fmt->prec - 1 : fmt->prec;
	fmt->prec = fmt->prec < 0 ? 0 : fmt->prec;
	len = fmt->field - ft_strlen(str) - (fmt->signe ? 1 : 0) - fmt->prec;
	len -= fmt->prefixe;
	len = print_numbers(fd, fmt, str, len);
	fmt->signe == '-' ? free(--str) : ft_strdel(&str);
	return (len);
}
