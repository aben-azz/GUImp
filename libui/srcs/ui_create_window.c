/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:02:44 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/28 14:22:36 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_create_window(const char *title, t_window *w)
{
	w->ptr = SDL_CreateWindow(title, w->position.x, w->position.y,
										w->size.x, w->size.y, w->flags);
	return (w->ptr != NULL);
}
