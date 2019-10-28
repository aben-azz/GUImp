/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:38:44 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/28 14:23:56 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include <stdio.h>

int	init_window_struct(t_window *window)
{
	window->position.x = 0;
	window->position.y = 0;
	window->size.x = 650;
	window->size.y = 750;
	window->flags = SDL_WINDOW_SHOWN | SDL_WINDOW_POPUP_MENU;
	return (1);
}

int	main(void)
{
	//SDL_Window*	window;
	SDL_Event	event;
	int			ret;
	t_window window;
	ret = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_dprintf(2 ,"Échec de l'initialisation de la SDL %s\n", SDL_GetError());
		return (-1);
	}
	if (init_window_struct(&window) && ui_create_window("SDL", &window))
	{
		while (ret)
			while (SDL_PollEvent(&event))
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					ret = 0;
			}
		SDL_DestroyWindow(window.ptr);
	}
	else
	{
		ft_dprintf(2, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
	}
	SDL_Quit();
	return 0;
}
