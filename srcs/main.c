/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:38:44 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/28 13:50:46 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#include <stdio.h>

int	main(void)
{
	SDL_Window*	window;
	SDL_Event	event;
	int			ret;

	ret = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(2 ,"Échec de l'initialisation de la SDL %s\n", SDL_GetError());
		return (-1);
	}

	if ((window = SDL_CreateWindow("GUImp", SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN)))
	{
		while (ret)
			while (SDL_PollEvent(&event))
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					ret = 0;
			}
		SDL_DestroyWindow(window);
	}
	else
	{
		fprintf(2, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
	}
	SDL_Quit();
	return 0;
}
