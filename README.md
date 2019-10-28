# **GUImp Documentation**
# Évenement
## Window Event
**SDL_WINDOWEVENT_SHOWN** *Fenetre mise en avant plan*\
**SDL_WINDOWEVENT_HIDDEN** *Fenetre mise en arriere plan*\
**SDL_WINDOWEVENT_EXPOSED** *descriptif*\
**SDL_WINDOWEVENT_MOVED** *Mouvement de fenetre (utiliser data1;data2)*\
**SDL_WINDOWEVENT_RESIZED** *Changement de taille de fenetre (utiliser data1;data2)*\
**SDL_WINDOWEVENT_SIZE_CHANGED** *Changement de taille ? (utiliser data1;data2)*\
**SDL_WINDOWEVENT_MINIMIZED** *Fenetre minimisée*\
**SDL_WINDOWEVENT_MAXIMIZED** *Fenetre maximisée*\
**SDL_WINDOWEVENT_RESTORED** *Fenetre restaurée*\
**SDL_WINDOWEVENT_ENTER** *jsp*\
**SDL_WINDOWEVENT_LEAVE** *jsp*\
**SDL_WINDOWEVENT_FOCUS_GAINED** *Fenetre gagne le focus*\
**SDL_WINDOWEVENT_FOCUS_LOST** *Fenetre perd le focus*\
**SDL_WINDOWEVENT_CLOSE** *Fermeture de la fenetre*
## Keyboard Event   
**SDL_KEYDOWN** *Appui d'une touche clavier*\
**SDL_KEYUP** *Relachement d'une touche clavier*
## TextInput Event
### Events
**SDL_TEXTINPUT** *Ajout d'un nouveau texte a la fin*
### Functions
**SDL_StartTextInput** *descriptif*\
**SDL_StopTextInput** *descriptif*
## TextEditing Event
## Events
**SDL_TEXTEDITING** *Changement du texte*
## Functions
**SDL_StartTextInput** *descriptif*\
**SDL_StopTextInput** *descriptif*\
## MouseMotion Event
## Events
**SDL_MOUSEMOTION** *Mouvement de souris*
## Functions
**SDL_GetMouseState** *descriptif*\
**SDL_GetRelativeMouseState** *descriptif*\
**SDL_SetRelativeMouseMode** *descriptif*
## MouseButton Event
## Events
**SDL_MOUSEMOTION** *Mouvement de souris*
## Functions
**SDL_GetMouseState** *descriptif*\
**SDL_GetRelativeMouseState** *descriptif*
## #DEFINE
**SDL_BUTTON_LEFT**\
**SDL_BUTTON_MIDDLE**\
**SDL_BUTTON_RIGHT**\
**SDL_BUTTON_X1**\
**SDL_BUTTON_X2**
## MouseWheel Event
### Events
**SDL_MOUSEWHEEL**
# Elements de la struc event et leurs types
    typedef struct event {
        SDL_WindowEvent window;
        SDL_KeyboardEvent key;
        SDL_TextEditingEvent edit;
        SDL_TextInputEvent text;
        SDL_MouseMotionEvent motion;
        SDL_MouseButtonEvent button;
        SDL_MouseWheelEvent wheel;
        SDL_QuitEvent quit;
    } SDL_Event
# Structure de la struct event
        SDL_Event event
        {
            key:
            {
                repeat: Est en repetition ?;
                keysym
                {
                    scancode: scancode;
                    sym: keycode;
                }
                event: type devent;
            },
            button:
            {
                Uint32  windowID: id de la fenetre courante;
                Sint32 which: id de la souris actuelle ? (a verifier);
                Sint32 button: id du bouton de la souris;
                Sint32 clicks: nombre de clicks successif;
                Sint32 x: coordonnée x;
                Sint32 y: coordonnée y;
            }    
            motion:
            {
                Uint32 windowID: id de la fenetre courante;
                Sint32 which: id de la souris actuelle ?;
                Sint32 x: coordonnée x;
                Sint32 y: coordonnée y;
                Sint32 xrel: delta x;
                Sint32 yrel: delta y;
            }            
            wheel:
            {
                Uint32 windowID: id de la fenetre courante;
                which: id de la souris actuelle;
                Sint32 x: pos x;           
                Sint32 y: pos y;
            }       
            window:
            {
                Uint32 windowID: id de la fenetre courante;
                Sint32 data1: donnée en fonction de l'evenement courant;
                Sint32 data2: donnée en fonction de levenement courant 2;
                timestamp: timestamp de levenement;
            }           
            edit:
            {
               Uint32 windowID: id de la fenetre courante;
               char[32] text: texte encodé en utf8 terminé par une valeur nulle
               Sint32 start: l'index du debut de l'edition
               Sint32 length: le nombre de caractere a editer a partir de start
            }
            text:
            {
               Uint32 windowID: id de la fenetre courante;
               char[32] text: texte encodé en utf8 terminé par une valeur nulle
               Sint32 start: l'index du debut de l'edition
               Sint32 length: le nombre de caractere a editer a partir de start
            }
        }
# Flags SDL_WindowFlags
**SDL_WINDOW_FULLSCREEN** *fullscreen window*
**SDL_WINDOW_FULLSCREEN_DESKTOP** *fullscreen window at the current desktop resolution*
**SDL_WINDOW_OPENGL** *window usable with OpenGL context*
**SDL_WINDOW_SHOWN** *window is visible*
**SDL_WINDOW_HIDDEN** *window is not visible*
**SDL_WINDOW_BORDERLESS** *no window decoration*
**SDL_WINDOW_RESIZABLE** *window can be resized*
**SDL_WINDOW_MINIMIZED** *window is minimized*
**SDL_WINDOW_MAXIMIZED** *window is maximized*
**SDL_WINDOW_INPUT_GRABBED** *window has grabbed input focus*
**SDL_WINDOW_INPUT_FOCUS** *window has input focus*
**SDL_WINDOW_MOUSE_FOCUS** *window has mouse focus*
**SDL_WINDOW_FOREIGN** *window not created by SDL*
**SDL_WINDOW_ALLOW_HIGHDPI** *window should be created in high-DPI mode if supported (>= SDL 2.0.1)*
**SDL_WINDOW_MOUSE_CAPTURE** *window has mouse captured (unrelated to INPUT_GRABBED, >= SDL 2.0.4)*
**SDL_WINDOW_ALWAYS_ON_TOP** *window should always be above others (X11 only, >= SDL 2.0.5)*
**SDL_WINDOW_SKIP_TASKBAR** *window should not be added to the taskbar (X11 only, >= SDL 2.0.5)*
**SDL_WINDOW_UTILITY** *window should be treated as a utility window (X11 only, >= SDL 2.0.5)*
**SDL_WINDOW_TOOLTIP** *window should be treated as a tooltip (X11 only, >= SDL 2.0.5)*
**SDL_WINDOW_POPUP_MENU** *window should be treated as a popup menu (X11 only, >= SDL 2.0.5)*
