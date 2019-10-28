/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:15:52 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/28 14:20:10 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include <unistd.h>
# include <math.h>
#include "/Users/aben-azz/brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h"

/*
** FONCTIONS AUTORISÉES
** ◦ Toutes les fonctions de la lib math (-lm et man 3 math)
** ◦ Toutes les fonctions de la SDL 2, SDL_ttf et SDL_image.
*/


//typedef SDL_Window t_window;
typedef struct	s_point
{

	int		x;
	int		y;
}				t_point;

typedef struct	s_window
{

	t_point			position;
	t_point			size;
	Uint32			flags;
	SDL_Window		*ptr;
}				t_window;
int	ui_create_window(const char *title, t_window *w);
/*

*/
#endif
