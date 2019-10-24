/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:59:16 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/24 13:23:31 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    int statut = EXIT_FAILURE;
    SDL_Rect rect = {100, 100, 100, 100}, dst = {0, 0, 0, 0};
    SDL_Color rouge = {255, 0, 0, 255}, bleu = {0, 0, 255, 255};

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    if(0 != SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        goto Quit;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                SDL_TEXTUREACCESS_TARGET, 200, 200);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        goto Quit;
    }

    SDL_SetRenderTarget(renderer, texture);
    /* La texture est la cible de rendu, maintenant, on dessine sur la texture. */
    SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
    SDL_RenderFillRect(renderer, &rect); /* On dessine un rectangle rouge sur la texture. */

    SDL_SetRenderTarget(renderer, NULL); /* Le renderer est la cible de rendu. */

    /* On récupère les dimensions de la texture, on la copie sur le renderer
       et on met à jour l’écran. */
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    SDL_RenderPresent(renderer);
    statut = EXIT_SUCCESS;
    SDL_Delay(3000);

Quit:
    if(NULL != texture)
        SDL_DestroyTexture(texture);
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}
